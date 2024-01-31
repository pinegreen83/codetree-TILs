#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    int answer = -1;
    cin >> n;
    vector<vector<int>> map(n+1, vector<int>(n+1));
    vector<vector<int>> move = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

    int start[2];
    int end[2];
    cin >> start[0] >> start[1] >> end[0] >> end[1];

    queue<pair<int, int>> q;
    q.push({start[0], start[1]});
    map[start[0]][start[1]] = 1;
    while(!q.empty())
    {
        pair<int, int> temp = q.front();
        if(temp.first == end[0] && temp.second == end[1]) answer = map[temp.first][temp.second];
        q.pop();
        for(int i=0; i<8; i++)
        {
            int dirx = temp.first + move[i][0];
            int diry = temp.second + move[i][1];
            if(1 <= dirx && dirx <= n && 1 <= diry && diry <= n)
            {
                if(!map[dirx][diry])
                {
                    q.push({dirx, diry});
                    map[dirx][diry] = map[temp.first][temp.second]+1;
                }
            }
        }
    }    

    cout << (answer == -1 ? answer : answer -1);

    return 0;
}