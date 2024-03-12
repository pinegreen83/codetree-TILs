#include <iostream>
#include <set>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, a;
    cin >> n >> m;
    set<int> s;
    for(int i=1; i<=m; i++) s.insert(i);

    for(int i=0; i<n; i++)
    {
        cin >> a;
        s.erase(a);
        cout << *s.rbegin() << endl;
    }

    return 0;
}