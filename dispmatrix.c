#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>

int main(int argc, char *argv[])
{
    initscr();

    srand(234);

    while (true) {
        clear();
        int i = 0;
        while (i != LINES) {
            move(i,0);

            int k = 0;
            while (k != COLS) {
                switch (rand() % 6) {
                    case 0:
                        attron(A_BOLD);
                        printw("%s", "1");
                        attroff(A_BOLD);
                        break;
                    case 1:
                        attron(A_BOLD);
                        printw("%s", "0");
                        attroff(A_BOLD);
                        break;
                    case 2:
                        attron(A_DIM);
                        printw("%s", "1");
                        attroff(A_DIM);
                        break;
                    case 3:
                        attron(A_DIM);
                        printw("%s", "0");
                        attroff(A_DIM);
                        break;
                    case 4:
                        printw("%s", "1");
                        break;
                    case 5:
                        printw("%s", "0");
                        break;
                }
                k++;
            }
            i++;
        }
        sleep(1);
        refresh();
    }

    endwin();

    return 0;
}
