#include <iostream>
#include <regex>
#include <string>

// using namespace std;

int main() {
    // Simple regular expression matching
    std::string str = "ello";
    std::regex pattern(R"(ello)");

    std:: cout << std::regex_match(str, pattern); //1

    return 0;
}
