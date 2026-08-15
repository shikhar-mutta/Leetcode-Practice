// Link: https://leetcode.com/problems/reward-top-k-students/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string> pos(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> neg(negative_feedback.begin(), negative_feedback.end());

        int n = report.size();
        vector<pair<int,int>> scores(n);
        for (int i = 0; i < n; i++) {
            stringstream ss(report[i]);
            string w;
            int score = 0;
            while (ss >> w) {
                if (pos.count(w)) score += 3;
                else if (neg.count(w)) score -= 1;
            }
            scores[i] = {score, student_id[i]};
        }

        sort(scores.begin(), scores.end(), [](auto &a, auto &b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });

        vector<int> ans;
        for (int i = 0; i < k; i++) ans.push_back(scores[i].second);
        return ans;
    }
};
