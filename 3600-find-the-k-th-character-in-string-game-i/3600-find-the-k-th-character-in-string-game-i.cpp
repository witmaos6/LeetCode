class Solution {
public:
    char kthCharacter(int k)
    {
        string Word = "a";

        while(Word.size() < k)
        {
            string GeneratedWord;
            for(char& C : Word)
            {
                GeneratedWord += Generated(C);
            }
            Word += GeneratedWord;
        }
        return Word[k - 1];
    }
private:
    char Generated(char C)
    {
        if(C == 'z')
            return 'a';

        return static_cast<char>(C + 1);
    }
};