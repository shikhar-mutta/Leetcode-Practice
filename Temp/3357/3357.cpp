// Link: https://leetcode.com/problems/minimize-the-maximum-adjacent-element-difference/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Returns {feasibleWithin2Points, listOfPointsUsed (<=2)} via greedy interval piercing.
    pair<bool, vector<long long>> pierce(vector<pair<long long,long long>>& constraints) {
        if (constraints.empty()) return {true, {}};
        sort(constraints.begin(), constraints.end(), [](const pair<long long,long long>& a, const pair<long long,long long>& b) {
            return a.second < b.second;
        });
        vector<long long> points;
        for (auto& [lo, hi] : constraints) {
            if (!points.empty() && points.back() >= lo && points.back() <= hi) continue;
            points.push_back(hi);
            if ((int)points.size() > 2) return {false, {}};
        }
        return {true, points};
    }

    // Rigorous check: does there exist x,y with |x-y|<=D such that every interval contains x or y?
    bool piercingWithProximity(vector<pair<long long,long long>>& intervals, long long D) {
        if (intervals.empty()) return true;
        int m = intervals.size();
        // events: (x, type) type=0 -> interval becomes good at x=lo (remove from bad), type=1 -> becomes bad at x=hi+1 (add to bad)
        vector<tuple<long long,int,int>> evs; // (x, type, idx)
        for (int k = 0; k < m; k++) {
            evs.push_back({intervals[k].first, 0, k});
            evs.push_back({intervals[k].second + 1, 1, k});
        }
        sort(evs.begin(), evs.end());

        multiset<long long> badLos, badHis;
        for (auto& [lo, hi] : intervals) { badLos.insert(lo); badHis.insert(hi); }

        auto checkSegment = [&](long long rangeLo, long long rangeHi) -> bool {
            if (rangeLo > rangeHi) return false;
            if (badLos.empty()) return true;
            long long maxLo = *badLos.rbegin();
            long long minHi = *badHis.begin();
            if (maxLo > minHi) return false;
            long long lo2 = max(rangeLo, maxLo - D);
            long long hi2 = min(rangeHi, minHi + D);
            return lo2 <= hi2;
        };

        int n2 = evs.size();
        // initial segment before any event
        long long firstX = get<0>(evs[0]);
        if (checkSegment(1, firstX - 1)) return true;

        int i = 0;
        while (i < n2) {
            long long curX = get<0>(evs[i]);
            int j = i;
            while (j < n2 && get<0>(evs[j]) == curX) {
                auto& [x, type, idx] = evs[j];
                if (type == 0) {
                    badLos.erase(badLos.find(intervals[idx].first));
                    badHis.erase(badHis.find(intervals[idx].second));
                } else {
                    badLos.insert(intervals[idx].first);
                    badHis.insert(intervals[idx].second);
                }
                j++;
            }
            long long segHi = (j < n2) ? get<0>(evs[j]) - 1 : (long long)4e9;
            if (checkSegment(curX, segHi)) return true;
            i = j;
        }
        return false;
    }

    bool feasible(vector<int>& nums, long long D) {
        int n = nums.size();

        // first check fixed-fixed adjacent pairs directly
        for (int i = 0; i + 1 < n; i++) {
            if (nums[i] != -1 && nums[i+1] != -1) {
                if (llabs((long long)nums[i] - nums[i+1]) > D) return false;
            }
        }

        vector<pair<long long,long long>> constraintsA; // single-value-per-run (always valid strategy)
        vector<pair<long long,long long>> constraintsGen; // for the general "mixing allowed" proximity check

        int i = 0;
        while (i < n) {
            if (nums[i] != -1) { i++; continue; }
            int j = i;
            while (j < n && nums[j] == -1) j++;
            long long leftN = (i > 0) ? nums[i-1] : -1;
            long long rightN = (j < n) ? nums[j] : -1;
            bool hasLeft = (i > 0), hasRight = (j < n);
            int runLen = j - i;

            if (hasLeft && hasRight) {
                long long lo = max({leftN - D, rightN - D, 1LL});
                long long hi = min(leftN + D, rightN + D);
                if (lo <= hi) constraintsA.push_back({lo, hi});
                else constraintsA.push_back({1, 0}); // impossible marker

                if (runLen >= 2) {
                    constraintsGen.push_back({max(leftN - D, 1LL), leftN + D});
                    constraintsGen.push_back({max(rightN - D, 1LL), rightN + D});
                } else {
                    // single position: must satisfy both simultaneously (same as constraintsA)
                    if (lo <= hi) constraintsGen.push_back({lo, hi});
                    else constraintsGen.push_back({1, 0});
                }
            } else if (hasLeft) {
                auto iv = make_pair(max(leftN - D, 1LL), leftN + D);
                constraintsA.push_back(iv);
                constraintsGen.push_back(iv);
            } else if (hasRight) {
                auto iv = make_pair(max(rightN - D, 1LL), rightN + D);
                constraintsA.push_back(iv);
                constraintsGen.push_back(iv);
            }

            i = j;
        }

        // Check option A (always valid regardless of |x-y|)
        bool aOk = true;
        for (auto& [lo, hi] : constraintsA) if (lo > hi) { aOk = false; break; }
        if (aOk) {
            auto [ok, pts] = pierce(constraintsA);
            if (ok) return true;
        }

        // Check general mixing-allowed case (rigorous proximity-aware piercing)
        bool genOk = true;
        for (auto& [lo, hi] : constraintsGen) if (lo > hi) { genOk = false; break; }
        if (genOk && piercingWithProximity(constraintsGen, D)) return true;

        return false;
    }

    int minDifference(vector<int>& nums) {
        long long lo = 0, hi = 1000000000;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (feasible(nums, mid)) hi = mid;
            else lo = mid + 1;
        }
        return (int)lo;
    }
};
