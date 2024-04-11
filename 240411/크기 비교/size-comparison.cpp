#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<vector<int>> maps(n+1, vector<int>(n+1));
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        maps[a][b] = 1;
    }

    for(int i=1; i<=n; i++) maps[i][i] = 1;

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(maps[i][k] && maps[k][j]) maps[i][j] = 1;
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        int cnt = 0;
        for(int j=1; j<=n; j++)
        {
            if(maps[i][j] || maps[j][i]) cnt++;
        }
        cout << n - cnt << "\n";
    }

    return 0;
}