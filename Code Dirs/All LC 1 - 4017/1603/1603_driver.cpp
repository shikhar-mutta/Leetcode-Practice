#include <bits/stdc++.h>
using namespace std;
#include "1603.cpp"

vector<string> _rvs() {
    string s; getline(cin,s);
    vector<string> v;
    auto body = s.substr(1, s.size()-2);
    bool in = false; string cur;
    for (char c : body) {
        if (c=='"') { in=!in; continue; }
        if (c==',' && !in) { v.push_back(cur); cur=""; continue; }
        cur += c;
    }
    if (!cur.empty()) v.push_back(cur);
    return v;
}

vector<string> extractGroupsRaw(const string& s) {
    vector<string> parts;
    int depth = 0; string cur;
    for (char c : s) {
        if (c == '[') {
            depth++;
            if (depth == 2) cur = "";
        } else if (c == ']') {
            depth--;
            if (depth == 1) parts.push_back(cur);
        } else if (depth >= 2) {
            cur += c;
        }
    }
    return parts;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        string argsLine; getline(cin, argsLine);
        auto groups = extractGroupsRaw(argsLine);

        ParkingSystem* ps = nullptr;
        cout << "[";
        for (int i = 0; i < (int)ops.size(); i++) {
            if (i) cout << ", ";
            vector<int> nums;
            stringstream ss(groups[i]);
            string tok;
            while (getline(ss, tok, ',')) if (!tok.empty()) nums.push_back(stoi(tok));

            if (ops[i] == "ParkingSystem") {
                ps = new ParkingSystem(nums[0], nums[1], nums[2]);
                cout << "null";
            } else if (ops[i] == "addCar") {
                cout << (ps->addCar(nums[0]) ? "true" : "false");
            }
        }
        cout << "]\n";
        delete ps;
    }
    return 0;
}
