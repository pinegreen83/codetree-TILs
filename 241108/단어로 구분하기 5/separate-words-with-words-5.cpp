#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    string temp;
    int cnt;
    while(cin >> temp) {
        cnt++;
        if(cnt % 2 == 0) cout << temp << "\n";
    }

    return 0;
}