#include <cstring>
#include <string_view>

bool starts_with(const char* const string, const std::string_view prefix) {
  // Optimized version of starts_with(string_view, string_view): avoid computing
  // the length of the string argument.
  return std::strncmp(string, prefix.data(), prefix.length()) == 0;
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