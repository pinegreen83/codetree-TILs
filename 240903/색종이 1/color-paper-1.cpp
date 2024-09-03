#include <iostream>

using namespace std;

int map[101][101] = {}, ans = 0;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, s, e;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> s >> e;

        for(int j=s+1; j<=s+10; j++) {
            for(int k=e+1; k<=e+10; k++) map[j][k] = 1;
        }
    }

    for(int i=1; i<=100; i++) {
        for(int j=1; j<=100; j++) {
            if(map[i][j] == 1) ans++;
        }
    }
    cout << ans;

    return 0;
}