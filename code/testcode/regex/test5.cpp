#include <iostream>
#include <string>
#include <regex>

int main() {

    // sử dụng dấu () để nhóm các nhóm con lại

    std::string s = "this subject has a submarine as a subsequence";
    std::smatch m;
    std::regex e("\\b(sub)([^ ]*)"); // Khớp các từ bắt đầu bằng "sub"
    std::cout << "Chuỗi đích: " << s << std::endl;

    if (std::regex_search(s, m, e)) {
        std::cout << "Match: " << m[0] << std::endl; // Toàn bộ phần khớp (subject)
        std::cout << "Group 1 (sub): " << m[1] << std::endl; // phần
        std::cout << "Group 2 (else): " << m[2] << std::endl; // Phần khớp của nhóm con thứ hai
    } else {
        std::cout << "Không tìm thấy phần khớp nào." << std::endl;
    }

    return 0;
}
