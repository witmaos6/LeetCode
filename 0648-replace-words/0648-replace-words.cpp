struct Node
{
    bool bIsEnd = false;
    vector<Node*> Next;
    
    Node()
    {
        Next.resize(26);
    }
};

class Solution {
    Node* Trie; 
public:
    string replaceWords(vector<string>& dictionary, string sentence)
    {
        Trie = new Node();
        
        for(string& Word : dictionary)
        {
            BuildTrie(Trie, Word, 0);
        }
        
        sentence.push_back(' ');
        const int N = static_cast<int>(sentence.size());
        string ReplaceWords;
        int Begin = 0;
        
        for(int i = 0; i < N; i++)
        {
            if(sentence[i] == ' ')
            {
                string Temp = sentence.substr(Begin, i - Begin);
                string Word;
                bool bFlag = true;
                FindWord(Temp, 0, Trie, Word, bFlag);
                
                if(Word == "" || Word.size() >= Temp.size() || bFlag == false)
                {
                    ReplaceWords += Temp;
                }
                else
                {
                    ReplaceWords += Word;
                }
                ReplaceWords += ' ';
                
                Begin = i + 1;
            }
        }
        
        ReplaceWords.pop_back();
        return ReplaceWords;
    }
    
private:
    void BuildTrie(Node* TrieNode, const string& Word, int Index)
    {
        if(Word.size() <= Index)
        {
            TrieNode->bIsEnd = true;
            return;
        }
        
        char CurrChar = Word[Index];
        int NextIndex = CurrChar - 'a';
        
        if(TrieNode->Next[NextIndex] == nullptr)
        {
            TrieNode->Next[NextIndex] = new Node();
        }
        
        BuildTrie(TrieNode->Next[NextIndex], Word, Index + 1);
    }
    
    void FindWord(const string& Temp, int Index, Node* TrieNode, string& Word, bool& Flag)
    {
        if(Temp.size() <= Index || TrieNode->bIsEnd)
        {
            Flag = true;
            return;
        }
        
        int NextIndex = Temp[Index] - 'a';
        if(TrieNode->Next[NextIndex] != nullptr)
        {
            Word += Temp[Index];
            FindWord(Temp, Index + 1, TrieNode->Next[NextIndex], Word, Flag);
        }
        else
        {
            Flag = false;
            return;
        }
    }
};