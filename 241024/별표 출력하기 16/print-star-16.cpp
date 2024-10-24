#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        string now;
        int calc = (n-i) * (n-i);
        for(int j=1; j<=(n*n - calc); j++) {
            now += " ";
        }
        for(int j=1; j<=calc; j++) {
            now += "*";
        }
        now += "\n";
        cout << now;
    }

    return 0;
}