class Solution {
public:
    vector<int> separateDigits(vector<int>& nums)
    {
        const int N = nums.size();
        vector<int> Result;

        for(int i = N - 1; i >= 0; i--)
        {
            int Num = nums[i];
            while(Num > 0)
            {
                Result.push_back(Num % 10);
                Num /= 10;
            }
        }
        reverse(Result.begin(), Result.end());
        return Result;
    }
};