class Solution {
    int N = 0;
    int Total = 0;
public:
    int subsetXORSum(vector<int>& nums)
    {
        N = static_cast<int>(nums.size());
        Total = accumulate(nums.begin(), nums.end(), 0);
        
        for(int i = 0; i < N; i++)
        {
            Recursion(nums, nums[i], i + 1);
        }
        
        return Total;
    }
    
private:
    void Recursion(const vector<int>& Nums, const int CurrNum, const int Index)
    {
        for(int i = Index; i < N; i++)
        {
            int Value = (CurrNum ^ Nums[i]);
            Total += Value;
            
            if(i + 1 < N)
            {
                Recursion(Nums, Value, i + 1);
            }
        }
    }
};