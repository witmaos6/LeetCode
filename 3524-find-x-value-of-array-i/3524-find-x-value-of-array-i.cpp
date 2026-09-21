class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k)
    {
        vector<long long> Result(k), Memo(k);
        for(int& Num : nums)
        {
            int X = Num % k;
            vector<long long> Next(k);
            Next[X]++;

            for(int R = 0; R < k; R++)
            {
                int NewR = (R * X) % k;
                Next[NewR] += Memo[R];
            }

            for(int R = 0; R < k; R++)
            {
                Result[R] += Next[R];
            }
            Memo = Next;
        }

        return Result;
    }
};