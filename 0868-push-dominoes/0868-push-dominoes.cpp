class Solution {
public:
    string pushDominoes(string dominoes)
    {
        string Stack;
        string Result;

        for(char& C : dominoes)
        {
            if(C == '.')
            {
                Stack += C;
            }
            else if(C == 'R')
            {
                if(Stack.front() == 'R')
                {
                    fill(Stack.begin(), Stack.end(), 'R');
                }
                Result += Stack;
                Stack.clear();
                Stack += C;
            }
            else if(C == 'L')
            {
                if(!Stack.empty())
                {
                    Stack += C;
                    if(Stack.front() == 'R')
                    {
                        int Left = 1;
                        int Right = Stack.size() - 2;
                        while(Left < Right)
                        {
                            Stack[Left] = 'R';
                            Stack[Right] = 'L';
                            Left++;
                            Right--;
                        }
                        Result += Stack;
                    }
                    else
                    {
                        fill(Stack.begin(), Stack.end(), 'L');
                        Result += Stack;
                    }
                    Stack.clear();
                }
                else
                {
                    Result += C;
                }
            }
        }
        if(!Stack.empty())
        {
            if(Stack.front() == 'R')
            {
                for(int i = 0; i < Stack.size(); i++)
                {
                    Result += 'R';
                }
            }
            else
            {
                Result += Stack;
            }
        }
        return Result;
    }
};