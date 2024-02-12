#include <iostream>
#include <vector>

using namespace std;
int n, m;
vector<vector<int>> map;

bool maxsquare(int height, int width)
{
    bool posi = false;
    for(int i=0; i<=n-height; i++)
    {
        for(int j=0; j<=m-width; j++)
        {
            bool temp = true;
            for(int h=i; h<i+height; h++)
            {
                if(!temp) break;
                for(int w=j; w<j+width; w++)
                {
                    if(map[h][w] < 0)
                    {
                        temp = false;
                        break;
                    }
                }
            }
            if(temp) 
            {
                posi = true;
                break;
            }
        }
    }
    return posi;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int ans = 0;
    cin >> n >> m;

    int a;
    for(int i=0; i<n; i++)
    {
        vector<int> temp;
        for(int j=0; j<m; j++)
        {
            cin >> a;
            temp.push_back(a);
        }
        map.push_back(temp);
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(maxsquare(i, j))
            {
                if(i * j > ans) ans = i*j;
            }
        }
    }

    cout << ans;

    return 0;
}