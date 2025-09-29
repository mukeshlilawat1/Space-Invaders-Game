---

# README.md

---

# 👾 Space Invaders - Raylib

![Stars](https://img.shields.io/github/stars/<your-username>/space-invaders-raylib.svg?style=social)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![C Language](https://img.shields.io/badge/Language-C-blue)
![Raylib](https://img.shields.io/badge/Library-Raylib-lightgrey)
![Version](https://img.shields.io/badge/version-1.0.0-blue)

---

## ✨ Overview

**Space Invaders** is a **classic arcade shooting game** built in **C** using the **Raylib library**. Players control a spaceship to shoot descending aliens.

This project demonstrates:

* Game development with C & Raylib
* Real-time graphics rendering
* Keyboard input handling & collision detection
* Game loop & state management
* Sound effects integration

---

## 🚀 Features

* Player-controlled spaceship
* Multiple enemy waves with increasing difficulty
* Shooting mechanics
* Collision detection
* Score tracking
* Game over & restart functionality
* Sound effects
* Organized **Graphics/** folder

---

## 🧩 Tech Stack

| Language | Library | Tools              |
| -------- | ------- | ------------------ |
| Cpp        | Raylib  | GCC / Clang / Make |

---

## 🗺️ Project Structure

```
Space-Invaders/
├── src/
│   ├── main.cpp
│   ├── spaceship.cpp / spaceship.hpp
│   ├── enemy.cpp / enemy.hpp
│   ├── bullet.cpp / bullet.hpp
│   ├── utils.cpp / utils.hpp
├── Graphics/
│   ├── sprites/
│   └── sounds/
├── Makefile
├── README.md
├── LICENSE
├── INSTALLATION.md
└── USAGE.md
```

---

## 📦 Installation

See [INSTALLATION.md](INSTALLATION.md) for setup instructions.

---

## 🎮 Usage

See [USAGE.md](USAGE.md) for game controls.

---

## 👤 Contributors

* Mukesh Lilawat – Lead Developer


---

## 📝 License

MIT License. See [LICENSE](LICENSE).

---

# CONTRIBUTING.md

---

# 🤝 Contributing to Space Invaders

First off, **thank you for considering contributing** to the Space Invaders project! 💖

## 📝 How to Contribute

* Adding features, fixing bugs, improving docs, graphics, or optimizing code.

## 📌 Guidelines

1. **Fork the repository**
2. **Clone your fork**

```bash
git clone https://github.com/<your-username>/space-invaders-raylib.git
cd space-invaders-raylib
```

3. **Create a branch**

```bash
git checkout -b feature/your-feature-name
```

4. **Make changes & commit**

```bash
git add .
git commit -m "Add descriptive commit message"
```

5. **Push branch**

```bash
git push origin feature/your-feature-name
```

6. **Open a PR**

## 🛡️ Code of Conduct

See [CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md).

## ⚠️ Notes

* Pull latest main before PR:

```bash
git pull origin main
```

* Ensure commits linked to GitHub.

---

# CHANGELOG.md

---

# Changelog

All notable changes to this project will be documented in this file.

## [1.0.0] - 2025-09-30

* Initial release with core gameplay
* Player spaceship movement
* Enemy waves & shooting
* Collision detection
* Scoring & game over
* Graphics & sounds included

---

# ISSUE_TEMPLATE.md

---

**Title**: [Bug / Feature]

**Description**:

* Steps to reproduce / Feature request details

**Expected behavior**:

**Screenshots / GIFs (optional)**:

**Environment**:

* OS:
* Compiler / Version:
* Raylib Version:

---

# PULL_REQUEST_TEMPLATE.md

---

**Title**: [Feature / Fix]

**Description**:

* Explain the purpose of this PR
* Include screenshots / demos if applicable

**Related issue**: #[issue-number]

**Checklist**:

* [ ] Code compiles
* [ ] Tested functionality
* [ ] Updated documentation if needed

---

# CODE_OF_CONDUCT.md

---

# Code of Conduct

Be respectful, collaborative, and constructive. Any harassment, discrimination, or abuse will not be tolerated.

---

# SECURITY.md

---

# Security Policy

Report security vulnerabilities responsibly:

* Email: [security@yourdomain.com](mailto:security@yourdomain.com)
* Include steps to reproduce and environment details
* Do not post sensitive info publicly

---

# FAQ.md

---

# Frequently Asked Questions

**Q: How to run the game?**
A: Follow [INSTALLATION.md](INSTALLATION.md) and then [USAGE.md](USAGE.md).

**Q: Which OS are supported?**
A: Windows, Linux, macOS.

**Q: How to contribute?**
A: See [CONTRIBUTING.md](CONTRIBUTING.md).

---

# ROADMAP.md

---

# Roadmap

* Add multiple enemy types and bosses
* Power-ups & upgrades
* Leaderboard & scoring system
* Enhanced graphics & animations
* Background music & more sound effects

---

# DEPLOYMENT.md

---

# Deployment

* Build using Makefile or IDE
* Run executable generated
* Include assets from Graphics folder

---

# TESTING.md

---

# Testing

* Manual testing for controls, collision, score tracking
* Ensure compatibility on Windows, Linux, macOS
* Automated scripts if added in future

---

# INSTALLATION.md

---

# Installation

1. Install Raylib and C compiler (GCC/Clang)
2. Clone repo:

```bash
git clone https://github.com/<your-username>/space-invaders-raylib.git
```

3. Build project using Makefile:

```bash
make
```

4. Run executable

---

# USAGE.md

---

# Usage

**Controls**:

| Key            | Action     |
| -------------- | ---------- |
| ⬅️ Left Arrow  | Move left  |
| ➡️ Right Arrow | Move right |
| SPACE          | Shoot      |
| ESC            | Quit       |

* Enjoy the game!
