class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost)
    {
        const int N = static_cast<int>(nums.size());
        long long Left =  1, Right = 1000000;
        long long MinCost = GetCost(nums, cost, N, 1);
        
        while(Left < Right)
        {
            long long Middle = (Left + Right) / 2;
            
            long long Result1 = GetCost(nums, cost, N, Middle);
            long long Result2 = GetCost(nums, cost, N, Middle + 1);
            
            MinCost = min(Result1, Result2);
            
            if(Result1 < Result2)
            {
                Right = Middle;
            }
            else
            {
                Left = Middle + 1;
            }
        }
        
        return MinCost;
    }
    
private:
    long long GetCost(vector<int>& Nums, vector<int>& Cost, const int N, const int Make)
    {
        long long Result = 0;
        
        for(int i = 0; i < N; i++)
        {
            long long Temp = static_cast<long long>(Nums[i] - Make);
            Result += abs(Temp) * Cost[i];
        }
        
        return Result;
    }
};