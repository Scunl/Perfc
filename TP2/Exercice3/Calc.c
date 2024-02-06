#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    if (argc >= 4) {
        if (argv[2][0] == '+')
            printf("%d %c %d = %d\n", atoi(argv[1]), argv[2][0], atoi(argv[3]),
                   atoi(argv[1]) + atoi(argv[3]));
        else if (argv[2][0] == 'x')
            printf("%d %c %d = %d\n", atoi(argv[1]), argv[2][0], atoi(argv[3]),
                   atoi(argv[1]) * atoi(argv[3]));
        else if (argv[2][0] == '-')
            printf("%d %c %d = %d\n", atoi(argv[1]), argv[2][0], atoi(argv[3]),
                   atoi(argv[1]) - atoi(argv[3]));
        else if (argv[2][0] == '/') {
            float result = (float)atoi(argv[1]) / (float)atoi(argv[3]);
            printf("%d %c %d = %.2f\n", atoi(argv[1]), argv[2][0], atoi(argv[3]),
                   result);
        } else {
            printf("une erreur\n");
            return -1;
        }
    }
    return 0;
}
