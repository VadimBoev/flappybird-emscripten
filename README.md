# Flappy Bird: Web Edition 🐦🕹️
  
## Overview 🌟

Welcome to the **Flappy Bird: Web Edition** repository!  
This project is a port of the classic Flappy Bird game, originally developed in C, to run seamlessly in your web browser using [Emscripten](https://emscripten.org/).  
Experience the nostalgia of this iconic game right from your browser, with all the original mechanics and charm intact.

## Features 🚀

- **Classic Gameplay**: Relive the addictive challenge of navigating Flappy Bird through endless pipes.
- **Web-Based**: Play directly in your browser without any downloads or installations.
- **Cross-Platform**: Compatible with all modern web browsers on desktop and mobile devices.
- **Performance**: Optimized for smooth performance using Emscripten's WebAssembly backend.
- **Open Source**: Fully open-source, allowing for community contributions and customization.

## How to Play 🎮

1. **Open the Game**: Simply navigate to the [live demo](https://vadimboev.ru/games/flappybird) (link to be added once deployed).
2. **Start Flapping**: Click or tap the screen to make Flappy Bird flap its wings and ascend.
3. **Avoid Obstacles**: Guide Flappy Bird through the gaps between the pipes without colliding.
4. **Score Points**: Each successful pass through a pair of pipes earns you a point.
5. **Challenge Yourself**: Try to beat your high score and share it with friends!

## Build the Project 🛠️

## Structure
```
┌── audio
│   ├── die.mp3
│   ├── hit.mp3
│   ├── point.mp3
│   └── wing.mp3
├── buttons
│   ├── menu.png
│   ├── ok.png
│   ├── pause.png
│   ├── resume.png
│   ├── score.png
│   ├── share.png
│   └── start.png
├── sprites
│   ├── 0.png
│   ├── 1.png
│   ├── 2.png
│   ├── 3.png
│   ├── 4.png
│   ├── 5.png
│   ├── 6.png
│   ├── 7.png
│   ├── 8.png
│   ├── 9.png
│   ├── 0_small.png
│   ├── 1_small.png
│   ├── 2_small.png
│   ├── 3_small.png
│   ├── 4_small.png
│   ├── 5_small.png
│   ├── 6_small.png
│   ├── 7_small.png
│   ├── 8_small.png
│   ├── 9_small.png
│   ├── background-day.png
│   ├── base.png
│   ├── bronze-medal.png
│   ├── gameover.png
│   ├── gold-medal.png
│   ├── logo.png
│   ├── message.png
│   ├── new.png
│   ├── panel.png
│   ├── pipe-green.png
│   ├── platinum-medal.png
│   ├── silver-medal.png
│   ├── sparkle-sheet.png
│   ├── yellowbird-downflap.png
│   ├── yellowbird-midflap.png
│   └── yellowbird-upflap.png
├── favicon.ico
├── flappybird-emscripten.data
├── flappybird-emscripten.js
├── flappybird-emscripten.wasm
└── index.html
```

### Prerequisites

- [Emscripten](https://emscripten.org/docs/getting_started/downloads.html) installed and configured.
- A modern web browser (Chrome, Firefox, Safari, etc.).

### Clone the Repository

```
git clone https://github.com/VadimBoev/flappybird-emscripten.git
cd flappybird-emscripten
```
  
## Build
- Edit CMakeLists.txt, it's mostly about paths, for example `G:\emsdk`  

I was building a project in Visual Studio 2022  
And so, you can build a project:
```
mkdir build && cd build && cmake ..
```

## Run the Game
Open the index.html file in your web browser
  
## Contributing 🤝
We welcome contributions from the community! Whether you're fixing bugs, improving performance, or adding new features, your help is appreciated.
  
Happy Flapping! 🐦🎉
