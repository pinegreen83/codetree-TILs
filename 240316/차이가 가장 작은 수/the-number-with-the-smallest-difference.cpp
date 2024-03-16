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
        int large;
        if(s.find(a+m) == s.end())
        {
            large = *s.upper_bound(a+m);
        }
        else
        {
            large = a+m;
        }
        int small = *s.lower_bound(a-m);
        if(large-a >= m) answer = min(answer, large-a);
        if(a-small >= m) answer = min(answer, a-small);
        s.insert(a);
    }
    cout << (answer == INT_MAX ? -1 : answer) ;

    return 0;
}