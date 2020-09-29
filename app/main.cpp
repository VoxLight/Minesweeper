#include "common.cpp"
#include "Terminal.hpp"
#include <iostream>
#include <string>


using namespace std;


/* 
    My naming conventions are as follows:
        class: TitleCase
        function/method: upperCamelCase
        variables/properties/parameters: lower_underscore_space
*/

// ASCII keycodes: https://en.cppreference.com/w/cpp/language/ascii
const int q_ = 113; // The letter q
const int w_ = 119; // The letter w
const int s_ = 115;
const int a_ = 97;
const int d_ = 100;
const int f_ = 102;




int main(){
    // nCurses wrapper
    Terminal terminal;

    const int SCREEN_WIDTH = 80;
    const int SCREEN_HEIGHT = 24;


    string selection = "@";


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
            case w_:
                y = clamp(y-1, SCREEN_HEIGHT);
            break;

            // DOWN
            case KEY_DOWN:
                y = clamp(y+1, SCREEN_HEIGHT);
            break; 
            case s_:
                y = clamp(y+1, SCREEN_HEIGHT);
            break;

            // LEFT
            case KEY_LEFT:
                x = clamp(x-1, SCREEN_WIDTH);
            break;
            case a_:
                x = clamp(x-1, SCREEN_WIDTH);
            break;

            //RIGHT
            case KEY_RIGHT:
                x = clamp(x+1, SCREEN_WIDTH);
            break;
            case d_:
                x = clamp(x+1, SCREEN_WIDTH);
            break;

            //SELECT
            case KEY_ENTER:
                //select
            break;
            case f_:
                //select
            break;

            //EXIT
            case KEY_EXIT:
                terminal.quit();
            break;
            case q_:
                terminal.quit();
            break;


        }

        // Drawing
        move(y, x);
    }
    


    return 0;
}