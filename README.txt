# Conway’s Game of Life

A C++ terminal-based implementation of Conway’s Game of Life, using CMake for build automation.

---

## Overview

This project simulates Conway's Game of Life on a grid in the terminal. It's designed to be lightweight, easy to build across platforms, and ideal for learning C++ and CMake.

---

## Highlights

- Clean implementation in a single C++ file
- Cross-platform build via CMake
- Customizable grid size via command-line arguments

---

## Installation

```bash
git clone https://github.com/tickymaster/Conoways-game-of-life.git
cd Conoways-game-of-life
mkdir build && cd build
cmake ..
cmake --build .
./gameoflife