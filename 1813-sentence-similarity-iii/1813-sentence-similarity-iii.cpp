class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        vector<string> Words1 = SplitWords(sentence1);
        vector<string> Words2 = SplitWords(sentence2);
        
        int Left = 0;
        int Right1 = static_cast<int>(Words1.size()) - 1;
        int Right2 = static_cast<int>(Words2.size()) - 1;
        
        while(Left <= Right1 && Left <= Right2)
        {
            if(Words1[Left] == Words2[Left])
            {
                Left++;
            }
            else if(Words1[Right1] == Words2[Right2])
            {
                Right1--;
                Right2--;
            }
            else
            {
                break;
            }
        }
        
        if(Right1 + 1 == Left || Right2 + 1 == Left)
            return true;
        
        return false;
    }
    
private:
    vector<string> SplitWords(const string& Str)
    {
        vector<string> Words;
        stringstream Stream(Str);
        string Word;
        
        while(Stream >> Word)
        {
            Words.push_back(Word);
        }
        
        return Words;
    }
};