#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    if (argc == 3) {
        int n = atoi(argv[1]);

        int max = n * (2 * n + 1);
        int temp = 0;
        int i, j;
        for (i = n; i >= 0; i--) {
            temp += 2 * i + 1;
            int espaces =
                (max - temp) / 2; // Espaces avant la ligne
            for (j = 0; j < espaces; j++) {
                printf(" ");
            }
            for (j = 0; j < temp; j++) {

                printf("%c", argv[2][0]);
            }
            temp = 0;
            printf("\n");
        }
    }
    return 0;
}
