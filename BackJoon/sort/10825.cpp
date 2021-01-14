#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct score {
    string name;
    int kor;
    int eng;
    int math;
};

bool scoreSort(score a, score b) {
    if (a.kor == b.kor && a.eng == b.eng && a.math == b.math) return a.name < b.name;
	if (a.kor == b.kor && a.eng == b.eng) return a.math > b.math;
	if (a.kor == b.kor) return a.eng < b.eng;
	return a.kor > b.kor;
}

int main() {

    int count;
    cin >> count;

    vector<score> scoreList;

    for (int idx = 0; idx < count; idx++) {
        score s;
        cin >> s.name >> s.kor >> s.eng >> s.math;
        scoreList.push_back(s);
    }

    sort(scoreList.begin(), scoreList.end(), scoreSort);

    for (auto s: scoreList) {
        cout << s.name << "\n";
    }

    return 0;
}