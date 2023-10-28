#include <stdio.h>
#include <string.h>
#include <omp.h>
// Univ. Canaviri Valdes luis Israel
//C.I. 7094535
int main() {
    char frase[] = "tres tristes tigres trigaban trigo por culpa del bolivar";

    // Dividir la frase en palabras
    char *palabras[50];  
    int i = 0;
    palabras[i] = strtok(frase, " ");
    while (palabras[i] != NULL) {
        i++;
        palabras[i] = strtok(NULL, " ");
    }
    int totalPalabras = i;

    // División de las palabras en dos secciones
    int mitad = totalPalabras / 2;

    #pragma omp parallel for
    for (int j = 0; j < totalPalabras; j++) {
        if (j < mitad) {
            // Procesar la primera sección
            printf("%s ", palabras[j]);
        } else {
            // Procesar la segunda sección
            if (j == mitad) {
                printf("\n");
            }
            printf("%s ", palabras[j]);
        }
    }

    return 0;
}