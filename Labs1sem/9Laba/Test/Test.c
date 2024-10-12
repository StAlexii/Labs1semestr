#include <stdio.h>

int main() {
    int n = 9;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%3d ", i * j);
        }
        printf("\n");
    }

    return 0;
}
