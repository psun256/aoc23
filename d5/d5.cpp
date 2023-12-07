#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    freopen("d5.in", "r", stdin);
    vector<string> inp;
    string s;
    while (getline(cin, s)) inp.push_back(s);
    vector<vector<pair<ll, pair<ll, ll>>>> maps;
    vector<ll> seeds;
    ll x;
    istringstream seedin(inp[0]);
    seedin >> s;
    while (seedin >> x) seeds.push_back(x);
    for (int i = 2; i < inp.size(); i++) {
        if (isalpha(inp[i][0]) && inp[i-1].size() == 0) {
            int it = i+1;
            maps.push_back(vector<pair<ll, pair<ll, ll>>>());
            while (inp[it].size() > 0) {
                istringstream mpin(inp[it]);
                ll a, b, c;
                mpin >> a >> b >> c;
                maps[maps.size()-1].push_back({a, {b, c}});
                it++;
            }
        }
    }
    ll p1 = 1e15, p2 = 1e15;
    for (auto seed : seeds) {
        ll ss = seed;
        for (auto& mp : maps) {
            for (auto& [a, bc] : mp) {
                ll b, c;
                tie(b, c) = bc;
                if (b <= ss && ss <= b+c) {
                    ss += a-b;
                    break;
                }
            }
        }
        p1 = min(p1, ss);
    }
    auto clamp = [](ll a, ll b, ll c, ll d) {
        return make_pair(max(a, c), min(b, d));
    };
    for (int i = 0; i < seeds.size(); i+= 2) {
        queue<pair<ll, ll>> cur;
        cur.push({seeds[i], seeds[i] + seeds[i+1]});
        for (auto& mp : maps) {
            queue<pair<ll, ll>> nxt;
            while (!cur.empty()) {
                ll s, e;
                tie(s, e) = cur.front(); cur.pop();
                bool matched = false;
                for (auto& [a, bc] : mp) {
                    ll b, c;
                    ll ns, ne;
                    tie(b, c) = bc;
                    tie(ns, ne) = clamp(s, e, b, b+c);
                    if (ne-ns > 0) {
                        nxt.push({ns+a-b, ne+a-b});
                        if (s < b) cur.push({s, b});
                        if (b+c < e) cur.push({b+c, e});
                        matched = true;
                        break;
                    }
                }
                if (!matched) nxt.push({s, e});
            }
            cur = nxt;
        }
        while (!cur.empty()) {
            p2 = min(p2, cur.front().first);
            cur.pop();
        }
    }
    cout << p1 << ' ' << p2 << '\n';
}
