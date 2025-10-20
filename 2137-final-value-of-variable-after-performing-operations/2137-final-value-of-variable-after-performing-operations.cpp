class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations)
    {
        int X = 0;
        for(string& Operation : operations)
        {
            if(Operation.size() <= 3)
            {
                if(Operation[1] == '+')
                {
                    X++;
                }
                else if(Operation[1] == '-')
                {
                    X--;
                }
            }
        }
        return X;
    }
};