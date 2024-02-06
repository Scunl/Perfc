#include <ncurses.h>
#include <stdio.h>

void creation_rectangle() {
    // Initialisation de ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Initialisation des couleurs
    start_color();
    init_pair(1, COLOR_RED, COLOR_RED);
    attron(COLOR_PAIR(1));

    for (int i = -3; i < 3; i++) {
        for (int j = -7; j < 7; j++) {
            mvprintw(LINES / 2 + i, COLS / 2 + j, " ");
        }
    }

    refresh();
    getch();
    endwin();
}

int main() {
    creation_rectangle();
    return 0;
}
