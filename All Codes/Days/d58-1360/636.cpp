// Link: https://leetcode.com/problems/exclusive-time-of-functions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(N) where N is the number of logs. We process each log exactly once.
    // SC: O(N) where N is the number of logs. In the worst case, all functions are nested, and we need to store all of them in the stack.
    //  Approach:
    //  1. We use a stack to keep track of the currently executing functions.
    //  2. We iterate through the logs, and for each log, we parse the function id, type (start or end), and timestamp.
    //  3. If the log is a start log, we check if there is a function currently executing (i.e., the stack is not empty). If so, we add the time difference between the current timestamp and the previous timestamp to the exclusive time of the function at the top of the stack. We then push the current function id onto the stack and update the previous timestamp to the current timestamp.
    //  4. If the log is an end log, we add the time difference between the current timestamp and the previous timestamp plus one (to account for the inclusive end time) to the exclusive time of the function at the top of the stack. We then pop the function id from the stack and update the previous timestamp to the current timestamp plus one.
    //  5. Finally, we return the result vector containing the exclusive times of all functions.
    vector<int> exclusiveTime(int n, vector<string> &logs)
    {
        vector<int> res(n, 0);
        stack<int> st;
        int prevTime = 0;
        for (auto &log : logs)
        {
            int c1 = log.find(':');
            int c2 = log.rfind(':');
            int id = stoi(log.substr(0, c1));
            string type = log.substr(c1 + 1, c2 - c1 - 1);
            int time = stoi(log.substr(c2 + 1));

            if (type == "start")
            {
                if (!st.empty())
                    res[st.top()] += time - prevTime;
                st.push(id);
                prevTime = time;
            }
            else
            {
                res[st.top()] += time - prevTime + 1;
                st.pop();
                prevTime = time + 1;
            }
        }
        return res;
    }
};
