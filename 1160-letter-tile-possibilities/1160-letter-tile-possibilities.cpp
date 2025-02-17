class Solution {
public:
    int numTilePossibilities(string tiles)
    {
        vector<int> CountLetter(26);
        for(char& C : tiles)
        {
            CountLetter[C - 'A']++;
        }
        return DFS(CountLetter);
    }
private:
    int DFS(vector<int>& CountLetter)
    {
        int PossibleSequence = 0;
        for(int& Count : CountLetter)
        {
            if(Count > 0)
            {
                Count--;
                PossibleSequence += 1 + DFS(CountLetter);
                Count++;
            }
        }

        return PossibleSequence;
    }
};