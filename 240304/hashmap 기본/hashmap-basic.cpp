#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    unordered_map<int, int> umap;
    for(int i=0; i<n; i++)
    {
        string ord;
        cin >> ord;
        if(ord == "add")
        {
            int a, b;
            cin >> a >> b;
            if(umap.find(a) == umap.end()) umap.insert(make_pair(a, b));
            else umap[a] = b;
        }
        else if(ord == "find")
        {
            int a;
            cin >> a;
            if(umap.find(a) != umap.end()) cout << umap[a] << endl;
            else cout << "None" << endl;
        }
        else if(ord == "remove")
        {
            int a;
            cin >> a;
            if(umap.find(a) != umap.end()) umap.erase(a);
        }
    }

    return 0;
}