#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    int maxnum = 0;
    int maxidx = 0;
    vector<int> a(n+1);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    int maxsum = 0;
    for(int i=0; i<n; i++)
    {
        int temp = a[i];
        if(a[i] > a[i+1])
        {
            int start = a[i+1];
            for(int j=i+1; j<=n; j++)
            {
                if(a[j] >= start)
                {
                    start = a[j];
                }
                else
                {
                    temp += start;
                    start = a[j];
                }
            }
        }
        maxsum = max(maxsum, temp);
    }

    cout << maxsum;

    return 0;
}