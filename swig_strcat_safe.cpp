#include <iostream>
#include <cstring>
#include <cstdlib>

int main() {
    const char* src = "This is a test string.";
    char result[] = "Result: ";
    char *dest = new char[std::strlen(result) + std::strlen(src) + 1];
    
    std::strcpy(dest, result);
    std::strcat(dest, src); // Compliant

    delete[] dest;
    return 0;
}