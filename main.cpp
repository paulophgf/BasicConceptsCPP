#include "files/basic_operations.h"
#include "files/vector_operations.h"
#include "files/matrix_operation.h"

int printMainMenuAndReturnAnOption() {
    std::cout << "\n----------------------------- " << std::endl;
    std::cout << "\nChoose one option to execute: " << std::endl;
    std::cout << "1 - Basic operations" << std::endl;
    std::cout << "2 - Vector operations" << std::endl;
    std::cout << "3 - Matrix operations" << std::endl;
    std::cout << "0 - Exit" << std::endl;
    int option;
    std::cin >> option;
    return option;
}

void start() {
    int option = -1;
    while(option != 0) {
        option = printMainMenuAndReturnAnOption();
        switch (option) {
            case 1: executeBasicOperation(); break;
            case 2: executeVectorOperation(); break;
            case 3: executeMatrixOperation(); break;
        }
    }
}

int main(){
    start();
    return 0;
}