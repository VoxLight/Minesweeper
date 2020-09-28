# Minesweeper


## Installation
You need to install the following two packages:

1. libncurses5-dev : Developer’s libraries for ncurses
1. libncursesw5-dev : Developer’s libraries for ncursesw

`sudo apt-get install libncurses5-dev libncursesw5-dev`

## Building
You need to link the following two libraries in order to build this source
1. ncurses
1. stdc++

`gcc ./app/main.cpp -o Minesweeper -lncurses -lstdc++`
See or run build.sh (set execute permission on the script `chmod +x ./build.sh`)