#include <stdio.h>

// Structure pour représenter un chronomètre
typedef struct {
    int etat;                // 1 si en activité, 0 sinon
    int duree_totale;        // Durée totale écoulée en millisecondes
    int duree_avertissement; // Durée en millisecondes provoquant un
                             // avertissement
    int nombre_tours;        // Nombre de tours stockés
    int tours[100];   // Tableau statique de taille raisonnable contenant les
                      // temps en millisecondes de chacun des tours enregistrés
    int dernier_tour; // Numéro du dernier tour enregistré
} Chronometre;

Chronometre initialiser_chronometre() {
    Chronometre chrono;
    chrono.etat = 0; 
    chrono.duree_totale = 0;
    chrono.duree_avertissement = 0;
    chrono.nombre_tours = 0;
    chrono.dernier_tour = 0;
    return chrono;
}

// Fonction pour afficher une durée en millisecondes
void afficher_duree(int y, int x, int nb_ms) {
    printf("(%d,%d): %d milliseconds\n", y, x, nb_ms);
}

// Fonction pour afficher l'interface du chronomètre
void afficher_interface(Chronometre chrono) {
    printf("Etat du chronomètre :\n");
    printf("Etat : %d\n", chrono.etat);
    printf("Durée totale : %d ms\n", chrono.duree_totale);
    printf("Durée d'avertissement : %d ms\n", chrono.duree_avertissement);
    printf("Nombre de tours stockés : %d\n", chrono.nombre_tours);
    printf("Dernier tour enregistré : %d\n", chrono.dernier_tour);
    printf("Tours enregistrés :\n");
    for (int i = 0; i < chrono.nombre_tours; i++) {
        printf("Tour %d : %d ms\n", i + 1, chrono.tours[i]);
    }
}

// Fonction pour afficher un flash d'avertissement
void afficher_flash() {
    printf("Flash d'avertissement\n");
    // À adapter pour une affichage graphique sur une fenêtre
}

// Fonction pour ajouter un tour au chronomètre
void ajouter_tour(Chronometre *chrono) {
    chrono->dernier_tour++;
    chrono->nombre_tours++;
    if (chrono->nombre_tours > 100) {
        chrono->nombre_tours = 100;
    }
    // Décalage du tableau des tours
    for (int i = chrono->nombre_tours - 1; i > 0; i--) {
        chrono->tours[i] = chrono->tours[i - 1];
    }
    // Enregistrement du temps du dernier tour
    chrono->tours[0] = chrono->duree_totale;
}

int main() {
    // Exemple d'utilisation des fonctions définies
    Chronometre chrono = initialiser_chronometre();
    afficher_interface(chrono);
    // Ajout d'un tour
    ajouter_tour(&chrono);
    // Affichage de l'interface après ajout du tour
    afficher_interface(chrono);
    return 0;
}
