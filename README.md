# 👾 Space Invaders - Raylib

![Stars](https://github.com/mukeshlilawat1/Space-Invaders-Cpp/stargazers)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Cpp Language](https://img.shields.io/badge/Language-Cpp-blue)
![Raylib](https://img.shields.io/badge/Library-Raylib-lightgrey)
![Version](https://img.shields.io/badge/version-1.0.0-blue)

---

## ✨ Overview

**Space Invaders** is a classic arcade shooting game implemented using the **Raylib** library in C.  
Players control a spaceship to shoot waves of descending aliens while avoiding enemy attacks.  

This project demonstrates:

- Real-time rendering and graphics using Raylib  
- Keyboard input handling  
- Collision detection between player, bullets, and enemies  
- Game loop management and basic game mechanics  
- Sound effects integration

---

## 🎮 Features

- Classic Space Invaders gameplay  
- Player-controlled spaceship with smooth movement  
- Multiple enemy waves with increasing difficulty  
- Bullet shooting mechanics  
- Collision detection for enemies, bullets, and player  
- Score tracking system  
- Game over and restart functionality  
- Simple sound effects for shooting and explosions

---

## 🛠 Technology Stack

| Language | Library |
|----------|---------|
| Cpp        | Raylib  |

---

## 📂 Project Structure

```
Space-Invaders/
│
├── src/                  # Source code files
│   ├── main.cpp            # Main game loop
│   ├── player.cpp          # Player logic
│   ├── enemy.cpp           # Enemy logic
│   ├── bullet.cpp          # Bullet logic
│   └── utils.cpp           # Helper functions
│
├── include/              # Header files
│   ├── player.h
│   ├── enemy.h
│   ├── bullet.h
│   └── utils.h
│
├── assets/               # Game assets
│   ├── sprites/          # Player, enemy, bullet images
│   └── sounds/           # Sound effects
│
├── Makefile              # Build instructions
└── README.md             # Project documentation
```

---

## 📦 Getting Started

### Prerequisites

- Raylib library installed (https://www.raylib.com/)  
- C compiler: GCC / Clang / MinGW

### Installation

1. Clone the repository:
```bash
git clone <https://github.com/mukeshlilawat1/Space-Invaders-Cpp.git>
cd space-invaders-raylib
```

2. Compile the game:
```bash
make
```

3. Run the game:
```bash
./space-invaders
```

---

## 🎮 Controls

- **Arrow keys / A,D:** Move spaceship left/right  
- **Space:** Shoot bullets  
- **Esc:** Quit game

---

## ⚡ Gameplay Mechanics

- Enemies move left-to-right and descend after hitting screen borders  
- Player can shoot bullets upward to destroy enemies  
- Game ends if an enemy reaches the bottom or player collides with enemy/bullet  
- Score increases for each enemy defeated

---

## 👤 Contributors

- Mukesh Lilawat – Lead Developer  

---

## 📝 License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## 🎨 Screenshots / GIFs

> _Add screenshots or GIFs of gameplay here._

---

## 🤝 Contributing

Pull requests are welcome! For major changes, open an issue first to discuss what you would like to change.

---

> _Star ⭐ this repo if you enjoy the game!_