#include <iostream>
#include <vector>

#define MAX_N 100000;

using namespace std;

int cnt = 0;
vector<int> dist;
vector<vector<int>> child;

void DFS(int start, int h)
{
    dist[start] = h;
    for(int i=0; i<child[start].size(); i++)
    {
        DFS(child[start][i], h+1);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    dist = vector<int>(n+1);
    child = vector<vector<int>>(n+1);
    for(int i=1; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        child[a].push_back(b);
    }

    DFS(1, 0);

    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        if(child[i].size() == 0) ans += dist[i];
    }
    cout << ans%2;

    return 0;
}