#include <iostream>
#include <map>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    map<int, int> m;
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin >> x;
        if(m.find(x) == m.end()) m[x] = i;
    }

    map<int, int>::iterator iter;
    for(iter=m.begin(); iter!=m.end(); iter++)
    {
        cout << iter->first << " " << iter->second << endl;
    }

    return 0;
}