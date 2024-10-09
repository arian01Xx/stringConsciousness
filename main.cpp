#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node{
    Node* child[26];
    int end;
    vector<int> palindrome_below;

    Node(){
        for(int i=0; i<26; i++){
            child[i]=NULL;
        }
        end=-1;
    }
};

class Solution {
private:
    Node* root=new Node();
    vector<vector<int>> ans;

    bool check(const string& s, int i, int j){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }

    void insert(string& s, int ind){
        Node* temp=root;
        for(int i=s.size()-1; i>=0; i--){
            if(check(s,0,i)){
                temp->palindrome_below.push_back(ind);
            }
            if(temp->child[s[i]-'a']==NULL){
                temp->child[s[i]-'a']=new Node;
            }
            temp=temp->child[s[i]-'a'];
        }
        temp->end=ind;
        temp->palindrome_below.push_back(ind);
    }

    void search(string& s, int ind){
        Node* temp=root;
        for(int i=0; i<s.size(); i++){
            if(temp->end!=-1 && temp->end!=ind && check(s,i,s.size()-1)){
                ans.push_back({ind,temp->end});
            }
            if(temp->child[s[i]-'a']==NULL) return;
            temp=temp->child[s[i]-'a'];
        }
        for(int idx: temp->palindrome_below){
            if(ind!=idx) ans.push_back({ind,idx});
        }
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        for(int i=0; i<words.size(); i++){
            insert(words[i],i);
        }
        for(int i=0; i<words.size(); i++){
            search(words[i],i);
        }
        return ans;
    }
};

int main(){
    
    return 0;
}