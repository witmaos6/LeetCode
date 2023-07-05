class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {
        vector<pair<int, int>> SubArr;
        int Ones = 0;
        int Zeros = 0;
        int Result = 0;
        
        for(int& Num : nums)
        {
            if(Num == 1)
            {
                if(Zeros > 0)
                {
                    SubArr.push_back({0, Zeros});
                    Zeros = 0;
                }
                Ones++;
            }
            else if(Num == 0)
            {
                if(Ones > 0)
                {
                    SubArr.push_back({1, Ones});
                    Result = max(Result, Ones);
                    Ones = 0;
                }
                Zeros++;
            }
        }
        if(Ones > 0)
        {
            SubArr.push_back({1, Ones});
            Result = max(Result, Ones);
        }
        else if(Zeros > 0)
        {
            SubArr.push_back({0, Zeros});
        }

        if(SubArr.size() == 1)
        {
            if(SubArr[0].first == 1)
            {
                return SubArr[0].second - 1;
            }
            else
            {
                return 0;
            }
        }
        
        int N = static_cast<int>(SubArr.size());
        for(int i = 1; i < N - 1; i++)
        {
            if(SubArr[i].first == 0 && SubArr[i].second == 1)
            {
                int Temp = SubArr[i - 1].second + SubArr[i + 1].second;
                Result = max(Result, Temp);
            }
        }
        
        return Result;
    }
};