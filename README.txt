# Conway’s Game of Life

A C++ terminal-based implementation of Conway’s Game of Life, using CMake for build automation.

---

## Overview

This is a terminal-based implementation of Conway's Game of Life written in C++, built using CMake. It was developed as part of an assignment for Stanford’s CS106X: Programming Abstractions in C++. The program simulates the evolution of cells on a 2D grid according to Conway’s classic rules.

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