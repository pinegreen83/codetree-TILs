#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int a, b;
    cin >> a >> b;

    switch(b) {
        case 1:
            for(int i=1; i<=a/2+1; i++) {
                for(int j=1; j<=i; j++) cout << '*';
                for(int j=1; j<=a/2-i; j++) cout << ' ';
                cout << "\n";
            }
            for(int i=a/2; i>=1; i--) {
                for(int j=1; j<=i; j++) cout << '*';
                for(int j=1; j<=a/2-i; j++) cout << ' ';
                cout << "\n";
            }
            break;
        case 2:
            for(int i=1; i<=a/2+1; i++) {
                for(int j=1; j<=a/2+1-i; j++) cout << ' ';
                for(int j=1; j<=i; j++) cout << '*';
                cout << "\n";
            }
            for(int i=a/2; i>=1; i--) {
                for(int j=1; j<=a/2+1-i; j++) cout << ' ';
                for(int j=1; j<=i; j++) cout << '*';
                cout << "\n";
            }
            break;
        case 3:
            for(int i=0; i<a/2; i++) {
                for(int j=0; j<i; j++) cout << ' ';
                for(int j=1; j<=a-2*i; j++) cout << '*';
                for(int j=0; j<i; j++) cout << ' ';
                cout << '\n';
            }
            for(int i=a/2; i>=0; i--) {
                for(int j=0; j<i; j++) cout << ' ';
                for(int j=1; j<=a-2*i; j++) cout << '*';
                for(int j=0; j<i; j++) cout << ' ';
                cout << '\n';
            }
            break;
        case 4:
            for(int i=0; i<a/2; i++) {
                for(int j=0; j<i; j++) cout << ' ';
                for(int j=0; j<=a/2-i; j++) cout << '*';
                cout << '\n';
            }
            for(int i=1; i<=a/2+1; i++) {
                for(int j=0; j<a/2; j++) cout << ' ';
                for(int j=1; j<=i; j++) cout << '*';
                cout << '\n';
            }
            break;
    }

    return 0;
}