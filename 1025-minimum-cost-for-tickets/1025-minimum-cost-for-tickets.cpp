class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        const int N = static_cast<int>(days.size());
        int Total = 0;
        int Left7 = 0;
        int Left30 = 0;

        vector<int> Memo(N);

        for(int Right = 0; Right < N; Right++)
        {
            while(days[Right] - days[Left7] >= 7)
            {
                Left7++;
            }
            while(days[Right] - days[Left30] >= 30)
            {
                Left30++;
            }

            int Cost1 = (Right > 0 ? Memo[Right - 1] : 0) + costs[0];
            int Cost7 = (Left7 > 0 ? Memo[Left7 - 1] : 0) + costs[1];
            int Cost30 = (Left30 > 0 ? Memo[Left30 - 1] : 0) + costs[2];

            Memo[Right] = min({Cost1, Cost7, Cost30});
        }

        return Memo.back();
    }
};