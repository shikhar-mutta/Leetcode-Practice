#include <bits/stdc++.h>
using namespace std;
#include "339.cpp"

// parse a bracketed nested-list literal like "[[1,1],2,[1,1]]" into NestedInteger vector
int _pos;
string _buf;

vector<NestedInteger> parseList();

NestedInteger parseValue() {
    if (_buf[_pos] == '[') {
        NestedInteger ni;
        _pos++; // consume '['
        if (_buf[_pos] == ']') { _pos++; return ni; }
        while (true) {
            NestedInteger child = parseValue();
            ni.add(child);
            if (_buf[_pos] == ',') { _pos++; continue; }
            break;
        }
        _pos++; // consume ']'
        return ni;
    } else {
        int start = _pos;
        while (_pos < (int)_buf.size() && (isdigit(_buf[_pos]) || _buf[_pos] == '-')) _pos++;
        int v = stoi(_buf.substr(start, _pos - start));
        return NestedInteger(v);
    }
}

vector<NestedInteger> parseList() {
    vector<NestedInteger> res;
    _pos++; // consume outer '['
    if (_buf[_pos] == ']') { _pos++; return res; }
    while (true) {
        res.push_back(parseValue());
        if (_buf[_pos] == ',') { _pos++; continue; }
        break;
    }
    _pos++; // consume outer ']'
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        getline(cin, _buf);
        _pos = 0;
        vector<NestedInteger> nested = parseList();
        Solution sol;
        cout << sol.depthSum(nested) << "\n";
    }
    return 0;
}
