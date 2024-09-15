#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        int temp = (n - i) * 2;
        while(temp--) {
            cout << '*';
        }
        cout << "\n";
    }

    for(int i=1; i<n; i++) {
        int temp = (i + 1) * 2;
        while(temp--) {
            cout << '*';
        }
        cout << "\n";
    }

    return 0;
}