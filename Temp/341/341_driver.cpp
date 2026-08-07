#include <bits/stdc++.h>
using namespace std;
#include "341.cpp"

int _pos;
string _buf;

vector<NestedInteger> parseList();

NestedInteger parseValue() {
    if (_buf[_pos] == '[') {
        NestedInteger ni;
        _pos++;
        if (_buf[_pos] == ']') { _pos++; return ni; }
        while (true) {
            NestedInteger child = parseValue();
            ni.add(child);
            if (_buf[_pos] == ',') { _pos++; continue; }
            break;
        }
        _pos++;
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
    _pos++;
    if (_buf[_pos] == ']') { _pos++; return res; }
    while (true) {
        res.push_back(parseValue());
        if (_buf[_pos] == ',') { _pos++; continue; }
        break;
    }
    _pos++;
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
        NestedIterator it(nested);
        vector<int> res;
        while (it.hasNext()) res.push_back(it.next());
        cout << "[";
        for (int i = 0; i < (int)res.size(); i++) {
            if (i) cout << ",";
            cout << res[i];
        }
        cout << "]\n";
    }
    return 0;
}
