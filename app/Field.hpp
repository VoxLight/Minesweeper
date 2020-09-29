#ifndef _FIELD
#define _FIELD

#include <ncurses.h>
#include <vector>
#include <string>

using namespace std;

const string BLANK = " ";
const string UNCHECKED = "#";
const string BOMB = "*";
const string FLAG = "f";

class Tile{
    public:
        Tile(vector<vector<Tile>> field, int x_, int y_){
            x = x_;
            y = y_;
            parent = field;
            isRevealed = false;
            isFlagged = false;
            bomb = 0;
        }

        string text(){
            if(isFlagged){
                return FLAG;
            }else if(!isRevealed){
                return UNCHECKED;
            }else if(bomb == 1){
                return BOMB;
            }else{
                return to_string(getNeighborBombs());
            }
        }
    private:
        int getNeighborBombs(){
            int bombs = 0;

            // up
            bombs += parent.at(x).at(y-1).bomb;

            // down
            bombs += parent.at(x).at(y+1).bomb;

            // left
            bombs += parent.at(x-1).at(y).bomb;

            // right
            bombs += parent.at(x+1).at(y-1).bomb;

            // northwest
            bombs += parent.at(x-1).at(y-1).bomb;

            // northeast
            bombs += parent.at(x+1).at(y-1).bomb;

            // southwest
            bombs += parent.at(x-1).at(y+1).bomb;

            // southeast
            bombs += parent.at(x+1).at(y+1).bomb;
            
        }
        vector<vector<Tile>> parent;
        bool isRevealed;
        bool isFlagged;
        int bomb;
        int x;
        int y;
        
};

class Field{
    public:
        Field(int width_, int height_){
            width = width_;
            height = height_;
            setup();

        }

        void draw(){
            // Store the position of the cursor before printing
            int cur_x = getcurx(stdscr), cur_y = getcury(stdscr);

            // Print the Field
            for (int x = 0; x < width; x++){
                for (int y = 0; y < height; y++){
                    mvprintw(y, x, getTile(x, y).text().c_str());
                }
                
            }
            // Move the cursor back to where it originally was before printing
            move(cur_x, cur_y);
            
        }

        Tile getTile(int x, int y){
            return field.at(x).at(y);
        }

    private:
        void setup(){
            int x = 0, y = 0;
            for(;y<height;y++){
                for (;  x < width; x++){
                    field.at(y).push_back(Tile(field));
                }
            }
        }
        int width, height;
        vector<vector<Tile>> field;
};

#endif