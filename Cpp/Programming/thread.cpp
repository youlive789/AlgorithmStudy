#include <iostream>
#include <thread>

using namespace std;

void proc(int no) {
    for (int idx = 0; idx < 5; idx++) {
        cout << "Thread #" << no << " " << idx << "\n";
    }
}

int main() {

    thread t1(proc, 1);
    thread t2(proc, 2);

    t1.join();
    t2.join();

    cout << "MAIN THREAD DONE" << endl;

    return 0;
}