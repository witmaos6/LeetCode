class Solution {
    int N = 0;
    int ORResult = 0;
public:
    int countMaxOrSubsets(vector<int>& nums)
    {
        N = static_cast<int>(nums.size());
        for(int i = 0; i < N; ++i)
        {
            ORResult |= nums[i];
        }
        
        int Result = 0;
        for(int i = 0; i < N; ++i)
        {
            if(nums[i] == ORResult)
            {
                int Remain = N - (i + 1);
                int RemainCount = pow(2, Remain);
                Result += RemainCount;
            }
            else
            {
                int Count = DFS(nums, i, nums[i]);
                Result += Count;
            }
        }
        
        return Result;
    }
    
private:
    int DFS(const vector<int>& Nums, const int Index, const int Num)
    {   
        int Count = 0;
        for(int i = Index + 1; i < N; ++i)
        {
            int ORNum = Num | Nums[i];
            
            if(ORNum == ORResult)
            {
                int Remain = N - (i + 1);
                int RemainCount = pow(2, Remain);
                Count += RemainCount;
            }
            else
            {
                Count += DFS(Nums, i, ORNum);
            }
        }
        
        return Count;
    }
};