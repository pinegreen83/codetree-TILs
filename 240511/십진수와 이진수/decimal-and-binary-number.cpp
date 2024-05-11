#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string n;
    cin >> n;

    long long a = 1, goal = 0;
    for(int i=n.size()-1; i>=0; i--)
    {
        if(n[i] == '1')
        {
            goal += a;
        }
        a *= 2;
    }
    goal *= 17;
    string ans, temp;
    while(goal)
    {
        if(goal % 2 == 0) temp += '0';
        else temp+= '1';
        goal /= 2;
    }
    for(int i=temp.size()-1; i>=0; i--)
    {
        ans += temp[i];
    }
    cout << ans;
    return 0;
}