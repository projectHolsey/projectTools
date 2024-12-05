#include <stdio.h>
#include <stdlib.h>

int main() {

    int numRows = 3;
    int numCols = 4;
    // Allocating memory for a 2d array
    int** dynamic2DArray = (int**)malloc(numRows * sizeof(int*));
    

    // Allocate memory for each row
    for (int i = 0; i < numRows; i++) {
        dynamic2DArray[i] = (int*)malloc(numCols * sizeof(int));
        if (dynamic2DArray[i] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
    }


    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("Element at dynamic2DArray[%i][%i]: ", i, j);
            printf("%d\n", dynamic2DArray[i][j]);
        }

    }

    return 0;

}