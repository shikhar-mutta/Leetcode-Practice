#include <bits/stdc++.h>
using namespace std;
#include "489.cpp"

class SimRobot : public Robot {
    vector<vector<int>>& grid;
    int r, c, dir; // 0=up,1=right,2=down,3=left
    set<pair<int,int>> cleaned;
public:
    SimRobot(vector<vector<int>>& grid, int r, int c) : grid(grid), r(r), c(c), dir(0) {}

    bool move() override {
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        int nr = r + dr[dir], nc = c + dc[dir];
        if (nr < 0 || nr >= (int)grid.size() || nc < 0 || nc >= (int)grid[0].size() || grid[nr][nc] == 0) return false;
        r = nr; c = nc;
        return true;
    }
    void turnLeft() override { dir = (dir + 3) % 4; }
    void turnRight() override { dir = (dir + 1) % 4; }
    void clean() override { cleaned.insert({r, c}); }

    int cleanedCount() { return cleaned.size(); }
};

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
int _ri() { string s; getline(cin,s); return stoi(s); }

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto grid = _rvvi();
        int row = _ri();
        int col = _ri();

        int totalOpen = 0;
        for (auto& r : grid) for (int c : r) if (c == 1) totalOpen++;

        SimRobot robot(grid, row, col);
        Solution sol;
        sol.cleanRoom(robot);

        cout << (robot.cleanedCount() == totalOpen ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
