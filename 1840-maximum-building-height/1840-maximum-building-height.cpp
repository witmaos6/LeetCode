class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions)
    {
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());

        const int N = restrictions.size();

        for(int i = 1; i < N; i++)
        {
            restrictions[i][1] = YCap(restrictions[i - 1], restrictions[i]);
        }

        for(int i = N - 2; i >= 0; i--)
        {
            restrictions[i][1] = YCap(restrictions[i + 1], restrictions[i]);
        }

        int Result = 0;
        for(int i = 1; i < N; i++)
        {
            Result = max(Result, YPeak(restrictions[i - 1], restrictions[i]));
        }

        return max(Result, restrictions[N - 1][1] + n - restrictions[N - 1][0]);
    }

private:
    int YCap(vector<int>& L, vector<int>& R)
    {
        int X1 = L[0], Y1 = L[1], X2 = R[0], Y2 = R[1];
        return min(Y2, Y1 + abs(X2 - X1));
    }

    int YPeak(vector<int>& L, vector<int>& R)
    {
        int X1 = L[0], Y1 = L[1], X2 = R[0], Y2 = R[1];
        return (Y1 + Y2 + X2 - X1) >> 1;
    }
};