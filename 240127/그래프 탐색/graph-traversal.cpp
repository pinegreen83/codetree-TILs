#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

int N, M, answer;
vector<vector<int>> nodes;
vector<int> visited;

void dfs(int now)
{
    if(now != 1) answer++;
    visited[now] = 1;
    for(int i=0; i<nodes[now].size(); i++)
    {
        int temp = nodes[now][i];
        if(visited[temp]) continue;
        dfs(temp);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    answer = 0;
    cin >> N >> M;

    for(int i=0; i<=N; i++)
    {   
        vector<int> temp;
        nodes.push_back(temp);
    }
    
    for(int i=0; i<M; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        nodes[node1].push_back(node2);
        nodes[node2].push_back(node1);
    }

    for(int i=0; i<=N; i++)
    {
        visited.push_back(0);
    }

    dfs(1);
    cout << answer;

    return 0;
}