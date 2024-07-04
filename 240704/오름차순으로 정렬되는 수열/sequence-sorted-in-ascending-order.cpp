#include <iostream>
#include <set>

#define MAX_NUM 200

using namespace std;

int nums[MAX_NUM];

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    for(int i=0; i<n; i++) cin >> nums[i];

    int now;
    if(nums[0] > nums[1]) now = 0;
    else
    {
        for(int i=0; i<n-1; i++)
        {
            if(nums[i] > nums[i+1]) 
            {
                now = i+1;
                break;
            }
        }
    }

    set<int> numset;

    for(int i=0; i<now; i++)
    {
        if(nums[i] > nums[now]) numset.insert(nums[i]);
    }
    cout << numset.size();

    return 0;
}