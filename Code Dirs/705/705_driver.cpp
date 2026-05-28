#include <bits/stdc++.h>
using namespace std;
#include "705.cpp"

vector<string> parseOps(const string &s) {
    vector<string> ops;
    string body = s.substr(1, s.size() - 2);
    stringstream ss(body);
    string tok;
    while (getline(ss, tok, ',')) {
        tok.erase(remove(tok.begin(), tok.end(), '"'), tok.end());
        ops.push_back(tok);
    }
    return ops;
}

vector<vector<int>> parseArgs(const string &s) {
    vector<vector<int>> args;
    int dep = 0;
    string cur;
    for (char c : s) {
        if (c == '[') { dep++; if (dep > 2) cur += c; }
        else if (c == ']') {
            dep--;
            if (dep == 1) {
                vector<int> row;
                if (!cur.empty()) {
                    stringstream ss(cur);
                    string t;
                    while (getline(ss, t, ','))
                        if (!t.empty()) row.push_back(stoi(t));
                }
                args.push_back(row);
                cur = "";
            } else if (dep > 0) cur += c;
        } else if (dep > 1) cur += c;
    }
    return args;
}


struct TeeBuf : std::streambuf {
    std::streambuf *orig, *echo;
    TeeBuf(std::streambuf* o, std::streambuf* e) : orig(o), echo(e) {}
    int_type uflow() override {
        int_type c = orig->sbumpc();
        if (c != traits_type::eof()) echo->sputc(c);
        return c;
    }
    int_type underflow() override { return orig->sgetc(); }
    std::streamsize xsgetn(char* s, std::streamsize n) override {
        std::streamsize got = orig->sgetn(s, n);
        echo->sputn(s, got);
        return got;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    cin.rdbuf(new TeeBuf(cin.rdbuf(), cerr.rdbuf()));
    while (t--) {
        struct Guard { ~Guard() { cerr << "\n---\n"; } } _guard;
        string opsLine, argsLine;
        getline(cin, opsLine);
        getline(cin, argsLine);

        auto ops  = parseOps(opsLine);
        auto args = parseArgs(argsLine);

        MyHashSet *obj = nullptr;
        cout << "[";
        for (int i = 0; i < (int)ops.size(); i++) {
            if (i > 0) cout << ", ";
            if (ops[i] == "MyHashSet") {
                obj = new MyHashSet();
                cout << "null";
            } else if (ops[i] == "add") {
                obj->add(args[i][0]);
                cout << "null";
            } else if (ops[i] == "remove") {
                obj->remove(args[i][0]);
                cout << "null";
            } else if (ops[i] == "contains") {
                cout << (obj->contains(args[i][0]) ? "true" : "false");
            }
        }
        cout << "]\n";
        delete obj;
    }
    return 0;
}
