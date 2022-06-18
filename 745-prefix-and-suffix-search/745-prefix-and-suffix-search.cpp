struct Node{
    Node* links[27];
    int ind=-1;
    int ew=0;
    
    bool isThere(char ch){
        if(ch=='#')return links[26]!=NULL;
        return links[ch-'a']!=NULL;
    }
    void put(char ch){
        if(ch=='#')links[26]=new Node();
        else links[ch-'a']=new Node();
    }
    Node* get(char ch){
        if(ch=='#')return links[26];
        return links[ch-'a'];
    }
};

class Trie{
    Node* root=new Node();
public:
    void insert(string& str, int index){
        Node* node=root;
        for(int i=0;i<str.size();++i){
            if(!node->isThere(str[i]))node->put(str[i]);
            node=node->get(str[i]);
            node->ind=index;
        }
        node->ew++;
        return ;
    }
    
    int calc(string& str){
        Node* node=root;
        for(int i=0;i<str.size();++i){
            if(!node->isThere(str[i]))return -1;
            node=node->get(str[i]);
        }
        return node->ind;
    }
};

class WordFilter {
public:
    Trie trie;
    WordFilter(vector<string>& words) {
        for(int i=0;i<words.size();++i){
            for(int j=0;j<=words[i].size();++j){
                string str="";
                str.insert(str.end(),words[i].begin()+j,words[i].end());
                str.push_back('#');
                str.insert(str.end(),words[i].begin(),words[i].end());
                trie.insert(str,i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string find="";
        find+=suffix;
        find.push_back('#');
        find+=prefix;
        return trie.calc(find);
    }
};