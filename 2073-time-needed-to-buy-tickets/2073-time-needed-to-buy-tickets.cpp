class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k)
    {
        const int N = static_cast<int>(tickets.size());
        int Result = 0;
        
        for(int i = 0; i < N; i++)
        {
            if(k >= i)
            {
                Result += min(tickets[i], tickets[k]);
            }
            else
            {
                Result += min(tickets[i], tickets[k] - 1);
            }
        }
        return Result;
    }
};