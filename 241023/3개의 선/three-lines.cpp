#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    
    int n;
    cin >> n;

    unordered_set<int> uset_x;
    unordered_set<int> uset_y;

    pair<int, int> arr[n];
    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        arr[i] = {x, y};
        uset_x.insert(x);
        uset_y.insert(y);
    }

    if(uset_x.size() <= 3 || uset_y.size() <= 3) {
        cout << 1;
        return 0;
    }

    int num = 0;
    unordered_map<int, int> umap_x;
    for(auto x : uset_x) {
        umap_x[x] = num++;
    }
    int x_num = num;

    num = 0;
    unordered_map<int, int> umap_y;
    for(auto y : uset_y) {
        umap_y[y] = num++;
    }
    int y_num = num;

    unordered_map<int, int> umap_x2;
    unordered_map<int, int> umap_y2;

    unordered_map<int, int> arrx[n];
    unordered_map<int, int> arry[n];

    for(int i=0; i<n; i++) {
        int x, y;
        tie(x, y) = arr[i];
        int x1 = umap_x[x];
        int y1 = umap_y[y];

        umap_x2[x1]++;
        umap_y2[y1]++;

        arrx[x1][y1]++;
        arry[y1][x1]++;
    }

    bool check = false;
    for(int i=0; i<x_num; i++) {
        int cnt = (int)uset_y.size();
        unordered_map<int, int>& m = arrx[i];
        for(auto y : m) {
            int val = y.first;
            int freq = y.second;
            if(umap_x2[val] == freq) {
                cnt--;
            }
        }

        if(cnt <= 2) {
            check = true;
            break;
        }
    }

    for(int i=0; i<y_num; i++) {
        int cnt = (int)uset_x.size();
        unordered_map<int, int>& m = arry[i];
        for(auto x : m) {
            int val = x.first;
            int freq = x.second;

            if(umap_x2[val] == freq) {
                cnt--;
            }
        }

        if(cnt <= 2) {
            check = true;
            break;
        }
    }

    if(check) cout << 1;
    else cout << 0;

    return 0;
}