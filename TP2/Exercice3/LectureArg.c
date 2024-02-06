#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Il y'a : %d arguments passés en paramètre\n", argc - 1);
    printf("Les arguments du programme sont : \n");
    for (int i = 0; i < argc - 1; i++) {
        printf("%s\n", argv[i + 1]);
    }
}
