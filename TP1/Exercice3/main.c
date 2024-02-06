#include <ncurses.h>

int main() {
    initscr();

    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLUE);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    
    curs_set(false); /*Cette ligne permet de rendre invisible le curseur sur l'affichage.*/

    attron(COLOR_PAIR(1));
    mvprintw(2, 3, "Abc123 **  *");
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    mvprintw(2, 16, "2121");
    attroff(COLOR_PAIR(2));

    refresh();
    getch();
    endwin();
    return 0;
}