#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>

// It is a constant
#define SIZE 10

// Uncomment the line bellow if you want to remove the prefix std:: at the commands
//using namespace std;

void printVariablesUsingC(int a, float b, char c, bool d);

void printVariablesUsingCPP(int a, float b, char c, bool d);

void printPreDefinedVariablesUsingC();

void printPreDefinedVariablesUsingCPP();

void readVariablesUsingC();

void readVariablesUsingCPP();

void counterUntilConstant();

void readStringUsingC();

int printMenuAndReturnAnOption() {
    std::cout << "Choose one option to execute: " << std::endl;
    std::cout << "1 - Print defined variables using C " << std::endl;
    std::cout << "2 - Print defined variables using C++ " << std::endl;
    std::cout << "3 - Read variables using C " << std::endl;
    std::cout << "4 - Read variables using C++ " << std::endl;
    std::cout << "5 - Count until " << SIZE << std::endl;
    std::cout << "6 - Read string using C " << std::endl;
    int option;
    std::cin >> option;
    return option;
}


void executeBasicOperation(){
    int option = printMenuAndReturnAnOption();
    switch (option) {
        case 1: printPreDefinedVariablesUsingC(); break;
        case 2: printPreDefinedVariablesUsingCPP(); break;
        case 3: readVariablesUsingC(); break;
        case 4: readVariablesUsingCPP(); break;
        case 5: counterUntilConstant(); break;
        case 6: readStringUsingC(); break;
    }
}


void printVariablesUsingC(int a, float b, char c, bool d) {
    // Print the variables (using C)
    printf("<< C Printing >> \n");
    printf("Value of a is %d \n", a);
    printf("Value of b is %f \n", b);
    printf("Value of b is %.2f (limiting decimals)\n", b);
    printf("Value of c is %c \n", c);
    printf("Value of d is %d \n", d);
    printf("\n");
}

void printVariablesUsingCPP(int a, float b, char c, bool d) {
    // Print the variables (using C++ / need use the iostream lib)
    std::cout << "<< C++ Printing >> \n";
    std::cout << "Value of a is " << a << "\n";
    std::cout << "Value of b is " << b << "\n";
    std::cout << "Value of c is " << c << "\n";
    std::cout << "Value of d is " << d << "\n";
    std::cout << "\n";
}

void printPreDefinedVariablesUsingC() {
    // Variables attribution
    int a = 5;
    float b = 2.7;
    char c = 'x';
    bool d = true;
    printVariablesUsingC(a, b, c, d);
}

void printPreDefinedVariablesUsingCPP() {
    // Variables attribution
    int a = 7;
    float b = 6.4;
    char c = 'H';
    bool d = false;
    printVariablesUsingC(a, b, c, d);
}

void readVariablesUsingC() {
    // Variables definition
    int a;
    float b;
    char c;
    bool d;

    // Read variables from input (using C)
    printf("<< C input read >> \n");
    printf("Reading an integer: ");
    scanf("%d", &a);
    printf("\nReading a float: ");
    scanf("%f", &b);
    getchar();
    printf("\nReading a character: ");
    scanf("%c", &c);
    getchar();
    printf("\nReading a boolean (0 or 1): ");
    int temp; // To read a boolean you need to use a temporary object of int type
    scanf("%d", &temp); // The temp is read as an integer (an integer is bigger than a boolean)
    d = temp; // Here the cast happen, changing the size of the integer to a boolean (one bit)
    printf("\n\n");

    printVariablesUsingC(a, b, c, d);
}

void readVariablesUsingCPP() {
    // Variables definition
    int a;
    float b;
    char c;
    bool d;

    // Read variables from input (using C++)
    std::cout << "<< C++ input read >> " << "\n";
    std::cout << "Reading an integer: " << std::endl;
    std::cin >> a;
    std::cout << "Reading a float: " << std::endl;
    std::cin >> b;
    std::cout << "Reading a character: " << std::endl;
    std::cin >> c;
    std::cout << "Reading a boolean (0 or 1): " << std::endl;
    std::cin >> d;

    printVariablesUsingCPP(a, b, c, d);
}

void counterUntilConstant() {
    printf("\n\nLoop for counting until %d using the constant SIZE", SIZE);
    int i;
    for(i=1; i<=SIZE; i++) {
        printf("\n%d", i);
    }
}

void readStringUsingC() {
    char word[10];
    printf("Type a word: ");

    // Clean the buffer
    setbuf(stdin, 0);

    //Read the string
    fgets(word, 10, stdin);

    // Clean the not used array memory
    /* In this case, an array of ten positions was created.
    If you type a word fewer than 10 characters, the follow line will
    put the symbol \0, that represents the end of the string, in the position
    relative the word length */
    word[strlen(word)-1] = '\0';

    //Print the word
    printf("The word typed was: %s", word);
}
