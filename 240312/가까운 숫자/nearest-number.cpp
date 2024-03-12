#include <iostream>
#include <set>
#include <climits>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, a, answer = INT_MAX;
    cin >> n;

    set<int> s;
    s.insert(0);
    set<int>::iterator it;
    
    for(int i=0; i<n; i++)
    {
        cin >> a;
        if(a > *s.rbegin())
        {
            answer = min(answer, a - *s.rbegin());
        }
        else
        {
            it = s.upper_bound(a);
            answer = min(answer, *it - a);
            it--;
            answer = min(answer, a - *it);
        }
        cout << answer << endl;
        s.insert(a);
    }

    return 0;
}