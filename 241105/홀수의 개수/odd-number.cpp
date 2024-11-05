#include <iostream>
#include <string>

using namespace std;

int minOdd = 1e9, maxOdd = 0;

int count(const string& num) {
    int cnt = 0;
    for(char n : num) {
        if((n - '0') % 2 == 1) cnt++; 
    }

    return cnt;
}

void div(string num, int nowOdd) {
    int len = num.length();
    nowOdd += count(num);

    if(len == 1) {
        minOdd = min(minOdd, nowOdd);
        maxOdd = max(maxOdd, nowOdd);
        return;
    }

    if(len == 2) {
        int sum = (num[0] - '0') + (num[1] - '0');
        div(to_string(sum), nowOdd);
    }
    else {
        for(int i=1; i<len-1; i++) {
            for(int j=i+1; j<len; j++) {
                int a = stoi(num.substr(0, i));
                int b = stoi(num.substr(i, j-i));
                int c = stoi(num.substr(j));
                int sum = a + b + c;
                div(to_string(sum), nowOdd);
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    string num;
    cin >> num;

    div(num, 0);
    cout << minOdd << " " << maxOdd;

    return 0;
}