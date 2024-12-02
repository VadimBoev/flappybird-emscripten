# Flappy Bird: Веб-версия 🐦🕹️

## Обзор 🌟
 
Этот проект представляет собой портированную версию классической игры [Flappy Bird](https://github.com/VadimBoev/FlappyBird), первоначально разработанной на C, для беспрепятственного запуска в вашем веб-браузере с использованием [Emscripten](https://emscripten.org/).  
Испытайте ностальгию по этой знаковой игре прямо в своем браузере, со всеми оригинальными механиками и очарованием.

## Особенности 🚀

- **Классическая Игра**: Переживите аддиктивный вызов навигации Flappy Bird через бесконечные трубы.
- **Веб-базированная**: Играйте прямо в браузере без каких-либо загрузок или установки.
- **Кроссплатформенность**: Совместима со всеми современными веб-браузерами на настольных и мобильных устройствах.
- **Производительность**: Оптимизирована для плавной работы с использованием бэкенда WebAssembly от Emscripten.
- **Открытый исходный код**: Полностью открытый исходный код, позволяющий сообществу вносить свой вклад и настраивать игру.

## Как играть 🎮

1. **Откройте игру**: Просто перейдите на [веб-версию](https://vadimboev.ru/games/flappybird).
2. **Начните махать крыльями**: Нажмите или коснитесь экрана, чтобы заставить Flappy Bird махать крыльями и подниматься.
3. **Избегайте препятствий**: Проводите Flappy Bird через промежутки между трубами, не сталкиваясь с ними.
4. **Набирайте очки**: Каждый успешный проход через пару труб приносит вам очко.
5. **Ставьте рекорды**: Попробуйте побить свой рекорд и поделиться им с друзьями!

## Сборка Проекта 🛠️

## Структура
```
┌── audio
│ ├── die.mp3
│ ├── hit.mp3
│ ├── point.mp3
│ └── wing.mp3
├── buttons
│ ├── menu.png
│ ├── ok.png
│ ├── pause.png
│ ├── resume.png
│ ├── score.png
│ ├── share.png
│ └── start.png
├── sprites
│ ├── 0.png
│ ├── 1.png
│ ├── 2.png
│ ├── 3.png
│ ├── 4.png
│ ├── 5.png
│ ├── 6.png
│ ├── 7.png
│ ├── 8.png
│ ├── 9.png
│ ├── 0_small.png
│ ├── 1_small.png
│ ├── 2_small.png
│ ├── 3_small.png
│ ├── 4_small.png
│ ├── 5_small.png
│ ├── 6_small.png
│ ├── 7_small.png
│ ├── 8_small.png
│ ├── 9_small.png
│ ├── background-day.png
│ ├── base.png
│ ├── bronze-medal.png
│ ├── gameover.png
│ ├── gold-medal.png
│ ├── logo.png
│ ├── message.png
│ ├── new.png
│ ├── panel.png
│ ├── pipe-green.png
│ ├── platinum-medal.png
│ ├── silver-medal.png
│ ├── sparkle-sheet.png
│ ├── yellowbird-downflap.png
│ ├── yellowbird-midflap.png
│ └── yellowbird-upflap.png
├── favicon.ico
├── flappybird-emscripten.data
├── flappybird-emscripten.js
├── flappybird-emscripten.wasm
└── index.html
```
### Предварительные Требования

- [Emscripten](https://emscripten.org/docs/getting_started/downloads.html) установлен и настроен.
- Современный веб-браузер (Chrome, Firefox, Safari и т.д.).

### Клонирование Репозитория
```
git clone https://github.com/VadimBoev/flappybird-emscripten.git
cd flappybird-emscripten
```

## Сборка
- Отредактируйте CMakeLists.txt, в основном это касается путей, например `G:\emsdk`  

Я собирал проект в Visual Studio 2022  
А так, вы можете собрать проект:
```
mkdir build && cd build && cmake ..
```

## Запуск Игры
Откройте файл `index.html` в вашем веб-браузере

## Вклад в Проект 🤝
Мы приветствуем вклад сообщества! Будь то исправление ошибок, улучшение производительности или добавление новых функций, ваша помощь ценится.

Счастливого хлопанья крыльями! 🐦🎉
