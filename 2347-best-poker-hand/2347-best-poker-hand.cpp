class Solution
{
public:    
    string bestHand(vector<int>& Ranks, vector<char>& Suits)
    {
        vector<int> RankTable(14);
        vector<int> SuitTable(4);
        
        for(int Rank : Ranks)
        {
            RankTable[Rank]++;
        }
        for(char Suit : Suits)
        {
            SuitTable[Suit - 'a']++;
        }
        
        for(int Suit : SuitTable)
        {
            if(Suit >= 5)
            {
                return "Flush";
            }
        }
        
        string Hand = "High Card";
        for(int Rank : RankTable)
        {
            if(Rank >= 3)
            {
                return "Three of a Kind";
            }
            else if(Rank >= 2)
            {
                Hand = "Pair";
            }
        }
        
        return Hand;
    }
};