// Project-specific wrapper for ncurses
// Modified by: me (to better suit my needs)
// Originally written by: Rachel Singh
#ifndef _TERMINAL
#define _TERMINAL

#include <ncurses.h>

class Terminal{
    public:
        Terminal(){
            setup();
        };

        ~Terminal(){
            tearDown();
        };

        void setup(){ // ncurses init
            initscr();
            raw();
            keypad(stdscr, TRUE);
            noecho();

            m_done = false;
        }

        void quit(){ // stop the program
            m_done = true;
        }

        void tearDown(){ // unalloc ncurses
            endwin();
        }

        void endDraw(){ // update the screen
            refresh();
        }

        // getters
        int getKey(){ // return the ascii int value assigned to a keypress
            return getch();
        }

        bool isDone(){ // figure out if the program is done running
            return m_done;
        }

    private:
        bool m_done;
};


#endif