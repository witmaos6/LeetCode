class Solution {
    int N = 0;
public:
    int minDays(vector<int>& bloomDay, int m, int k)
    {
        N = static_cast<int>(bloomDay.size());
        long long NeedFlowers = 1LL * m * k;
        if(NeedFlowers > N)
            return -1;
        
        auto[MinNum, MaxNum] = minmax_element(bloomDay.begin(), bloomDay.end());
        int L = *MinNum, R = *MaxNum;
        
        while(L < R)
        {
            int Mid = L + (R - L) / 2;
            
            if(IsValid(Mid, bloomDay, m, k))
            {
                R = Mid;
            }
            else
            {
                L = Mid + 1;
            }
        }
        return L;
    }
    
private:
    bool IsValid(const int D, vector<int>& BloomDay, const int M, const int K)
    {
        int Length = 0, Bouquet = 0;
        for(int i = 0; i < N; i++)
        {
            if(BloomDay[i] <= D)
            {
                Length++;
                if(Length == K)
                {
                    Bouquet++;
                    Length = 0;
                }
            }
            else
            {
                Length = 0;
            }
            
            if(Bouquet >= M)
                return true;
        }
        
        return Bouquet >= M;
    }
};