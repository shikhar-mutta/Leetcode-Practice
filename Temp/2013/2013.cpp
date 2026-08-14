// Link: https://leetcode.com/problems/detect-squares/description/

#include <bits/stdc++.h>
using namespace std;

class DetectSquares {
    unordered_map<int, unordered_map<int,int>> cnt;
public:
    DetectSquares() {}

    void add(vector<int> point) {
        cnt[point[0]][point[1]]++;
    }

    int count(vector<int> point) {
        int x = point[0], y = point[1];
        if (!cnt.count(x)) return 0;
        int ans = 0;
        for (auto& [y2, c2] : cnt[x]) {
            if (y2 == y) continue;
            int side = y2 - y;
            for (int x3 : {x + side, x - side}) {
                if (!cnt.count(x3)) continue;
                auto& m = cnt[x3];
                auto it1 = m.find(y), it2 = m.find(y2);
                if (it1 != m.end() && it2 != m.end()) {
                    ans += c2 * it1->second * it2->second;
                }
            }
        }
        return ans;
    }
};
