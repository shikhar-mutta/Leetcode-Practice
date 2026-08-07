#include <bits/stdc++.h>
using namespace std;
#include "588.cpp"

string _rs() {
    string s; getline(cin,s);
    if (s.size()>=2 && s.front()=='"' && s.back()=='"') s=s.substr(1,s.size()-2);
    return s;
}
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
        FileSystem* fs = nullptr;
        vector<string> outputs;
        for (int i = 0; i < n; i++) {
            if (ops[i] == "FileSystem") { fs = new FileSystem(); outputs.push_back("null"); }
            else if (ops[i] == "ls") {
                auto res = fs->ls(args[i][0]);
                sort(res.begin(), res.end());
                string s = "[";
                for (size_t j = 0; j < res.size(); j++) { if(j) s+=","; s+=res[j]; }
                s += "]";
                outputs.push_back(s);
            } else if (ops[i] == "mkdir") { fs->mkdir(args[i][0]); outputs.push_back("null"); }
            else if (ops[i] == "addContentToFile") { fs->addContentToFile(args[i][0], args[i][1]); outputs.push_back("null"); }
            else if (ops[i] == "readContentFromFile") { outputs.push_back(fs->readContentFromFile(args[i][0])); }
        }
        cout << "[";
        for (int i = 0; i < n; i++) { if(i) cout << ","; cout << outputs[i]; }
        cout << "]\n";
        delete fs;
    }
    return 0;
}
