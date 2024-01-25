#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n, m;
    cin >> n >> m;

    vector<int> line(n);
    for(int i=0; i<n; i++)
    {
        cin >> line[i];
    }

    int maxsum = 0;
    int nowsum = 0;
    int sumnum = 1;

    for(int i=0; i<m; i++)
    {
        maxsum += line[i];
        nowsum += line[i];
    }
    
    for(int i=0, j=m; j<n; i++, j++)
    {
        nowsum -= line[i];
        nowsum += line[j];    
        if(nowsum == maxsum)
        {
            sumnum++;
        }
        else
        {
            if(nowsum > maxsum)
            {
                maxsum = nowsum;
                sumnum = 1;
            }
        }
    }

    if(maxsum)
    {
        cout << maxsum << endl << sumnum;
    }
    else
    {
        cout << maxsum;
    }

    return 0;
}