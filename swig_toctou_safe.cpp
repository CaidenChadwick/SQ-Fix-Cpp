#include <cstdio>
#include <cerrno>
#include <io.h>
#include <sys/stat.h>
#include <cstdlib>
#include <iostream>


int create_cachedirtag() {
    std::string filename = "cache_tag.txt";
    struct stat st;
    FILE *f;

    // Check if file already exists
    if (stat(filename.c_str(), &st) == 0) {
        errno = EEXIST;
        return -1;
    }

	f = fopen(filename.c_str(), "wx");
    if (f == nullptr) {
        return -1;
    }

    fclose(f);
    return 0;
}

int main() {
    if (create_cachedirtag() == -1) {
        std::cout << ("Error creating cache dir tag");
        return 1;
    }
    std::cout << "Cache dir tag created successfully." << '\n';
    return 0;
}