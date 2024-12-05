#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main() {

    /*
    Dynamic arrays allocate memory at runtime
    They aren't fixed and can be adjusted at runtime

    MALLOC (memory allocation)
    - allocate specified number of bytes


    CALLOC (Contiguous Allocation)
    - allocates memory for an array of elements, initializing each one to 0


    REALLOC (Reallocate memory)
    - Changes the size of the previously allocated memory block


    FREE
    - Function to free allocated memory
    - ALWAYS use free on dynamic memory to prevent leaks
    - Don't use memory after it has been freed

    

    =======
    Usage
    =======
    Dynamic memory is used when we don't know the size of the 
    data structure we're creating until runtime.

    // Comparable to ArrayList() in Java

    */

    // malloc array
    // Created a dynamic array that's 5 * the size of bytes for an in
    int *dynamicArray = (int*)malloc(5 * sizeof(int));
    // This pointer will be to the first byte of the allocated memory


    // calloc array
    int *dynamicArray2 = (int*)calloc(5, sizeof(int));
    // {0, 0, 0, 0, 0}


    // realloc array
    int *dynamicArray3 = (int*)realloc(dynamicArray, 10 * sizeof(int));
     



    return 0;
}



void example_usage1() {

    // Variable sized array example

    srand(time(NULL));

    int x = rand();

    printf("Size of array is %d \n", x);

    int *dynamicArray = (int*)malloc(x * sizeof(int));

    free(dynamicArray);

    return;

}

struct Node {
    int data;
    struct Node* next;
};
void example_usage2(){
    // Linked list example

    struct Node* head = NULL;

    // Code to manipulate the linked list

    // Free the allocated memory in the linked list when done
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

}


void example_usage3() {

    // Matrices of with variable dimensions

    int rows, cols;
    srand(time(NULL));

    rows = rand();
    cols = rand();

    // Create a 2d array
    // Create a pointer to a pointer of ints
    int **matrix = (int**)malloc(rows * sizeof(int*));
    
    // for each item in the matrix
    // Create a pointer to a block of ints
    for (int i = 0; i < rows; i++) {
        // Allocate memory for x number of ints for this block of memory
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    // Free allocated memory for each row
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }

    // Free allocated memory for the array of row pointers
    free(matrix);

}