#include <bits/stdc++.h>
using namespace std;
#include "622.cpp"

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
vector<vector<int>> _rvvi() {
    string s; getline(cin,s);
    vector<vector<int>> v;
    int dep=0; string cur;
    for (char c : s) {
        if (c=='[') { dep++; if(dep>2) cur+=c; }
        else if (c==']') {
            dep--;
            if (dep==1) {
                vector<int> row; stringstream ss(cur);
                string t; while(getline(ss,t,',')) if(!t.empty()) row.push_back(stoi(t));
                v.push_back(row); cur="";
            } else if (dep>0) cur+=c;
        } else if (dep>1) cur+=c;
    }
    return v;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        auto args = _rvvi();
        int n = ops.size();
        MyCircularQueue* q = nullptr;
        vector<string> outputs;
        for (int i = 0; i < n; i++) {
            if (ops[i] == "MyCircularQueue") { q = new MyCircularQueue(args[i][0]); outputs.push_back("null"); }
            else if (ops[i] == "enQueue") outputs.push_back(q->enQueue(args[i][0]) ? "true" : "false");
            else if (ops[i] == "deQueue") outputs.push_back(q->deQueue() ? "true" : "false");
            else if (ops[i] == "Front") outputs.push_back(to_string(q->Front()));
            else if (ops[i] == "Rear") outputs.push_back(to_string(q->Rear()));
            else if (ops[i] == "isEmpty") outputs.push_back(q->isEmpty() ? "true" : "false");
            else if (ops[i] == "isFull") outputs.push_back(q->isFull() ? "true" : "false");
        }
        cout << "[";
        for (int i = 0; i < n; i++) { if(i) cout << ", "; cout << outputs[i]; }
        cout << "]\n";
        delete q;
    }
    return 0;
}
