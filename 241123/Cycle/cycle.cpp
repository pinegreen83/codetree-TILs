#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, p;
    cin >> n >> p;

    int cnt = 1;
    int test = (n * n) % p;
    int ps[98] = { 0 };
    while(true) {
        if(ps[test] != 0) {
            cout << cnt - ps[test];
            break;
        }
        ps[test] = cnt;
        test = (test * n) % p;
        cnt++;
    }

    return 0;
}