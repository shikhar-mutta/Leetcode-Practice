// Link: https://leetcode.com/problems/count-beautiful-numbers/description/

#include <bits/stdc++.h>
using namespace std;

static unordered_map<string, int> dp3490;
class Solution {
public:
    vector<int> getDigits(int n) {
        vector<int> res;
        while (n > 0) {
            res.push_back(n % 10);
            n /= 10;
        }
        return res;
    }

    int digitSum(int idx, int tight, int sum, string prod, int trailingZero,
                 vector<int>& digits) {
        if (idx < 0) {
            if (sum == 0) return 0;
            if (stoll(prod) % sum == 0) return 1;
            else return 0;
        }

        string key = to_string(idx) + "-" + to_string(tight) + "-" +
                     to_string(sum) + "-" + prod + "-" +
                     to_string(trailingZero);
        if (dp3490.count(key) && tight != -1) return dp3490[key];

        int ret{};

        int k = (tight) ? digits[idx] : 9;
        long long currProd = stoll(prod);

        for (int i = 0; i <= k; i++) {
            int newTight = (digits[idx] == i) ? tight : 0;
            int newTrailingZero{}, newSum{sum + i};
            string newProd{to_string(currProd * i)};
            if (trailingZero == 1 && i == 0) {
                newTrailingZero = 1;
                newSum = 0;
                newProd = "0";
            }
            if (trailingZero == 1 && i != 0)
                newProd = to_string(i);

            ret += digitSum(idx - 1, newTight, newSum, newProd, newTrailingZero,
                            digits);
        }

        if (!tight) dp3490[key] = ret;
        return ret;
    }

    int beautifulNumbers(int l, int r) {
        vector<int> leftDigits = getDigits(l - 1);
        vector<int> rightDigits = getDigits(r);
        int leftCount =
            digitSum(leftDigits.size() - 1, 1, 0, "0", 1, leftDigits);
        int rightCount =
            digitSum(rightDigits.size() - 1, 1, 0, "0", 1, rightDigits);

        return rightCount - leftCount;
    }
};
