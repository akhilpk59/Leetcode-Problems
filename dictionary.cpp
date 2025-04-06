#include<iostream>
#include<string>
#include<map>
using std::string;
using std::map;

class WordDictionary {
struct Tree {
    string val;
    Tree* left;
    Tree* right;        
};

Tree* root;

Tree* create (string val){
    Tree* temp = new Tree;
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
map<string, bool> store;

bool check (string mains, string dots){
    if (mains==dots) return true;
    int nD = dots.length();
    int nM = mains.length();
    if (nM!=nD) return false;
    for (int i=0;i<nD;i++){
        if (dots[i]!=mains[i]&&dots[i]!='.') return false;
    }
    return true;
}


void insert(Tree*& root, string value, map<string, bool>& store){
    if (root==NULL) {
        root = create(value);
        for (auto it = store.begin();it!=store.end();it++){
            if (it->second) continue;
            if (check(value,it->first)) it->second = true;
        }
        store[value] = true;
        return;
    }

    if (root->val==value) {
        for (auto it = store.begin();it!=store.end();it++){
            if (it->second) continue;
            if (check(value,it->first)) it->second = true;
        }
        store[value] = true;
        return;
    }
    else if (root->val<value) insert(root->right,value,store);
    else insert(root->left,value,store);
}

bool search(Tree* root, string val, map<string,bool>& store){
    if (store.find(val)!=store.end()) return store[val];
    if (root==NULL) return false;
    if (check(root->val,val)) {
        store[val] = true;
        return true;
    }
    int l = val.length();
    int n = root->val.length();
    int k = (l<n) ? l : n;
    for (int i=0;i<k;i++){
        if (val[i]=='.') {
            store[val] = search(root->left,val,store)||search(root->right,val,store);
            return store[val];
        }
        if (root->val[i]<val[i]) {
            store[val] = search(root->right,val,store);
            return store[val];
        }
        else if (root->val[i]>val[i]) {
            store[val] = search(root->left, val,store);
            return store[val];
        }
    }
    store[val] = search(root->right,val,store);
    return store[val];
}

public:
    WordDictionary() {
        root = NULL;
    }
    
    void addWord(string word) {
        insert(root,word,store);
    }
    
    bool search(string word) {
        return search(root,word,store);
    }
};
