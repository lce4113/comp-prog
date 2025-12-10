#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> ori(33333, -1); // -1 if unknown, 1 if 0 first, otherwise 2
    cout << 66668 << endl;
    while(true) {
        int guess;
        cin >> guess;
        if(guess == -1){
            break;
        }
        if(guess == 0){
            cout << "1" << endl;
            continue;
        }
        if(guess == 100000) {
            cout << "66668" << endl;
            continue;
        }
        guess --;
        int g_id = guess / 3;
        // cout << "G_ID : " << g_id << endl;
        if(guess % 3 == 0){
            cout << 1 + g_id * 2 + 1 << endl;
            continue;
        }
        assert(g_id >= 0 && g_id < ori.size());
        if(ori[g_id] == -1){
            ori[g_id] = (guess % 3 == 1)? 2 : 1;
        }
        if(ori[g_id] == (guess % 3)) {
            cout << 1 + g_id * 2 + 1 + 1 << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    cout << 0 << "\n";
    for(int i = 0; i < ori.size(); i++) {
        cout << i * 3 + 1 << "\n";
        cout << i * 3 + 1 + ori[i] << "\n";
    }
    cout << 100000 << endl;
    
    return 0;
}
