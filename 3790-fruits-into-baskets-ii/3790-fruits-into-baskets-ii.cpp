class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets)
    {
        const int N = static_cast<int>(fruits.size());
        int Count = 0;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(fruits[i] <= baskets[j])
                {
                    Count++;
                    baskets[j] = 0;
                    break;
                }
            }
        }
        return N - Count;
    }
};