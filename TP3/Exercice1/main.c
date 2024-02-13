#include <ncurses.h>
#include <signal.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

struct timeval temps_debut, temps_fin;

int intervalle_ms(struct timeval debut, struct timeval fin) {
    int sec = fin.tv_sec - debut.tv_sec;
    int usec = fin.tv_usec - debut.tv_usec;
    return sec * 1000 + usec / 1000;
}
int nb_ms_vers_centiemes(int nb_ms) {
    return (nb_ms / 10) % 100;
}

int nb_ms_vers_secondes(int nb_ms) {
    return (nb_ms / 1000) % 60;
}

int nb_ms_vers_minutes(int nb_ms) {
    return (nb_ms / (1000 * 60)) % 60;
}

int nb_ms_vers_heures(int nb_ms) {
    return nb_ms / (1000 * 60 * 60);
}

void afficher_temps(int temps_total_ms) {
    int heures = nb_ms_vers_heures(temps_total_ms);
    int minutes = nb_ms_vers_minutes(temps_total_ms);
    int secondes = nb_ms_vers_secondes(temps_total_ms);
    int centiemes = nb_ms_vers_centiemes(temps_total_ms);
    mvprintw(0, 0, "%02d:%02d:%02d.%02d\n", heures, minutes, secondes,
             centiemes);
}

int main(void) {
    int temps_total = 0;
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    while (1) {
        int var = 1;
        int touche = getch();
        afficher_temps(temps_total);
        if (touche == ' ') {
            while (var) {
                touche = getch();
                if (touche == ' ') {
                    var = 0;
                    break;
                }
            }
        }
        usleep(500 * 1000);
        temps_total += 500;
    }
    return 0;
}
