class Solution {
public:
    int smallestRepunitDivByK(int k)
    {
        int Remain = 0;
        for(int L = 1; L <= k; L++)
        {
            Remain = (Remain * 10 + 1) % k;
            if(Remain == 0)
                return L;
        }

        return -1;
    }
};