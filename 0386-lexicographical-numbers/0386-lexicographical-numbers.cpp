class Solution {
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> Result(n);
        int Input = 1;
        for(int i = 0; i < n; i++)
        {
            Result[i] = Input;
            if(Input * 10 > n)
            {
                if(Input == n)
                {
                    Input /= 10;
                }
                Input++;

                while(Input % 10 == 0)
                {
                    Input /= 10;
                }
            }
            else
            {
                Input *= 10;
            }
        }
        return Result;
    }
};