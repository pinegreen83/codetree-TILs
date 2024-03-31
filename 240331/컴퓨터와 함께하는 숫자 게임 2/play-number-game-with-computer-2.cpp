#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

long m, minnum = INT_MAX, maxnum = INT_MIN;

void binary(long now)
{
    long left = 1, right = m, cnt = 0;
    while(left <= right)
    {
        long mid = (left + right) / 2;
        if(mid > now) right = mid - 1;
        else left = mid + 1;
        cnt++;
        if(mid == now) break;
    }
    minnum = min(minnum, cnt);
    maxnum = max(maxnum, cnt);
}

int main() {
    // 여기에 코드를 작성해주세요.
    long a, b;
    cin >> m >> a >> b;

    for(long i=a; i<=b; i++)
    {
        binary(i);
    }
    cout << minnum << " " << maxnum;

    return 0;
}