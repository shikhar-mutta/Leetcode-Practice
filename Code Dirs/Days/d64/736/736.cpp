// Link: https://leetcode.com/problems/parse-lisp-expression/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
//  Approach: Use a recursive function to evaluate the expression. Maintain a scope for variable assignments using an unordered_map. Handle 'let', 'add', and 'mult' expressions accordingly, and parse tokens while respecting parentheses to ensure correct evaluation of nested expressions.
class Solution
{
public:
    string expression;

    int evaluate(string expression)
    {
        this->expression = expression;
        int pos = 0;
        unordered_map<string, vector<int>> scope;
        return eval(pos, scope);
    }

private:
    int eval(int &pos, unordered_map<string, vector<int>> &scope)
    {
        if (expression[pos] != '(')
        {
            return parseAtom(pos, scope);
        }

        pos++; // skip '('
        int result;
        vector<string> assigned;

        if (expression[pos] == 'l')
        {             // let
            pos += 4; // skip "let "
            while (true)
            {
                int save = pos;
                string raw = parseTokenRespectingParens(pos);

                if (expression[pos] == ')')
                {
                    // raw was the final expr; re-parse properly via eval
                    pos = save;
                    result = eval(pos, scope);
                    break;
                }
                else
                {
                    // raw is a variable name (guaranteed bare token)
                    pos++; // skip space
                    int val = eval(pos, scope);
                    scope[raw].push_back(val);
                    assigned.push_back(raw);
                    pos++; // skip space after e_i
                }
            }
        }
        else if (expression[pos] == 'a')
        { // add
            pos += 4;
            int v1 = eval(pos, scope);
            pos++;
            int v2 = eval(pos, scope);
            result = v1 + v2;
        }
        else
        { // mult
            pos += 5;
            int v1 = eval(pos, scope);
            pos++;
            int v2 = eval(pos, scope);
            result = v1 * v2;
        }

        pos++; // skip ')'
        for (auto &var : assigned)
            scope[var].pop_back();
        return result;
    }

    // Extracts the next unit as a raw substring, WITHOUT evaluating.
    // If it starts with '(', consumes the whole matching parenthesized group
    // (so nested parens don't confuse the peek). Otherwise scans to the
    // next space or ')'.
    string parseTokenRespectingParens(int &pos)
    {
        int start = pos;
        if (expression[pos] == '(')
        {
            int depth = 0;
            do
            {
                if (expression[pos] == '(')
                    depth++;
                else if (expression[pos] == ')')
                    depth--;
                pos++;
            } while (depth > 0);
        }
        else
        {
            while (pos < (int)expression.size() && expression[pos] != ' ' && expression[pos] != ')')
            {
                pos++;
            }
        }
        return expression.substr(start, pos - start);
    }

    int parseAtom(int &pos, unordered_map<string, vector<int>> &scope)
    {
        int start = pos;
        while (pos < (int)expression.size() && expression[pos] != ' ' && expression[pos] != ')')
        {
            pos++;
        }
        string token = expression.substr(start, pos - start);
        if (isdigit(token[0]) || token[0] == '-')
            return stoi(token);
        return scope[token].back();
    }
};