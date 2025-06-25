class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k)
    {
        long long Left = -1e10, Right = 1e10;
        while(Left < Right)        
        {
            long long Mid = Left + (Right - Left) / 2;

            if(CountProducts(nums1, nums2, Mid) < k)
            {
                Left = Mid + 1;
            }
            else
            {
                Right = Mid;
            }
        }
        return Left;
    }

private:
    long long CountProducts(vector<int>& Nums1, vector<int>& Nums2, long long Target)
    {
        long long Count = 0;
        const long long Nums2Size = static_cast<long long>(Nums2.size());
        for(int& Num1 : Nums1)
        {
            if(Num1 == 0)
            {
                if(Target >= 0)
                {
                    Count += Nums2Size;
                    continue;
                }
            }

            int Low = 0, High = Nums2Size;
            while(Low < High)
            {
                int Mid = (Low + High) / 2;
                long long Prod = 1LL * Num1 * Nums2[Mid];

                if(Prod <= Target)
                {
                    if(Num1 > 0)
                    {
                        Low = Mid + 1;
                    }
                    else
                    {
                        High = Mid;
                    }
                }
                else
                {
                    if(Num1 > 0)
                    {
                        High = Mid;
                    }
                    else
                    {
                        Low = Mid + 1;
                    }
                }
            }
            Count += (Num1 > 0) ? Low : (Nums2Size - Low);
        }
        return Count;
    }
};