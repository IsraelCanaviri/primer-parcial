#include <stdio.h>
#include <string.h>
#include <omp.h>

//Univ: Luis Irael Canaviri Valdes
// C.I. 7094535
int main() {
    char frase[] = "tres tristes tigres trigaban trigo por culpa del bolivar";
    char palabras[50][20];  // Suponemos un máximo de 50 palabras de 20 caracteres

    // Dividir la frase en palabras
    int i = 0;
    char *token = strtok(frase, " ");
    while (token != NULL) {
        strcpy(palabras[i], token);
        token = strtok(NULL, " ");
        i++;
    }
    int totalPalabras = i;

    // División de las palabras en dos secciones 
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            printf("Primera seccion: ");
            for (int j = 0; j < totalPalabras; j += 2) {
                printf("%s ", palabras[j]);
            }
            printf("\n");
        }

        #pragma omp section
        {
            printf("Segunda seccion: ");
            for (int j = 1; j < totalPalabras; j += 2) {
                printf("%s ", palabras[j]);
            }
            printf("\n");
        }
    }

    return 0;
}
