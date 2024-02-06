#include <ncurses.h>
#include <stdio.h>

int main(void) {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Initialisation des couleurs
    start_color();
    init_pair(1, COLOR_RED, COLOR_RED);
    attron(COLOR_PAIR(1));

    for (int i = -3; i <= 3; i++) {
        for (int j = -3 * 2; j <= 3 * 2; j++) {
            mvprintw(LINES / 2 + i, COLS / 2 + j, " ");
        }
    }
    while (1) {
        int touche = getch();

        if (touche == 'a') {
            init_pair(1, COLOR_RED, COLOR_BLUE);
            attron(COLOR_PAIR(1));
            for (int i = -3; i <= 3; i++) {
                for (int j = -3 * 2; j <= 3 * 2; j++) {
                    mvprintw(LINES / 2 + i, COLS / 2 + j, " ");
                }
            }
            refresh();
            getch();
            endwin();
        }
    }

    return 0;
}
