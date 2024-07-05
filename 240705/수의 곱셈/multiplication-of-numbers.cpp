#include <iostream>
#include <set>

using namespace std;

int nums[3];
set<int> odd, even;
bool visited[3];

void ints(int cnt, int mul)
{
    if(cnt <= 3)
    {
        if(mul % 2 == 0)
        {
            even.insert(mul);
        }
        else odd.insert(mul);
        if(cnt == 3) return;
    }
    for(int i=0; i<3; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            ints(cnt+1, mul*nums[i]);
            visited[i] = false;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    for(int i=0; i<3; i++)
    {
        cin >> nums[i];
        visited[i] = false;
    }

    ints(0, 1);

    int ans = 0;
    set<int>::iterator iter;
    for(iter=odd.begin(); iter!=odd.end(); iter++) ans = max(ans, *iter);

    if(odd.size() == 1)
    {
        for(iter=even.begin(); iter!=even.end(); iter++) ans = max(ans, *iter);
    }
    cout << ans;

    return 0;
}