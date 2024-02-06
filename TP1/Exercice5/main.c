#include <ncurses.h>

void old_main() {
    char chaine[128];
    int entier;

    initscr();

    getstr(chaine); /*La fonction getstr permet d'attendre l'entrée utilisateur
                     qu'il prendra comme une chaine de caractere et sa variable
                     en parametre*/
    mvprintw(3, 0, "Chaine lue : %s", chaine);

    mvscanw(10, 0, "%d",
            &entier); /*La fonction mvscanw permet d'attendre l'entrée
                       utilisateur d'un int et sa variable en parametre ainsi
                       que les coordonnées de déplacement du curseur.*/

    mvprintw(11, 0, "Entier lu : %d", entier);

    refresh();
    getch();
    endwin();
}

void q2_main(void) {
    char chaine[128];
    initscr();

    mvgetstr(2, 4, chaine);

    mvprintw(0, 0, "La chaine lu est: %s\n", chaine);
    refresh();
    getch();
    endwin();
}

int main(void) {
    int valeur;
    int i = 0;
    initscr();
    do {
        mvscanw(i, i, "%d", &valeur);
        mvprintw(i, i, "La chaine lu est: %d\n", valeur);
        i++;
        refresh();

    } while (valeur != 0);
    getch();
    endwin();
}
