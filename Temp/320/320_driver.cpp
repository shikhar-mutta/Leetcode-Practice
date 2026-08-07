#include <bits/stdc++.h>
using namespace std;
#include "320.cpp"

string _rs() {
    string s; getline(cin,s);
    if (s.size()>=2 && s.front()=='"' && s.back()=='"') s=s.substr(1,s.size()-2);
    return s;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string word = _rs();
        Solution sol;
        auto res = sol.generateAbbreviations(word);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < (int)res.size(); i++) {
            if (i) cout << ",";
            cout << "\"" << res[i] << "\"";
        }
        cout << "]\n";
    }
    return 0;
}
