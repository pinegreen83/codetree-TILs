#include <iostream>
#include <set>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    set<pair<int, int>> s;
    for(int i=0; i<n; i++)
    {
        int x, y;
        cin >> x >> y;
        s.insert(make_pair(x, y));
    }


    for(int i=0; i<m; i++)
    {
        int x;
        cin >> x;
        pair<int, int> temp = {x, 0};

        if(s.upper_bound(temp) != s.end())
        {
            pair<int, int> now = *s.upper_bound(temp);
            cout << now.first << " " << now.second << endl;
            s.erase(now);
        }
        else
        {
            cout << -1 << " " << -1 << endl;
        }
    }

    return 0;
}