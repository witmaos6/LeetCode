class Solution {
public:
    int countSeniors(vector<string>& details)
    {
        const int FirstOldIndex = 11;
        const int SecondOldIndex = 12;
        const int ReturnOldGreaterThan = 60;
        
        int Count = 0;
        for(const string& Detail : details)
        {
            string OldString;
            OldString += Detail[FirstOldIndex];
            OldString += Detail[SecondOldIndex];
            
            int Old = stoi(OldString);
            if(Old > ReturnOldGreaterThan)
            {
                Count++;
            }
        }
        
        return Count;
    }
};