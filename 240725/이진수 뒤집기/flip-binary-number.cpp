#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string str1, str2;
    cin >> str1 >> str2;

    int ch1 = 0, ch2 = 0, diff = 0;
    for(int i=0; i<str1.size(); i++)
    {
        if(str1[i] == '1') ch1++;
        if(str2[i] == '1') ch2++;
    }

    bool one = (ch1 > ch2);
    for(int i=0; i<str1.size(); i++)
    {
        if(one)
        {
            if(str2[i] == '1' && str1[i] != str2[i]) diff++;
        }
        else
        {
            if(str1[i] == '1' && str1[i] != str2[i]) diff++;
        }
    }
    int ans = (ch1 > ch2 ? ch1 - ch2 : ch2 - ch1);
    cout << ans + diff;

    return 0;
}