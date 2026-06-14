#include <bits/stdc++.h>
using namespace std;
#include "355.cpp"

vector<string> parseOps(const string& s) {
    vector<string> ops;
    string body = s.substr(1, s.size() - 2);
    bool in = false; string cur;
    for (char c : body) {
        if (c == '"') { in = !in; continue; }
        if (c == ',' && !in) { ops.push_back(cur); cur = ""; continue; }
        cur += c;
    }
    if (!cur.empty()) ops.push_back(cur);
    return ops;
}

vector<vector<int>> parseArgs(const string& s) {
    vector<vector<int>> result;
    int dep = 0; string cur;
    for (char c : s) {
        if (c == '[') { dep++; if (dep > 2) cur += c; }
        else if (c == ']') {
            dep--;
            if (dep == 1) {
                vector<int> row;
                stringstream ss(cur);
                string t;
                while (getline(ss, t, ',')) if (!t.empty()) row.push_back(stoi(t));
                result.push_back(row);
                cur = "";
            } else if (dep > 0) cur += c;
        } else if (dep > 1) cur += c;
    }
    return result;
}

int main() {
    int t; cin >> t; cin.ignore();
    while (t--) {
        string opsLine, argsLine;
        getline(cin, opsLine);
        getline(cin, argsLine);

        auto ops  = parseOps(opsLine);
        auto args = parseArgs(argsLine);

        Twitter* obj = nullptr;
        cout << "[";
        for (int i = 0; i < (int)ops.size(); i++) {
            if (i) cout << ", ";
            if (ops[i] == "Twitter") {
                obj = new Twitter();
                cout << "null";
            } else if (ops[i] == "postTweet") {
                obj->postTweet(args[i][0], args[i][1]);
                cout << "null";
            } else if (ops[i] == "getNewsFeed") {
                auto res = obj->getNewsFeed(args[i][0]);
                cout << "[";
                for (int j = 0; j < (int)res.size(); j++) {
                    if (j) cout << ", ";
                    cout << res[j];
                }
                cout << "]";
            } else if (ops[i] == "follow") {
                obj->follow(args[i][0], args[i][1]);
                cout << "null";
            } else if (ops[i] == "unfollow") {
                obj->unfollow(args[i][0], args[i][1]);
                cout << "null";
            }
        }
        cout << "]\n";
        delete obj;
    }
    return 0;
}
