class Solution {
public:
    int minOperations(string s)
    {
        int Count1 = 0;
        char Input = '1';

        for(char& C : s)
        {
            if(C == Input)
            {
                Count1++;
            }
            Input = (Input == '1') ? '0' : '1';
        }
        
        int Count0 = s.size() - Count1;
        return min(Count0, Count1);
    }
};