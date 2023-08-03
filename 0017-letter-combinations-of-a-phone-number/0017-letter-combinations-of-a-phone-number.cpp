class Solution {
    unordered_map<char, string> Phone = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    
    vector<string> Combinations;
public:
    vector<string> letterCombinations(string digits)
    {
        if(digits.empty())
        {
            return Combinations;
        }
        string Temp;
        SetCombinations(digits, 0, Temp);
        
        return Combinations;
    }
    
private:
    void SetCombinations(string& Digits, int Index, string& Temp)
    {
        if(Index == Digits.size())
        {
            Combinations.push_back(Temp);
            return;
        }
        
        for(char& C : Phone[Digits[Index]])
        {
            Temp.push_back(C);
            SetCombinations(Digits, Index + 1, Temp);
            Temp.pop_back();
        }
    }
};