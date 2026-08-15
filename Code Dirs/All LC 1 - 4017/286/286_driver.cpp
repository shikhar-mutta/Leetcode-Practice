#include <bits/stdc++.h>
using namespace std;
#include "286.cpp"

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
        auto rooms = _rvvi();
        for (auto& row : rooms)
            for (auto& v : row)
                if (v == 2147483647) v = INT_MAX;
        Solution sol;
        sol.wallsAndGates(rooms);
        cout << "[";
        for (int i = 0; i < (int)rooms.size(); i++) {
            if (i) cout << ",";
            cout << "[";
            for (int j = 0; j < (int)rooms[i].size(); j++) {
                if (j) cout << ",";
                cout << rooms[i][j];
            }
            cout << "]";
        }
        cout << "]\n";
    }
    return 0;
}
