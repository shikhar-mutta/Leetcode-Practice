#include <bits/stdc++.h>
using namespace std;
#include "3484.cpp"

vector<string> splitArgLists(const string& s) {
    string inner = s.substr(1, s.size() - 2);
    vector<string> parts;
    int dep = 0;
    string cur;
    for (char c : inner) {
        if (c == '[') { dep++; cur += c; }
        else if (c == ']') { dep--; cur += c; }
        else if (c == ',' && dep == 0) { parts.push_back(cur); cur = ""; }
        else cur += c;
    }
    if (!cur.empty()) parts.push_back(cur);
    return parts;
}

vector<string> parseArgTokens(const string& inner) {
    // inner is comma-separated tokens, strings quoted, numbers plain
    vector<string> v;
    bool in = false;
    string cur;
    for (char c : inner) {
        if (c == '"') { in = !in; continue; }
        if (c == ',' && !in) { v.push_back(cur); cur = ""; continue; }
        cur += c;
    }
    if (!cur.empty()) v.push_back(cur);
    return v;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line1; getline(cin, line1);
        string line2; getline(cin, line2);
        vector<string> names = [&]() {
            vector<string> v;
            string body = line1.substr(1, line1.size() - 2);
            bool in = false; string cur;
            for (char c : body) {
                if (c == '"') { in = !in; continue; }
                if (c == ',' && !in) { v.push_back(cur); cur = ""; continue; }
                cur += c;
            }
            if (!cur.empty()) v.push_back(cur);
            return v;
        }();

        vector<string> argGroups = splitArgLists(line2);

        cout << "[";
        Spreadsheet* obj = nullptr;
        for (int i = 0; i < (int)names.size(); i++) {
            if (i > 0) cout << ", ";
            string& name = names[i];
            string& args = argGroups[i];
            string inner = args.substr(1, args.size() >= 2 ? args.size() - 2 : 0);
            auto toks = parseArgTokens(inner);
            if (name == "Spreadsheet") {
                obj = new Spreadsheet(stoi(toks[0]));
                cout << "null";
            } else if (name == "setCell") {
                obj->setCell(toks[0], stoi(toks[1]));
                cout << "null";
            } else if (name == "resetCell") {
                obj->resetCell(toks[0]);
                cout << "null";
            } else if (name == "getValue") {
                cout << obj->getValue(toks[0]);
            }
        }
        cout << "]\n";
        delete obj;
    }
    return 0;
}
