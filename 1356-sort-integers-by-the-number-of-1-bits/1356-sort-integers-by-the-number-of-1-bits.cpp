class Solution {
public:
    vector<int> sortByBits(vector<int>& arr)
    {
        sort(arr.begin(), arr.end(), [] (int A, int B)
        {
            int CountA = __builtin_popcount(A);
            int CountB = __builtin_popcount(B);

            if(CountA == CountB)
                return A < B;
            return CountA < CountB;
        });
        return arr;
    }
};