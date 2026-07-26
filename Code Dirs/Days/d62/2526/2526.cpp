// Link: https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) per consec call
// SC: O(1)
// Approach: track a running count of how many times "value" has been
// seen consecutively, resetting to 0 whenever a different number
// arrives. consec returns whether that running count has reached k.
class DataStream {
    int value;
    int pastCounter;
    int k;

public:
    DataStream(int value, int k) : value(value), pastCounter(0), k(k) {}

    bool consec(int num) {
        if (num == value) {
            pastCounter++;
        } else {
            pastCounter = 0;
        }

        return pastCounter >= k;
    }
};
