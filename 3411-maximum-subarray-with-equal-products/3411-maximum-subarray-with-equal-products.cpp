class Solution {
public:
    int maxLength(vector<int>& nums)
    {
        int Best = 2;
        int Left = 0;
        int Prod = 1;
        const int N = nums.size();

        for(int Right = 0; Right < N; Right++)
        {
            int X = nums[Right];
            while(gcd(Prod, X) > 1)
            {
                Prod /= nums[Left++];
            }
            Prod *= X;
            Best = max(Best, Right - Left + 1);
        }
        return Best;
    }
};