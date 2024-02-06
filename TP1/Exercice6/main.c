#include <ncurses.h>

int main() {
    int touche;
    int x, y;
    int x_prec, y_prec;

    initscr();
    curs_set(false);
    noecho(); /*Elle permet de ne plus afficher les entrées utilisateurs sur le
                 terminale*/

    x = COLS / 2;
    y = LINES / 2;
    int pas = 0;
    mvaddch(y, x, 'o');
    mvprintw(LINES - 1, COLS - 10, "Pas : %d", pas);

    while (1) {
        x_prec = x;
        y_prec = y;

        touche = getch();
        if (touche == 'a')
            break;
        if (touche == 'q' && x > pas)
            x -= 1 + pas;
        if (touche == 'd' && x < COLS - 1)
            x += 1 + pas;
        if (touche == 'z' && y > 0 && pas + 1 > 0)
            y -= 1 + pas;
        if (touche == 's' && y < LINES - 1 && pas + 1 < LINES - 1)
            y += 1 + pas;
        if (touche == 'i') {
            x = COLS / 2;
            y = LINES / 2;
        }
        if (touche == 'p' && pas + 1 <= COLS) {
            pas++;
            mvprintw(LINES - 1, COLS - 10, "Pas : %d", pas);
        }
        if (touche == 'm' && pas - 1 >= 0) {
            pas--;
            mvprintw(LINES - 1, COLS - 10, "Pas : %d", pas);
        }

        mvaddch(y_prec, x_prec, ' ');
        mvaddch(y, x, 'o');
        refresh();
    }

    getch();
    endwin();
    return 0;
}