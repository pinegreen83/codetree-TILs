#include <iostream>
#include <set>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, a;
    cin >> n >> m;
    set<int> s;

    for(int i=0; i<n; i++)
    {
        cin >> a;
        s.insert(a);
    }

    for(int i=0; i<m; i++)
    {
        cin >> a;
        if(s.find(a) != s.end()) cout << a << endl;
        else 
        {
            if(s.lower_bound(a) != s.end()) cout << *s.lower_bound(a) << endl;
            else cout << -1 << endl;
        }
    }

    return 0;
}