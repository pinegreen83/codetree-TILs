#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k, ans = 0;
    cin >> n >> k;
    unordered_map<int, int> umap;
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        if(umap.find(a) == umap.end()) umap[a] = i;
        else
        {
            if(i - umap[a] <= k) ans = max(ans, a);
            umap[a] = i;
        }
    }
    cout << ans;

    return 0;
}