#include <iostream>
#include <map>

using namespace std;
map<int, int> m;

void printline()
{
    if(m.empty()) cout << "None" << endl;
    else
    {
        map<int, int>::iterator it;
        for(it=m.begin(); it!=m.end(); it++)
        {
            cout << it -> second << " ";
        }
        cout << endl;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        string a;
        cin >> a;
        if(a == "add")
        {
            int b, c;
            cin >> b >> c;
            if(m.find(b) == m.end()) m.insert(make_pair(b, c));
            else m[b] = c;
        }
        else if(a == "remove")
        {
            int b;
            cin >> b;
            if(m.find(b) != m.end()) m.erase(b);
        }
        else if(a == "find")
        {
            int b;
            cin >> b;
            if(m.find(b) == m.end()) cout << "None" << endl;
            else cout << m[b] << endl;
        }
        else if(a == "print_list") printline();
    }

    return 0;
}