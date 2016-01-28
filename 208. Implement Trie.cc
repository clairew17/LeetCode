class TrieNode {
public:
    bool isKey;
    TrieNode* next[26]={NULL};
    // Initialize your data structure here.
    TrieNode() {
        isKey=false;
    }
};

class Trie {
public:
    Trie(){
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        auto cur = root;
        for(auto w:word){
            if(cur->next[w-'a']==NULL)
            {
                cur->next[w-'a'] = new TrieNode();
            }
            cur = cur->next[w-'a'];
        }
        cur->isKey=true;
    }

    TrieNode* query(string word)
    {
        TrieNode *p = root;
        for(int i = 0; i < word.size() && p != NULL; ++ i)
            p = p -> next[word[i] - 'a'];
        return p;
        
    }
    // Returns if the word is in the trie.
    bool search(string word) {
        auto p = query(word);
        return p&&p->isKey;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        auto p = query(prefix);
        return p!=NULL;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");