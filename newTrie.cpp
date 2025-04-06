#include<iostream>
#include<string>
using std::string;

class WordDictionary {
    struct Trie {
        Trie* children[26];
        bool end = false;
    };
    
    Trie* root = NULL;

    Trie* create(){
        Trie* root = new Trie;
        for (int i=0;i<26;i++) root->children[i] = NULL;
        return root;
    }

    bool search(string word, Trie* root){
        int n = word.length();
        if (word==""){
            if (root==NULL) return true;
            else return (root->end);
        } 
        Trie* temp = root;
        for (int i=0;i<n;i++){
            if (temp==NULL) return false;
            if (word[i]!='.'){
                int index = word[i] - 97;
                if (temp->children[index]==NULL) return false;
                else temp = temp->children[index];
            }
            else {
                for (int j=0;j<26;j++){
                    if (temp->children[j]!=NULL) {
                        string next = word;
                        next.erase(next.begin(),next.begin()+i+1);
                        if (search(next,temp->children[j])) return true;
                    }
                }
                return false;
            }
        }
        if (temp==NULL) return false;
        return (temp->end);
    }

public:
    WordDictionary() {
            root = create();
    }
    
    void addWord(string word) {
        int n = word.length();
        Trie* temp = root;
        for (int i=0;i<n;i++){
            int index = word[i]-97;
            if (temp->children[index]==NULL) temp->children[index] = create();
            temp = temp->children[index];
        }
        temp->end = true;
    }
    
    bool search(string word) {
        return search(word,root);
    }
};

int main(){
    WordDictionary Dick;
    Dick.addWord("at");
    Dick.addWord("and");
    Dick.addWord("an");
    Dick.addWord("add");
    std::cout<<std::boolalpha<<Dick.search("a")<<std::endl;
    std::cout<<std::boolalpha<<Dick.search(".at")<<std::endl;
    Dick.addWord("bat");
    std::cout<<std::boolalpha<<Dick.search(".at")<<std::endl;
    std::cout<<std::boolalpha<<Dick.search("an.")<<std::endl;
    std::cout<<std::boolalpha<<Dick.search("a.d.")<<std::endl;
    std::cout<<std::boolalpha<<Dick.search("b.")<<std::endl;
    std::cout<<std::boolalpha<<Dick.search("a.d")<<std::endl;
    std::cout<<std::boolalpha<<Dick.search(".")<<std::endl;

    return 0;
}