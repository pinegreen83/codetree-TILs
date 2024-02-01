#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<vector<int>> map(n, vector<int>(n));
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> map[i][j];
        }
    }

    int start, end;
    cin >> start >> end;

    for(int i=0; i<4; i++)
    {
        int dirx = start-1;
        int diry = end-1;
        for(int j=1; j<map[start-1][end-1]; j++)
        {
            dirx += dir[i][0];
            diry += dir[i][1];
            if(0 <= dirx && dirx < n && 0 <= diry && diry < n)
            {
                map[dirx][diry] = 0;
            }
            else break;
        }
    }
    map[start-1][end-1] = 0;

    vector<vector<int>> temp(n, vector<int>(n));
    for(int i=0; i<n; i++)
    {
        int tempnum = n-1;
        for(int j=n-1; j>=0; j--)
        {
            if(map[j][i])
            {
                temp[tempnum][i] = map[j][i];
                tempnum--;
            }
        }
    }
    map = temp;

    for(auto a : map)
    {
        for(auto i : a)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}