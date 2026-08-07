#include <bits/stdc++.h>
using namespace std;
#include "631.cpp"

vector<string> _rvs() {
    string s; getline(cin,s);
    vector<string> v;
    if (s.size() < 2) return v;
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

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        int n = ops.size();
        vector<vector<string>> args(n);
        for (int i = 0; i < n; i++) args[i] = _rvs();
        Excel* excel = nullptr;
        vector<string> outputs;
        for (int i = 0; i < n; i++) {
            if (ops[i] == "Excel") {
                excel = new Excel(stoi(args[i][0]), args[i][1][0]);
                outputs.push_back("null");
            } else if (ops[i] == "set") {
                excel->set(stoi(args[i][0]), args[i][1][0], stoi(args[i][2]));
                outputs.push_back("null");
            } else if (ops[i] == "get") {
                outputs.push_back(to_string(excel->get(stoi(args[i][0]), args[i][1][0])));
            } else if (ops[i] == "sum") {
                vector<string> nums(args[i].begin()+2, args[i].end());
                outputs.push_back(to_string(excel->sum(stoi(args[i][0]), args[i][1][0], nums)));
            }
        }
        cout << "[";
        for (int i = 0; i < n; i++) { if(i) cout << ","; cout << outputs[i]; }
        cout << "]\n";
        delete excel;
    }
    return 0;
}
