#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    freopen("d2.in", "r", stdin);
    int p1 = 0, p2 = 0;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        string s; int id; char c;
        iss >> s >> id >> c;
        
        map<char, int> col;
        int cnt = 0, mnr = 0, mng = 0, mnb = 0;
        bool possible = true;
        while (true) {
            iss >> cnt >> s;
            col[s[0]] = cnt;
            mnr = max(mnr, col['r']);
            mng = max(mng, col['g']);
            mnb = max(mnb, col['b']);
            if (s[s.size()-1] == ';' || isalpha(s[s.size()-1])) {
                possible &= (col['r'] <= 12 && col['g'] <= 13 && col['b'] <= 14);
                col.clear();
            }
            if (isalpha(s[s.size()-1])) {
                break;
            }
        }
        if (possible) {
            p1 += id;
        }
        p2 += mnr * mng * mnb;
    }
    cout << p1 << ' ' << p2 << '\n';
}
