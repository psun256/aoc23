#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    freopen("d1.in", "r", stdin);
    string line;
    map<string, string> rep = {
        {"one", "o1e"},
        {"two", "t2o"},
        {"three", "t3e"},
        {"four", "f4r"},
        {"five", "f5e"},
        {"six", "s6x"},
        {"seven", "s7n"},
        {"eight", "e8t"},
        {"nine", "n9e"},
        {"ten", "z0o"}
    };
    int p1 = 0, p2 = 0;
    while (getline(cin, line)) {
        string s1 = "";
        for (char c : line) {
            if (c-'0' >= 0 && c-'0' <= 9) {
                s1 += c;
            }
        }
        string s2 = "";
        for (auto& [from, to] : rep) {
            line = regex_replace(line, regex(from), to);
        }
        for (char c : line) {
            if (c-'0' >= 0 && c-'0' <= 9) {
                s2 += c;
            }
        }
        p1 += 10*(s1[0]-'0') + s1[s1.size()-1]-'0';
        p2 += 10*(s2[0]-'0') + s2[s2.size()-1]-'0';
    }
    cout << p1 << ' ' << p2 << '\n';
}
