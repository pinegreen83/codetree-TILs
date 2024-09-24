#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, a, i, x;
    cin >> n >> m;

    vector<vector<int>> arrs(n+1, vector<int>(21, 2));
    while(m--)
    {
        cin >> a >> i;
        switch(a)
        {
            case 1:
                cin >> x;
                arrs[i][x] = 1;
                break;
            case 2:
                cin >> x;
                arrs[i][x] = 0;
                break;
            case 3:
                for(int j=1; j<=20; j++) {
                    if(arrs[i][j] == 1) {
                        if(j != 20) {
                            arrs[i][j+1] = 1;
                        }
                        arrs[i][j] = 2;
                    }
                }
                break;
            case 4:
                for(int j=1; j<=20; j++) {
                    if(arrs[i][j] == 1) {
                        if(j != 1) {
                            arrs[i][j-1] = 1;
                        }
                        arrs[i][j] = 2;
                    }
                }
                break;
        }
    }

    unordered_set<string> uset;
    for(int i=1; i<=n; i++) {
        string temp = "";
        for(int j=1; j<=20; j++) {
            temp += (arrs[i][j] + '0');
        }
        uset.insert(temp);
    }
    cout << uset.size();

    return 0;
}