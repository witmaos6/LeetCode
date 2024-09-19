class Solution {
public:
    vector<int> diffWaysToCompute(string expression)
    {
        const int N = static_cast<int>(expression.size());
        vector<int> Result;
        
        for (int i = 0; i < N; ++i)
        {
            char Oper = expression[i];
            if (Oper == '+' || Oper == '-' || Oper == '*')
            {
                vector<int> S1 = diffWaysToCompute(expression.substr(0, i));
                vector<int> S2 = diffWaysToCompute(expression.substr(i + 1));
                
                for (int A : S1)
                {
                    for (int B : S2)
                    {
                        if (Oper == '+')
                        {
                            Result.push_back(A + B);
                        }
                        else if (Oper == '-')
                        {
                            Result.push_back(A - B);
                        }
                        else if (Oper == '*')
                        {
                            Result.push_back(A * B);
                        }
                    }
                }
            }
        }
        
        if (Result.empty())
        {
            Result.push_back(stoi(expression));
        }
        return Result;
    }
};