#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<int> machine(m);
    for(int i=0; i<m; i++) cin >> machine[i];

    unordered_set<int> uset;
    for(int i=0; i<m; i++)
    {
        uset.insert(machine[i]);
        for(int j=i+1; j<m; j++)
        {
            uset.insert(machine[i] + machine[j]);
        }
    }
    
    vector<int> result;
    unordered_set<int>::iterator iter;
    for(iter=uset.begin(); iter!=uset.end(); iter++)
    {
        result.push_back(*iter);
    }

    sort(result.rbegin(), result.rend());

    int ans = 0;
    bool finish = false;
    vector<bool> visited(n+1);
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while(!q.empty() && !finish)
    {
        int now = q.front().first, step = q.front().second;
        q.pop();

        for(int i=0; i<result.size(); i++)
        {
            int next = now + result[i];
            if(next == n)
            {
                ans = step + 1;
                finish = true;
                break;
            }
            if(next < n && !visited[next])
            {
                visited[next] = true;
                q.push(make_pair(next, step+1));
            }
        }
    }
    cout << ans;

    return 0;
}