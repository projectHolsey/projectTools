#include <stdio.h>
#include <stdlib.h>


void addItem(int*** array, int* numRows, int numCols, int* newItem) {
    // Increase the number of rows
    int newNumRows = (*numRows) + 1;

    // Reallocate memory for the array with the new number of rows
    int*** newArray = (int***)realloc(*array, newNumRows * sizeof(int*));
    if (newArray == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the new row
    newArray[newNumRows - 1] = (int*)malloc(numCols * sizeof(int));
    if (newArray[newNumRows - 1] == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Copy the existing content to the new array
    for (int i = 0; i < (*numRows); i++) {
        newArray[i] = (*array)[i];
    }

    // Copy the new item to the last row
    for (int i = 0; i < numCols; i++) {
        newArray[newNumRows - 1][i] = newItem[i];
    }

    // Update the array and the number of rows
    *array = newArray;
    *numRows = newNumRows;
}



int main() {
    int size = 5;
    int* dynamicArray = (int*)malloc(size * sizeof(int));

    // Adding an item at index 2
    int index = 2;
    int newItem = 100;

    if (index >= 0 && index < size) {
        dynamicArray[index] = newItem;
    } else {
        fprintf(stderr, "Invalid index.\n");
    }

    // Free the memory when done
    free(dynamicArray);


    int numRows = 3;
    int numCols = 4;

    int** dynamic2DArray = (int**)malloc(numRows * sizeof(int*));
    if (dynamic2DArray == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numRows; i++) {
        dynamic2DArray[i] = (int*)malloc(numCols * sizeof(int));
        if (dynamic2DArray[i] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
    }

    // Adding an item to the array
    int newItem2[] = {10, 11, 12, 13};
    addItem(&dynamic2DArray, &numRows, numCols, newItem2);

    // Free the memory
    for (int i = 0; i < numRows; i++) {
        free(dynamic2DArray[i]);
    }
    free(dynamic2DArray);

    return 0;

}

