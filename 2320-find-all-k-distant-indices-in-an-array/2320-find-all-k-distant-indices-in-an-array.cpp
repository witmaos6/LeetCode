class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k)
    {
        const int N = static_cast<int>(nums.size());
        vector<int> Result;

        int Begin = 0;
        for(int i = 0; i < N; i++)
        {
            if(nums[i] == key)
            {
                int Left = max(0, i - k);
                int Right = min(N - 1, i + k);

                while(Begin <= Right)
                {
                    if(Begin >= Left)
                    {
                        Result.push_back(Begin);
                    }
                    Begin++;
                }
            }
        }
        return Result;
    }
};