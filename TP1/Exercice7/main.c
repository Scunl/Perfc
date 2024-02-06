#include <ncurses.h>
#include <unistd.h>

int main() {
    int touche, val, delai;

    initscr();
    noecho();
    nodelay(stdscr, true); /*Cttte fonction permet de debloquer le programme
                              lors d'un appel getch par exemple*/
    keypad(stdscr, TRUE);

    val = 0;
    delai = 1000000;

    attron(A_BOLD);
    printw("Valeur : ");
    attroff(A_BOLD);
    mvprintw(0, 8, "%3d", val);

    refresh();

    while (1) {
        touche = getch();
        if (touche != ERR) {
            if (touche == 'q')
                break;
            if (touche == 'r')
                val = 0;
            if (touche == KEY_UP)
                delai /= 2;
            if (touche == KEY_DOWN)
                delai *= 2;
            if (touche == 'q')
                break;
        }
        mvprintw(0, 8, "%3d", val);

        val = (val + 1) % 128;
        usleep(delai);
    }

    endwin();
    return 0;
}