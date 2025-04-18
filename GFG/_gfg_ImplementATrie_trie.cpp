#include <bits/stdc++.h>
using namespace std;


// User function template for C++
struct Node{
    Node* links[26];
    bool flag=false;
    bool containskey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
};

class Trie {
  private:
    Node* root;
public:
    Trie() {
        root=new Node();
    }

    void insert(string &word) {
        // insert word into Trie
        int n=word.size();
        Node* node=root;
        for(int i=0;i<n;i++){
            if(!node->containskey(word[i])){
                node->put(word[i],new Node());
            }
            node =node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string &word) {
        // search word in the Trie
        Node* node=root;
        int n=word.size();
        for(int i=0;i<n;i++){
            if(!node->containskey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        if(node->flag==true) return true;
        return false;
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        Node* node=root;
        int n=word.size();
        for(int i=0;i<n;i++){
            if(!node->containskey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        // if(node->flag==true) return true;
        return true;
    }
};



int main(){
    Trie t;
    string s="app";
    string s1="apple";
    string s2="bat";
    t.insert(s1);
    t.insert(s2);
    t.insert(s);

    cout<<t.search(s)<<endl;
    cout<<t.search(s1)<<endl;
    cout<<t.search(s2)<<endl;
    cout<<t.isPrefix(s)<<endl;
    cout<<t.isPrefix(s1)<<endl;
    cout<<t.isPrefix(s2)<<endl;

        return 0;
}