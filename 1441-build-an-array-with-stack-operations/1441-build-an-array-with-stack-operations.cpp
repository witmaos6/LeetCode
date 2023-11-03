class Solution {
    vector<string> Operations;
    
    const string PushOper = "Push";
    const string PopOper = "Pop";
public:
    vector<string> buildArray(vector<int>& target, int n)
    {
        int Index = 0;
        
        for(int i = 1; i <= target.back(); i++)
        {
            if(target[Index] == i)
            {
                Operations.push_back(PushOper);
                Index++;
                
                if(target.size() <= Index)
                    break;
            }
            else
            {
                Operations.push_back(PushOper);
                Operations.push_back(PopOper);
            }
            
        }
        
        return Operations;
    }
};