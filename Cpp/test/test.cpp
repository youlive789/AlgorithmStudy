#include <iostream>
#include <cstddef>
#include <string>
using namespace std;	

class Node
{
    public:
        string data = "wow";
        
};

int main()
{
	Node* a = new Node();
    Node* b = new Node();
    cout << &(a->data) << endl;
    cout << &(b->data) << endl;

    if (&(a->data) == &(b->data)) {
        cout << "같음" << endl;
    }
    else {
        cout << "틀림" << endl;
    }

    if (a->data == b->data) {
        cout << "값 같음" << endl;
    }
    else {
        cout << "값 틀림" << endl;
    }
}