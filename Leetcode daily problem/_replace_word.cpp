#include <bits/stdc++.h> 

class Trie {
public:
    class Node {
    public:
        Node* links[26] = {nullptr};
        bool flag = false;
        int pre=0;
        int end=0;
        vector<int> index;

        void put(Node* node, char ch) {
            links[ch - 'a'] = node;
        }

        Node* get(char ch) {
            return links[ch - 'a'];
        }

        bool containsKey(char ch) {
            return links[ch - 'a'] != nullptr;
        }

        void setEnd() {
            flag = true;
        }

        bool isEnd() {
            return flag;
        }
    };

    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string& word,int j) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(new Node(), word[i]);
            }
            node = node->get(word[i]);
            node->pre++;
            node->index.push_back(j); //index of the word ending with this ps 

        }

        node->end++;
        node->setEnd();
    }

    int countWordsEqualTo(string& word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->isEnd() ? node->end : 0;
    }

    int countWordsStartingWith(string& word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->pre;
    }

        vector<int>  indexofWordsStartingWith(string& word) {
        Node* node = root;
        vector<int>void1;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                return void1;
            }
            node = node->get(word[i]);
        }
        return node->index;
    }


    void erase(string& word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                return;
            }
            node = node->get(word[i]);
            node->pre--;
        }

        node->end--;
        node->flag = false;
    }

    bool checkpre(string &word)
    {
             Node* node = root;
        for (int i = 0; i < word.size(); i++) {
           
            node = node->get(word[i]);

            if(node->flag==false)
            return false;
            
        }

        return true;

    }

    

};



class Solution {
public:

//lets implement using Trie
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        sort(dictionary.begin(),dictionary.end());  //this will ensure that smaller prefix will get replaced first ---

        vector<string>word;
        string temp;
        for(int i =0;i<sentence.length();i++)
        {   
            if(sentence[i]!=' ')
            temp +=sentence[i];
            else
            {   
                word.push_back(temp);
                temp="";
            }
        }

        word.push_back(temp);

        Trie trie;

        for(int i =0;i<word.size();i++)
        {
            // cout<<word[i]<<" ";
            trie.insert(word[i],i);
        }

vector<int>visited(word.size(),0);

       for(int i =0;i<dictionary.size();i++)
       {
           vector<int> index;
           index = trie.indexofWordsStartingWith(dictionary[i]);

           for(int j=0;j<index.size();j++)
           {
             if(visited[index[j]]==0)
             {
                visited[index[j]]=1;

                word[index[j]] = dictionary[i];
             }
           }

       }
      string ans=word[0];
       for(int i =1;i<word.size();i++)
       {
          ans+=' '+word[i];
       }
        return ans;
    }
};
