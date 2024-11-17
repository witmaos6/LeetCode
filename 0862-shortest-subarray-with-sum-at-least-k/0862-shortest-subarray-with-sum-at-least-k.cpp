class Solution {
    using Pair = pair<long long, int>;
public:
    int shortestSubarray(vector<int>& nums, int k)
    {
        const int N = static_cast<int>(nums.size());
        
        vector<long long> PrefixSum(N);
        int MinLength = INT_MAX;
        long long CurrSum = 0;
        deque<Pair> PrefixSums;
        for(int Right = 0; Right < N; ++Right)
        {
            CurrSum += nums[Right];
            
            if(CurrSum >= k)
            {
                MinLength = min(MinLength, Right + 1);
            }
            
            while(!PrefixSums.empty() && CurrSum - PrefixSums.front().first >= k)
            {
                auto[PrefixSum, Index] = PrefixSums.front();
                PrefixSums.pop_front();
                MinLength = min(MinLength, Right - Index);
            }
            
            while(!PrefixSums.empty() && PrefixSums.back().first > CurrSum)
            {
                PrefixSums.pop_back();
            }
            PrefixSums.emplace_back(CurrSum, Right);
        }
        
        return (MinLength == INT_MAX) ? -1 : MinLength;
    }
};