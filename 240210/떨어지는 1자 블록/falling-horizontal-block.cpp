#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> map(n, vector<int>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> map[i][j];
        }
    }

    bool check = true;
    int now = 0;
    while(check)
    {
        for(int i=k-1; i<k+m-1; i++)
        {
            if(map[now][i])
            {
                check = false;
                now--;
                break;
            }
        }
        if(check) now++;
    }

    for(int i=k-1; i<k+m-1; i++)
    {
        map[now][i] = 1;
    }

    for(auto m : map)
    {
        for(auto i : m)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}