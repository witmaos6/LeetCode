class Solution {
public:
    int sortableIntegers(vector<int>& nums)
    {
        const int N = nums.size();
        int Result = 0;

        for(int k = 1; k * k <= N; k++)
        {
            if(N % k == 0)
            {
                if(Check(nums, k))
                {
                    Result += k;
                }

                if(k * k != N && Check(nums, N / k))
                {
                    Result += N / k;
                }
            }
        }
        return Result;
    }

private:
    bool Check(vector<int>& Nums, int k)
    {
        const int N = Nums.size();
        int Prev = 0;

        for(int i = 0; i < N; i+=k)
        {
            int Count = 0;
            int Mini = Nums[i];
            int Maxi = Nums[i];

            for(int j = i; j < i + k - 1; j++)
            {
                if(Nums[j] > Nums[j + 1])
                    Count++;

                Mini = min(Mini, Nums[j + 1]);
                Maxi = max(Maxi, Nums[j + 1]);
            }

            if(Nums[i + k - 1] > Nums[i])
                Count++;
            
            if(Count > 1 || Prev > Mini)
                return false;
            
            Prev = Maxi;
        }
        return true;
    }
};