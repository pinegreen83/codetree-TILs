#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string expr;
    cin >> expr;

    stringstream ss(expr);
    string temp;
    int ans = 0;
    bool isplus = true;

    while(getline(ss, temp, '-'))
    {
        stringstream ss2(temp);
        string temp2;

        int now = 0;
        while(getline(ss2, temp2, '+'))
        {
            now += stoi(temp2);
        }

        if(isplus)
        {
            ans += now;
            isplus = false;
        }
        else 
        {
            ans -= now;
        }
    }
    cout << ans;

    return 0;
}