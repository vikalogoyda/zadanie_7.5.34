# zadanie_7.5.34
# Popis kódu

Kód v souboru `main.c` implementuje funkcionalitu pro provedení operace ohnutí mincí na cyklickém grafu. Předpokládá se, že první a poslední prvek pole jsou sousední. Po provedení operace jsou mince rozděleny mezi sousední prvky tak, že každý prvek pole obsahuje polovinu mincí předchozího a následujícího prvku, s výjimkou případu, kdy počet mincí v aktuálním prvku je lichý. V takovém případě se jedna mince sníží v aktuálním prvku a zbývající mince se rozdělí mezi sousední prvky.

## Použití

Program přijímá pole `a`, které reprezentuje výchozí konfiguraci mincí, a jeho délku `len`. Po provedení operace program vypíše aktualizovanou konfiguraci mincí.

```c
#include <stdio.h>

// Funkce pro ohnutí mincí
void prehrnutie_minci_cyklicke(unsigned int *a, unsigned int len) {
  // Procházení každého prvku pole
  for (int i = 0; i < len; i++) {
    unsigned int mince = a[i]; // Počet mincí v aktuálním prvku

    // Manipulace s lichým počtem mincí
    if (mince % 2 != 0) {
      a[i]--; // Snížení počtu mincí o 1
      // Rozdělení mincí mezi sousední prvky
      a[(i + 1) % len] += mince / 2; // Přidání poloviny mincí sousednímu prvku vpravo
      a[(i - 1 + len) % len] += mince / 2; // Přidání poloviny mincí sousednímu prvku vlevo
      a[i] = 1; // Aktualizace aktuálního prvku na 1 minci
    } else {
      // Rozdělení mincí mezi sousední prvky pro sudý počet mincí
      a[(i + 1) % len] += mince / 2; // Přidání poloviny mincí sousednímu prvku vpravo
      a[(i - 1 + len) % len] += mince / 2; // Přidání poloviny mincí sousednímu prvku vlevo
    }
  }
}

int main() {
  unsigned int a[] = {3, 4, 5, 6};
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
##Priklad pouzity
unsigned int a[] = {3, 4, 5, 6};
unsigned int len = sizeof(a) / sizeof(a[0]);

printf("Pôvodná postupnosť: ");
// Výstup pôvodní postupnosti...

prehrnutie_minci_cyklicke(a, len);

printf("Rozdelenie po prehnutí: ");
// Výstup aktualizované konfigurace...
