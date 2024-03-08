#include <iostream>
#include <map>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    map<string, int> m;
    for(int i=0; i<n; i++)
    {
        string a;
        cin >> a;
        m[a]++;
    }

    for(map<string, int>::iterator iter=m.begin(); iter!=m.end(); iter++)
    {
        cout << iter->first << " " << iter->second << endl;
    }

    return 0;
}