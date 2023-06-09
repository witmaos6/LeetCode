class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target)
    {
        int Index = upper_bound(letters.begin(), letters.end(), target) - letters.begin();
        
        if(Index < letters.size())
        {
            return letters[Index];
        }
        return letters[0];
    }
};