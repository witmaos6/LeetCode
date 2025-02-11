class Solution {
public:
    string removeOccurrences(string s, string part)
    {
        string Stack;
        Stack.reserve(s.size());
        const int PartSize = static_cast<int>(part.size());

        for(char& C : s)
        {
            Stack += C;
            if(C == part.back())
            {
                if(Stack.size() >= PartSize && equal(part.rbegin(), part.rend(), Stack.rbegin()))
                {
                    for(int i = 0; i < PartSize; i++)
                    {
                        Stack.pop_back();
                    }
                }
            }
        }

        return Stack;
    }
};