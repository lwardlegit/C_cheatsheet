#include <stdio.h> // these are called directives and run in pre-processing before program runs
#include <errno.h>
#include <string.h>
#define PI 3.14 // this will happen before program
// #include "myfile.h" will bring in a file of your choice
// #define SQUARE(x) ((x) * (x)) can also be a function or some operation

/*
this is a useful almost constant so you can use #ifdef
#define DEBUG

 so in main we can now do this:

 #ifdef DEBUG
    printf("Debug mode is ON\n");
  #endif
*/

    enum Level {
        LOW,
        MEDIUM,
        HIGH
    }; 
    
    void someCoolFunc(char name[]){
        printf("%s", name);
    }
     struct myStructure {
        int myNum;
        char myLetter;
    };

    struct Car {
        char brand[30];
        int year;
    };

    union myUnion {        // Union declaration
        int myNum;           // Member (int)
        char myLetter;       // Member (char)
        char myString[30];   // Member (char array)
    }; 

int main(){
    
    typedef double SpookyEnergy;
    enum Level myLevel = LOW;
    int myNumber = 3;
    float myDecimal = 4.5;
    float sum = (float) 5/2;
    int myInts[] = {1,2,4,6,8};
    int* intPtr = &myNumber;
    int f = 2;

    printf("%d%s", myNumber, "\n" );
    printf("%.6f%s", myDecimal, "\n");
    printf("hello world");


    int a = 5;
    int b = 10;
    switch(!(b % a == 2)){
        case 1:
        printf("\n yes it is");
        break;

        case 0:
        printf("\n no it is not");
        break;
    }
    int i = 0;
    do{
        printf("\n ya like jazz kid??");
        i++;
    }
    while(i < 3);

    int arrlength = sizeof(myInts) / sizeof(myInts[0]);
    printf("\n my array length is %d", arrlength);

    // Get the memory size of an int
    printf("\n%zu", sizeof(myNumber));

    // points to memory address
    printf("\n %p", intPtr);

    //points to value of variable pointer points to (dereferencing)
    printf("\n %d", *intPtr);

    // Get the value of the third element in myNumbers
    printf("\n%d", *(myInts + 2));


    someCoolFunc("thebestname");

    /*
    FILE *fptr;
    fptr = fopen(filename, mode); 

    FILE *fptr;

    // Create a file
    fptr = fopen("filename.txt", "w");

    // Close the file
    fclose(fptr); 

    // Open a file in writing mode
    fptr = fopen("filename.txt", "w");

    // Write some text to the file
    fprintf(fptr, "Some text");

    // Close the file
    fclose(fptr);

    
    // Open a file in append mode
    fptr = fopen("filename.txt", "a");

    // Append some text to the file
    fprintf(fptr, "\nHi everybody!");

    // Close the file
    fclose(fptr); 

    // Open a file in read mode
    fptr = fopen("filename.txt", "r");

    // Store the content of the file
    char myString[100]; 
    fgets(myString, 100, fptr); 

    */
  
    struct myStructure s1;

    struct Car car = {"Toyota", 2020};

    // Declare a pointer to the struct
    struct Car *ptr = &car;

    // Access members using the -> operator
    printf("Brand: %s\n", ptr->brand);
    printf("Year: %d\n", ptr->year);

    // DYNAMIC MEMORY FUNCTIONS 

    int *ptr1, *ptr2;
    ptr1 = malloc(sizeof(*ptr1));
    ptr2 = calloc(1, sizeof(*ptr2));
 
    /*
    Be careful: sizeof(*ptr1) tells C to measure the size of the data at the address. 
    If you forget the * and write sizeof(ptr1) instead,
    it will measure the size of the pointer itself, 
    which is the (usually) 8 bytes that are needed to store a memory address.
    */

    /* SAMPLE READING AND WRITING FROM DYNAMIC MEMORY*/

    // Allocate memory
    int *ptrmem;
    ptrmem = calloc(4, sizeof(*ptrmem));

    // Write to the memory
    *ptrmem = 2;
    ptrmem[1] = 4;
    ptrmem[2] = 6;

    // Read from the memory
    printf("%d\n", *ptrmem);
    printf("%d %d %d", ptrmem[1], ptrmem[2], ptrmem[3]); 
    free(ptrmem);

    //int *ptr2 = realloc(ptr1, size);

    // FAILURE CHECK FOR MEMORY RESIZE
    /*
    int *ptr1, *ptr2;

    // Allocate memory
    ptr1 = malloc(4);

    // Attempt to resize the memory
    ptr2 = realloc(ptr1, 8);

    // Check whether realloc is able to resize the memory or not
    if (ptr2 == NULL) {
    // If reallocation fails
    printf("Failed. Unable to resize memory");
    } else {
    // If reallocation is sucessful
    printf("Success. 8 bytes reallocated at address %p \n", ptr2);
    ptr1 = ptr2;  // Update ptr1 to point to the newly allocated memory
    } 
    */


    //WORKING EXAMPLE WITH ERROR CHECKING

    /*
        int *ptr;
    ptr = malloc(sizeof(*ptr)); // Allocate memory for one integer

    // If memory cannot be allocated, print a message and end the main() function
    if (ptr == NULL) {
    printf("Unable to allocate memory");
    return 1;  // Exit the program with an error code
    }

    // Set the value of the integer
    *ptr = 20;

    // Print the integer value
    printf("Integer value: %d\n", *ptr);

    // Free allocated memory
    free(ptr);

    // Set the pointer to NULL to prevent it from being accidentally used
    ptr = NULL;
    */

    /*
    
    Remember to check for errors (NULL return values) to find out if memory allocation was sucessful or not
    Prevent memory leaks - always remember to free memory that is no longer used, or else the program might underperform or even worse, crash if it runs out of memory
    Set the pointer to NULL after freeing memory so that you cannot accidentally continue using it

    */

    struct Car *ptr = (struct Car*) malloc(sizeof(struct Car));

    if (f == NULL) {
    printf("Error: %s\n", strerror(errno));
    return 1;
  }

  char sickname[100]; // Buffer to store the user's name

  do {
    printf("Enter your name: ");
    fgets(sickname, sizeof(sickname), stdin); // Read input as a string
    sickname[strcspn(sickname, "\n")] = 0; // Remove the newline character if present
  } while (strlen(sickname) == 0); // Repeat if the input is empty

  printf("Hello, %s\n", sickname); // Greet the user


  // RANDOMS
  // in this case % 6 means 0 -> 6 and then + 1 will make sure its never 0 
  // also you can use srand() to make sure the number is always different since it represents the current time which always changes

  srand(time(NULL));

  int dice1 = (rand() % 6) + 1;
  int dice2 = (rand() % 6) + 1;
  printf("You rolled %d and %d (total = %d)\n", dice1, dice2, dice1 + dice2);

  // COMPILING
  // if using multiple files
  // gcc main.c calc.c -o program
    

    return 0;
}