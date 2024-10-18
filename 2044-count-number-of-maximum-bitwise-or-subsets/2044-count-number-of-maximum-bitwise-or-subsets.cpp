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
            int Count = DFS(nums, i, nums[i]);
            if(nums[i] == ORResult)
            {
                Count += 1;
            }
            Result += Count;
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
                Count++;
            }
            
            Count += DFS(Nums, i, ORNum);
        }
        
        return Count;
    }
};