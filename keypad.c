#include <unistd.h>
#include <stdlib.h>
#include <curses.h>

#define LOCAL_ESCAPE_KEY 27

int main(int argc, char *argv[])
{
    int key;

    initscr();

    crmode();
    keypad(stdscr, TRUE);

    noecho();
    clear();

    mvprintw(5, 5, "Keypad demonstration. Press 'q' to quit");
    move(7, 5);
    refresh();
    key = getch();

    while (key != ERR && key != 'q') {
        move(7, 5);
        clrtoeol();

        if ((key > 'A' && key <= 'Z') ||
            (key >= 'a' && key <= 'z')) {
            printw("Key was %c", (char)key);
        }
        else {
            switch (key) {
                case LOCAL_ESCAPE_KEY:
                    printw("%s", "Escape key");
                    break;
                case KEY_END:
                    printw("%s", "End key");
                    break;
                case KEY_BEG:
                    printw("%s", "Beginning key");
                    break;
                case KEY_RIGHT:
                    printw("%s", "Right key");
                    break;
                case KEY_LEFT:
                    printw("%s", "Left key");
                    break;
                case KEY_UP:
                    printw("%s", "Up key");
                    break;
                case KEY_DOWN:
                    printw("%s", "Down key");
                    break;
                default:
                    printw("Unmatched - ", key);
            }
        }

        refresh();
        key = getch();
    }

    endwin();

    return 0;
}
