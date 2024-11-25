#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    int cnt = 1;
    for(int i=0; i<n; i++) {
        int temp[m] = {};
        if(i % 2 == 0) {
            for(int j=0; j<m; j++) {
                temp[j] = cnt++;
            }
        }
        else {
            for(int j=m-1; j>=0; j--) {
                temp[j] = cnt++;
            }
        }
        for(auto te : temp) cout << te << " ";
        cout << "\n";
    }

    return 0;
}