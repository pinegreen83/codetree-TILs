#include <iostream>
#include <string>

using namespace std;

int tsize;
string s, t;

bool check()
{
    string ss = "";
    for(int i=0; i<s.size(); i++)
    {
        string temp = s.substr(i, tsize);
        if(temp == t)
        {
            string now = s.substr(i+tsize, s.size()-i);
            ss += now;
            swap(s, ss);
            return true;
        }
        else ss += s[i];
    }
    return false;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> s >> t;
    tsize = t.size();

    while(true)
    {
        if(!check()) break;
    }
    cout << s;

    return 0;
}