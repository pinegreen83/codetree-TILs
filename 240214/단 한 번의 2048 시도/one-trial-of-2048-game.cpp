#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    vector<vector<int>> map(4, vector<int>(4));
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cin >> map[i][j];
        }
    }

    char dir;
    cin >> dir;

    switch(dir)
    {
        case 'L':
            for(int i=0; i<4; i++)
            {
                vector<int> temp;
                queue<int> q;
                for(int j=0; j<4; j++)
                {
                    if(!map[i][j]) continue;
                    else q.push(map[i][j]);
                }
                while(!q.empty())
                {
                    int now = q.front();
                    q.pop();
                    if(now == q.front())
                    {
                        now *= 2;
                        q.pop();
                    }
                    temp.push_back(now);
                }
                while(temp.size() < 4)
                {
                    temp.push_back(0);
                }
                for(int j=0; j<4; j++)
                {
                    map[i][j] = temp[j];
                }
            }
            break;
        case 'R':
            for(int i=0; i<4; i++)
            {
                vector<int> temp;
                queue<int> q;
                for(int j=3; j>=0; j--)
                {
                    if(!map[i][j]) continue;
                    else q.push(map[i][j]);
                }
                while(!q.empty())
                {
                    int now = q.front();
                    q.pop();
                    if(now == q.front())
                    {
                        now *= 2;
                        q.pop();
                    }
                    temp.push_back(now);
                }
                while(temp.size() < 4)
                {
                    temp.push_back(0);
                }
                for(int j=0; j<4; j++)
                {
                    map[i][j] = temp[3-j];
                }
            }
            break;
        case 'U':
            for(int i=0; i<4; i++)
            {
                vector<int> temp;
                queue<int> q;
                for(int j=0; j<4; j++)
                {
                    if(!map[j][i]) continue;
                    else q.push(map[j][i]);
                }
                while(!q.empty())
                {
                    int now = q.front();
                    q.pop();
                    if(now == q.front())
                    {
                        now *= 2;
                        q.pop();
                    }
                    temp.push_back(now);
                }
                while(temp.size() < 4)
                {
                    temp.push_back(0);
                }
                for(int j=0; j<4; j++)
                {
                    map[j][i] = temp[j];
                }
            }
            break;
        case 'D':
            for(int i=0; i<4; i++)
            {
                vector<int> temp;
                queue<int> q;
                for(int j=3; j>=0; j--)
                {
                    if(!map[j][i]) continue;
                    else q.push(map[j][i]);
                }
                while(!q.empty())
                {
                    int now = q.front();
                    q.pop();
                    if(now == q.front())
                    {
                        now *= 2;
                        q.pop();
                    }
                    temp.push_back(now);
                }
                while(temp.size() < 4)
                {
                    temp.push_back(0);
                }
                for(int j=3; j>=0; j--)
                {
                    map[j][i] = temp[3-j];
                }
            }
            break;
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