#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>

int main(int argc, char *argv[])
{
    initscr();

    int l = 0;
    while (true) {
        int k = 0;

        clear();
        int i = k + l;
        while (k != LINES) {

            move(k, 0);

            attron(A_DIM);
            for (int j = 0; j < i; ++j) {
                printw("%s", "O");
            }
            attroff(A_DIM);

            attron(A_BOLD);
            printw("%s", "O");
            attroff(A_BOLD);

            attron(A_DIM);
            for (int j = i + 1; j < COLS; ++j) {
                printw("%s", "O");
            }
            attroff(A_DIM);

            
            i += 1;
            if (i == COLS) {
                i = 0;
            }

            k += 1;
        }

        refresh();
        sleep(1);
        l += 1;

        if (l == COLS - 1) {
            l = 0;
        }
    }

    endwin();

    return 0;
}
