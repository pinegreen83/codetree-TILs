#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, cnt = 0;
    string start, goal;
    cin >> n >> start >> goal;

    for(int i=n-1; i>=0; i--)
    {
        if(cnt % 2 == 0)
        {
            if(start[i] != goal[i]) cnt++;
        }
        else
        {
            if(start[i] == goal[i]) cnt++;
        }
    }
    cout << cnt;

    return 0;
}