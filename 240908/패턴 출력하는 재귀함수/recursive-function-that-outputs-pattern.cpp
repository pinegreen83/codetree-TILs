#include <iostream>
using namespace std;

int n;
void recur(int now) {
    if(now == 369) {
        cout << now << " ";
        return;
    }
    if(n >= 369) {
        recur(now - 2);
        cout << now << " ";
    }
    else {
        cout << now << " ";
        recur(now + 2);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    int temp;
    if(n >= 369) {
        temp = (n % 2 == 1 ? n : n-1);
    }
    else temp = (n % 2 == 1 ? n : n+1);

    recur(temp);

    return 0;
}