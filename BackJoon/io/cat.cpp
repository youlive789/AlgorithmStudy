#include <iostream>
#include <string>

int main() {

    std::string cat = "\\    /\\\n";
    cat.append(" )  ( ')\n");
    cat.append("(  /  )\n");
    cat.append(" \\(__)|");

    std::cout << cat.c_str() << std::endl;
    return 0;
}