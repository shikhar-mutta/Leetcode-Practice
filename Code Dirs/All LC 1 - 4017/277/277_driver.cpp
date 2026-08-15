#include <bits/stdc++.h>
using namespace std;

static vector<vector<int>> _matrix;

bool knows(int a, int b) {
    return _matrix[a][b] == 1;
}

#include "277.cpp"

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
        _matrix = _rvvi();
        int n = _matrix.size();
        Solution sol;
        auto res = sol.findCelebrity(n);
        cout << res << "\n";
    }
    return 0;
}
