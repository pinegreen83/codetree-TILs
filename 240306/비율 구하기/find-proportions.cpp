#include <iostream>
#include <map>

using namespace std;
int n;
map<string, int> m;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    string a;
    for(int i=0; i<n; i++)
    {
        cin >> a;
        if(m.find(a) == m.end()) m.insert(make_pair(a, 1));
        else m[a]++;
    }

    map<string, int>::iterator iter;
    for(iter=m.begin(); iter!=m.end(); iter++)
    {
        float per = (float) (iter->second * 100) / n;
        cout << fixed;
        cout.precision(4);
        cout << iter->first << " " << per << endl;
    }

    return 0;
}