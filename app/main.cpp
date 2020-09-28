#include "Terminal.hpp"
#include <iostream>

/* 
    My naming conventions are as follows:
        class: TitleCase
        function/method: upperCamelCase
        variables/properties/parameters: lower_underscore_space
*/

// ASCII keycodes: https://en.cppreference.com/w/cpp/language/ascii
const int q = 113; // The letter q
const int w = 119; // The letter w
const int s = 115;
const int a = 97;
const int d = 100;

int clamp(int val, int max, int min=0){
    if(val > max-1){
        return max-1;
    }else if(val < min){
        return min;
    }else{
        return val;
    }
}



int main(){
    // nCurses wrapper
    Terminal terminal;

    const int SCREEN_WIDTH = 80;
    const int SCREEN_HEIGHT = 24;

    const char selection = '.';


    // Cordinates
    int x = SCREEN_WIDTH/2;
    int y = SCREEN_HEIGHT/2;

    // The game loop
    while (!terminal.isDone()){
        int input = terminal.getKey();

        // Selection Handling
        switch(input){

            // UP
            case KEY_UP:
                y = clamp(y-1, SCREEN_HEIGHT);
            break;
            case w:
                y = clamp(y-1, SCREEN_HEIGHT);
            break;

            // DOWN
            case KEY_DOWN:
                y = clamp(y+1, SCREEN_HEIGHT);
            break; 
            case s:
                y = clamp(y+1, SCREEN_HEIGHT);
            break;

            // LEFT
            case KEY_LEFT:
                x = clamp(x-1, SCREEN_WIDTH);
            break;
            case a:
                x = clamp(x-1, SCREEN_WIDTH);
            break;

            //RIGHT
            case KEY_RIGHT:
                x = clamp(x+1, SCREEN_WIDTH);
            break;
            case d:
                x = clamp(x+1, SCREEN_WIDTH);
            break;

            //EXIT
            case KEY_EXIT:
                terminal.quit();
            break;
            case q:
                terminal.quit();
            break;
        }

        // Drawing
        move(y, x);
    }
    


    return 0;
}