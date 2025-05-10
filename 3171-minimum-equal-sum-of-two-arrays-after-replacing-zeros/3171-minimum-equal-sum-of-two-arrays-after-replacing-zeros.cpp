class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2)
    {
        long long Nums1Sum = 0;
        int Nums1ZeroCount = 0;
        for(int& Num : nums1)
        {
            Nums1Sum += Num;
            if(Num == 0)
            {
                Nums1ZeroCount++;
            }
        }

        long long Nums2Sum = 0;
        int Nums2ZeroCount = 0;
        for(int& Num : nums2)
        {
            Nums2Sum += Num;
            if(Num == 0)
            {
                Nums2ZeroCount++;
            }
        }

        if(Nums1ZeroCount == 0 && Nums2ZeroCount == 0)
        {
            return Nums1Sum == Nums2Sum ? Nums1Sum : -1;
        }        
        else if (Nums1ZeroCount == 0)
        {
            return (Nums2Sum + Nums2ZeroCount <= Nums1Sum) ? Nums1Sum : -1;
        }
        else if (Nums2ZeroCount == 0)
        {
            return (Nums1Sum + Nums1ZeroCount <= Nums2Sum) ? Nums2Sum : -1;
        }
        return max(Nums1Sum + Nums1ZeroCount, Nums2Sum + Nums2ZeroCount);
    }
};