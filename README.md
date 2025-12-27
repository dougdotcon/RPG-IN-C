# 🤖 CyberRpgSystem - Neural Combat Engine

[![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Terminal](https://img.shields.io/badge/Terminal-4D4D4D?style=for-the-badge&logo=windows-terminal&logoColor=white)](https://github.com/microsoft/terminal)
[![License](https://img.shields.io/badge/License-MIT-cyan?style=for-the-badge)](LICENSE)
[![Status](https://img.shields.io/badge/Status-ONLINE-brightgreen?style=for-the-badge)](README.md)

**A high-performance RPG system written in C featuring a futuristic neural interface and deep mechanical combat.**

*Immerse yourself in a world where low-level programming meets high-fantasy cyberpunk gameplay.*

---

## 🌟 **System Overview**

CyberRpgSystem is a **cyberpunk RPG engine** developed in pure C, offering an immersive terminal-based experience. It combines efficient low-level programming with a visually stunning ANSI-interface designed for cyberpunk enthusiasts.

### 🎯 **Key Features**
- 🧠 **Neural Interface**: Futuristic cyberpunk visuals using ANSI escape codes
- ⚔️ **Combat Mechanics**: Classic RPG turn-based combat system
- 🎭 **13 Unique Classes**: Distinct playstyles and special attributes
- 🌍 **5 Explorable Areas**: Diverse environments with unique enemy rosters
- 💾 **Save System**: Full data persistence (load/save game states)
- 📊 **XP Progression**: Balanced leveling and stat growth system

---

## 🚀 **Quick Start**

### 📋 **Prerequisites**
bash
# GCC Compiler
sudo apt install gcc        # Ubuntu/Debian
brew install gcc            # macOS
# Windows: MinGW or WSL


### ⚡ **Installation**
bash
# Clone the repository
git clone https://github.com/elyz0/cyber-rpg.git
cd cyber-rpg

# Compile using Makefile (Recommended)
make cyberpunk

# Execute
./cyberpunk


### 🎮 **Manual Compilation**
If you don't have `make` installed:
bash
gcc -o cyberpunk main.c game.c player.c combat.c utils.c -Wall


---

## 📂 **Project Structure**


cyber-rpg/
├── main.c           # Entry point and main loop
├── game.c           # Game logic and state management
├── player.c         # Player stats and class definitions
├── combat.c         # Combat engine and AI
├── utils.c          # ANSI graphics and helpers
├── save.dat         # (Generated) Save file
└── Makefile         # Build automation


---

## 🛠 **Technical Details**

- **Language**: C (Standard C99)
- **Architecture**: Modular procedural programming
- **Graphics**: Terminal-based ANSI escape codes
- **Storage**: Binary file I/O for save states

---

## 🤝 **Contributing**

Contributions are welcome! Please ensure your code follows the existing style.

1. Fork the project
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

---

## 📜 **License**

Distributed under the MIT License. See `LICENSE` for more information.
