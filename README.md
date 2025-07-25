# CHIP-8 Emulator

A simple CHIP-8 emulator written in C, built for learning and experimentation with low-level systems and emulation.  
It supports basic instruction decoding, keypad input, and rendering using SDL2.

---

## ✨ Features

- Interprets standard CHIP-8 instructions
- 64×32 monochrome graphics rendering
- Hex keypad input mapped to physical keyboard
- Cross-platform build support (Linux/WSL/Windows)
- SDL2-based graphics output

---

## 🔧 Requirements

- GCC or Clang
- [SDL2 development libraries](https://github.com/libsdl-org/SDL)

---

## 🛠️ Build Instructions

### ▶️ Linux / WSL

```bash
sudo apt install libsdl2-dev    # if not already installed
mkdir build && cd build
cmake ..
make
./chip8_emulator path/to/rom.ch8
```