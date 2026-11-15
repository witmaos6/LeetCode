class Solution {
public:
    int numOfSubarrays(vector<int>& arr)
    {
        const int Mod = 1e9 + 7;
        int Odd = 0;
        int Even = 1;
        int Result = 0;
        int Sum = 0;
        for(int& Num : arr)
        {
            Sum += Num;
            if(Sum & 1)
            {
                Result = (Result + Even) % Mod;
                Odd++;
            }
            else
            {
                Result = (Result + Odd) % Mod;
                Even++;
            }
        }
        return Result;
    }
};