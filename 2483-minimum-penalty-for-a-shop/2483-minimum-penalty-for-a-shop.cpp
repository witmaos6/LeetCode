class Solution {
public:
    int bestClosingTime(string customers)
    {
        const int N = static_cast<int>(customers.size());
        
        int MinPenalty = 0;
        int MinIndex = -1;
        int PrefixPenalty = 0;
        
        for(int i = 0; i < N; i++)
        {
            PrefixPenalty += (customers[i] == 'Y') ? 1 : -1;
            
            if(PrefixPenalty > MinPenalty)
            {
                MinPenalty = PrefixPenalty;
                MinIndex = i;
            }
        }
        
        return MinIndex + 1;
    }
};