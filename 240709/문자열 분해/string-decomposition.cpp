#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin >> str;

    vector<bool> check(str.size());
    int ans = 0;
    bool finish = true;
    while(finish)
    {
        int idx = 0, cnt = 0;
        string now = "";
        for(int i=0; i<str.size(); i++)
        {
            if(!check[i] && str[i] == 'a'+idx)
            {
                check[i] = true;
                now += str[i];
                idx++;
                if(idx == 5) 
                {
                    idx = 0;
                    cnt++;
                }
            }
            else now += '_';
        }
        if(cnt == 0) finish = false;
        else ans++;
    }
    bool use = true;
    for(int i=0; i<str.size(); i++) use = check[i];
    if(!use) cout << -1;
    else cout << (ans == 0 ? -1 : ans);

    return 0;
}