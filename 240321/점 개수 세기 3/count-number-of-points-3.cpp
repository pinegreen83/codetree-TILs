#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, q;
    cin >> n >> q;
    set<int> numset;
    unordered_map<int, int> umap;

    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        umap[a] = i;
        numset.insert(a);
    }

    while(q > 0)
    {
        int a, b;
        cin >> a >> b;
        int start = *numset.lower_bound(a);
        set<int>::iterator ends = numset.lower_bound(b);
        if(*ends > b) ends--;
        int end = *ends;
        cout << umap[end] - umap[start] + 1 << endl;
        q--;
    }

    return 0;
}