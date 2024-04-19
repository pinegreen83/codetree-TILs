#include <iostream>
#include <vector>

using namespace std;

int cnt = 0, n, k;
vector<int> nums, nodes;

void inorder(int now)
{
    if(now > k) return;
    inorder(now*2);
    nodes[now] = nums[cnt++];
    inorder(now*2 + 1);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    k = 1 << n;
    nums = vector<int>(k+1);
    nodes = vector<int>(k+1);
    for(int i=1; i<=k; i++)
    {
        cin >> nums[i];
    }

    inorder(1);

    int depth = 1;
    while(depth <= n)
    {
        int start = 1 << depth-1, end = 1 << depth;
        for(int i=start; i<end; i++)
        {
            cout << nodes[i] << " ";
        }
        cout << "\n";
        depth++;
    }

    return 0;
}