class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        sort(nums.begin(), nums.end());
        
        vector<int> Memo(N, 1);
        int MaxNum = 1;
        for(int i = 1; i < N; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if((nums[i] % nums[j] == 0) && Memo[i] < Memo[j] + 1)
                {
                    Memo[i] = Memo[j] + 1;
                    if(MaxNum < Memo[i])
                    {
                        MaxNum = Memo[i];
                    }
                }
            }
        }
        
        vector<int> Answer;
        int Num = -1;
        for(int i = N - 1; i >= 0; i--)
        {
            if(MaxNum == Memo[i] && (Num == -1 || (Num % nums[i] == 0)))
            {
                Answer.push_back(nums[i]);
                MaxNum--;
                Num = nums[i];
            }
        }
        return Answer;
    }
};