class Solution {
public:
    int minOperations(vector<int>& nums, int k)
    {
        int TotalXOR = 0;
        for(int Num : nums)
        {
            TotalXOR ^= Num;
        }
        
        int Count = 0;
        while(k > 0 || TotalXOR)
        {
            if((k & 1) != (TotalXOR & 1))
            {
                Count++;
            }
            
            k >>= 1;
            TotalXOR >>= 1;
        }
        return Count;
    }
};