class Solution {
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        const int N = static_cast<int>(s.size());
        vector<int> Costs(N);
        
        for(int i = 0; i < N; i++)
        {
            int Cost = abs(s[i] - t[i]);
            Costs[i] = Cost;
        }
        
        int MaxLength = 0;
        int CurrCost = 0;
        int Left = 0;
        
        for(int Right = 0; Right < N; Right++)
        {
            CurrCost += Costs[Right];
            
            while(CurrCost > maxCost)
            {
                CurrCost -= Costs[Left];
                Left++;
            }
            
            MaxLength = max(MaxLength, Right - Left + 1);
        }
        
        return MaxLength;
    }
};