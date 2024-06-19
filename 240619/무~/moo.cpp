#include <iostream>
#include <string>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    int mid = 3, sum = 3, cnt = 0;

    while (sum < n)
    {
        mid++;
        cnt++;
        sum = sum*2 + mid;
    }

    bool calc = false;
    while(cnt > 0)
    {
        cnt--;
        sum -= mid;
        sum /= 2;
        if(n <= sum) 
        {  
            mid--;
            continue;
        }
        else if(sum < n && n <= sum + mid)
        {
            calc = true;
            if(n == sum + 1) cout << "m";
            else cout << "o";
            break;
        }
        else if(sum + mid < n && n <= sum*2 + mid) n -= (sum + mid);
        mid--;
    }
    if(!calc)
    {
        if(n == 1) cout << "m";
        else cout << "o";
    }

    return 0;
}