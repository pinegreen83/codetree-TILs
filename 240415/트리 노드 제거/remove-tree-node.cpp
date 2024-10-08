#include <iostream>
#include <vector>

using namespace std;

int ans = 0;
vector<vector<int>> edges;

void DFS(int now)
{
    if(edges[now].size() == 0) ans++;
    else
    {
        for(int i=0; i<edges[now].size(); i++)
        {
            DFS(edges[now][i]);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, root;
    cin >> n;
    vector<int> parents(n+1);
    edges = vector<vector<int>>(n+1);
    for(int i=0; i<n; i++)
    {
        cin >> parents[i];
        if(parents[i] != -1) edges[parents[i]].push_back(i);
        else root = i;
    }

    int del, dparent;
    cin >> del;
    if(del != root)
    {
        dparent = parents[del];
        for(int i=0; i<edges[dparent].size(); i++)
        {
            if(edges[dparent][i] == del)
            {
                edges[dparent].erase(edges[dparent].begin() + i);
                break;
            }
        }
        
        DFS(root);
    }
    cout << ans;
    

    return 0;
}