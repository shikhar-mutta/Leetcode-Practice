#include <bits/stdc++.h>
using namespace std;
#include "1912.cpp"

vector<string> _rvs() {
    string s; getline(cin, s);
    vector<string> v;
    auto body = s.substr(1, s.size() - 2);
    bool in = false; string cur;
    for (char c : body) {
        if (c == '"') { in = !in; continue; }
        if (c == ',' && !in) { v.push_back(cur); cur = ""; continue; }
        cur += c;
    }
    if (!cur.empty()) v.push_back(cur);
    return v;
}

// Extract each top-level arg-group; preserves nested brackets when depth>2
vector<string> extractGroupsRaw(const string& s) {
    vector<string> res;
    int depth = 0; string cur;
    for (char c : s) {
        if (c == '[') {
            depth++;
            if (depth == 2) cur = "";
            else if (depth > 2) cur += c;
            continue;
        }
        if (c == ']') {
            depth--;
            if (depth == 1) res.push_back(cur);
            else if (depth >= 2) cur += c;
            continue;
        }
        if (depth >= 2) cur += c;
    }
    return res;
}

vector<int> parseIntList(const string& s) {
    vector<int> v;
    stringstream ss(s);
    string t;
    while (getline(ss, t, ',')) if (!t.empty()) v.push_back(stoi(t));
    return v;
}

vector<vector<int>> parseEntries(const string& s) {
    vector<vector<int>> res;
    int depth = 0; string cur;
    for (char c : s) {
        if (c == '[') { depth++; if (depth == 1) cur = ""; continue; }
        if (c == ']') { depth--; if (depth == 0) res.push_back(parseIntList(cur)); continue; }
        if (depth >= 1) cur += c;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        string argsLine; getline(cin, argsLine);
        auto groups = extractGroupsRaw(argsLine);

        MovieRentingSystem* obj = nullptr;
        vector<string> outputs;
        for (size_t i = 0; i < ops.size(); i++) {
            auto& op = ops[i];
            auto& argStr = groups[i];
            if (op == "MovieRentingSystem") {
                int commaPos = argStr.find(',');
                int n = stoi(argStr.substr(0, commaPos));
                string entriesStr = argStr.substr(commaPos + 1);
                if (!entriesStr.empty() && entriesStr.front() == '[' && entriesStr.back() == ']') {
                    entriesStr = entriesStr.substr(1, entriesStr.size() - 2);
                }
                auto entries = parseEntries(entriesStr);
                obj = new MovieRentingSystem(n, entries);
                outputs.push_back("null");
            } else if (op == "search") {
                int movie = stoi(argStr);
                auto res = obj->search(movie);
                string s = "[";
                for (size_t j = 0; j < res.size(); j++) { if (j) s += ","; s += to_string(res[j]); }
                s += "]";
                outputs.push_back(s);
            } else if (op == "rent") {
                auto args = parseIntList(argStr);
                obj->rent(args[0], args[1]);
                outputs.push_back("null");
            } else if (op == "drop") {
                auto args = parseIntList(argStr);
                obj->drop(args[0], args[1]);
                outputs.push_back("null");
            } else if (op == "report") {
                auto res = obj->report();
                string s = "[";
                for (size_t j = 0; j < res.size(); j++) {
                    if (j) s += ",";
                    s += "[" + to_string(res[j][0]) + "," + to_string(res[j][1]) + "]";
                }
                s += "]";
                outputs.push_back(s);
            }
        }
        delete obj;

        cout << "[";
        for (size_t i = 0; i < outputs.size(); i++) {
            if (i) cout << ",";
            cout << outputs[i];
        }
        cout << "]\n";
    }
    return 0;
}
