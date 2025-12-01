#include <cstring>
#include <iostream>

int main () {
    const char* src = "This is a test string.";
    char dest[256];
    strcpy(dest, "Result: ");
    strcat(dest, src); // Sensitive: might overflow

    if (strlen(dest) > sizeof(dest) - 1) {
        // Handle potential overflow
        std::cerr << "Buffer overflow detected!" << '\n';
        return 1;
    }

    return 0;
}