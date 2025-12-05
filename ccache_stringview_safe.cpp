#include <cstring>
#include <string_view>

bool starts_with(const char* string, std::string_view prefix) {
    if (!string) return false;
    std::string_view s(string);
    return s.size() >= prefix.size() &&
           s.compare(0, prefix.size(), prefix) == 0;
}

int main() {
    const char* testString = "Hello, World!";
    std::string_view prefix = "Hello";

    if (starts_with(testString, prefix)) {
        return 0; // Success
    } else {
        return 1; // Failure
    }
}