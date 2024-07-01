#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    bool check[1001] = {false};

    set<int> primes;
    for(int i=2; i*i<sqrt(1000); i++)
    {
        if(check[i]) continue;
        for(int j=i+i; j<=1000; j+=i)
        {
            check[j] = true;
        }
    }

    for(int i=2; i<=1000; i++)
    {
        if(!check[i]) primes.insert(i);
    }

    int n, ans = 0;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int now;
        cin >> now;
        if(primes.find(now) != primes.end()) ans++;
    }
    cout << ans;

    return 0;
}