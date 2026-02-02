class Solution {
    long long Sum = 0;
    multiset<int> Small, Large;

    void Add(int X, int M)
    {
        Small.insert(X);
        Sum += X;
        if(Small.size() > M)
        {
            int ToMove = *Small.rbegin();
            Sum -= ToMove;
            Large.insert(ToMove);
            Small.erase(prev(Small.end()));
        }
    }

    void Remove(int X)
    {
        auto It = Small.find(X);
        if(It != Small.end())
        {
            Sum -= X;
            Small.erase(It);
            if(!Large.empty())
            {
                auto Lit = Large.begin();
                int ToMove = *Lit;
                Sum += ToMove;
                Small.insert(ToMove);
                Large.erase(Lit);
            }
        }
        else
        {
            auto Lit = Large.find(X);
            Large.erase(Lit);
        }
    }

public:
    long long minimumCost(vector<int>& nums, int k, int dist)
    {
        const int N = static_cast<int>(nums.size());
        k--;

        const int D = dist + 2;
        vector<int> Win(nums.begin() + 1, nums.begin() + D);

        nth_element(Win.begin(), Win.begin() + k, Win.end());
        Small = multiset<int>(Win.begin(), Win.begin() + k);
        Sum = accumulate(Win.begin(), Win.begin() + k, 0LL);
        Large = multiset<int>(Win.begin() + k, Win.end());

        long long Min = nums[0] + Sum;
        for(int l = 1, r = D; r < N; l++, r++)
        {
            Remove(nums[l]);
            Add(nums[r], k);

            Min = min(Min, nums[0] + Sum);
        }
        return Min;
    }
};