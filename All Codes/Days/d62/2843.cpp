// Link: https://leetcode.com/problems/count-symmetric-integers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) (fixed 100-entry precomputed tables, O(1) getCount calls)
// SC: O(1)
// Approach: answer via prefix counting, getCount(x) = number of symmetric
// integers in [x, 9999]; result = getCount(low) - getCount(high+1). vec[d] =
// count of pairs of d-digit halves (1..9 digit sums, or two-digit halves 10..18
// mapped by 20-d-1) whose two halves have equal digit sum, used to quickly sum
// over whole "leading small pair" ranges; sum[i] = digit sum of two-digit
// number i (or single digit padded). getCount branches on num's digit range
// (below 100, below 1000 — odd digit counts are never symmetric — or 4-digit)
// to combine a partial-range brute count with the precomputed vec[] totals for
// the remaining higher ranges.
class Solution {
public:

    int getCount(int num, vector<int> &vec, vector<int> &sum)
    {
        if(num>9999)
            return 0;
        int c=0, st, sm=0;
        if(num<100)
            {c = (99-num)/11 + 1;
            st=10;}
        else if(num<1000)
            st = 10;
        else{
            sm = sum[num/100];
            for(int i=num%100;i<=99;i++)
            {
                if(sum[i]==sm)
                    c++;
            }
            st = num/100+1;
        }

        for(int i = st;i<=99;i++)
        {
            c+=vec[sum[i]];
        }
        return c;
    }
    int countSymmetricIntegers(int low, int high) {

        vector<int> vec(20,0), sum(100+1,0);

        for(int i=1;i<=9;i++)
        {
            vec[i] = i+1;
        }

        for(int i=10;i<=18;i++)
        {
            vec[i] = 20-i-1;
        }
        for(int i = 0;i<=99;i++)
        {
            sum[i] = i%10 +i/10;
        }

        int c1,c2;
        c1 = getCount(low, vec, sum);
        c2 = getCount(high+1, vec, sum);

        return c1-c2;

    }
};
