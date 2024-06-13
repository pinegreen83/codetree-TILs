#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    unordered_map<string, int> umap;

    for(int i=0; i<n; i++)
    {
        vector<string> names(3);
        for(int j=0; j<3; j++) cin >> names[j];
        sort(names.begin(), names.end());
        string last = "";
        for(int j=0; j<3; j++) last += names[j] + " ";
        umap[last] += 1;
    }

    int ans = 0;
    for(auto u : umap) ans = max(ans, u.second);
    cout << ans;

    return 0;
}