#include <iostream>
#include <unordered_map>

#define MAX_NUM 100000

using namespace std;
string strs[MAX_NUM+1];
unordered_map<string, int> umap;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    string a;
    for(int i=1; i<=n; i++)
    {
        cin >> a;
        strs[i] = a;
        umap[a] = i;
    }

    for(int i=0; i<m; i++)
    {
        cin >> a;
        if('0' <= a[0] && a[0] <= '9')
        {
            int temp = stoi(a);
            cout << strs[temp] << endl;
        }
        else
        {
            cout << umap[a] << endl;
        }
    }

    return 0;
}