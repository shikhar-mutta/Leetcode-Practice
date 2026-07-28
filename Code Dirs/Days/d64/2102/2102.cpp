// Link: https://leetcode.com/problems/sequentially-ordinal-rank-tracker/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(log n) per add, O(n) per get  SC: O(n)
// Approach: ordered set of (-score, name) sorts by score desc then name asc.
// The k-th call to get() must return the k-th best name in the CURRENT full
// ranking (not "next after previous element"), since later inserts can rank
// above an earlier answer and shift everyone's absolute position. Track the
// call count and walk to that index each time.
class SORTracker {
    set<pair<int,string>> st;
    int callCount = 0;
public:
    SORTracker() {}

    void add(string name, int score) {
        st.insert({-score, name});
    }

    string get() {
        callCount++;
        auto it = st.begin();
        advance(it, callCount - 1);
        return it->second;
    }
};
