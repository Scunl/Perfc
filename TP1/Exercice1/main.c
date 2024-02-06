#include <ncurses.h>

void old_main() {
    initscr();

    printw("1"); /*Permet d'afficher une chaine de caractere.*/

    move(2, 20); /*Permet de déplacer le curseur en coordonnées x, y passé en
                    parametre*/
    addch('2');
    addch('3');

    move(LINES, COLS);
    addch('8'); /*Permet d'afficher un caractere*/
    mvaddch(4, 2, '5');
    mvprintw(3, 3, "ABCD"); /*Permet de print sur la table d'affichage et de
                               déplacer le curseur avant*/
    printw("**");

    refresh();
    getch();
    endwin();
}

int main() {

    initscr();
    /*mvprintw(8, 4, "4!+2"); Premiere methode
    ==========================================*/
    /*move(8, 2);
    printw("4!+2"); Deuxieme methode
    ==========================================*/
    /*move(8,2);
    addch('4');
    addch('!');
    addch('+');
    addch('2');*/
    mvaddch(8, 2, '4');
    mvaddch(8, 3, '!');
    mvaddch(8, 4, '+');
    mvaddch(8, 5, '2');
    refresh();
    getch();
    endwin();
    return 0;
}