#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> map(n, vector<char>(m));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++) cin >> map[i][j];
    }

    for(int i=0; i<n; i++)
    {
        string now = "";
        for(int j=0; j<m; j++)
        {
            for(int c=0; c<k; c++) now += map[i][j];
        }
        now += '\n';
        for(int c=0; c<k; c++) cout << now;
    }

    return 0;
}