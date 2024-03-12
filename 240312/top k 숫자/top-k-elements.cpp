#include <iostream>
#include <set>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k, a;
    cin >> n >> k;
    set<int> s;
    for(int i=0; i<n; i++)
    {
        cin >> a;
        s.insert(a);
    }

    set<int>::iterator it = s.end();

    for(int i=0; i<k; i++)
    {
        it--;
        cout << *it << " ";
    }

    return 0;
}