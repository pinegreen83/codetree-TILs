#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, ans = 0;
    unordered_map<string, int> umap;
    cin >> n;
    string a;
    for(int i=0; i<n; i++)
    {
        cin >> a;
        map<char, int> cmap;
        for(int j=0; j<a.size(); j++)
        {
            cmap[a[j]]++;
        }

        string temp;
        map<char, int>::iterator iter;
        for(iter=cmap.begin(); iter!=cmap.end(); iter++)
        {
            temp.push_back(iter->first);
            temp += to_string(iter->second);
        }
        umap[temp]++;
    }

    unordered_map<string, int>::iterator uiter;
    for(uiter=umap.begin(); uiter!=umap.end(); uiter++)
    {
        ans = max(ans, uiter->second);
    }
    cout << ans;

    return 0;
}