#include <stdio.h>

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[10] = {10, 20, 30, 40, 50};
    int n = 5; // Mevcut eleman sayısı
    int pos, value;

    // Araya Ekleme
    pos = 2; value = 25; // 2. indexe 25 ekle
    for (int i = n; i > pos; i--) arr[i] = arr[i-1];
    arr[pos] = value;
    n++;
    printf("Ekleme sonrasi: "); display(arr, n);

    // Silme İşlemi
    pos = 3; // 3. indexteki elemanı sil
    for (int i = pos; i < n - 1; i++) arr[i] = arr[i+1];
    n--;
    printf("Silme sonrasi: "); display(arr, n);

    return 0;
}