#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string now;
    int cnt = 0;
    while(cin >> now) {
        cnt++;
        if(cnt % 3 == 0) cout << now << " ";
    }

    return 0;
}