#include <cstdio>
#include <cerrno>
#include <io.h>
#include <sys/stat.h>
#include <cstdlib>
#include <iostream>

int create_cachedirtag() {
    char filename[256] = "test.txt";
    struct stat st;
    FILE *f;

    // Race window exists here: another process can create/replace the file now
    f = fopen(filename, "wx");  // <-- SonarQube should flag this
    if (f == NULL) {
        return -1;
    }
    fclose(f);

    return 0;
}

int main() {
    if (create_cachedirtag() == -1) {
        printf("Error creating file.\n");
        return 1;
    }
    printf("File created successfully.\n");
    return 0;
}
