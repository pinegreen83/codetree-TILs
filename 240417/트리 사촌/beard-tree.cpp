#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k, root;
    cin >> n >> k >> root;
    
    vector<vector<int>> nodes;
    vector<int> tree = {root}, temp = {root};
    int before = root;
    for(int i=1; i<n; i++)
    {
        int a;
        cin >> a;
        if(a == before + 1) temp.push_back(a);
        else
        {
            nodes.push_back(temp);
            temp.clear();
            temp.push_back(a);
        }
        before = a;
        tree.push_back(a);
    }
    nodes.push_back(temp);

    map<int, vector<int>> treem;
    map<int, int> parents;
    parents[root] = 0;
    for(int i=0; i<nodes.size()-1; i++)
    {
        int parent = tree[i];
        treem[parent] = nodes[i+1];
        for(int j=0; j<nodes[i+1].size(); j++)
        {
            parents[nodes[i+1][j]] = parent;
        }
    }

    int first = parents[k], ans = 0;
    if(first != 0)
    {
        int second = parents[first];
        if(second != 0)
        {
            vector<int> temp = treem[second];
            for(int i=0; i<temp.size(); i++)
            {
                if(temp[i] != first)
                {
                    ans += treem[temp[i]].size();
                }
            }
        }
    }
    cout << ans;

    return 0;
}