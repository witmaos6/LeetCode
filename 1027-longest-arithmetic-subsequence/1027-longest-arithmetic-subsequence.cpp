class Solution {
    vector<unordered_map<int, int>> Memo;
    int N = 0;
public:
    int longestArithSeqLength(vector<int>& nums)
    {
        N = static_cast<int>(nums.size());
        Memo.resize(N);
        
        int LongestSub = 2;
        
        for(int i = 1; i < N; i++)
        {
            for(int j = 0; j < i; j++)
            {
                int Diff = nums[i] - nums[j];
                
                if(Memo[j].find(Diff) != Memo[j].end())
                {
                    Memo[i][Diff] = Memo[j][Diff] + 1;
                }
                else
                {
                    Memo[i][Diff] = 2;
                }
                
                LongestSub = max(LongestSub, Memo[i][Diff]);
            }
        }
        
        
        return LongestSub;
    }
};