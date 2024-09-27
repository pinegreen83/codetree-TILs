#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<vector<int>> piramid(n+1, vector<int>(n+1, 0));
    piramid[1][1] = 2;

    for(int i=2; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            piramid[i][j] = piramid[i-1][j-1] + piramid[i-1][j];
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) cout << piramid[i][j] << " ";
        cout << "\n";
    }

    return 0;
}