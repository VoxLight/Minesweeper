#include "Field.hpp"
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
const int a_ = 97;  // ascii decimal value for 'a'
const int d_ = 100; // ascii decimal value for 'd'
const int e_ = 101; // decimal value for 'e'
const int f_ = 102; // etc
const int q_ = 113;
const int w_ = 119; 
const int s_ = 115;



int main(){

    const int FIELD_WIDTH = 8;
    const int FIELD_HEIGHT = 8;
    const int BOMB_COUNT = 12;

    // nCurses wrapper
    Terminal terminal;

    // Minefield
    Field field = Field(FIELD_WIDTH, FIELD_HEIGHT, BOMB_COUNT);


    // Cordinates
    int x = 0;
    int y = 0;

    

    // Initial render of the board
    field.draw();
    terminal.endDraw();

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
                if(x > field.getWidth() || y > field.getHeight()){continue;}
                field.select(x, y);
            break;
            case e_:   
                if(x > field.getWidth() || y > field.getHeight()){continue;}    
                field.select(x, y);
            break;


            //FLAG
            case f_:
                if(x > field.getWidth() || y > field.getHeight()){continue;}
                field.flag(x, y);
            break;

            //EXIT
            case KEY_EXIT:
                terminal.quit();
            break;
            case q_:
                terminal.quit();
            break;

        }

            if(field.isDead()){
                break;
            }

        // Drawing
        move(y, x);

        field.draw();
        terminal.endDraw();

        
    }
    


    return 0;
}