#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    freopen("d4.in", "r", stdin);
    vector<string> v;
    string line;
    while (getline(cin, line)) {
        v.push_back(line);
    }
    int p1 = 0, p2 = 0;
    vector<int> combo(v.size(), 1);
    for (int i = 0; i < v.size(); i++) {
        set<int> w;
        string s;
        int n, cnt = 0;
        istringstream iss0(v[i].substr(0, v[i].find("|")-1)),
                      iss1(v[i].substr(v[i].find("|")+2));
        iss0 >> s >> s;
        while (iss0 >> n) w.insert(n);
        while (iss1 >> n) cnt += w.count(n);
        p1 += cnt? (1 << (cnt-1)) : 0;
        p2 += combo[i];
        for (int j = i+1; j < min(i+1+cnt, (int)v.size()); j++) {
            combo[j] += combo[i];
        }
    }
    cout << p1 << ' ' << p2 << '\n';
}
