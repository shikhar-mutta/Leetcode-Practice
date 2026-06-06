#include <bits/stdc++.h>
using namespace std;
#include "3242.cpp"

vector<string> parseOps(const string &s) {
    vector<string> ops;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '"') {
            int j = i + 1;
            while (j < (int)s.size() && s[j] != '"') j++;
            ops.push_back(s.substr(i + 1, j - i - 1));
            i = j;
        }
    }
    return ops;
}

// splits outer args array into per-operation arg strings
vector<string> parseArgs(const string &s) {
    vector<string> args;
    int depth = 0, start = -1;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '[') {
            depth++;
            if (depth == 2) start = i;
        } else if (s[i] == ']') {
            if (depth == 2) args.push_back(s.substr(start, i - start + 1));
            depth--;
        }
    }
    return args;
}

// parses "[[[r0c0,r0c1,...],[r1c0,...],...]]" into 2D grid
vector<vector<int>> parseGrid(const string &s) {
    vector<vector<int>> grid;
    vector<int> row;
    int depth = 0;
    string num;
    for (char c : s) {
        if (c == '[') {
            depth++;
            if (depth == 3) row.clear();
        } else if (c == ']') {
            if (depth == 3) {
                if (!num.empty()) { row.push_back(stoi(num)); num.clear(); }
                grid.push_back(row);
            }
            depth--;
        } else if (depth == 3) {
            if (c == ',') { if (!num.empty()) { row.push_back(stoi(num)); num.clear(); } }
            else if (c != ' ') num += c;
        }
    }
    return grid;
}

int parseInt(const string &s) {
    return stoi(s.substr(1, s.size() - 2));
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string opsLine, argsLine;
        getline(cin, opsLine);
        getline(cin, argsLine);

        auto ops  = parseOps(opsLine);
        auto args = parseArgs(argsLine);

        NeighborSum *obj = nullptr;
        cout << "[";
        for (int i = 0; i < (int)ops.size(); i++) {
            if (i > 0) cout << ", ";
            if (ops[i] == "NeighborSum") {
                auto grid = parseGrid(args[i]);
                obj = new NeighborSum(grid);
                cout << "null";
            } else if (ops[i] == "adjacentSum") {
                cout << obj->adjacentSum(parseInt(args[i]));
            } else if (ops[i] == "diagonalSum") {
                cout << obj->diagonalSum(parseInt(args[i]));
            }
        }
        cout << "]\n";
        delete obj;
    }
    return 0;
}
