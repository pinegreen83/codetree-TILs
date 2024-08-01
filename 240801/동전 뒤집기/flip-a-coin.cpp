#include <iostream>

using namespace std;

int n, m;
int map[101][101];

void flip(int x, int y)
{
    for(int i=1; i<=x; i++)
    {
        for(int j=1; j<=y; j++)
        {
            if(map[i][j]) map[i][j] = 0;
            else map[i][j] = 1;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) cin >> map[i][j];
    }

    int ans = 0, N = n, M = m;
    while(N > 0 || M > 0)
    {
        for(int i=N; i>=1; i--)
        {
            if(map[i][M] == 1) 
            {
                ans++;
                flip(i, M);
            }
        }

        for(int i=M; i>=1; i--)
        {
            if(map[N][i] == 1) 
            {
                ans++;
                flip(N, i);
            }
        }
        N--;
        M--;
    }
    cout << ans;

    return 0;
}