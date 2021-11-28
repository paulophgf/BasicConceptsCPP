#include <iostream>

void declareAndPrint();

void usingTypedefDeclaration();

void usingEnumeratedTypes();


int printDataTypeMenuAndReturnAnOption() {
    std::cout << "Choose one option to execute: " << std::endl;
    std::cout << "1 - Declare data types and print the sizes" << std::endl;
    std::cout << "2 - Using typedef declaration" << std::endl;
    std::cout << "3 - Using enumerated types" << std::endl;
    int option;
    std::cin >> option;
    return option;
}

void executeDataTypeOperation() {
    int option = printDataTypeMenuAndReturnAnOption();
    switch (option) {
        case 1: declareAndPrint(); break;
        case 2: usingTypedefDeclaration(); break;
        case 3: usingEnumeratedTypes(); break;
    }
}

void declareAndPrint() {
    std::cout << "The size of variables might be different, because it's depend on the compiler and the computer you are using" << std::endl;

    bool boolean = true; // Size: 1 bit (0 or 1)
    std::cout << "Size of bool:" << sizeof(bool) << std::endl;

    int integer = 28515; // Size: 4 bytes | Typical Range: -2147483648 to 2147483647
    signed int signedInteger = -55185; // Size: 4 bytes | Typical Range: -2147483648 to 2147483647
    unsigned int unsignedInteger = 52196515; // Size: 4 bytes | Typical Range: 0 to 4294967295
    std::cout << "Size of int:" << sizeof(int) << std::endl;
    std::cout << "Size of signed int:" << sizeof(signed int) << std::endl;
    std::cout << "Size of unsigned int:" << sizeof(unsigned int) << std::endl;

    short int shortNumber = 2851; // Size: 2 bytes | Typical Range: -32768 to 32767
    signed short int signedShort = -555; // Size: 2 bytes | Typical Range: -32768 to 32767
    unsigned short int unsignedShort = 526; // Size: 2 bytes | Typical Range: 0 to 65,535
    std::cout << "Size of int:" << sizeof(short int) << std::endl;
    std::cout << "Size of signed short int:" << sizeof(signed short int) << std::endl;
    std::cout << "Size of unsigned short int:" << sizeof(unsigned short int) << std::endl;

    long int longNumber = 2845451; // Size: 8 bytes | Typical Range: -2147483648 to 2147483647
    signed long int signedLongNumber = -5515465; // Size: 8 bytes | Typical Range: -2147483648 to 2147483647
    unsigned long int unsignedLongNumber = 455124454; // Size: 8 bytes | Typical Range: 0 to 4294967295
    std::cout << "Size of long int:" << sizeof(long int) << std::endl;
    std::cout << "Size of signed long int:" << sizeof(signed long int) << std::endl;
    std::cout << "Size of unsigned long int:" << sizeof(unsigned long int) << std::endl;

    long long int longLongNumber = 28965154654681584; // Size: 8 bytes | Typical Range: -(2^63) to (2^63)-1
    unsigned long long int unsignedLongLongNumber = 45512445461518548; // Size: 8 bytes | Typical Range: 0 to 18.446.744.073.709.551.615
    std::cout << "Size of long long int:" << sizeof( long long int) << std::endl;
    std::cout << "Size of unsigned long long int:" << sizeof(unsigned long long int) << std::endl;

    float floatNumber = 2851.154; // Size: 4 bytes
    double doubleNumber = -554.4512; // Size: 8 bytes
    long double longDoubleNumber = 4551244.5185; // Size: 12 bytes
    std::cout << "Size of float:" << sizeof(float) << std::endl;
    std::cout << "Size of double:" << sizeof(double) << std::endl;
    std::cout << "Size of long double:" << sizeof(long double) << std::endl;

    char letter = 'P'; // Size: 1 byte | Typical Range: -127 to 127 or 0 to 255
    signed char signedLetter = 'K'; // Size: 1 byte | Typical Range: 0 to 255
    unsigned char unsignedLetter = 'm'; // Size: 1 byte | Typical Range: -127 to 127
    wchar_t wLetter = 'A'; // Size: 4 bytes | Typical Range: 1 wide character
    std::cout << "Size of char:" << sizeof(char) << std::endl;
    std::cout << "Size of signed char:" << sizeof(signed char) << std::endl;
    std::cout << "Size of unsigned char:" << sizeof(unsigned char) << std::endl;
    std::cout << "Size of wchar_t:" << sizeof(wchar_t) << std::endl;

    /*
     * The difference between char and wchar_t is that char is used for so-called ANSI family of functions
     * and wchar_t is used for new so-called Unicode (or Wide) family of functions
     */
}

void usingTypedefDeclaration() {
    std::cout << "You can create a new name for an existing type using typedef." << std::endl;
    typedef bool boolean;
    typedef int level;

    boolean isActive = true;
    if(isActive) {
        std::cout << "bool changed to boolean" << std::endl;
        level next = 2;
        std::cout << "int changed to level where value of variable next is: " << next << std::endl;
    }
}

void usingEnumeratedTypes() {
    enum color {red, green, blue} selectedColor;
    selectedColor = red;
    std::cout << "The color selected was: " << selectedColor << std::endl;
}
