#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <new>

void printStaticVector();

void createRandomlyVectorUsingC(int size);

void createManuallyVectorUsingC(int size);

void createRandomlyVectorUsingCPP(int size);

void createManuallyVectorUsingCPP(int size);

void readVector(int *vector, int size);


int printVectorMenuAndReturnAnOption() {
    std::cout << "Choose one option to execute: " << std::endl;
    std::cout << "1 - Print static integer vector" << std::endl;
    std::cout << "2 - Create a integer vector randomly using C" << std::endl;
    std::cout << "3 - Create a integer vector manually using C" << std::endl;
    std::cout << "4 - Create a integer vector randomly using C++" << std::endl;
    std::cout << "5 - Create a integer vector manually using C++" << std::endl;
    int option;
    std::cin >> option;
    return option;
}

int readVectorSize() {
    std::cout << "Inform a vector size: " << std::endl;
    int size;
    std::cin >> size;
    return size;
}

void executeVectorOperation() {
    int option = printVectorMenuAndReturnAnOption();
    switch (option) {
        case 1: printStaticVector(); break;
        case 2: createRandomlyVectorUsingC(readVectorSize()); break;
        case 3: createManuallyVectorUsingC(readVectorSize()); break;
        case 4: createRandomlyVectorUsingCPP(readVectorSize()); break;
        case 5: createManuallyVectorUsingCPP(readVectorSize()); break;
    }
}

void printStaticVector() {
    int vector[SIZE];
    int i;
    srand(time(NULL));
    for(i=0; i<SIZE; i++) {
        vector[i] = rand();
    }
    for(i=0; i < SIZE; i++) {
        printf("\nPosition %d = %d", i+1, vector[i]);
    }
}

void readVector(int *vector, int size) {
    int i;
    for(i=0; i < size; i++) {
        printf("\nPosition %d = %d", i+1, vector[i]);
    }
}

int* allocateVector(int size) {
    int *aux;
    aux = (int*) malloc(size * sizeof(int));
    return aux;
}

void createVectorUsingC(int size, bool isRandom) {
    int *vector = allocateVector(size);
    int i;
    srand(time(NULL));
    for(i=0; i<size; i++) {
        if(isRandom) {
            vector[i] = rand();
        } else {
            printf("\nPosition %d: ", i+1);
            scanf("%d", &vector[i]);
        }
    }
    readVector(vector, size);

    // Don't forget to free the memory
    free(vector);
}

void createRandomlyVectorUsingC(int size) {
    createVectorUsingC(size, true);
}

void createManuallyVectorUsingC(int size) {
    createVectorUsingC(size, false);
}

void createVectorUsingCPP(int size, bool isRandom) {
    int *vector = new int[size];
    int i;
    srand(time(NULL));
    for(i=0; i<size; i++) {
        if(isRandom) {
            vector[i] = rand();
        } else {
            std::cout << "\nPosition " << i+1 << ": " << std::endl;
            std::cin >> vector[i];
        }
    }
    readVector(vector, size);

    // Don't forget to free the memory
    delete vector;
}

void createRandomlyVectorUsingCPP(int size){
    createVectorUsingCPP(size, true);
}

void createManuallyVectorUsingCPP(int size){
    createVectorUsingCPP(size, false);
}