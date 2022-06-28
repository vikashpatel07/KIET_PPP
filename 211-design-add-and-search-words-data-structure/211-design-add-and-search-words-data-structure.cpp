struct Node{
    Node* link[26];
    bool flag=false;
    
    bool containsKey(char ch){
        return link[ch-'a'];
    }
    Node* get(char ch){
        return link[ch-'a'];
    }
    void put(char ch, Node* node){
        link[ch-'a']=node;
    }
    void setEnd(){
        flag=true;
    }
};
class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
       return search(word,root);
    }
    bool search(string word,Node *node){
       for(int i=0;i<word.size() && node;i++){
           if(word[i]!='.'){
               node=node->get(word[i]);
           }
           else{
                Node* temp=node;
               for(int j=0;j<26;j++){
                   node=temp->link[j];
                   string p=word.substr(i+1);
                   if(search(p,node))return true;
               }
           }
       }
        return node&&node->flag;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */