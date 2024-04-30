#include <stdio.h>

void prehrnutie_minci_cyklicke(unsigned int* a, unsigned int len) {
    // Prechádzanie cez každý prvok poľa
    for (int i = 0; i < len; i++) {
        unsigned int mince = a[i]; // Počet mincí v aktuálnom prvku

        // Manipulácia s nepárnym počtom mincí
        if (mince % 2 != 0) {
            a[i]--; // Zníženie počtu mincí o 1
            // Rozdelenie mincí medzi susedné prvky
            a[(i + 1) % len] += mince / 2; // Pridanie polovice mincí susednému prvku vpravo
            a[(i - 1 + len) % len] += mince / 2; // Pridanie polovice mincí susednému prvku vľavo
            a[i] = 1; // Aktualizácia aktuálneho prvku na 1 mincu
        }
        else {
            // Rozdelenie mincí medzi susedné prvky pre párny počet mincí
            a[(i + 1) % len] += mince / 2; // Pridanie polovice mincí susednému prvku vpravo
            a[(i - 1 + len) % len] += mince / 2; // Pridanie polovice mincí susednému prvku vľavo
        }
    }
}

int main() {
    unsigned int a[] = { 3, 4, 5, 6 };
    unsigned int len = sizeof(a) / sizeof(a[0]);

    printf("Pôvodná postupnosť: ");
    for (int i = 0; i < len; i++) {
        printf("%u ", a[i]);
    }
    printf("\n");

    prehrnutie_minci_cyklicke(a, len);

    printf("Rozdelenie po prehnutí: ");
    for (int i = 0; i < len; i++) {
        printf("%u ", a[i]);
    }
    printf("\n");

    return 0;
}
