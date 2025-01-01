#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b;
    cin >> a >> b;

    bool isPrime[b+1] = {};
    isPrime[1] = true;
    for(int i=2; i<=b; i++) {
        if(isPrime[i]) continue;

        for(int j=i*2; j<=b; j+=i) {
            isPrime[j] = true;
        }
    }

    int sum = 0;
    int cnt = 0;
    for(int i=a; i<=b; i++) {
        if(!isPrime[i]) {
            sum += i;
            cnt++;
        }
    }
    cout << sum << " " << cnt;

    return 0;
}