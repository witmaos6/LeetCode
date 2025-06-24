class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k)
    {
        const int N = static_cast<int>(nums.size());
        int j = 0;
        vector<int> Result;

        while(j < N)
        {
            if(nums[j] == key)
            {
                int Begin = max(0, j - k);
                for(int i = Begin; i < j; i++)
                {
                    if((!Result.empty() && Result.back() < i) || Result.empty())
                    {
                        Result.push_back(i);
                    }
                }
                int End = min(N, j + k + 1);
                for(int i = j; i < End; i++)
                {
                    Result.push_back(i);
                    if(nums[i] == key)
                    {
                        End = min(N, i + k + 1);
                    }
                }
                j = End;
            }
            else
            {
                j++;
            }
        }
        return Result;
    }
};