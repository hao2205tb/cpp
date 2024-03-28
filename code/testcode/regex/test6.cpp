#include <iostream>
#include <regex>


int main() {

    // c++ no support "named capturing group" in regex
    // using enum instead;
    enum{_, greeting, subject};
    std::string text = "Hello, World!";

    std::regex pattern("(Hello), (\\w+)!");

    std::smatch matches;

    if (std::regex_search(text, matches, pattern)) {
        std::cout << "Greeting: " << matches[greeting] << std::endl;
        std::cout << "Subject: " << matches[subject] << std::endl;
    } else {
        std::cout << "No match found." << std::endl;
    }

    return 0;
}
