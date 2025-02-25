class Solution {
    const int Mod = 1e9 + 7;
public:
    int numOfSubarrays(vector<int>& arr)
    {
        int Odd = 0;
        int Even = 1;
        int Result = 0;
        int Sum = 0;

        const int N = static_cast<int>(arr.size());
        for(int i = 0; i < N; i++)
        {
            Sum += arr[i];
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