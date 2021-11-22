#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <new>

void printStaticMatrix();

void createRandomlyMatrixUsingC(int *msize);

void createManuallyMatrixUsingC(int *msize);

void createRandomlyMatrixUsingCPP(int *msize);

void createManuallyMatrixUsingCPP(int *msize);

void readMatrix(int **matrix, int *msize);


int printMatrixMenuAndReturnAnOption() {
    std::cout << "Choose one option to execute: " << std::endl;
    std::cout << "1 - Print static integer matrix" << std::endl;
    std::cout << "2 - Create a integer matrix randomly using C" << std::endl;
    std::cout << "3 - Create a integer matrix manually using C" << std::endl;
    std::cout << "4 - Create a integer matrix randomly using C++" << std::endl;
    std::cout << "5 - Create a integer matrix manually using C++" << std::endl;
    int option;
    std::cin >> option;
    return option;
}

int* readMatrixSize() {
    // It needs to be static to not change the value when allocateMatrix will be called
    static int msize[2]; //msize[0] = columns and msize[1] = lines
    std::cout << "How many columns: " << std::endl;
    std::cin >> msize[0];
    std::cout << "How many lines: " << std::endl;
    std::cin >> msize[1];
    return msize; // return the array pointer
}

void executeMatrixOperation() {
    int option = printMatrixMenuAndReturnAnOption();
    switch (option) {
        case 1: printStaticMatrix(); break;
        case 2: createRandomlyMatrixUsingC(readMatrixSize()); break;
        case 3: createManuallyMatrixUsingC(readMatrixSize()); break;
        case 4: createRandomlyMatrixUsingCPP(readMatrixSize()); break;
        case 5: createManuallyMatrixUsingCPP(readMatrixSize()); break;
    }
}

void printStaticMatrix() {
    int matrix[SIZE][SIZE];
    int i, j;
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            matrix[i][j] = rand();
        }
    }

    printf("Matrix: \n");
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            printf("[%d] ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** allocateMatrix(int *msize) {
    printf("Allocating memory to matrix [%d] [%d] \n", msize[1], msize[0]);
    int **matrix;
    matrix = (int **) malloc(msize[1] * sizeof(int *));
    for(int i=0; i<msize[1]; i++) {
        matrix[i] = (int *) malloc(msize[0] * sizeof(int));
    }
    return matrix;
}

void createMatrixUsingC(int *msize, bool isRandom) {
    int **matrix = allocateMatrix(msize);
    int i, j;
    srand(time(NULL));
    for(i=0; i<msize[1]; i++) {
        for(j=0; j<msize[0]; j++) {
            if (isRandom) {
                matrix[i][j] = rand();
            } else {
                printf("\nPosition [%d] [%d]: ", i + 1, j + 1);
                scanf("%d", &matrix[i][j]);
            }
        }
    }
    readMatrix(matrix, msize);

    // Don't forget to free the memory
    free(matrix);
}

void createRandomlyMatrixUsingC(int *msize) {
    createMatrixUsingC(msize, true);
}

void createManuallyMatrixUsingC(int *msize) {
    createMatrixUsingC(msize, false);
}

void createMatrixUsingCPP(int *msize, bool isRandom) {
    int i, j;

    // Allocate memory
    int **matrix = new int*[msize[1]];
    for(i=0; i<msize[1]; i++) {
        matrix[i] = new int[msize[0]];
    }

    // Fill matrix
    srand(time(NULL));
    for(i=0; i<msize[1]; i++) {
        for(j=0; j<msize[0]; j++) {
            if (isRandom) {
                matrix[i][j] = rand();
            } else {
                std::cout << "\nPosition [" << i + 1 << "] [" << j + 1 << "]: " << std::endl;
                std::cin >> matrix[i][j];
            }
        }
    }

    // Print matrix
    readMatrix(matrix, msize);

    // Don't forget to free the memory
    for(i=0; i<msize[1]; i++) {
        delete matrix[i];
    }
    delete matrix;
}

void createRandomlyMatrixUsingCPP(int *msize) {
    createMatrixUsingCPP(msize, true);
}

void createManuallyMatrixUsingCPP(int *msize) {
    createMatrixUsingCPP(msize, false);
}

void readMatrix(int **matrix, int *msize) {
    int i, j;
    printf("Matrix: \n");
    for(i=0; i<msize[1]; i++) {
        for(j=0; j<msize[0]; j++) {
            printf("[%d] ", matrix[i][j]);
        }
        printf("\n");
    }
}
