#include <ncurses.h>
#include <unistd.h>

#define DELAI 1000000

int main() {
    int x, y;
    initscr();
    x = 0;
    y = 0;
    int var = 1;
    while (var) {

        /*Elle permet d'effacer tous les elements de la fenetre*/
        mvaddch(y, x, 'o');

        usleep(DELAI); /*La fonction usleep permet de faire une pause dans le programme*/
        x = (x + 1) % COLS;
        refresh();
        erase(); 
        y = (y + 1) % LINES;
    }
    endwin();
    return 0;
}