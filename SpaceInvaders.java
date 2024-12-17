import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.Random;
import javax.swing.*;

public class SpaceInvaders extends JPanel implements ActionListener, KeyListener {

    //board
    int tileSize = 32;
    int row = 16;
    int columns = 16;

    int boardWidht = tileSize * columns; //32*16
    int boardHeight = tileSize * row;

    Image shipImage;
    Image alienImage;
    Image alienCyanImage;
    Image alienMagentaImage;
    Image alienYellowImage;
    ArrayList<Image> alienImageArray;

    class Block {
        int x;
        int y;
        int width;
        int height;
        Image image;
        boolean alive = true; //used for aliens
        boolean used = false; //used for bullets

        Block(int x, int y, int width, int height, Image image) {
            this.x = x;
            this.y = y;
            this.width = width;
            this.height = height;
            this.image = image;
        }
    }

    //ship
    int shipWidth = tileSize * 2; //64px
    int shipHeight = tileSize;
    int shipX = tileSize * columns / 2 - tileSize;
    int shipY = boardHeight - tileSize * 2;
    int shipVelocityX = tileSize;
    Block ship;

    //aliens
    ArrayList<Block> alienArray;
    int alienWidth = tileSize * 2;
    int alienHeight = tileSize;
    int alienX = tileSize;
    int alienY = tileSize;

    int alienRow = 2;
    int alienColumns = 3;
    int AlienCount = 0; //number of aliens to defeat
    int alienVelocityX = 1; //alien moving speed

    //bullets
    ArrayList<Block> bulletArray;
    int bulletWidth = tileSize / 8;
    int bulletHeight = tileSize / 2;
    int bulletVelocityY = -10; //bullet moving speed

    Timer gameLoop;
    int score = 0;
    boolean GameOver = false;

