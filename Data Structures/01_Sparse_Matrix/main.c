#include <stdio.h>

// Seyrek matris eleman yapısı
struct Element {
    int row;
    int col;
    int value;
};

int main() {
    // 4x4 Örnek bir matris
    int matrix[4][4] = {
        {0, 0, 10, 0},
        {0, 5, 0, 0},
        {0, 0, 0, 7},
        {3, 0, 0, 0}
    };

    struct Element sparse[16]; // En fazla 16 eleman olabilir
    int k = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (matrix[i][j] != 0) {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].value = matrix[i][j];
                k++;
            }
        }
    }

    printf("Sparse Matrix Temsili (Row | Col | Value):\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < k; i++) {
        printf("%d | %d | %d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }

    return 0;
}