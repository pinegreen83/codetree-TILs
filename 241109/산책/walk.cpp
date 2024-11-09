#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

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

    long long ans = 1;
    for(auto um : umap) {
        ans *= um.second.size();
    }

    cout << ans - 1;

    return 0;
}