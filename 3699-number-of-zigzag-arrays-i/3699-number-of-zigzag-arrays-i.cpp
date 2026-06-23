class Solution {
public:
    int zigZagArrays(int n, int l, int r)
    {
        const int Mod = 1e9 + 7;
        int M = r - l + 1;

        vector<int> Memo(M, 1);

        for(int i = 2; i <= n; i++)
        {
            reverse(Memo.begin(), Memo.end());
            int Sum = 0;
            for(int& Num : Memo)
            {
                swap(Num, Sum);
                Sum = (Sum + Num) % Mod;
            }
        }
        return ((accumulate(Memo.begin(), Memo.end(), 0LL) % Mod) << 1) % Mod;
    }
};