#include <iostream>
#include <string>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin >> str;

    string maxnum = "";
    string minnum = "";
    int m_cnt = 0;
    for(char c : str) {
        if(c == 'M') {
            m_cnt++;
        }
        else if(c == 'K') {
            if(m_cnt > 0) {
                maxnum += "5";
                maxnum += string(m_cnt, '0');

                minnum += "1";
                if(m_cnt > 1) {
                    minnum += string(m_cnt-1, '0');
                }
                minnum += "5";

                m_cnt = 0;
            }
            else {
                maxnum += "5";
                minnum += "5";
            }
        }
    }
    if(m_cnt > 0) {
        maxnum += "1";
        minnum += "1";
        if(m_cnt > 1) maxnum += string(m_cnt - 1, '1');
        if(m_cnt > 1) minnum += string(m_cnt - 1, '0');
    }
    cout << maxnum << "\n" << minnum;

    return 0;
}