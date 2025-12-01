#include <cstdio>
#include <cerrno>
#include <io.h>
#include <sys/stat.h>
#include <cstdlib>
#include <iostream>

int create_cachedirtag() {
    std::string filename = "cache_tag.txt";
    struct stat st;

    // Check if file already exists
    if (stat(filename.c_str(), &st) != 0) {
        // Race window exists here: another process can create/replace the file now
        FILE *f = fopen(filename.c_str(), "w");  // <-- SonarQube should flag this
        if (f == nullptr) {
            return -1;
        }
        fclose(f);
    }
    
    return 0;
}

int main() {
    if (create_cachedirtag() == -1) {
        std::cout << "Error creating file.\n";
        return 1;
    }
    std::cout << "File created successfully.\n";
    return 0;
}
