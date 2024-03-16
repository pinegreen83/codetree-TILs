#include <iostream>
#include <set>
#include <climits>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, a, answer = INT_MAX;
    cin >> n >> m;

    set<int> s;
    cin >> a;
    s.insert(a);
    for(int i=1; i<n; i++)
    {
        cin >> a;
        if(s.lower_bound(a+m) != s.end())
        {
            answer = min(answer, *s.lower_bound(a+m) - a);
        }
        set<int>::iterator it = s.upper_bound(a-m);
        if(it != s.begin())
        {
            it--;
            answer = min(answer, a - *it);
        }
        s.insert(a);
    }
    cout << (answer == INT_MAX ? -1 : answer) ;

    return 0;
}