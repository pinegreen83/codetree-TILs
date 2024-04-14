#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    string init, target;
    cin >> n >> init >> target;

    int diff = 0, cnt = 0;
    for(int i=0; i<n; i++)
    {
        if(init[i] != target[i])
        {
            diff++;
            if(diff == 4)
            {
                diff = 0;
                cnt++;
            }
        }
        else
        {
            if(diff > 0)
            {
                diff = 0;
                cnt++;
            }
        }
    }
    if(diff > 0) cnt++;
    cout << cnt;

    return 0;
}