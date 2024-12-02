#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int now, sum;

    for(int i=1; i<=5; ++i) {
        sum = 0;
        for(int j=1; j<=4; ++j) {
            cin >> now;
            sum += now;
        }
        cout << sum << "\n";
    }

    return 0;
}