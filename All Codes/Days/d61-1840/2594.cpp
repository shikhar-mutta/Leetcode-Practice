// Link: https://leetcode.com/problems/minimum-time-to-repair-cars/description/

#include <bits/stdc++.h>
using namespace std;

// TC: V1 O(101 log(cars^2)) via a rank-frequency table, used when there are
//     many mechanics (>=256) so grouping by distinct rank value pays off;
//     V2 O(ranks.size() * log(cars^2)), used otherwise.
// SC: O(1) extra (V1's frequency array is fixed-size 101)
// Approach: binary search the answer time m. A mechanic of rank r can
// repair floor(sqrt(m/r)) cars in time m, so feasibility of m is checking
// whether the summed capacity across mechanics reaches >= cars. V1 speeds
// this check up by bucketing mechanics by rank (ranks are bounded by 100)
// so repeated ranks are handled with one multiplication instead of a
// per-mechanic loop; V2 is the straightforward per-mechanic version, cheaper
// when there just aren't many mechanics to begin with.
class Solution {
public:
    long long repairCarsV1(vector<int>& ranks, int cars) {
        long long l = 0, r = 100LL * cars * cars;
        array<int, 101> f = {};
        for (int r : ranks)
            ++f[r];
        while (r - l > 1) {
            long long m = (r + l) / 2;
            long long c = 0;
            for (int r = 0; r < 101; ++r) {
                if (!f[r])
                    continue;
                c += (long long)sqrt((double)m / r) * f[r];
                if (c >= cars)
                    break;
            }
            (c >= cars ? r : l) = m;
        }
        return r;
    }

    long long repairCarsV2(vector<int>& ranks, int cars) {
        long long l = 0, r = 100LL * cars * cars;
        while (r - l > 1) {
            long long m = (r + l) / 2;
            long long c = 0;
            for (int r : ranks) {
                c += sqrt((double)m / r);
                if (c >= cars)
                    break;
            }
            (c >= cars ? r : l) = m;
        }
        return r;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        if (ranks.size() >= 256)
            return repairCarsV1(ranks, cars);
        return repairCarsV2(ranks, cars);
    }
};
