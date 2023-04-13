class Solution {
public:
    string firstPalindrome(vector<string>& words)
    {
        for(string& word : words)
        {
            if(bIsPalindrome(word))
            {
                return word;
            }
        }
        return "";
    }
    
private:
    bool bIsPalindrome(string& s)
    {
        int i = 0, j = static_cast<int>(s.size()) - 1;
        
        while(i < j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
};