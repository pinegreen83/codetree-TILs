#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, sum = 0;
    cin >> a;

    while(a > 0) {
        sum += a--;
    }
    cout << sum;

    return 0;
}