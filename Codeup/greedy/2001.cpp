#include <iostream>

using namespace std;

int main() {
    float answer = 0.0;
    float pasta = 0.0;
    float juice = 0.0;

    for (int i = 0; i < 3; i++) {
        int tmpPasta;
        cin >> tmpPasta;
        if (i == 0) {
            pasta = tmpPasta;
        }
        else {
            if (pasta > tmpPasta) {
                pasta = tmpPasta;
            }
        }
    }
    
    for (int i = 0; i < 2; i++) {
        int tmpJuice;
        cin >> tmpJuice;
        if (i == 0) {
            juice = tmpJuice;
        }
        else {
            if (juice > tmpJuice) {
                juice = tmpJuice;
            }
        }
    }

    answer = (juice + pasta) * 1.1;
    cout.precision(1);
    cout << fixed;
    cout << answer << endl;
}