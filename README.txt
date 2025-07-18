# Conway’s Game of Life

A C++ terminal-based implementation of Conway’s Game of Life, using CMake for build automation.

---

## Overview

This is a terminal-based implementation of Conway's Game of Life written in C++, built using CMake. It displays the evolution of cellular automata on a 2D grid, following the classic rules defined by John Conway.

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