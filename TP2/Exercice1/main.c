#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    printf("TEST POUR STRCMP\n");
    printf("===================\n");

    printf("%d\n", strcmp("test", "aba"));
    printf("%d\n", strcmp("aba", "test"));
    printf("%d\n", strcmp("Tba", "tba"));
    printf("%d\n", strcmp("aa", "a"));
    printf("%d\n", strcmp("a", "a"));
    printf("===================\n");
    printf("===== str =====\n");

    char *val = strchr("Test", 'e');
    printf("     %c\n", val[0]);
    printf("     %s\n", val);
    printf("===== strr =====\n");
    char *val2 = strrchr("Doublement de lettre", 't');
    printf("     %c\n", val2[0]);
    printf("     %s\n", val2);
    printf("===================\n");
    char *st = "1237894";
    printf("%d\n", atoi(st) + 1);
    return 0;
}
