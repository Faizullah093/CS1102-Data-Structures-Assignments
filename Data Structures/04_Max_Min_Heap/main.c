#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Max Heap olustur
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    printf("Max Heap (Dizi hali):\n");
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}