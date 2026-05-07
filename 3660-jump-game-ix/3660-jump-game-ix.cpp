class Solution {
public:
    vector<int> maxValue(vector<int>& nums)
    {
        const int N = nums.size();

        vector<int> Pre(N), Suf(N);

        Pre[0] = nums[0];
        Suf[N - 1] = nums[N - 1];
        for(int i = 1; i < N; i++)
        {
            Pre[i] = max(Pre[i - 1], nums[i]);

            Suf[N - 1 - i] = min(Suf[N - i], nums[N - 1 - i]);
        }

        vector<int> Result(N);
        Result[N - 1] = Pre[N - 1];
        for(int i = N - 2; i >= 0; i--)
        {
            if(Pre[i] > Suf[i + 1])
            {
                Result[i] = Result[i + 1];
            }
            else
            {
                Result[i] = Pre[i];
            }
        }
        return Result;
    }
};