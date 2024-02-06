#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
void dessiner_chat(int y, int x) {
    mvprintw(y, x, " ***** ");
    mvprintw(y + 1, x, "* * *");
    mvprintw(y + 2, x, " ***** ");
}
void effacer_chat(int y, int x) {
    mvprintw(y, x, " ");
    mvprintw(y + 1, x, " ");
    mvprintw(y + 2, x, " ");
}
int main() {
    int touche;
    int chat_x, chat_y;
    int souris_x, souris_y;
    MEVENT ev;
    srand(time(NULL));
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    chat_x = rand() % (COLS - 4);
    chat_y = rand() % (LINES - 2);
    while (1) {
        touche = getch();
        if (touche == 'q')
            break;
        if (touche == KEY_MOUSE && getmouse(&ev) == OK) {
            souris_x = ev.x;
            souris_y = ev.y;
            if ((chat_x <= souris_x) && (souris_x <= chat_x + 4) &&
                (chat_y <= souris_y) && (souris_y <= chat_y + 2)) {
                effacer_chat(chat_y, chat_x);
                chat_x = rand() % (COLS - 4);
                chat_y = rand() % (LINES - 2);
            }
        }
    }
    dessiner_chat(chat_y, chat_x);
    refresh();
}