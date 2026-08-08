#include <bits/stdc++.h>
using namespace std;
#include "759.cpp"

// parses [[[1,2],[5,6]],[[1,3]],[[4,10]]]
vector<vector<vector<int>>> _rSchedule() {
    string s; getline(cin, s);
    vector<vector<vector<int>>> res;
    string inner = s.substr(1, s.size()-2); // strip outer [ ]
    int depth = 0; string cur;
    vector<string> empGroups;
    for (char c : inner) {
        if (c == '[') { depth++; if (depth > 1) cur += c; }
        else if (c == ']') { depth--; if (depth >= 1) cur += c; else { empGroups.push_back(cur); cur.clear(); } }
        else if (depth >= 1) cur += c;
    }
    for (auto& eg : empGroups) {
        // eg like "[1,2],[5,6]"
        vector<vector<int>> emp;
        int d2 = 0; string cur2;
        vector<string> ivGroups;
        for (char c : eg) {
            if (c == '[') { d2++; if (d2 > 1) cur2 += c; }
            else if (c == ']') { d2--; if (d2 >= 1) cur2 += c; else { ivGroups.push_back(cur2); cur2.clear(); } }
            else if (d2 >= 1) cur2 += c;
        }
        for (auto& ig : ivGroups) {
            vector<int> iv;
            stringstream ss(ig);
            string tok;
            while (getline(ss, tok, ',')) if (!tok.empty()) iv.push_back(stoi(tok));
            emp.push_back(iv);
        }
        res.push_back(emp);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto schedule = _rSchedule();
        Solution sol;
        auto res = sol.employeeFreeTime(schedule);
        cout << "[";
        for (size_t i = 0; i < res.size(); i++) {
            if (i) cout << ",";
            cout << "[" << res[i][0] << "," << res[i][1] << "]";
        }
        cout << "]\n";
    }
    return 0;
}
