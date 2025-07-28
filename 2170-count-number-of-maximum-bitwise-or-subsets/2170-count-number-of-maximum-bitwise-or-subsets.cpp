class Solution {
    int N = 0;
public:
    int countMaxOrSubsets(vector<int>& nums)
    {
        int MaxOR = 0;
        N = static_cast<int>(nums.size());
        for(int& Num : nums)
        {
            MaxOR |= Num;
        }
        return Backtrack(nums, MaxOR, 0, 0);
    }
private:
    int Backtrack(vector<int>& Nums, int MaxOR, int Index, int CurrOR)
    {
        if(Index == N)
            return CurrOR == MaxOR ? 1 : 0;

        if(CurrOR == MaxOR)
            return 1 << (N - Index);

        int In = Backtrack(Nums, MaxOR, Index + 1, CurrOR | Nums[Index]);
        int Ex = Backtrack(Nums, MaxOR, Index + 1, CurrOR);
        return In + Ex;
    }
};