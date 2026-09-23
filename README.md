# Costruire-videogiochi-da-zero

This repo is a C translation of Daniele Ceravolo's game online course at: doorstotheunknown.substack.com/

<br><br>

Lessons list:

  https://doorstotheunknown.substack.com/p/costruire-videogiochi-da-zero-0

  https://doorstotheunknown.substack.com/p/costruire-videogiochi-da-zero-1

  https://doorstotheunknown.substack.com/p/costruire-videogiochi-da-zero-2

  https://doorstotheunknown.substack.com/p/costruire-videogiochi-da-zero-3

<br><br>

Lessons repository:

  https://github.com/mechanapoleon/DoorsToTheUnknown
<br><br>


## Getting Started

### Dependencies

* Before compiling raylib, need to install gcc, make and graphic libraries (X11, OpenGL and ALSA):

  sudo apt install build-essential git libasound2-dev libx11-dev libxrandr-dev libxi-dev libxinerama-dev libxcursor-dev libxkbcommon-dev

* Clone and compile raylib:

  git clone https://github.com/raysan5/raylib

  cd raylib/src

* Compile static library:

  make PLATFORM=PLATFORM_DESKTOP

* Install as system library:

  sudo make install

<br>

## Run files

  * To compile:

    gcc -Wall -O2 gameN.c -o gameN -lraylib -lGL -lm -lpthread -ldl -lrt -lX11


  * To execute:

    ./gameN

<br>

## License

  This project is licensed under the MIT License - see the LICENSE.md file for details
