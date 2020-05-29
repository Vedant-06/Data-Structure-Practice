#include<iostream>
#include<map>
using namespace std;
class TrieNode{
public:
    map<char,TrieNode*> m;
    bool endOfWord;
    TrieNode(){
        endOfWord=false;
    }
};
//As trie is a tree (recursive data structure)recursive insertion is best ;
void insert(TrieNode* current,string word,int index){
    //base condition for recursion
    //yaha word and hogya h
    if(word.length()==index){
        current->endOfWord=true;
        return;
    }
    char ch=word[index];
    //checking whether ch exist or not if not then creating entry for ch
    TrieNode* node=current->m[ch];
    if(node==NULL){
        node=new TrieNode();
        current->m[ch]=node;
    }
    insert(node,word,index+1);
}
bool prefix_based_search(TrieNode* current,string word,int index){
    if(index==word.length()){
        return 1;
    }
    char ch=word[index];
    if(current->m.find(ch)!=current->m.end()){
        // iwant to get node of child
        TrieNode* node=current->m[ch];
        return prefix_based_search(node,word,index+1);
    }
    return 0;
}
bool search(TrieNode* current,string word,int index){
    if(index==word.length()){
        if(current->endOfWord==true){
            return true;
        }
        return false;
    }
    char ch=word[index];
    if(current->m.find(ch)!=current->m.end()){
        TrieNode* node=current->m[ch];
        return search(node,word,index+1);
    }
    return false;
}
bool delete(TrieNode* current,string word,int index){
    if(index==word.length()){
        if(current->endOfWord==false){
            return false;
        }
        current->endOfWord=false;
        return current->m.size()==0;
    }
    char ch=word[index];
    TrieNode* node=current->m[ch]
    if(node==NULL){
        return false;
    }
    //should i delete the child node and its entry
    bool shouldDeleteTheNode=delete(node,word,index+1);
    if(shouldDeleteTheNode){
        current->m.erase(ch);
        return current->m.size()==0;
    }
    return false;
}
void display(TrieNode* current,string str){
    if(current->endOfWord==true){
        cout<<str<<endl;
        return;
    }
    for(auto it=current->m.begin();it!=current->m.end();it++){
        str.push_back(it->first);
        display(it->second,str);
        str.pop_back();
    }
}
int main(){
    TrieNode *root=new TrieNode();
    int i;
    string word;
    while(1){
        cin>>i;
        if(i==1){
            cin>>word;
            insert(root,word,0);
        }
        if(i==2){
            cin>>word;
            prefix_based_search(root,word,0);
        }
        if(i==3){
            cin>>word;
            search(root,word,0);
        }
        if(i==4){
            cin>>word;
            delete(root,word,0);
        }
    }
    return 0;
}
