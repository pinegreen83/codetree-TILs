#include <iostream>

using namespace std;

int n;
long ispara(long x)
{
    return x - (x / 3) - (x / 5) + (x / 15);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    long left = 1, right = n*15, ans = n*15;
    
    while(left <= right)
    {
        long mid = (left + right) / 2;
        long cal = ispara(mid);
        if(cal >= n) 
        {
            right = mid -1;
            ans = min(ans, mid);
        }
        else left = mid + 1;
    }
    cout << ans;

    return 0;
}