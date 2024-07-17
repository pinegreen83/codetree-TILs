#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    string ans;
    for(int i=0; i<n; i++)
    {
        if(i%2 == 0)
        {
            if(i == n-1)
            {
                ans += "3";
            }
            else ans += "1 ";
        }
        else ans += "2 ";
    }
    cout << ans;

    return 0;
}