#include <bits/stdc++.h>
using namespace std;
#include "642.cpp"

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
        auto ops = _rvs();
        int n = ops.size();
        vector<string> rawArgs(n);
        for (int i = 0; i < n; i++) { string s; getline(cin,s); rawArgs[i]=s; }
        AutocompleteSystem* sys = nullptr;
        vector<string> outputs;
        for (int i = 0; i < n; i++) {
            if (ops[i] == "AutocompleteSystem") {
                string s = rawArgs[i];
                string inner = s.substr(1, s.size()-2); // strip outer [ ]
                size_t split = inner.find("],[");
                string sentPart = inner.substr(1, split-1); // strip leading [ of first list
                string timesPart = inner.substr(split+3, inner.size()-(split+3)-1); // skip "],[" and trailing ]
                vector<string> sentences;
                {
                    bool in=false; string cur2;
                    for (char c : sentPart) {
                        if (c=='"') { in=!in; continue; }
                        if (c==',' && !in) { sentences.push_back(cur2); cur2=""; continue; }
                        cur2 += c;
                    }
                    if (!cur2.empty()) sentences.push_back(cur2);
                }
                vector<int> times;
                {
                    stringstream ss(timesPart);
                    string t2;
                    while (getline(ss,t2,',')) if(!t2.empty()) times.push_back(stoi(t2));
                }
                sys = new AutocompleteSystem(sentences, times);
                outputs.push_back("null");
            } else if (ops[i] == "input") {
                string s = rawArgs[i];
                char c = s[2]; // ["c"]
                auto res = sys->input(c);
                string out = "[";
                for (size_t j = 0; j < res.size(); j++) { if(j) out+=","; out += "\""+res[j]+"\""; }
                out += "]";
                outputs.push_back(out);
            }
        }
        cout << "[";
        for (int i = 0; i < n; i++) { if(i) cout << ","; cout << outputs[i]; }
        cout << "]\n";
        delete sys;
    }
    return 0;
}
