#include <iostream>
#include <cmath>

using namespace std;

int a, b;
int dp[31][31];

void clear()
{
    for(int i=a; i<=b; i++)
    {
        for(int j=a; j<=b; j++) dp[i][j] = 0;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b;
    if(a > b) 
    {
        int temp = a;
        a = b;
        b = temp;
    }

    clear();

    for(int i=a; i<=b; i++)
    {
        dp[a][i] = 1;
    }

    for(int y=a; y<=b; y++)
    {
        for(int x=a; x<=b; x++)
        {
            dp[x][y+1] += dp[x][y];
            if(y <= x) dp[x+1][y] += dp[x][y];
        }
    }
    cout << dp[b][b];


    return 0;
}