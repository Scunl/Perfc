#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    if (argc == 3) {
        int temp = 0;
        for (int i = atoi(argv[1]); i >= 0; i--) {
            temp += 2 * i + 1;
            for (int j = 0; j < temp; j++) {
                printf("%c", argv[2][0]);
            }
            temp = 0;
            printf("\n");
        }
    }
    return 0;
}
