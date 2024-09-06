#include <iostream>
using namespace std;

void recur(int now) {
    if(now == 1) {
        cout << now << " ";
        return;
    }
    recur(now / 3);
    cout << now << " ";
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    recur(n);

    return 0;
}