#include <stdio.h>

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);
    int table[m];
    for (int i = 0; i < m; i++) {
        table[i] = -1;
    }
    while (q--) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);
        int h = key % m;
        if (op[0] == 'I') {
            for (int i = 0; i < m; i++) {
                int index = (h + i*i) % m;

                if (table[index] == -1) {
                    table[index] = key;
                    break;
                }
            }
        }
        else {
            int found = 0;
            for (int i = 0; i < m; i++) {
                int index = (h + i*i) % m;
                if (table[index] == -1)
                    break;
                if (table[index] == key) {
                    found = 1;
                    break;
                }
            }
            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }
    return 0;
}