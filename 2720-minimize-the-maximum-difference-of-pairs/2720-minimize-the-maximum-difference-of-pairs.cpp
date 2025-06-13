class Solution {
    int N = 0;
public:
    int minimizeMax(vector<int>& nums, int p)
    {
        N = static_cast<int>(nums.size());
        if(N == 1 || p == 0)
        {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        
        int Low = 0, High = nums[N - 1] - nums[0];
        
        while(Low < High)
        {
            int Middle = (Low + High) / 2;
            
            if(PossiblePair(nums, Middle, p))
            {
                High = Middle;
            }
            else
            {
                Low = Middle + 1;
            }
        }
        
        return Low;
    }
    
private:
    bool PossiblePair(vector<int>& Nums, int Middle, int Pair)
    {
        int Sum = 0;
        
        for(int i = 1; i < N; i++)
        {
            if(Nums[i] - Nums[i - 1] <= Middle)
            {
                Sum++;
                i++;
            }
        }
        if(Sum >= Pair)
        {
            return true;
        }
        
        return false;
    }
};