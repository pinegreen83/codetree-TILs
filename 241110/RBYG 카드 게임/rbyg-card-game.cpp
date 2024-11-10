#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    set<char> colors;
    int nums[10] = {};
    for(int i=0; i<5; i++) {
        char color;
        int num;
        cin >> color >> num;
        colors.insert(color);
        nums[num]++;
    }

    int cnt = 0;
    int bigStrNum = 0, bigNum = 0;
    bool isStraight = false;
    bool isFour = false;
    int fourNum = 0;
    bool isThree = false;
    int threeNum = 0;
    bool isTwo = false;
    vector<int> twoNum;
    for(int i=0; i<10; i++) {
        cnt = 0;
        if(nums[i] > 0) {
            if(nums[i] == 4) {
                isFour = true;
                fourNum = i;
            }
            if(nums[i] == 3) {
                isThree = true;
                threeNum = i;
            }
            if(nums[i] == 2) {
                isTwo = true;
                twoNum.push_back(i);
            }
            for(int j=i; j<=i+4; j++) {
                if(nums[j] == 0) {
                    break;
                }
                else cnt++;
                bigStrNum = max(bigStrNum, j);
            }
            if(cnt == 5) isStraight = true;
            bigNum = max(bigNum, i);
        }
    }

    int ans = 0;
    if(colors.size() == 1) {
        if(isStraight) {
            ans = max(ans, 900 + bigStrNum);
        }
        else {
            ans = max(ans, 600 + bigNum);
        }
    }
    if(isFour) {
        ans = max(ans, 800 + fourNum);
    }
    if(isThree) {
        if(isTwo) {
            ans = max(ans, 700 + threeNum * 10 + twoNum[0]);
        }
        else {
            ans = max(ans, 400 + threeNum);
        }
    }
    if(isStraight) {
        ans = max(ans, 500 + bigNum);
    }
    if(isTwo) {
        if(twoNum.size() == 2) {
            ans = max(ans, 300 + twoNum[1] * 10 + twoNum[0]);
        }
        else {
            ans = max(ans, 200 + twoNum[0]);
        }
    }
    ans = max(ans, 100 + bigNum);
    cout << ans;

    return 0;
}