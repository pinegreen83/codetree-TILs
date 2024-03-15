#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, a;
    cin >> n >> m;
    unordered_set<int> groupa;
    for(int i=0; i<n; i++)
    {
        cin >> a;
        groupa.insert(a);
    }

    unordered_set<int> groupb;
    for(int i=0; i<m; i++)
    {
        cin >> a;
        groupb.insert(a);
    }

    unordered_set<int> total;
    unordered_set<int>::iterator it;
    for(it=groupa.begin(); it!=groupa.end(); it++)
    {
        if(groupb.find(*it) == groupb.end()) total.insert(*it);
    }

    for(it=groupb.begin(); it!=groupb.end(); it++)
    {
        if(groupa.find(*it) == groupa.end()) total.insert(*it);
    }

    cout << total.size();

    return 0;
}