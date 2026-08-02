// Link: https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
//  Approach: Use a priority queue to maintain the k smallest elements in the current window of size dist + 2. The sum of these k smallest elements is the cost of the current window.
class Solution
{
public:
    template <class Value, class Storage, class Comparator>
    struct priority_queue_with_erase
    {
        const Value &top() const
        {
            purge();
            return queued.top();
        }
        void pop() { /*purge();*/ queued.pop(); }
        bool empty() const { return queued.size() == erased.size(); }
        size_t size() const { return queued.size() - erased.size(); }
        void push(const Value &v) { queued.push(v); }
        void erase(const Value &v) { erased.push(v); }

    private:
        void purge() const
        {
            while (!erased.empty() && erased.top() == queued.top())
            {
                erased.pop();
                queued.pop();
            }
        }
        mutable priority_queue<Value, Storage, Comparator> queued, erased;
    };

    struct sum_n_smallest
    {
        sum_n_smallest(vector<int>::const_iterator begin,
                       vector<int>::const_iterator end)
        {
            for (auto i = begin; i < end; ++i)
            {
                smaller.push(*i);
                sum += *i;
            }
        }

        void drop_and_add(int d, int a)
        {
            const int top_larger = larger.top();
            if (a >= top_larger == d >= top_larger)
            {
                if (a == d)
                    return;
                if (a >= top_larger)
                {
                    larger.erase(d);
                    larger.push(a);
                }
                else
                {
                    smaller.erase(d);
                    smaller.push(a);
                    sum += a - d;
                }
                return;
            }
            if (d < top_larger)
            {
                larger.pop();
                smaller.erase(d);
                smaller.push(top_larger);
                sum += top_larger - d;
            }
            else
            {
                larger.erase(d);
            }
            add(a);
        }

        void add(int i)
        {
            const int old_top = smaller.top();
            if (i < old_top)
            {
                smaller.pop();
                smaller.push(i);
                larger.push(old_top);
                sum += i - old_top;
            }
            else
            {
                larger.push(i);
            }
        }

        long long cost() const { return sum; }

    private:
        long long sum = 0;
        priority_queue_with_erase<int, vector<int>, less<>> smaller;
        priority_queue_with_erase<int, vector<int>, greater<>> larger;
    };

    long long special_case(const vector<int> &nums, int k) const
    {
        long long run_sum = 0;
        auto e = nums.begin() + k;
        for (auto i = nums.begin() + 1; i < e; ++i)
            run_sum += *i;

        long long min_run_sum = run_sum;
        auto ai = nums.begin() + k, di = nums.begin() + 1;
        for (; ai < nums.end(); ++ai, ++di)
        {
            run_sum += *ai - *di;
            min_run_sum = min(min_run_sum, run_sum);
        }
        return nums[0] + min_run_sum;
    }

    long long normal_case(const vector<int> &nums, int k, int dist) const
    {
        sum_n_smallest sum_n(nums.begin() + 1, nums.begin() + k);
        auto e = nums.begin() + dist + 2;
        for (auto i = nums.begin() + k; i < e; ++i)
            sum_n.add(*i);

        long long min_cost = sum_n.cost();
        auto ai = nums.begin() + dist + 2, di = nums.begin() + 1;
        for (; ai < nums.end(); ++ai, ++di)
        {
            sum_n.drop_and_add(*di, *ai);
            min_cost = min(min_cost, sum_n.cost());
        }
        return nums[0] + min_cost;
    }

    long long minimumCost(const vector<int> &nums, int k, int dist) const
    {
        return k == dist + 2 ? special_case(nums, k)
                             : normal_case(nums, k, dist);
    }
};
