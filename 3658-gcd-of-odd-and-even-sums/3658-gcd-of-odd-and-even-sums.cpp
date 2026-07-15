class Solution {
public:
    int gcdOfOddEvenSums(int n)
    {
        int OddSum = n * (2 * n + 1);
        int EvenSum = n * (n + 1);

        return gcd(OddSum, EvenSum);
    }
};