#include <bits/stdc++.h>
using namespace std;

static string _read4Source;
static int _read4Pos = 0;

int read4(char *buf4) {
    int cnt = 0;
    while (cnt < 4 && _read4Pos < (int)_read4Source.size()) {
        buf4[cnt++] = _read4Source[_read4Pos++];
    }
    return cnt;
}

#include "157.cpp"

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
        string file = _rs();
        int n = _ri();
        _read4Source = file;
        _read4Pos = 0;
        vector<char> buf(n + 1, 0);
        Solution sol;
        int len = sol.read(buf.data(), n);
        string result(buf.data(), len);
        cout << "\"" << result << "\"\n";
    }
    return 0;
}
