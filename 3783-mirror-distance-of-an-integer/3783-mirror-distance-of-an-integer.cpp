class Solution {
public:
    int mirrorDistance(int n)
    {
        int Reverse = 0;
        int Temp = n;
        while(Temp > 0)
        {
            Reverse = Reverse * 10 + (Temp % 10);
            Temp /= 10;
        }
        return abs(n - Reverse);
    }
};