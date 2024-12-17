import javax.swing.*;


public class App {
    public static void main(String[] args) {
//window variavles
        int tileSie = 32;
        int row = 16;
        int columns = 16;
        int boardWidth = tileSie * columns; //32*16 = 512
        int boardheight = tileSie * row; //32*16 = 512

        JFrame frame = new JFrame("Space Invaders");
        frame.setVisible(true);
        frame.setSize(boardWidth, boardheight);
        frame.setLocationRelativeTo(null);
        frame.setResizable(false);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        SpaceInvaders spaceInvaders = new SpaceInvaders();
        frame.add(spaceInvaders);
        frame.pack();
        spaceInvaders.requestFocus();
        frame.setVisible(true);
    }
}
