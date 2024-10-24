#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    if(n >= 90) cout << "passed";
    else cout << "need " << (90 - n) << " more score";
    return 0;
}