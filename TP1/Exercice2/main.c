#include <ncurses.h>

int old_main() {
    initscr();

    attron(A_NORMAL);
    printw("Normal              : ABCabc012\n");

    attron(A_REVERSE);
    printw("Inverse             : ABCabc012\n");
    attroff(A_REVERSE); /*Permet de retirer l'effet reverse pour les prochains
                           printw*/

    attron(A_BOLD);
    printw("Gras                : ABCabc012\n");
    attroff(A_BOLD);

    attron(A_UNDERLINE);
    printw("Souligne            : ABCabc012\n");
    attroff(A_UNDERLINE);

    attron(A_REVERSE | A_UNDERLINE);
    printw("Inverse et souligne : ABCabc012\n");
    attron(A_NORMAL);

    refresh();
    getch();
    endwin();

    return 0;
}

int main(int argc, char const *argv[]) {
    initscr();
    attron(A_BOLD | A_UNDERLINE);
    printw("*10*");
    refresh();
    getch();
    endwin();
    return 0;
}
