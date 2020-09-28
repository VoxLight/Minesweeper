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

        void setup(){
            initscr();
            raw();
            keypad(stdscr, TRUE);
            noecho();

            m_done = false;
        }

        void quit(){
            m_done = true;
        }

        void tearDown(){
            endwin();
        }

        void updateScreen(){
            refresh();
        }

        // getters
        int getKey(){
            return getch();
        }

        bool isDone(){
            return m_done;
        }

    private:
        bool m_done;
};


#endif