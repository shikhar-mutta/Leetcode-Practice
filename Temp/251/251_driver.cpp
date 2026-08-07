#include <bits/stdc++.h>
using namespace std;
#include "251.cpp"

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
        auto vec = _rvvi();
        Vector2D obj(vec);
        vector<int> out;
        while (obj.hasNext()) out.push_back(obj.next());
        for (int i = 0; i < (int)out.size(); i++) { if (i) cout << " "; cout << out[i]; }
        cout << "\n";
    }
    return 0;
}
