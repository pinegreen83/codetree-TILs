#include <iostream>
using namespace std;

int n;
int recur(int now) {
    if(now == n) {
        return n;
    }
    return now + recur(now - 2);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    if(n % 2 == 1) cout << recur(99);
    else cout << recur(100);

    return 0;
}