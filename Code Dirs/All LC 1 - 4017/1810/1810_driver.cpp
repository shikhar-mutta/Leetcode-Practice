#include <bits/stdc++.h>
using namespace std;
#include "1810.cpp"

class MockGridMaster : public GridMaster {
public:
    vector<vector<int>> g; // -1 blocked, else cost of entering
    int rows, cols;
    int curR, curC;
    int tR, tC;

    MockGridMaster(vector<vector<int>>& grid_, int startR, int startC, int targetR_, int targetC_) {
        g = grid_;
        rows = g.size(); cols = g[0].size();
        curR = startR; curC = startC;
        tR = targetR_; tC = targetC_;
    }

    pair<int,int> delta(char d) {
        if (d == 'U') return {-1, 0};
        if (d == 'D') return {1, 0};
        if (d == 'L') return {0, -1};
        return {0, 1};
    }

    bool canMove(char direction) override {
        auto [dr, dc] = delta(direction);
        int nr = curR + dr, nc = curC + dc;
        if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) return false;
        return g[nr][nc] != -1;
    }

    int move(char direction) override {
        if (!canMove(direction)) return -1;
        auto [dr, dc] = delta(direction);
        curR += dr; curC += dc;
        return g[curR][curC];
    }

    bool isTarget() override {
        return curR == tR && curC == tC;
    }
};

int main() {
    {
        vector<vector<int>> g = {{2,1,4},{3,3,1},{1,5,4}};
        MockGridMaster master(g, 0, 0, 2, 2);
        Solution sol;
        cout << sol.findShortestPath(master) << "\n";
    }
    {
        vector<vector<int>> g = {{1,3,-1},{-1,2,-1},{-1,1,-1}};
        MockGridMaster master(g, 0, 0, 2, 0);
        Solution sol;
        cout << sol.findShortestPath(master) << "\n";
    }
    {
        vector<vector<int>> g = {{5}};
        MockGridMaster master(g, 0, 0, 0, 0);
        Solution sol;
        cout << sol.findShortestPath(master) << "\n";
    }

    return 0;
}
