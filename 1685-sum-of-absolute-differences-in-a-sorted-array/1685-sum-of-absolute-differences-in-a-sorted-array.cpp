class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums)
    {
        int Left = 0;
        int Right = accumulate(nums.begin(), nums.end(), 0);
        
        const int N = static_cast<int>(nums.size());
        vector<int> Result(N);
        
        for(int i = 0; i < N; i++)
        {
            int Num = nums[i];
            Right -= Num;
            
            Result[i] = (Num * i) - Left + Right - (Num * (N - i - 1));
            
            Left += Num;
        }
        return Result;
    }
};