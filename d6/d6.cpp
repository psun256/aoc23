#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    freopen("d6.in", "r", stdin);
    vector<ll> t, d;
    string line, s;
    ll x;
    getline(cin, line);
    istringstream iss(line);
    iss >> s;
    while (iss >> x) t.push_back(x);
    getline(cin, line);
    istringstream is2(line);
    is2 >> s;
    while (is2 >> x) d.push_back(x);

    ll p1 = 1;
    for (int i = 0; i < t.size(); i++) {
        ll l = ceil((t[i] - sqrt(t[i]*t[i] - 4 * (d[i]+1))) / 2.0);
        ll r = floor((t[i] + sqrt(t[i]*t[i] - 4 * (d[i]+1))) / 2.0);
        p1 *= r-l+1;
    }

    string t1s, d1s;
    for (auto x : t) t1s += to_string(x);
    for (auto x : d) d1s += to_string(x);
    ll t1 = stoll(t1s), d1 = stoll(d1s);
    ll l = ceil((t1 - sqrt(t1*t1 - 4 * (d1+1))) / 2.0);
    ll r = floor((t1 + sqrt(t1*t1 - 4 * (d1+1))) / 2.0);

    cout << p1 << ' ' << r-l+1 << '\n';
}
