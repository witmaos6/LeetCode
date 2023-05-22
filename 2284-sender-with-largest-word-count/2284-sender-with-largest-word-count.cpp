class Solution {
public:
    string largestWordCount(vector<string>& messages, 
                            vector<string>& senders)
    {
        map<string, int> NrOfWords;
        const size_t N = messages.size();
        
        for(size_t i = 0; i < N; i++)
        {
            int Count = 0;
            for(char c : messages[i])
            {
                if(c == ' ')
                {
                    Count++;
                }
            }
            NrOfWords[senders[i]] += (Count + 1);
        }
        
        string LargerName;
        int MaxCount = 0;
        
        for(pair<const string, int>& Sender : NrOfWords)
        {
            if(MaxCount < Sender.second)
            {
                LargerName = Sender.first;
                MaxCount = Sender.second;
            }
            else if(MaxCount == Sender.second && LargerName < Sender.first)
            {
                LargerName = Sender.first;
            }
        }
        
        return LargerName;
    }
};