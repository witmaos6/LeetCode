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
            BuildTrie(Trie, Word);
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
                string Find = FindWord(Temp, Trie);
                Begin = i + 1;
                if(Find == "")
                {
                    ReplaceWords += Temp;
                }
                else
                {
                    ReplaceWords += Find;
                }
                ReplaceWords += ' ';
            }
        }
        
        ReplaceWords.pop_back();
        return ReplaceWords;
    }
    
private:
    void BuildTrie(Node* TrieNode, const string& Word)
    {
        for(const char& C : Word)
        {
            int Index = C - 'a';
            
            if(TrieNode->Next[Index] == nullptr)
            {
                TrieNode->Next[Index] = new Node();
            }
            TrieNode = TrieNode->Next[Index];
        }
        TrieNode->bIsEnd = true;
    }
    
    string FindWord(const string& Word, Node* TrieNode)
    {
        const int N = static_cast<int>(Word.size());
        string Temp;
        
        for(int i = 0; i < N; i++)
        {
            int Index = Word[i] - 'a';
            
            if(TrieNode->Next[Index])
            {
                Temp += Word[i];
                TrieNode = TrieNode->Next[Index];
            }
            else
            {
                break;
            }
            if(TrieNode->bIsEnd)
            {
                return Temp;
            }
        }
        return "";
    }
};