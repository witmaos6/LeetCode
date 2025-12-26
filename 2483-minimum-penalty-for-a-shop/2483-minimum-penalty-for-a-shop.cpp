class Solution {
public:
    int bestClosingTime(string customers)
    {
        const int N = static_cast<int>(customers.size());
        int MinPenalty = 0;
        int MinIndex = -1;
        int PenaltySum = 0;

        for(int i = 0; i < N; i++)
        {
            PenaltySum += (customers[i] == 'Y') ? 1 : -1;
            if(PenaltySum > MinPenalty)
            {
                MinPenalty = PenaltySum;
                MinIndex = i;
            }
        }
        return MinIndex + 1;
    }
};