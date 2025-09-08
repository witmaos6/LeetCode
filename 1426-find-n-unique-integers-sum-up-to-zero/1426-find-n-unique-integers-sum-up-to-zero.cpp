class Solution {
public:
    vector<int> sumZero(int n)
    {
        vector<int> Nums(n);
        int Negative = -1;
        int Positive = 1;

        for(int i = 0; i < n / 2; i++)
        {
            Nums[i * 2] = Positive;
            Positive++;
            Nums[i * 2 + 1] = Negative;
            Negative--;
        }
        return Nums;
    }
};