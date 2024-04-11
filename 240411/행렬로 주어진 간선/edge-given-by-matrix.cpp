#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<vector<int>> maps(n, vector<int>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> maps[i][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        maps[i][i] = 1;
    }

    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(maps[i][k] == 1 && maps[k][j] == 1) maps[i][j] = 1;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++) cout << maps[i][j] << " ";
        cout << "\n";
    }

    return 0;
}