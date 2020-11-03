#ifndef _FIELD
#define _FIELD

#include <ncurses.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <math.h>

using namespace std;

const string BLANK = " ";
const string UNCHECKED = "#";
const string BOMB = "*";
const string FLAG = "f";


const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 24;


int clamp(int val, int max, int min=0){
    if(val > max-1){
        return max-1;
    }else if(val < min){
        return min;
    }else{
        return val;
    }
}

int randomInt(int max){
    return (int)round(rand()%(max+1));
}

class Field{
    public:
        Field(int width_, int height_, int num_bombs_){
            width = width_;
            height = height_;
            num_bombs = num_bombs_;
            setup();
            setupBombs();

        }

        int getWidth(){
            return width;
        }

        int getHeight(){
            return height;
        }

        void draw(){
            // Store the position of the cursor before printing
            int cur_x = getcurx(stdscr), cur_y = getcury(stdscr);

            // Print the Field
            for (int x = 0; x < width; x++){
                for (int y = 0; y < height; y++){
                    mvprintw(y, x, getTile(x, y).c_str());
                }
                
            }
            // Move the cursor back to where it originally was before printing
            move(cur_y, cur_x);
            
        }


        void select(int x, int y){
            if(isFlag(x, y) || num_grid[y][x] == 0 ){return;}
            else if(bomb_grid[y][x] == 1){dead = true; return;}
            else{num_grid[y][x] = getBombs(x, y);}
                        
        }

        void flag(int x, int y){
            flag_grid[y][x] += 1;
        }



        bool isDead(){
            return dead;
        }




    private:
        void setup(){
            for (int y = 0; y < height; y++){
                for (int x = 0; x < width; x++){
                    num_grid[y][x] = 1;
                }
                
            }
            
        }
        
        
        void setupBombs(){
            srand(time(NULL)); // init random seed
            while(num_bombs > 0){
                int x = randomInt(width);
                int y = randomInt(height);

                if(bomb_grid[y][x] == 1){continue;}
                bomb_grid[y][x] = 1;
                num_bombs -= 1;
                cout << num_bombs;
            }
        }


        bool isFlag(int x, int y){
            if(flag_grid[y][x] > 0){
                return flag_grid[y][x]%2 != 0;
            }
            return false;
        }

        


        int getBombs(int x, int y){
            int bombs = 0;

            // north
            if(bomb_grid[y-1][x]==1){bombs+=1;}

            // south
            if(bomb_grid[y+1][x]==1){bombs+=1;}

            // east
            if(bomb_grid[y][x+1]==1){bombs+=1;}

            // west
            if(bomb_grid[y][x-1]==1){bombs+=1;}

            // northeast
            if(bomb_grid[y-1][x+1]==1){bombs+=1;}

            // northwest
            if(bomb_grid[y-1][x-1]==1){bombs+=1;}

            // southeast
            if(bomb_grid[y+1][x+1]==1){bombs+=1;}

            // north
            if(bomb_grid[y+1][x-1]==1){bombs+=1;}

            return bombs;

        }


        string getTile(int x, int y){
            if (isFlag(x, y)){return FLAG;}
            else if(num_grid[y][x]==1){return UNCHECKED;}
            else if(num_grid[y][x]==0){return BLANK;}
            else if(bomb_grid[y][x] == 1){return BOMB;}
            else{
                return to_string(num_grid[y][x]);
            }
        }


        int width, height;
        int bomb_grid[SCREEN_HEIGHT][SCREEN_WIDTH];
        int num_grid[SCREEN_HEIGHT][SCREEN_WIDTH];
        int flag_grid[SCREEN_HEIGHT][SCREEN_WIDTH];
        int num_bombs;
        bool dead = false;

};

#endif