#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    int maxnum = -1001;

    int before = 0;
    int now;
    for(int i=0; i<n; i++)
    {
        cin >> now;
        if(before + now < now) before = now;
        else before += now;
        if(maxnum < before) maxnum = before;
    }

    cout << maxnum;

    return 0;
}