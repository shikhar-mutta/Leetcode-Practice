// Link: https://leetcode.com/problems/stock-price-fluctuation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n), SC: O(n)
//   Approach:
//   1. We can use a hash table to store the latest price of each timestamp
//   2. We can use a max heap to store the maximum price of each timestamp
//   3. We can use a min heap to store the minimum price of each timestamp
//   4. We can use a variable to store the latest timestamp
//   5. We can use a variable to store the size of the max heap and min heap
//   6. We can use a variable to store the mask of the hash
class StockPrice
{
public:
    StockPrice()
    {
        unsigned cap = 1;
        while (cap < 200000)
            cap <<= 1;
        mask_ = cap - 1;
        slots_ = new Slot[cap]();
        max_heap_ = new Entry[100001];
        min_heap_ = new Entry[100001];
        max_sz_ = min_sz_ = 0;
        latest_ = 0;
    }

    ~StockPrice()
    {
        delete[] slots_;
        delete[] max_heap_;
        delete[] min_heap_;
    }

    void update(int ts, int price) noexcept
    {
        unsigned idx = hash(ts) & mask_;
        while (slots_[idx].key && slots_[idx].key != ts)
            idx = (idx + 1) & mask_;
        if (!slots_[idx].key)
            slots_[idx].key = ts;
        slots_[idx].val = price;

        unsigned i = max_sz_++;
        max_heap_[i] = {price, ts};
        while (i > 0)
        {
            unsigned par = (i - 1) >> 1;
            if (max_heap_[par].price >= price)
                break;
            max_heap_[i] = max_heap_[par];
            i = par;
        }
        max_heap_[i] = {price, ts};

        i = min_sz_++;
        min_heap_[i] = {price, ts};
        while (i > 0)
        {
            unsigned par = (i - 1) >> 1;
            if (min_heap_[par].price <= price)
                break;
            min_heap_[i] = min_heap_[par];
            i = par;
        }
        min_heap_[i] = {price, ts};

        if (ts > latest_)
            latest_ = ts;
    }

    int current() noexcept
    {
        unsigned idx = hash(latest_) & mask_;
        while (slots_[idx].key != latest_)
            idx = (idx + 1) & mask_;
        return slots_[idx].val;
    }

    int maximum() noexcept
    {
        while (true)
        {
            Entry top = max_heap_[0];
            unsigned idx = hash(top.ts) & mask_;
            while (slots_[idx].key != top.ts)
                idx = (idx + 1) & mask_;
            if (slots_[idx].val == top.price)
                return top.price;

            Entry last = max_heap_[--max_sz_];
            unsigned i = 0;
            while (true)
            {
                unsigned l = (i << 1) + 1;
                if (l >= max_sz_)
                    break;
                unsigned r = l + 1;
                unsigned child =
                    (r < max_sz_ && max_heap_[r].price > max_heap_[l].price)
                        ? r
                        : l;
                if (last.price >= max_heap_[child].price)
                    break;
                max_heap_[i] = max_heap_[child];
                i = child;
            }
            max_heap_[i] = last;
        }
    }

    int minimum() noexcept
    {
        while (true)
        {
            Entry top = min_heap_[0];
            unsigned idx = hash(top.ts) & mask_;
            while (slots_[idx].key != top.ts)
                idx = (idx + 1) & mask_;
            if (slots_[idx].val == top.price)
                return top.price;

            Entry last = min_heap_[--min_sz_];
            unsigned i = 0;
            while (true)
            {
                unsigned l = (i << 1) + 1;
                if (l >= min_sz_)
                    break;
                unsigned r = l + 1;
                unsigned child =
                    (r < min_sz_ && min_heap_[r].price < min_heap_[l].price)
                        ? r
                        : l;
                if (last.price <= min_heap_[child].price)
                    break;
                min_heap_[i] = min_heap_[child];
                i = child;
            }
            min_heap_[i] = last;
        }
    }

private:
    struct Slot
    {
        int key;
        int val;
    };
    struct Entry
    {
        int price;
        int ts;
    };

    static unsigned hash(int x) noexcept
    {
        return static_cast<unsigned>(x) * 2654435761u;
    }

    Slot *slots_;
    unsigned mask_;
    Entry *max_heap_;
    Entry *min_heap_;
    unsigned max_sz_;
    unsigned min_sz_;
    int latest_;
};