    SpaceInvaders() {
        setPreferredSize(new Dimension(boardWidht, boardHeight));
        setBackground(Color.black);
        setFocusable(true);
        addKeyListener(this);

        //load images
        shipImage = new ImageIcon(getClass().getResource("./ship.png")).getImage();
        alienImage = new ImageIcon(getClass().getResource("./alien.png")).getImage();
        alienCyanImage = new ImageIcon(getClass().getResource("./alien-cyan.png")).getImage();
        alienMagentaImage = new ImageIcon(getClass().getResource("./alien-magenta.png")).getImage();
        alienYellowImage = new ImageIcon(getClass().getResource("./alien-yellow.png")).getImage();

        alienImageArray = new ArrayList<Image>();
        alienImageArray.add(alienImage);
        alienImageArray.add(alienCyanImage);
        alienImageArray.add(alienMagentaImage);
        alienImageArray.add(alienYellowImage);

        ship = new Block(shipX, shipY, shipWidth, shipHeight, shipImage);
        alienArray = new ArrayList<Block>();
        bulletArray = new ArrayList<Block>();
        //game timer
        gameLoop = new Timer(1000 / 60, this); // 1000/60 = 16.7
        createAliens();
        gameLoop.start();
    }

    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        draw(g);
    }

    public void draw(Graphics g) {
        //ship
        g.drawImage(ship.image, ship.x, ship.y, ship.width, ship.height, null);

        //aliens
        for (int i = 0; i < alienArray.size(); i++) {
            Block alien = alienArray.get(i);
            if (alien.alive) {
                g.drawImage(alien.image, alien.x, alien.y, alien.width, alien.height, null);
            }
        }

        //bullets
        g.setColor(Color.white);
        for (int bullet = 0; bullet < bulletArray.size(); bullet++) {
            Block bullets = bulletArray.get(bullet);
            if (!bullets.used) {
                g.fillRect(bullets.x, bullets.y, bullets.width, bullets.height);
            }
        }

        //score
        g.setColor(Color.white);
        g.setFont(new Font("Times New Roman", Font.BOLD, 32));
        if (GameOver) {
            g.drawString("Game Over 😢: " + String.valueOf((int) score), 10, 35);
        } else {
            g.drawString(String.valueOf((int) score), 10, 35);
        }
    }

    public void move() {
        //aliens
        for (int i = 0; i < alienArray.size(); i++) {
            Block alien = alienArray.get(i);
            if (alien.alive) {
                alien.x += alienVelocityX;

                //if alien touches the borders
                if (alien.x + alien.width > boardWidht) {
                    alien.x = boardWidht - alien.width; // Adjust exact position at right boundary
                    alienVelocityX *= -1;
                    moveAliensDown();
                } else if (alien.x < 0) {
                    alien.x = 0; // Adjust exact position at left boundary
                    alienVelocityX *= -1;
                    moveAliensDown();
                }

                if (alien.y >= ship.y) {
                    GameOver = true;
                }
            }
        }

        //bullets move
        for (int bullet = 0; bullet < bulletArray.size(); bullet++) {
            Block bullets = bulletArray.get(bullet);
            bullets.y += bulletVelocityY;

            //bullet collision with aliens
            for (int j = 0; j < alienArray.size(); j++) {
                Block alien = alienArray.get(j);
                if (!bullets.used && alien.alive && detectCollision(bullets, alien)) {
                    bullets.used = true;
                    alien.alive = false;
                    AlienCount--;
                    score += 50;
                }
            }
        }

        //clear all bullets
        while (bulletArray.size() > 0 && (bulletArray.get(0).used || bulletArray.get(0).y < 0)) {
            bulletArray.remove(0); //remove the first element of the array
        }

        //next level
        if (AlienCount == 0) {
            score += alienColumns * alienRow * 50;
            alienColumns = Math.max(alienColumns + 1, columns / 2 - 2);
            alienRow = Math.min(alienRow + 1, row - 6);
            alienArray.clear();
            bulletArray.clear();
            alienVelocityX = 1;
            createAliens();
        }
    }

    public void createAliens() {
        Random random = new Random();
        for (int Alien = 0; Alien < alienRow; Alien++) {
            for (int Minati = 0; Minati < alienColumns; Minati++) {
                int randomImageIndex = random.nextInt(alienImageArray.size());
                Block alien = new Block(
                        alienX + Minati * alienWidth,
                        alienY + Alien * alienHeight,
                        alienWidth,
                        alienHeight,
                        alienImageArray.get(randomImageIndex)
                );
                alienArray.add(alien);
            }
        }
        AlienCount = alienArray.size();
    }

    public boolean detectCollision(Block a, Block b) {
        return a.x < b.x + b.width &&
                a.x + a.width > b.x &&
                a.y < b.y + b.height &&
                a.y + a.height > b.y;
    }

    public void moveAliensDown() {
        for (int j = 0; j < alienArray.size(); j++) {
            alienArray.get(j).y += alienHeight;
        }
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        move();
        repaint();
        if (GameOver) {
            gameLoop.stop();
        }
    }

    @Override
    public void keyTyped(KeyEvent e) {
    }

    @Override
    public void keyPressed(KeyEvent e) {
    }

    @Override
    public void keyReleased(KeyEvent e) {
        if (GameOver) {
            ship.x = shipX;
            alienArray.clear();
            bulletArray.clear();
            score = 0;
            alienVelocityX = 1;
            alienColumns = 3;
            alienRow = 2;
            GameOver = false;
            createAliens();
            gameLoop.start();
        }
        if (e.getKeyCode() == KeyEvent.VK_LEFT && ship.x - shipVelocityX >= 0) {
            ship.x -= shipVelocityX;
        } else if (e.getKeyCode() == KeyEvent.VK_RIGHT && ship.x + ship.width + shipVelocityX <= boardWidht) {
            ship.x += shipVelocityX;
        } else if (e.getKeyCode() == KeyEvent.VK_SPACE) {
            Block bullet = new Block(ship.x + shipWidth * 15 / 32, ship.y, bulletWidth, bulletHeight, null);
            bulletArray.add(bullet);
        }
    }
}
