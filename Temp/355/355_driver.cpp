#include <bits/stdc++.h>
using namespace std;
#include "355.cpp"

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
vector<string> _rargs() {
    string s; getline(cin,s);
    vector<string> v;
    int dep=0; string cur;
    for (char c : s) {
        if (c=='[') { dep++; if(dep>=2) cur+=c; }
        else if (c==']') { if(dep>=2) cur+=c; dep--; if(dep==1){ v.push_back(cur); cur=""; } }
        else if (dep>=2) cur+=c;
    }
    return v;
}
vector<int> _parseInts(const string& s) {
    vector<int> v;
    stringstream ss(s);
    string t;
    while (getline(ss, t, ',')) if (!t.empty()) v.push_back(stoi(t));
    return v;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> ops = _rvs();
        vector<string> args = _rargs();
        Twitter* tw = nullptr;
        vector<string> out;
        for (int i = 0; i < (int)ops.size(); i++) {
            vector<int> a = _parseInts(args[i].substr(1, args[i].size() - 2));
            if (ops[i] == "Twitter") {
                tw = new Twitter();
                out.push_back("null");
            } else if (ops[i] == "postTweet") {
                tw->postTweet(a[0], a[1]);
                out.push_back("null");
            } else if (ops[i] == "getNewsFeed") {
                auto res = tw->getNewsFeed(a[0]);
                string s = "[";
                for (int j = 0; j < (int)res.size(); j++) {
                    if (j) s += ", ";
                    s += to_string(res[j]);
                }
                s += "]";
                out.push_back(s);
            } else if (ops[i] == "follow") {
                tw->follow(a[0], a[1]);
                out.push_back("null");
            } else if (ops[i] == "unfollow") {
                tw->unfollow(a[0], a[1]);
                out.push_back("null");
            }
        }
        cout << "[";
        for (int i = 0; i < (int)out.size(); i++) {
            if (i) cout << ", ";
            cout << out[i];
        }
        cout << "]\n";
        delete tw;
    }
    return 0;
}
