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

#include "158.cpp"

string _rs() {
    string s; getline(cin,s);
    if (s.size()>=2 && s.front()=='"' && s.back()=='"') s=s.substr(1,s.size()-2);
    return s;
}
vector<int> _rvi() {
    string s; getline(cin,s);
    vector<int> v; stringstream ss(s.substr(1,s.size()-2));
    string t; while(getline(ss,t,',')) { if(!t.empty()) v.push_back(stoi(t)); }
    return v;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string file = _rs();
        auto calls = _rvi();
        _read4Source = file;
        _read4Pos = 0;
        Solution sol;
        vector<string> results;
        for (int n : calls) {
            vector<char> buf(n + 1, 0);
            int len = sol.read(buf.data(), n);
            results.push_back(string(buf.data(), len));
        }
        cout << "[";
        for (int i = 0; i < (int)results.size(); i++) {
            if (i) cout << ",";
            cout << "\"" << results[i] << "\"";
        }
        cout << "]\n";
    }
    return 0;
}
