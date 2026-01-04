#include <stdio.h>

void hanoi(int n, char kaynak, char hedef, char yardimci) {
    if (n == 1) {
        printf("Disk 1: %c -> %c\n", kaynak, hedef);
        return;
    }
    // n-1 diski yardımcı direğe taşı
    hanoi(n - 1, kaynak, yardimci, hedef);
    
    // n. diski hedefe taşı
    printf("Disk %d: %c -> %c\n", n, kaynak, hedef);
    
    // n-1 diski yardımcıdan hedefe taşı
    hanoi(n - 1, yardimci, hedef, kaynak);
}

int main() {
    int n = 3; // Örnek olarak 3 disk
    printf("%d disk icin hamleler:\n", n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}