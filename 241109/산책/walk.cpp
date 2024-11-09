#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int ans = 0;
vector<int> comb;

void DFS(int idx, vector<int>& clothes) {
    if(idx == clothes.size()) {
        int cnt = 0;
        for(int i=0; i<clothes.size(); i++) {
            if(comb[i] != 0) cnt++;
        }
        if(cnt != 0) ans++;
        return;
    }

    for(int i=0; i<clothes[idx]; i++) {
        comb.push_back(i);
        DFS(idx+1, clothes);
        comb.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    unordered_map<string, vector<string>> umap;
    for(int i=0; i<n; i++) {
        string a, b;
        cin >> a >> b;

        if(umap.find(b) == umap.end()) {
            string temp = "no " + b;
            umap[b].push_back(temp);
            umap[b].push_back(a);
        }
        else umap[b].push_back(a);
    }

    vector<int> clothes;
    for(auto um : umap) {
        clothes.push_back(um.second.size());
    }

    DFS(0, clothes);
    cout << ans;

    return 0;
}