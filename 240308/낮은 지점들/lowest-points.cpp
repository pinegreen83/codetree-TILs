#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, x, y;
    cin >> n;

    unordered_map<int, int> umap;
    for(int i=0; i<n; i++)
    {
        cin >> x >> y;
        if(umap.find(x) == umap.end()) umap[x] = y;
        else
        {
            if(umap[x] > y) umap[x] = y;
        }
    }

    int ans = 0;
    unordered_map<int, int>::iterator iter;
    for(iter=umap.begin(); iter!=umap.end(); iter++)
    {
        ans += iter->second;
    }
    cout << ans;

    return 0;
}