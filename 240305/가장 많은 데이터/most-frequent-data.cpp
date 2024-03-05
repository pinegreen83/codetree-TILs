#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, answer = 0;
    cin >> n;
    unordered_map<string, int> umap;
    string a;
    for(int i=0; i<n; i++)
    {
        cin >> a;
        if(umap.find(a) == umap.end()) umap[a] = 1;
        else umap[a]++;
        answer = max(answer, umap[a]);
    }

    cout << answer;

    return 0;
}