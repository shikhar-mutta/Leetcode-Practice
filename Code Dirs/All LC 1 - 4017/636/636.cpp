// Link: https://leetcode.com/problems/exclusive-time-of-functions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m) SC: O(n)
// Approach: use a call stack of function ids; on "start" credit any prior time gap to the top of stack (if non-empty) then push; on "end" credit elapsed time (inclusive) to top, pop, and reset the timer baseline to end+1.
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<int> st;
        int prevTime = 0;
        for (auto& log : logs) {
            size_t p1 = log.find(':');
            size_t p2 = log.find(':', p1+1);
            int id = stoi(log.substr(0, p1));
            string type = log.substr(p1+1, p2-p1-1);
            int time = stoi(log.substr(p2+1));
            if (type == "start") {
                if (!st.empty()) res[st.top()] += time - prevTime;
                st.push(id);
                prevTime = time;
            } else {
                res[st.top()] += time - prevTime + 1;
                st.pop();
                prevTime = time + 1;
            }
        }
        return res;
    }
};
