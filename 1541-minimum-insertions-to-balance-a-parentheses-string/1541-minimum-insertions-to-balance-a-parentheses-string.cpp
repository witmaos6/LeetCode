class Solution {
public:
    int minInsertions(string s)
    {
        int Open = 0;
        int Close = 0;

        for(char& C : s)
        {
            if(C == '(')
            {
                if(Close & 1)
                {
                    Open++;
                    Close--;
                }
                Close += 2;
            }
            else if(C == ')')
            {
                Close--;
                if(Close < 0)
                {
                    Open++;
                    Close = 1;
                }
            }
        }

        return Open + Close;
    }
};