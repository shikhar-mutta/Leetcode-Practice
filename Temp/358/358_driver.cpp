#include <bits/stdc++.h>
using namespace std;
#include "358.cpp"

string _rs() {
    string s; getline(cin,s);
    if (s.size()>=2 && s.front()=='"' && s.back()=='"') s=s.substr(1,s.size()-2);
    return s;
}
int _ri() { string s; getline(cin,s); return stoi(s); }

bool valid(const string& res, const string& orig, int k) {
    if (res.empty()) return false;
    unordered_map<char,int> a, b;
    for (char c : orig) a[c]++;
    for (char c : res) b[c]++;
    if (a != b) return false;
    unordered_map<char,int> last;
    for (int i = 0; i < (int)res.size(); i++) {
        if (last.count(res[i]) && i - last[res[i]] < k) return false;
        last[res[i]] = i;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s = _rs();
        int k = _ri();
        Solution sol;
        auto res = sol.rearrangeString(s, k);
        bool expectEmpty = res.empty();
        cout << (valid(res, s, k) || (expectEmpty && res.empty()) ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
