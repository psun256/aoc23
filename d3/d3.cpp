#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    freopen("d3.in", "r", stdin);
    vector<string> v;
    string line;
    while (getline(cin, line)) {
        v.push_back('.' + line + '.');
    }
    v.insert(v.begin(), 1, string(v[0].size(), '.'));
    v.push_back(v[0]);

    int p1 = 0, p2 = 0;
    vector<vector<bool>> vis(v.size(), vector<bool>(v.size()));
    for (int i = 1; i < v.size()-1; i++) {
        for (int j = 1; j < v.size()-1; j++) {
            if (!isdigit(v[i][j])) continue;
            int j2 = j;
            bool add = false;
            while (isdigit(v[i][j2])) {
                for (int k = 0; k < 8; k++) {
                    if (!isdigit(v[i+dy[k]][j2+dx[k]]) && v[i+dy[k]][j2+dx[k]] != '.') {
                        add = true;
                    }
                }
                j2++;
            }
            j2--;
            int c = 0, p = 1;
            while (isdigit(v[i][j2])) {
                c += p * (v[i][j2--]-'0');
                p *= 10;
            }
            if (add) p1 += c;
            while (isdigit(v[i][j++])) continue; j--;
        }
    }
    for (auto& vi : vis) fill(vi.begin(), vi.end(), false);
    for (int i = 1; i < v.size()-1; i++) {
        for (int j = 1; j < v.size()-1; j++) { 
            if(v[i][j] != '*') continue;
            vector<int> nums;
            for (int k = 0; k < 8; k++) {
                if (isdigit(v[i+dy[k]][j+dx[k]]) && !vis[i+dy[k]][j+dx[k]]) {
                    int i2 = i+dy[k], j2 = j+dx[k];
                    while (isdigit(v[i2][j2++])) continue; j2--;
                    int c = 0, p = 1;
                    while (isdigit(v[i2][--j2])) {
                        vis[i2][j2] = true;
                        c += p * (v[i2][j2]-'0');
                        p *= 10;
                    }
                    nums.push_back(c);
                }
            }
            if (nums.size() == 2) {
                p2 += nums[0] * nums[1];
            }
        }
    }
    cout << p1 << ' ' << p2 << '\n';
}
