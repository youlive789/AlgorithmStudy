#include <iostream>
#include <string>
#include <format>

using namespace std;

int main() {

    string id;
    cin >> id;
    
    string emoticon = ":fan::fan::fan:\n:fan::{}::fan:\n:fan::fan::fan:";
    
    cout << format(emoticon, id);

    return 0;
}