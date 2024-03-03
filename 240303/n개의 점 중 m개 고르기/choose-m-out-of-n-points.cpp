#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int answer = INT_MAX;
vector<int> comb;
vector<vector<int>> points;
vector<vector<int>> map;

void perm(int cnt, int start, int maxpoint)
{
    if(start == n)
    {
        if(cnt == m)
        {
            answer = min(answer, maxpoint);
        }
        return;
    }
    
    int temp = maxpoint;
    for(auto& c : comb)
    {
        if(map[start][c] > temp) temp = map[start][c];
    }
    comb.push_back(start);
    perm(cnt+1, start+1, temp);
    comb.pop_back();
    perm(cnt, start+1, maxpoint);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        vector<int> temp(2);
        cin >> temp[0] >> temp[1];
        points.push_back(temp);
    }

    map = vector<vector<int>>(n, vector<int>(n));
    for(int i=0; i<n; i++)
    {
        vector<int> now = points[i];
        for(int j=0; j<n; j++)
        {
            if(i==j) continue;
            int x = now[0] - points[j][0];
            int y = now[1] - points[j][1];
            map[i][j] = x * x + y * y;
        }
    }
    
    perm(0, 0, 0);
    cout << answer;

    return 0;
}