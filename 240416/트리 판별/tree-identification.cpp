#include <iostream>
#include <vector>

#define MAX_N 10000

using namespace std;

int root = 0, cnt = 0;
vector<int> parents[MAX_N + 1];

void DFS(int start)
{
    int now = start;
    vector<bool> visited(MAX_N+1);
    visited[now] = true;
    while(parents[now].size() == 1)
    {
        int temp = parents[now][0];
        if(!visited[temp]) now = temp;
        else break;
    }
    if(start != now)
    {
        if(root == 0)
        {
            root = now;
            cnt++;
        }
        else if(root == now) cnt++;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int m;
    cin >> m;
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        parents[b].push_back(a);
    }

    for(int i=1; i<=MAX_N; i++)
    {
        DFS(i);
    }
    cout << (cnt == m ? 1 : 0);

    return 0;
}