// Link: https://leetcode.com/problems/longest-absolute-file-path/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(depth)
// Approach: split by '\n', count leading tabs for depth, maintain a stack
// of cumulative path lengths per depth; track max on files (containing '.')
class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> stack{0}; // stack[d] = cumulative length up to depth d (excluding trailing '/')
        int best = 0;
        stringstream ss(input);
        string line;
        while (getline(ss, line, '\n')) {
            int depth = 0;
            while (depth < (int)line.size() && line[depth] == '\t') depth++;
            string name = line.substr(depth);

            if ((int)stack.size() > depth + 1) stack.resize(depth + 1);

            int len = stack[depth] + (int)name.size() + (depth > 0 ? 1 : 0);
            if (name.find('.') != string::npos) {
                best = max(best, len);
            } else {
                stack.push_back(len);
            }
        }
        return best;
    }
};
