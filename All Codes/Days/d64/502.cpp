// Link: https://leetcode.com/problems/ipo/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
//  Approach: Sort projects by capital required. Use a max-heap to keep track of the profits of the projects that can be started with the current capital. For each of the k rounds, add all projects that can be started with the current capital to the max-heap, then pop the project with the maximum profit from the heap and add its profit to the current capital. Repeat this process for k rounds or until there are no more projects that can be started.
enum Type
{
    MAX_HEAP = 1,
    MIN_HEAP
};

template <typename T>
struct PQueue
{
    T *arr = nullptr;
    int N = 0;        // heapsize
    int capacity = 0; // capacity;
    Type type;
    PQueue(Type _type = MAX_HEAP)
    {
        capacity = 10;
        assert(capacity > 0);
        arr = new T[capacity + 1];
        type = _type;
    }

    void resize()
    {
        capacity *= 2;
        T *temp = new T[capacity + 1];
        for (int i = 1; i <= N; i++)
            temp[i] = std::move(arr[i]);
        delete[] arr;
        arr = temp;
    }

    int size() { return N; }

    int left(int i) { return 2 * i; }

    int right(int i) { return 2 * i + 1; }

    int parent(int i) { return i / 2; }

    bool empty() { return N == 0; }

    void push(T v)
    {
        if (N == capacity)
        {
            resize();
        }
        arr[++N] = v;
        if (N == 1)
            return;
        if (type == MAX_HEAP)
        {
            max_heapify_up(N);
            return;
        }
        min_heapify_up(N);
    }

    void pop()
    {
        if (N == 0)
        {
            cerr << "[Warning] Pop in empty queue\n";
            assert(N > 0);
        }
        swap(arr[1], arr[N]);
        N--;
        if (N == 0)
            return;
        if (type == MAX_HEAP)
        {
            max_heapify_down(1);
            return;
        }
        min_heapify_down(1);
    }

    T top()
    {
        if (N == 0)
        {
            cerr << "[Warning] Top in empty queue\n";
            assert(N > 0);
        }
        return arr[1];
    }

    void max_heapify_up(int i)
    {
        if (i == 1)
            return;
        int p = parent(i);
        if (arr[i] > arr[p])
        {
            swap(arr[i], arr[p]);
            max_heapify_up(p);
        }
    }

    void min_heapify_up(int i)
    {
        if (i == 1)
            return;
        int p = parent(i);
        if (arr[i] < arr[p])
        {
            swap(arr[i], arr[p]);
            min_heapify_up(p);
        }
    }

    void min_heapify_down(int i)
    {
        int l = left(i);
        int r = right(i);
        int lowest = i;
        if (l <= N && arr[l] < arr[lowest])
            lowest = l;
        if (r <= N && arr[r] < arr[lowest])
            lowest = r;
        if (lowest != i)
        {
            swap(arr[i], arr[lowest]);
            min_heapify_down(lowest);
        }
    }

    void max_heapify_down(int i)
    {
        int l = left(i);
        int r = right(i);
        int largest = i;
        if (l <= N && arr[l] > arr[largest])
            largest = l;
        if (r <= N && arr[r] > arr[largest])
            largest = r;
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            max_heapify_down(largest);
        }
    }
};

using pii = pair<int, int>;
using heap = PQueue<int>;

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits,
                             vector<int> &capital)
    {
        vector<pii> proyects;
        for (int i = 0; i < profits.size(); i++)
            proyects.push_back({capital[i], profits[i]});
        std::sort(proyects.begin(), proyects.end());
        heap h;
        int j = 0;
        for (int i = 0; i < k; i++)
        {
            while (j < proyects.size() && proyects[j].first <= w)
            {
                h.push(proyects[j].second);
                j++;
            }

            if (!h.empty())
                w = w + h.top();
            if (!h.empty())
                h.pop();
        }
        return w;
    }
};