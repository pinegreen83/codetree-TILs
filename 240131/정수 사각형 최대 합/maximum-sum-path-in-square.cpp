#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> map[i][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i > 0)
            {
                map[i][j] += max(map[i-1][j], map[i][j-1]);
            }
            else
            {
                map[i][j] += map[i][j-1];
            }
        }
    }

    cout << map[n-1][n-1];

    return 0;
}