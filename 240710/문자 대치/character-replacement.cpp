#include <iostream>
#include <set>

using namespace std;

int str_size;
string str;
set<string> ss;

void change(int start, string now)
{
    if(start == str_size)
    {
        ss.insert(now);
        return;
    }

    if(str[start] == '.') change(start+1, now+".");
    else
    {
        int cnt = 0;
        while(start + cnt < str_size && cnt <= 4)
        {
            if(str[start+cnt] != 'X') break;
            cnt++;
        }
        if(cnt >= 4) change(start+4, now+"aaaa");
        if(cnt >= 2) change(start+2, now+"bb");
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> str;

    str_size = str.size();
    change(0, "");
    if(ss.size() > 0)
    {
        set<string>::iterator iter;
        iter = ss.begin();
        cout << *iter;
    }
    else cout << -1;

    return 0;
}