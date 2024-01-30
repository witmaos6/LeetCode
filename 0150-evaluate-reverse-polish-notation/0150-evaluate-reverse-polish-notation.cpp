class Solution {
    array<char, 4> Operators = {'+','-','*','/'};
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> PolishStack;
        
        for(string& Token : tokens)
        {
            if(Token.size() == 1 && IsOperator(Token[0]))
            {
                int Num1 = PolishStack.top();
                PolishStack.pop();
                int Num2 = PolishStack.top();
                PolishStack.pop();
                
                int OperationResult = GetOperationResult(Token[0], Num2, Num1);
                PolishStack.push(OperationResult);
            }
            else
            {
                PolishStack.push(stoi(Token));
            }
        }
        
        return PolishStack.top();
    }
    
private:
    bool IsOperator(const char Token)
    {
        for(char Oper : Operators)
        {
            if(Token == Oper)
            {
                return true;
            }
        }
        return false;
    }
    
    int GetOperationResult(const char Oper, const int Num1, const int Num2)
    {
        int Result = 0;
        switch(Oper)
        {
            case '+': Result = Num1 + Num2;
                break;
            case '-': Result = Num1 - Num2;
                break;
            case '*': Result = Num1 * Num2;
                break;
            case '/': Result = Num1 / Num2;
                break;
                default : break;
        }
        return Result;
    }
};