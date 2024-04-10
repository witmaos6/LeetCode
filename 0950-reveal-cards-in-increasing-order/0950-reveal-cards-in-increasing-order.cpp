class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck)
    {
        const int N = static_cast<int>(deck.size());
        
        deque<int> Indices;
        for(int i = 0; i < N; i++)
        {
            Indices.push_back(i);
        }
        
        sort(deck.begin(), deck.end());
        vector<int> Result(N);
        for(int Card : deck)
        {
            int Index = Indices.front();
            Indices.pop_front();
            
            Result[Index] = Card;
            
            if(!Indices.empty())
            {
                Indices.push_back(Indices.front());
                Indices.pop_front();
            }
        }
        
        return Result;
    }
};