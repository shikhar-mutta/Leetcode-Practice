// Link: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
//  Approach: build the n+1 gaps around meetings. For each meeting i,
//  removing it always lets its two neighboring gaps merge (worst case by
//  just sliding meeting i to touch one side, gaining gap[i]+gap[i+1] with
//  no capacity check needed). If some OTHER gap (not adjacent to i) is
//  large enough to fully host meeting i's duration, the meeting can be
//  moved entirely away instead, gaining the full gap[i]+dur[i]+gap[i+1].
//  Track the top-3 largest gaps (by value) so, excluding indices i and
//  i+1, we can always find a valid "other gap" candidate in O(1).
class Solution
{
public:
    int maxFreeTime(int event_time, vector<int> &start_time,
                    vector<int> &end_time)
    {
        int n = start_time.size();
        // go to every meeting one by one and check for its left and right gaps
        // . and then f you reschedule that meeting the combined gap would be
        // left+right+meeting duration . but this will happen only if you can
        // place that meeting somewhere else( in some gap different than left
        // right gap) .only possible if there exists some gap>= meeting duration
        // in some place else except left or right of that meeting ....  if that
        // is not possible at all the combined gap is left+right only as meeting
        // duration will be in that left+right+meeting duration wala gap

        // how to find if there is any gap>= meeting duration except right
        // before or after that meeint: prefix/ suffix maxmum gap arrays

        vector<int> prefix(n);
        vector<int> suffix(n);
        // prefix[i] means meeting[i] tak jitne bhi gaps hai usme se maximum gap
        // konsa hai suffix[i] means meeting[i] ke baad jitne gaps hai usme se
        // maximum gap konsa hai
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            // ith meeting
            if (i == 0)
            {
                int gap = start_time[i] - 0;
                prefix[i] = max(gap, maxi);
                maxi = prefix[i];
                continue;
            }
            // i=0 is done
            int gap = start_time[i] - end_time[i - 1];
            prefix[i] = max(maxi, gap);
            maxi = prefix[i];
        }
        // prefix gaps are done

        maxi = INT_MIN;
        for (int i = n - 1; i >= 0; i--)
        {
            // ith meeting
            if (i == n - 1)
            {
                int gap = event_time - end_time[i];
                suffix[i] = max(gap, maxi);
                maxi = suffix[i];
                continue;
            }
            // i=0 is done
            int gap = start_time[i + 1] - end_time[i];
            suffix[i] = max(maxi, gap);
            maxi = suffix[i];
        }
        // suffix is updated
        int maxgap = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            // traverse the meetings store left and right gaps
            int left_gap;
            int right_gap;
            if (i == 0)
            {
                left_gap = start_time[i] - 0;
                right_gap = start_time[i + 1] - end_time[i];
            }
            else if (i == n - 1)
            {
                right_gap = event_time - end_time[i];
                left_gap = start_time[i] - end_time[i - 1];
            }
            else
            {
                left_gap = start_time[i] - end_time[i - 1];
                right_gap = start_time[i + 1] - end_time[i];
            }

            // gaps are stored check if you can have any gap in prefix[i-1] or
            // suffix [i+1] with duration >= meeting duration
            int duration = end_time[i] - start_time[i];
            int combined_gap = left_gap + right_gap;
            if ((i != 0 && prefix[i - 1] >= duration) ||
                (i != n - 1 && suffix[i + 1] >= duration))
            {
                combined_gap += duration;
            }
            maxgap = max(maxgap, combined_gap);
        }
        return maxgap;
    }
};