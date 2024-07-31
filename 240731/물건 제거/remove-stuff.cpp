#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> machines(n);
    for(int i=0; i<n; i++) cin >> machines[i];
    sort(machines.begin(), machines.end());

    int k;
    cin >> k;
    vector<int> products(k);
    for(int i=0; i<k; i++) cin >> products[i];
    sort(products.begin(), products.end());

    int time = 0, totalCnt = 0;
    vector<bool> visited(k);
    while(totalCnt < k)
    {
        time++;
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<k; j++)
            {
                if(!visited[j] && products[j] <= machines[i])
                {
                    visited[j] = true;
                    cnt++;
                    break;
                }
            }
        }
        if(cnt == 0)
        {
            time = -1;
            break;
        }
        else totalCnt += cnt;
    }
    cout << time;

    return 0;
}