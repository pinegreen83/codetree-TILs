#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, M;
    cin >> n >> M;

    int nums[n], o, i, j, x;
    for(int i=0; i<n; i++) cin >> nums[i];
    
    for(int m=0; m<M; m++)
    {
        cin >> o;
        switch(o)
        {
            case 1:
                cin >> i >> x;
                nums[i-1] = x;
                break;
            case 2:
                cin >> i >> j;
                for(int t=i-1; t<=j-1; t++)
                {
                    nums[t] = (nums[t] == 1 ? 0 : 1);
                }
                break;
            case 3:
                cin >> i >> j;
                for(int t=i-1; t<=j-1; t++)
                {
                    nums[t] = 0;
                }
                break;
            case 4:
                cin >> i >> j;
                for(int t=i-1; t<=j-1; t++)
                {
                    nums[t] = 1;
                }
                break;
        }
    }

    for(int i=0; i<n; i++) cout << nums[i] << " ";

    return 0;
}