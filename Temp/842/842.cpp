// Link: https://leetcode.com/problems/split-array-into-fibonacci-sequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> splitIntoFibonacci(string num) {
        vector<long long> res;
        if (backtrack(num, 0, res)) {
            return vector<int>(res.begin(), res.end());
        }
        return {};
    }

private:
    bool backtrack(const string& num, int start, vector<long long>& res) {
        if (start == (int)num.size()) return res.size() >= 3;
        for (int len = 1; start + len <= (int)num.size(); len++) {
            if (len > 1 && num[start] == '0') break;
            string sub = num.substr(start, len);
            long long val = stoll(sub);
            if (val > INT_MAX) break;
            int m = res.size();
            if (m >= 2 && res[m-2] + res[m-1] != val) {
                if (res[m-2] + res[m-1] < val) break;
                continue;
            }
            res.push_back(val);
            if (backtrack(num, start + len, res)) return true;
            res.pop_back();
        }
        return false;
    }
};
