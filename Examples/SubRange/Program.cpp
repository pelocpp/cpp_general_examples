// ===========================================================================
// Program.cpp // // Demonstration of Partial Template Specialization
// ===========================================================================

#include <iostream>

// function prototypes
void main_function_subrange();

// entry point
int main() {
    try
    {
        main_function_subrange();
    }
    catch (const std::exception& ex) {
        std::cout << "Exception: " << ex.what() << std::endl;
    }
    return 0;
}

// ===========================================================================
// End-of-File
// ===========================================================================
