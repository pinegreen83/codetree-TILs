#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    unordered_set<int> uset;
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        uset.insert(a);
    }

    int m;
    cin >> m;
    for(int i=0; i<m; i++)
    {
        int b;
        cin >> b;
        if(uset.find(b) != uset.end()) cout << 1 << " ";
        else cout << 0 << " ";
    }

    return 0;
}