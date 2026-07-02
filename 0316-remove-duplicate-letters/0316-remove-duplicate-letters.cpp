class Solution {
public:
    string removeDuplicateLetters(string s)
    {
        int N = static_cast<int>(s.size());
        deque<char> Stack;
        vector<bool> CharTable(26);
        unordered_map<char, int> Table;
        
        for(int i = 0; i < N; i++)
        {
            Table[s[i]] = i;
        }
        
        for(int i = 0; i < N; i++)
        {
            char C = s[i];
            int Index = C - 'a';
            
            if(!CharTable[Index])
            {
                while(!Stack.empty() && C < Stack.back() && i < Table[Stack.back()])
                {
                    CharTable[Stack.back() - 'a'] = false;
                    Stack.pop_back();
                }
                CharTable[Index] = true;
                Stack.push_back(C);
            }
        }
        
        string Result;
        Result.reserve(Stack.size());
        while(!Stack.empty())
        {
            Result += Stack.front();
            Stack.pop_front();
        }
        
        return Result;
    }
};