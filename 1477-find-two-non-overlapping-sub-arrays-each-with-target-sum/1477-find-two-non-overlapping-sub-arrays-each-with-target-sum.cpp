class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target)
    {
        const int N = arr.size();
        vector<int> Memo(N + 1, N);
        int Result = N + 1;
        int L = 0;
        int Sum = 0;

        for(int R = 0; R < N; R++)
        {
            Sum += arr[R];
            while(Sum > target)
            {
                Sum -= arr[L++];
            }

            Memo[R + 1] = Memo[R];
            
            if(target == Sum)
            {
                int Length = R - L + 1;
                Result = min(Result, Length + Memo[L]);
                Memo[R + 1] = min(Memo[R], Length);
            }
        }
       
        return Result == N + 1? -1 : Result;
    }
};