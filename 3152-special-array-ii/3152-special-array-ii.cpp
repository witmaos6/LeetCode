class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries)
    {
        const int N = static_cast<int>(nums.size());
        vector<int> Prefix(N);
        for(int i = 1; i < N; i++)
        {
            Prefix[i] = Prefix[i - 1];
            if ((nums[i - 1] % 2 == 0 && nums[i] % 2 == 0) || (nums[i - 1] % 2 != 0 && nums[i] % 2 != 0))
            {
                Prefix[i]++;
            }
        }
        
        vector<bool> IsSpecial;
        IsSpecial.reserve(queries.size());
        
        for(vector<int>& Query : queries)
        {
            int From = Query[0];
            int To = Query[1];
            int SpecialCount = Prefix[To] - (From > 0 ? Prefix[From] : 0);
            IsSpecial.push_back(SpecialCount == 0);
        }
        
        return IsSpecial;
    }
};