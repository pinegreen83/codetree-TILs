#include <iostream>
#include <set>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, x, y;
    cin >> n >> m;

    set<pair<int, int>> s;
    for(int i=0; i<n; i++)
    {
        cin >> x >> y;
        s.insert(make_pair(x, y));
    }

    for(int i=0; i<m; i++)
    {
        cin >> x >> y;
        if(s.lower_bound(make_pair(x, y)) != s.end()) 
        {
            pair<int, int> temp = *s.lower_bound(make_pair(x, y));
            cout << temp.first << " " << temp.second << endl;
        }
        else cout << -1 << " " << -1 << endl;
    }

    return 0;
}