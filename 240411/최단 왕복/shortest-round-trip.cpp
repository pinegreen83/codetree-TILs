#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<vector<int>> maps(n+1, vector<int>(n+1, 1e9));
    for(int i=0; i<m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        maps[a][b] = c;
    }

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(maps[i][j] > maps[i][k] + maps[k][j]) maps[i][j] = maps[i][k] + maps[k][j];
            }
        }
    }

    int ans = 1e9;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i == j) continue;
            if(maps[i][j] != 1e9 && maps[j][i] != 1e9)
            {
                ans = min(ans, maps[i][j] + maps[j][i]);
            }
        }
    }
    cout << ans;
    
    return 0;
}