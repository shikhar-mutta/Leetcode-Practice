// Link: https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool fits(const vector<char>& run, const string& w) {
        if (run.size() != w.size()) return false;
        for (int i = 0; i < (int)run.size(); i++) {
            if (run[i] != ' ' && run[i] != w[i]) return false;
        }
        return true;
    }

    bool tryRuns(const vector<vector<char>>& lines, const string& word) {
        string rev(word.rbegin(), word.rend());
        for (auto& line : lines) {
            vector<char> run;
            for (int i = 0; i <= (int)line.size(); i++) {
                if (i < (int)line.size() && line[i] != '#') {
                    run.push_back(line[i]);
                } else {
                    if (!run.empty()) {
                        if (fits(run, word) || fits(run, rev)) return true;
                    }
                    run.clear();
                }
            }
        }
        return false;
    }

    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        if (tryRuns(board, word)) return true;
        vector<vector<char>> cols(n, vector<char>(m));
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cols[j][i] = board[i][j];
        return tryRuns(cols, word);
    }
};
