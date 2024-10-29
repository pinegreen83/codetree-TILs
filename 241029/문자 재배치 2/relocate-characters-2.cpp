#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    char now[n];
    for(int i=0; i<n; i++) {
        cin >> now[i];
    }
    
    for(int i=n-1; i>=0; i--) cout << now[i] << " ";

    return 0;
}