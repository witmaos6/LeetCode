class Solution {
    int N = 0;
    int Result = 0;
    vector<int> WordTable;
    vector<int> LetterTable;
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
    {
        LetterTable.resize(26);
        for(char C : letters)
        {
            LetterTable[C - 'a']++;
        }
        
        N = static_cast<int>(words.size());
        WordTable.resize(26);
        Backtracking(words, 0, score, 0);
        
        return Result;
    }
    
private:
    void Backtracking(const vector<string>& Words, int Index, const vector<int>& Score, int CurrScore)
    {
        for(int i = Index; i < N; i++)
        {
            for(char C : Words[i])
            {
                int Index = C - 'a';
                WordTable[Index]++;
                CurrScore += Score[Index];
            }
            
            if(IsValid())
            {
                Result = max(Result, CurrScore);
                Backtracking(Words, i + 1, Score, CurrScore);
            }
            
            for(char C : Words[i])
            {
                int Index = C - 'a';
                WordTable[Index]--;
                CurrScore -= Score[Index];
            }
        }
    }
    
    bool IsValid()
    {
        for(int i = 0; i < 26; i++)
        {
            if(WordTable[i] > LetterTable[i])
            {
                return false;
            }
        }
        return true;
    }
};