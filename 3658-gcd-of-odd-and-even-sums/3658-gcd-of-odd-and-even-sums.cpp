class Solution {
public:
    int gcdOfOddEvenSums(int n)
    {
        int OddSum = 0;
        int EvenSum = 0;
        for(int i = 0; i < n; i++)
        {
            OddSum += (i * 2) + 1;
            EvenSum += (i * 2) + 2;
        }

        return gcd(OddSum, EvenSum);
    }
};