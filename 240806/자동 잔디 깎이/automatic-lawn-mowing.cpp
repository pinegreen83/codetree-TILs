#include <iostream>
#include <map>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    char dir;
    int move, x = 0, y = 0, time = 0, ans = 100000000;
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    map<pair<int, int>, int> moves;
    for(int i=0; i<n; i++)
    {
        cin >> dir >> move;
        int go;
        switch(dir)
        {
            case 'E':
                go = 0;
                break;
            case 'W':
                go = 1;
                break;
            case 'S':
                go = 2;
                break;
            case 'N':
                go = 3;
                break;
        }

        for(int m=0; m<move; m++)
        {
            time++;
            x += dirs[go][0];
            y += dirs[go][1];
            pair<int, int> temp = {x, y};
            if(moves.find(temp) != moves.end())
            {
                ans = min(ans, time - moves[temp]);
                moves[temp] = time;
            }
            else moves[temp] = time;
        }
    }
    cout << (ans == 100000000 ? -1 : ans);

    return 0;
}