class Solution {
public:
    int maximum69Number (int num)
    {
        string NumString = to_string(num);
        for(char& C : NumString)
        {
            if(C == '6')
            {
                C = '9';
                break;
            }
        }
        
        num = stoi(NumString);
        return num;
    }
};