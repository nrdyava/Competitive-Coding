class Trie {
public:
    /** Initialize your data structure here. */
    
    bool isLeaf;
    Trie* children[58];
    
    Trie() {
        this->isLeaf = false;
        for(int i=0; i<58; i++){
            this->children[i] = nullptr;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* curr = this;
        
        for(int i=0; i<word.length(); i++){
            
            int index = word[i] - 'A';
            
            if(curr->children[index] == nullptr){
                curr->children[index] = new Trie();
            }
            
            curr = curr->children[index];
        }
        curr->isLeaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* curr = this;
        
        for(int i=0; i<word.length(); i++){
            int index = word[i] - 'A';
            curr = curr->children[index];
            
            if(curr == nullptr) return false;
        }
        return curr->isLeaf;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
        Trie* curr = this;
        
        for(int i=0; i<prefix.length(); i++){
            int index = prefix[i] - 'A';
            curr = curr->children[index];
            
            if(curr == nullptr) return false;
        }
        
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */