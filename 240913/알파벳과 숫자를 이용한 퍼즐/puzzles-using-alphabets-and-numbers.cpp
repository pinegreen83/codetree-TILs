#include <iostream>
#include <vector>

enum Alp {
    B,
    E,
    S,
    I,
    G,
    O,
    M
};

using namespace std;

int n;
vector<int> odd(7, 0), even(7, 0);

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    int num;
    char now;
    for(int i=0; i<n; i++) {
        cin >> now >> num;

        int idx;
        switch(now) {
            case 'B':
                idx = Alp::B;
                break;
            case 'E':
                idx = Alp::E;
                break;
            case 'S':
                idx = Alp::S;
                break;
            case 'I':
                idx = Alp::I;
                break;
            case 'G':
                idx = Alp::G;
                break;
            case 'O':
                idx = Alp::O;
                break;
            case 'M':
                idx = Alp::M;
                break;
        }

        if(num % 2 == 0) even[idx]++;
        else odd[idx]++;
    }

    long long ans = 0;
    for(int i=0; i<(1 << 7); i++) {
        int B_type = (i >> Alp::B) & 1;
        int E_type = (i >> Alp::E) & 1;
        int S_type = (i >> Alp::S) & 1;
        int I_type = (i >> Alp::I) & 1;
        int G_type = (i >> Alp::G) & 1;
        int O_type = (i >> Alp::O) & 1;
        int M_type = (i >> Alp::M) & 1;

        int a = (B_type + I_type) % 2;
        int b = (G_type + O_type + E_type + S_type) % 2;
        int c = M_type;

        if(a == 0 || b == 0 || c == 0) {
            long long cnt = 1;

            cnt *= (B_type == 0) ? even[Alp::B] : odd[Alp::B];
            cnt *= (E_type == 0) ? even[Alp::E] : odd[Alp::E];
            cnt *= (S_type == 0) ? even[Alp::S] : odd[Alp::S];
            cnt *= (I_type == 0) ? even[Alp::I] : odd[Alp::I];
            cnt *= (G_type == 0) ? even[Alp::G] : odd[Alp::G];
            cnt *= (O_type == 0) ? even[Alp::O] : odd[Alp::O];
            cnt *= (M_type == 0) ? even[Alp::M] : odd[Alp::M];

            ans += cnt;
        }
    }

    cout << ans;

    return 0;
}