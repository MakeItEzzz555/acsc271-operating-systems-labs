#include <iostream>

int main(int argc, char* argv[]) {
    // Print the number of parameters
    std::cout << "Number of parameters: " << argc << std::endl;

    // Loop through each parameter and print its value
    for (int i = 0; i < argc; ++i) {
        std::cout << "Parameter " << i << ": " << argv[i] << std::endl;
    }

    return 0;
}
