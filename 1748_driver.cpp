#include <bits/stdc++.h>
using namespace std;
#include "1748.cpp"

// ── token utils ───────────────────────────────────────────────────
static string _trim(const string& s) {
    size_t a = s.find_first_not_of(" \t\r\n");
    if (a == string::npos) return "";
    return s.substr(a, s.find_last_not_of(" \t\r\n") - a + 1);
}
static string _unwrap(const string& s) {          // "[1,2]" → "1,2"
    string x = _trim(s);
    if (x.size() >= 2 && x.front() == '[' && x.back() == ']') return x.substr(1, x.size() - 2);
    return x;
}
static vector<string> _splitTop(const string& body) {   // split on depth-0 commas
    vector<string> out; int dep = 0; bool ins = false; string cur;
    for (size_t i = 0; i < body.size(); i++) {
        char c = body[i];
        if (c == '"' && (i == 0 || body[i-1] != '\\')) ins = !ins;
        if (!ins) {
            if (c == '[' || c == '{') dep++;
            else if (c == ']' || c == '}') dep--;
            else if (c == ',' && dep == 0) { out.push_back(cur); cur = ""; continue; }
        }
        cur += c;
    }
    if (!_trim(cur).empty()) out.push_back(cur);
    return out;
}

// ── token → value ─────────────────────────────────────────────────
static int       _toI (const string& s) { return stoi(_trim(s)); }
static long long _toLL(const string& s) { return stoll(_trim(s)); }
static double    _toD (const string& s) { return stod(_trim(s)); }
static bool      _toB (const string& s) { string x = _trim(s); return x == "true" || x == "1"; }
static string    _toS (const string& s) {
    string x = _trim(s);
    if (x.size() >= 2 && x.front() == '"' && x.back() == '"') x = x.substr(1, x.size() - 2);
    return x;
}
static char      _toC (const string& s) { string x = _toS(s); return x.empty() ? ' ' : x[0]; }

template<class F> static auto _toV(const string& s, F f) -> vector<decltype(f(s))> {
    vector<decltype(f(s))> v;
    for (const string& t : _splitTop(_unwrap(s))) v.push_back(f(t));
    return v;
}
static vector<int>            _toVI (const string& s) { return _toV(s, _toI);  }
static vector<long long>      _toVLL(const string& s) { return _toV(s, _toLL); }
static vector<double>         _toVD (const string& s) { return _toV(s, _toD);  }
static vector<bool>           _toVB (const string& s) { return _toV(s, _toB);  }
static vector<char>           _toVC (const string& s) { return _toV(s, _toC);  }
static vector<string>         _toVS (const string& s) { return _toV(s, _toS);  }
static vector<vector<int>>    _toVVI(const string& s) { return _toV(s, _toVI); }
static vector<vector<char>>   _toVVC(const string& s) { return _toV(s, _toVC); }
static vector<vector<string>> _toVVS(const string& s) { return _toV(s, _toVS); }

// ── line readers ──────────────────────────────────────────────────
// The raw line is echoed to stderr so run.sh can show the input of a failing
// case; debug.sh compiles with -DDEBUG and keeps stderr for your own prints.
static string _line() {
    string s; getline(cin, s);
#ifndef DEBUG
    cerr << s << "\n";
#endif
    return s;
}
static int       _ri()   { return _toI (_line()); }
static long long _rll()  { return _toLL(_line()); }
static double    _rd()   { return _toD (_line()); }
static bool      _rb()   { return _toB (_line()); }
static string    _rs()   { return _toS (_line()); }
static char      _rc()   { return _toC (_line()); }
static vector<int>            _rvi()  { return _toVI (_line()); }
static vector<long long>      _rvll() { return _toVLL(_line()); }
static vector<double>         _rvd()  { return _toVD (_line()); }
static vector<bool>           _rvb()  { return _toVB (_line()); }
static vector<char>           _rvc()  { return _toVC (_line()); }
static vector<string>         _rvs()  { return _toVS (_line()); }
static vector<vector<int>>    _rvvi() { return _toVVI(_line()); }
static vector<vector<char>>   _rvvc() { return _toVVC(_line()); }
static vector<vector<string>> _rvvs() { return _toVVS(_line()); }
static void _endCase() {
#ifndef DEBUG
    cerr << "---\n";
#endif
}

int main() {
    string _t; getline(cin, _t);
    int _T = stoi(_trim(_t));
    while (_T--) {
        vector<int> nums = _rvi();
        Solution sol;
        auto _res = sol.sumOfUnique(nums);
        cout << _res << "\n";
        _endCase();
    }
    return 0;
}
