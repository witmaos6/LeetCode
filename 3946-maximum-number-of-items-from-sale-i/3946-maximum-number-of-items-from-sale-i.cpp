class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget)
    {
        vector<int> Mult(1501);
        for(vector<int>& Item : items)
        {
            int Fac = Item[0];
            for(int F = 1; F <= 1500; F++)
            {
                if(Fac % F == 0)
                    Mult[F]++;
            }
        }

        vector<int> Memo(budget + 1);
        for(vector<int>& Item : items)
        {
            int F = Item[0];
            int P = Item[1];

            vector<int> Next = Memo;
            for(int B = budget; B >= P; B--)
            {
                Next[B] = max(Next[B], Memo[B - P] + Mult[F]);
            }
            for(int B = P; B <= budget; B++)
            {
                Next[B] = max(Next[B], Next[B - P] + 1);
            }
            Memo = move(Next);
        }
        return *max_element(Memo.begin(), Memo.end());
    }
};