#include <iostream>
#include <regex>

int main() {
    std::string target = "1234 is a number.";
    std::regex digit_pattern("\\d"); // "\\d" = R"(\d)"
    std::string replacement = "-";
    std::string result = std::regex_replace(target, digit_pattern, replacement);

    std::cout << "Kết quả sau khi thay thế: " << result << std::endl;

    return 0;
}
