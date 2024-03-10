#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, ans = 0;
    cin >> n;

    vector<int> a(n);
    unordered_map<int, int> umap;

    for(int t=0; t<4; t++)
    {
        if(t % 2 == 0)
        {
            for(int i=0; i<n; i++)
            {
                cin >> a[i];
            }
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                int b;
                cin >> b;
                for(int j=0; j<n; j++)
                {
                    if(t == 1) umap[a[j]+b]++;
                    else
                    {
                        int test = (a[j] + b) * -1;
                        if(umap.find(test) != umap.end())
                        {
                            ans += umap[test];
                            umap[test]--;
                        }
                    }
                }
            }
        }
    }
    cout << ans;

    return 0;
}