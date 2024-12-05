#include <stdio.h>

int main() {

    // Need to add string end character in order to print to console
    printf("something\n");

    /*
    PRINTF
    This is the standard print function

    Print character stream of data to stdout console
    printf(const char* str, ...);
    */

    printf("hello world");



    /*
    SPRINF
    String print function instead of printing to console
    it stores it on the char buffer (array) which is
    specified in sprintf

    sprintf(char *str, const char *string,...); 
    */
    
    char buffer[50];
    int a = 10, b = 20, c;
    c = a + b;
    sprintf(buffer, "Sum of %d and %d is %d", a, b, c);
 
    // The string "sum of 10 and 20 is 30" is stored
    // into buffer instead of printing on stdout
    printf("%s", buffer);



    /*hello
    FPRINTF
    Used to print the string content in file but not 
    to the stdout console

    fprintf(FILE *fptr, const char *str, ...);
    */

   int i, n = 2;
    char str[50];
 
    // open file sample.txt in write mode
    FILE* fptr = fopen("sample.txt", "w");
 
    for (i = 0; i < n; i++) {
        // Write line / string to output
        puts("Enter a name");
        // Standard input stream stdin and stores in buffer
        gets(str);
        // Writes i.s\n to the fprt file
        fprintf(fptr, "%d.%s\n", i, str);
    }
    fclose(fptr);

    return 0;

}