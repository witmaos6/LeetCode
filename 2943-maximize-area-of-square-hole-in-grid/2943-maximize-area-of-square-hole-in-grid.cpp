class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars)
    {
        int L = 1 + min(FindLength(hBars), FindLength(vBars));
        return L * L;
    }

private:
    int FindLength(vector<int>& Bars)
    {
        sort(Bars.begin(), Bars.end());
        const int N = static_cast<int>(Bars.size());

        int L = 1;
        int MaxL = 1;
        for(int i = 0; i < N - 1; i++)
        {
            L = 1 + (-(Bars[i] + 1 == Bars[i + 1]) & L);
            MaxL = max(MaxL, L);
        }
        return MaxL;
    }
};