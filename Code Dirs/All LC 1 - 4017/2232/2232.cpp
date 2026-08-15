// Link: https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minimizeResult(string expression) {
        int plusPos = expression.find('+');
        string left = expression.substr(0, plusPos);
        string right = expression.substr(plusPos + 1);

        unsigned long long bestVal = ULLONG_MAX;
        string bestStr;

        for (int i = 0; i < (int)left.size(); i++) {
            for (int j = 1; j <= (int)right.size(); j++) {
                string prefixStr = left.substr(0, i);
                string innerLeft = left.substr(i);
                string innerRight = right.substr(0, j);
                string suffixStr = right.substr(j);

                unsigned long long sumVal = stoull(innerLeft) + stoull(innerRight);
                unsigned long long prefixVal = prefixStr.empty() ? 1ULL : stoull(prefixStr);
                unsigned long long suffixVal = suffixStr.empty() ? 1ULL : stoull(suffixStr);
                unsigned long long totalVal = prefixVal * sumVal * suffixVal;

                string resultStr = prefixStr + "(" + innerLeft + "+" + innerRight + ")" + suffixStr;

                if (totalVal < bestVal ||
                    (totalVal == bestVal && (resultStr.size() < bestStr.size() ||
                        (resultStr.size() == bestStr.size() && resultStr < bestStr)))) {
                    bestVal = totalVal;
                    bestStr = resultStr;
                }
            }
        }
        return bestStr;
    }
};
