#include <iostream>
#include <regex>

int main() {
    std::string target = "Hello, World! Hello, Universe!";
    std::regex pattern("Hello");
    std::regex_iterator<std::string::iterator> it(target.begin(), target.end(), pattern);
    std::regex_iterator<std::string::iterator> end;

    while (it != end) {
        std::cout << it->str() << std::endl;
        ++it;
    }

    return 0;
}
/* output
Hello
Hello
*/
