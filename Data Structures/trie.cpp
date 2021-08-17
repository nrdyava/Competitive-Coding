#include <iostream>
using namespace std;

#define CHAR_SIZE 26

class Trie(){
    public:

    bool isLeaf;
    Trie* character[CHAR_SIZE];

    //Constructor
    Trie()
    {
        this->isLeaf = false;
        for(int i=0; i<26; i++){
            this->character[i] = nullptr;
        }
    }

    void insert(string);
    bool deletetion(Trie* &, string);
    bool search(string);
    bool haveChildren(Trie const *);

};

// Insert Operation
void Trie::insert(string key){

    Trie* curr = this;
    for(int i=0; i<key.length() ; i++){
        
        int index = key[i] - 'a';
        if(curr->character[index] == nullptr){
            curr->character[index] = new Trie();
        }

        curr = curr->character[index];
    }
    curr->isLeaf = true;
}

// Search Operation
bool Trie::search(string key){

    if(this == nullptr) return false;

    Trie* curr = this;

    for(int i=0; i<key.length(); i++){
        int index = key[i] - 'a';
        curr = curr->character[index];
        
        if(curr == nullptr) return false;
    }

    return curr->isLeaf;
}



