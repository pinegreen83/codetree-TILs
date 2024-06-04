#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b;
    cin >> a >> b;

    bool comp = a > b;
    int move = 0, cnt = 1, before = a;
    while(true)
    {
        int now = a + cnt;
        if(!comp && now >= b) 
        {
            move += abs(before - b);
            break;
        }
        else if(comp && now <= b)
        {
            move += abs(before - b);
            break;
        }
        move += abs(before - now);
        before = now;
        cnt *= -2;
    }
    cout << move;

    return 0;
}