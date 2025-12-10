class Solution {
public:
    int countPermutations(vector<int>& complexity)
    {
        const int N = static_cast<int>(complexity.size());
        const int Mod = 1e9 + 7;
        
        for(int i = 1; i < N; i++)
        {
            if(complexity[i] <= complexity[0])
                return 0;
        }

        long long F = 1;
        for(int i = 2; i < N; i++)
        {
            F = (F * i) % Mod;
        }
        return F;
    }
};