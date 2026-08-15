// Link: https://leetcode.com/problems/maximum-average-pass-ratio/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double gain(int pass, int total) {
        return (double)(pass + 1) / (total + 1) - (double)pass / total;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int,int>>> pq;
        for (auto& c : classes) {
            pq.push({gain(c[0], c[1]), {c[0], c[1]}});
        }
        while (extraStudents--) {
            auto [g, pt] = pq.top(); pq.pop();
            int p = pt.first + 1, t = pt.second + 1;
            pq.push({gain(p, t), {p, t}});
        }
        double sum = 0;
        int n = classes.size();
        while (!pq.empty()) {
            auto [g, pt] = pq.top(); pq.pop();
            sum += (double)pt.first / pt.second;
        }
        return sum / n;
    }
};
