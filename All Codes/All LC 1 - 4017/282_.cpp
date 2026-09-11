// Link: https://leetcode.com/problems/expression-add-operators/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> addOperators(string num, int target)
    {
        vector<string> res;
        if (num.empty())
            return res;
        backtrack(num, target, 0, "", 0, 0, res);
        return res;
    }

private:
    // TC: O(4^n). SC: O(n).
    // curVal = value of expression so far, prev = last operand (signed, for *)
    void backtrack(const string &num,
                   long long target,
                   int pos,
                   string expr,
                   long long curVal,
                   long long prev,
                   vector<string> &res)
    {
        if (pos == (int)num.size()) // end of string reached
        {
            if (curVal == target)
                res.push_back(expr);
            return;
        }
        // try all possible splits of the remaining string into a new operand
        for (int i = pos; i < (int)num.size(); i++)
        {
            // no leading zeros: a multi-digit operand can't start with '0'
            if (i > pos && num[pos] == '0')
                break;
            string curStr = num.substr(pos, i - pos + 1);
            long long cur = stoll(curStr);
            if (pos == 0)
            {
                backtrack(num, target, i + 1, curStr, cur, cur, res);
            }
            else
            {
                // operator order *, -, + to match expected output ordering
                // for '*', undo the last operand and re-multiply it (operator precedence)
                backtrack(num, target, i + 1, expr + "*" + curStr,
                          curVal - prev + prev * cur, prev * cur, res);
                // For '-', we subtract the new operand from the current value and set prev to -cur.
                backtrack(num, target, i + 1, expr + "-" + curStr,
                          curVal - cur, -cur, res);
                // For '+', we add the new operand to the current value and set prev to cur.
                backtrack(num, target, i + 1, expr + "+" + curStr,
                          curVal + cur, cur, res);
            }
        }
    }

    // public:
    //     // TC: O(4^n). SC: O(n).
    //     using int64 = long long; // To avoid overflow when multiplying two 10-digit numbers.
    //     char mExpr[20];          // The longest expression is 19 characters: 10 digits and 9 operators.
    //     int mDigits[10];         // The input number has at most 10 digits.
    //     char const *mNumText;    // To avoid repeated calls to num.c_str().
    //     int mLengthSubOne;       // index of the last digit (num.length() - 1)
    //     int64 mTarget;           // The target value to compare against.
    //     vector<string> mResult;  // To store the valid expressions that evaluate to the target.

    //     vector<string> addOperators(string num, int target)
    //     {
    //         mTarget = target;
    //         mNumText = num.c_str();                  // cache char buffer (avoid repeated c_str()/[] calls)
    //         mLengthSubOne = num.length() - 1;        // index of the last digit
    //         for (int i = 0; i <= mLengthSubOne; ++i) // store digits in an array
    //             mDigits[i] = num[i] - '0';

    //         // Build the first operand digit by digit. After taking i+1 digits,
    //         // recurse to place an operator before the rest of the string.
    //         int64 value = 0;
    //         for (int i = 0; i < mLengthSubOne; ++i)
    //         {
    //             if (i > 0 && mDigits[0] == 0) // no leading-zero operands (e.g. "05")
    //                 break;

    //             value = 10 * value + mDigits[i];
    //             mExpr[i] = mNumText[i]; // copy digit into the expression buffer
    //             evalDFS(i + 1, i + 1, value, value);
    //         }

    //         // Special case: the whole number used as a single operand, no operators.
    //         if (!(mLengthSubOne > 0 && mDigits[0] == 0))
    //         {
    //             value = 10 * value + mDigits[mLengthSubOne];
    //             if (mTarget == value)
    //                 mResult.emplace_back(num);
    //         }

    //         return std::move(mResult);
    //     }

    //     // index    : position in num where the next operand starts
    //     // exprLen  : current length of the expression built in mExpr
    //     // accValue : value of the expression so far
    //     // lastValue: value of the last operand (signed) — needed to fix up '*' precedence
    //     void evalDFS(int index, int exprLen, int64 accValue, int64 lastValue)
    //     {
    //         int64 value = 0;
    //         int op = exprLen++; // reserve one slot for the operator char before this operand

    //         for (int i = index; i < mLengthSubOne; ++i)
    //         {
    //             if (i > index && mDigits[index] == 0) // no leading-zero operands
    //                 break;

    //             value = 10 * value + mDigits[i];
    //             mExpr[exprLen++] = mNumText[i]; // append this digit

    //             // Try each operator before this operand, then recurse on the rest.
    //             // Order *, -, + matches the expected output ordering.
    //             // For '*', undo the last operand and re-multiply it (operator precedence).
    //             mExpr[op] = '*';
    //             evalDFS(i + 1, exprLen, accValue -
    //                                         // Last operand must run to the final digit; check all 3 operators here.
    //                                         if (!(mLengthSubOne > index && mDigits[index] == 0)) {
    //             value = 10 * value + mDigits[mLengthSubOne];
    //             mExpr[exprLen++] = mNumText[mLengthSubOne];

    //             if (mTarget == accValue + value)
    //             {
    //                 mExpr[op] = '+';
    //                 mResult.emplace_back(mExpr, mExpr + exprLen);
    //             }

    //             if (mTarget == accValue - value)
    //             {
    //                 mExpr[op] = '-';
    //                 mResult.emplace_back(mExpr, mExpr + exprLen);
    //             }

    //             if (mTarget == accValue - lastValue + lastValue * value)
    //             {
    //                 mExpr[op] = '*';
    //                 mResult.emplace_back(mExpr, mExpr + exprLen);
    //             } } lastValue + lastValue * value,
    //                     lastValue * value);

    //             mExpr[op] = '-';
    //             evalDFS(i + 1, exprLen, accValue - value, -value);

    //             mExpr[op] = '+';
    //             evalDFS(i + 1, exprLen, accValue + value, value);
    //         }

    //         // Last operand must run to the final digit; check all 3 operators here.
    //         if (!(mLengthSubOne > index && mDigits[index] == 0))
    //         {
    //             value = 10 * value + mDigits[mLengthSubOne];
    //             mExpr[exprLen++] = mNumText[mLengthSubOne];

    //             if (mTarget == accValue - lastValue + lastValue * value)
    //             {
    //                 mExpr[op] = '*';
    //                 mResult.emplace_back(mExpr, mExpr + exprLen);
    //             }

    //             if (mTarget == accValue - value)
    //             {
    //                 mExpr[op] = '-';
    //                 mResult.emplace_back(mExpr, mExpr + exprLen);
    //             }

    //             if (mTarget == accValue + value)
    //             {
    //                 mExpr[op] = '+';
    //                 mResult.emplace_back(mExpr, mExpr + exprLen);
    //             }
    //         }
    //     }
};
