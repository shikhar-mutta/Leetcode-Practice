#include <bits/stdc++.h>
using namespace std;
#include "340.cpp"

string _rs() {
    string s; getline(cin,s);
    if (s.size()>=2 && s.front()=='"' && s.back()=='"') s=s.substr(1,s.size()-2);
    return s;
}
int _ri() { string s; getline(cin,s); return stoi(s); }

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s = _rs();
        int k = _ri();
        Solution sol;
        cout << sol.lengthOfLongestSubstringKDistinct(s, k) << "\n";
    }
    return 0;
}
