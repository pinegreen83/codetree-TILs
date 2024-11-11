#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string strs[4];
    for(int i=0; i<4; i++) cin >> strs[i];

    for(int i=3; i>=0; i--) {
        for(int j=strs[i].size()-1; j>=0; j--) cout << strs[i][j];
        cout << "\n";
    }

    return 0;
}