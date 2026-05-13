class Solution {
public:
    int minMoves(vector<int>& nums, int limit)
    {
        const int N = nums.size();

        vector<int> Diff(2 * limit + 2);
        for(int i = 0; i < N / 2; i++)
        {
            int ValA = min(nums[i], nums[N - 1 - i]);
            int ValB = max(nums[i], nums[N - 1 - i]);

            Diff[2] += 2;
            Diff[2 * limit + 1] -= 2;
            Diff[ValA + 1] -= 1;
            Diff[ValB + limit + 1] += 1;
            Diff[ValA + ValB] -= 1;
            Diff[ValA + ValB + 1] += 1;
        }

        int Result = N;
        int Curr = 0;
        for(int i = 2; i <= 2 * limit; i++)
        {
            Curr += Diff[i];
            Result = min(Result, Curr);
        }
        return Result;
    }
};