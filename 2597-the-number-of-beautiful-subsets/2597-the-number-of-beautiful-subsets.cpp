class Solution {
    int N = 0;
    int Result = 0;
public:
    int beautifulSubsets(vector<int>& nums, int k)
    {
        N = static_cast<int>(nums.size());
        Result += N;
        
        for(int i = 0; i < N - 1; i++)
        {
            vector<int> Subset = {nums[i]};
            
            Backtracking(nums, Subset, i + 1, k);
        }
        
        return Result;
    }
private:
    void Backtracking(const vector<int>& Nums, vector<int>& Subset, const int Index, const int K)
    {
        for(int i = Index; i < N; i++)
        {
            if(IsBeautiful(Subset, Nums[i], K))
            {
                Subset.push_back(Nums[i]);
                Result++;
                
                if(i + 1 < N)
                {
                    Backtracking(Nums, Subset, i + 1, K);
                }
                Subset.pop_back();
            }
        }
    }
    
    bool IsBeautiful(const vector<int>& Subset, const int InNum, const int K)
    {
        for(int Num : Subset)
        {
            if(abs(InNum - Num) == K)
            {
                return false;
            }
        }
        return true;
    }
};