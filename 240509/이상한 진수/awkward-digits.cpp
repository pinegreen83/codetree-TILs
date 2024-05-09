#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string a, b;
    cin >> a >> b;

    long long num, now = 1;
    unordered_set<long long> uset;
    for(int i=a.size()-1; i>=0; i--)
    {
        num = 0;
        string nump = a;
        now = 1;
        if(a[i] == '0')
        {
            nump[i] = '1';
            for(int i=a.size()-1; i>=0; i--)
            {
                num += now * (nump[i] - '0');
                now *= 2;
            }
        }
        else
        {
            nump[i] = '0';
            for(int i=a.size()-1; i>=0; i--)
            {
                num += now * (nump[i] - '0');
                now *= 2;
            }
        }
        uset.insert(num);
    }

    for(int i=b.size()-1; i>=0; i--)
    {
        num = 0;
        string nump = b;
        now = 1;
        if(b[i] == '0')
        {
            nump[i] = '1';
            for(int i=b.size()-1; i>=0; i--)
            {
                num += now * (nump[i] - '0');
                now *= 3;
            }
            if(uset.find(num) != uset.end()) cout << num;
            num = 0;
            string nump = b;
            now = 1;
            nump[i] = '2';
            for(int i=b.size()-1; i>=0; i--)
            {
                num += now * (nump[i] - '0');
                now *= 3;
            }
        }
        else if(b[i] == '1')
        {
            nump[i] = '0';
            for(int i=b.size()-1; i>=0; i--)
            {
                num += now * (nump[i] - '0');
                now *= 3;
            }
            if(uset.find(num) != uset.end()) cout << num;
            num = 0;
            string nump = b;
            now = 1;
            nump[i] = '2';
            for(int i=b.size()-1; i>=0; i--)
            {
                num += now * (nump[i] - '0');
                now *= 3;
            }
        }
        else
        {
            nump[i] = '0';
            for(int i=b.size()-1; i>=0; i--)
            {
                num += now * (nump[i] - '0');
                now *= 3;
            }
            if(uset.find(num) != uset.end()) cout << num;
            num = 0;
            string nump = b;
            now = 1;
            nump[i] = '1';
            for(int i=b.size()-1; i>=0; i--)
            {
                num += now * (nump[i] - '0');
                now *= 3;
            }
        }
        if(uset.find(num) != uset.end()) cout << num;
    }

    return 0;
}