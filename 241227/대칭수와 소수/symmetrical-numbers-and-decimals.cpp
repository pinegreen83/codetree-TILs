#include <iostream>
#include <cmath>

using namespace std;

bool checkPal(int now) {
    int a = now, b = 0, ten = 1;
    while(true) {
        b += a % 10;
        a /= 10;
        if(a == 0) break;
        b *= 10;
    }

    return b == now;
}

bool isPrime(int now) {
    int roots = sqrt(now);
    for(int i=2; i<=roots; i++) {
        if(now % i == 0) return false;
    }
    return true;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    while(true) {
        n++;
        if(checkPal(n)) {
            if(isPrime(n)) {
                cout << n;
                break;
            }
        }
    }

    return 0;
}