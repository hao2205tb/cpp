#include <iostream>
#include <regex>

int main() {
    std::string target = "Hello, World!";
    std::regex replace_pattern(R"(World)");
    std::string result = std::regex_replace(target, replace_pattern, "Universe");

    std::cout << result << std::endl; //Hello, Universe!

    return 0;
}
