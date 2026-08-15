#include <bits/stdc++.h>
using namespace std;
#include "408.cpp"

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
        string abbr = _rs();
        Solution sol;
        cout << (sol.validWordAbbreviation(word, abbr) ? "true" : "false") << "\n";
    }
    return 0;
}
