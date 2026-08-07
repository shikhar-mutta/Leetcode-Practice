#include <bits/stdc++.h>
using namespace std;
#include "681.cpp"

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
        string time = _rs();
        Solution sol;
        auto res = sol.nextClosestTime(time);
        cout << res << "\n";
    }
    return 0;
}
