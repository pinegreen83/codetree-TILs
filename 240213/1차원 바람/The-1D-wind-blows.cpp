#include <iostream>
#include <vector>

using namespace std;

int n, m, q;
vector<vector<int>> map;

void wind(vector<int> blow, int line, char dir)
{
    vector<int> temp;
    switch(dir)
    {
        case 'L':
            temp.push_back(map[line][m-1]);
            for(int i=0; i<m-1; i++)
            {
                temp.push_back(map[line][i]);
            }
            break;
        case 'R':
            for(int i=1; i<m; i++)
            {
                temp.push_back(map[line][i]);
            }
            temp.push_back(map[line][0]);
            break;
    }
    map[line] = temp;

    for(int i=0; i<blow.size(); i++)
    {
        int newline = line+blow[i];
        if(0 <= newline && newline < n)
        {
            for(int j=0; j<m; j++)
            {
                if(map[line][j] == map[newline][j])
                {
                    if(dir == 'L') wind({blow[i]}, newline, 'R');
                    else wind({blow[i]}, newline, 'L');
                    break;
                }
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> q;

    int a;
    for(int i=0; i<n; i++)
    {
        vector<int> temp;
        for(int j=0; j<m; j++)
        {
            cin >> a;
            temp.push_back(a);
        }
        map.push_back(temp);
    }

    for(int i=0; i<q; i++)
    {
        int line;
        char dir;
        cin >> line >> dir;
        wind({-1, 1}, line-1, dir);
    }

    for(auto m : map)
    {
        for(auto i : m)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}