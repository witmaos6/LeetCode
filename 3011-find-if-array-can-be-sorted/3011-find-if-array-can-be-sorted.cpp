class Solution {
public:
    bool canSortArray(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        vector<int> BitCounts(N);
        for(int i = 0; i < N; ++i)
        {
            BitCounts[i] = BitCount(nums[i]);
        }
        
        int Index = 0;
        int PrevMax = 0;
        while(Index < N)
        {
            int CurrMin = INT_MAX;
            int CurrMax = 0;
            int Last = Index;
            
            for(int i = Index; i < N; ++i)
            {
                if(BitCounts[Index] == BitCounts[i])
                {
                    CurrMin = min(CurrMin, nums[i]);
                    CurrMax = max(CurrMax, nums[i]);
                    ++Last;
                }
                else
                {
                    break;
                }
            }
            
            if(CurrMin < PrevMax)
            {
                return false;
            }
            Index = Last;
            PrevMax = CurrMax;
        }
        
        return true;
    }
    
    int BitCount(int Num)
    {
        int Count = 0;
        while(Num > 0)
        {
            if(Num & 1)
            {
                Count++;
            }
            Num >>= 1;
        }
        return Count;
    }
};