#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    unordered_map<int, int> umap;
    int a;
    for(int i=0; i<n; i++)
    {
        cin >> a;
        if(umap.find(a) != umap.end()) umap[a]++;
        else umap[a] = 1;
    }

    for(int i=0; i<m; i++)
    {
        cin >> a;
        if(umap.find(a) == umap.end()) cout << 0 << " ";
        else cout << umap[a] << " ";
    }

    return 0;
}