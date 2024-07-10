class Solution {
public:
    int minOperations(vector<string>& logs)
    {
        int LengthFromMain = 0;
        
        for(const string& Log : logs)
        {
            if(Log == "../")
            {
                if(LengthFromMain > 0)
                {
                    LengthFromMain--;
                }
            }
            else if(Log == "./")
            {
                continue;
            }
            else
            {
                LengthFromMain++;
            }
        }
        return LengthFromMain;
    }
};