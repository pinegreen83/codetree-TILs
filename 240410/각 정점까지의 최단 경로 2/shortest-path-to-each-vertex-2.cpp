#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<vector<int>> maps(n+1, vector<int>(n+1, 1e9));
    for(int i=1; i<=n; i++)
    {
        maps[i][i] = 0;
    }

    for(int i=0; i<m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        maps[a][b] = min(maps[a][b], c);
    }

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                maps[i][j] = min(maps[i][j], maps[i][k] + maps[k][j]);
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(maps[i][j] == 1e9) cout << -1 << " ";
            else cout << maps[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}