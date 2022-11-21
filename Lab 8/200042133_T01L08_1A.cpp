#include <bits/stdc++.h>
using namespace std;


class WordDictionary
{
public :
    int trie[300005][50];
    int id = 1;
    int endmark[300005];
    int pre[300005];
    WordDictionary()
    {
        memset(trie,0,sizeof(trie));
        memset(endmark,0,sizeof(endmark));
        memset(pre,0,sizeof(pre));
        cout<<"Object created"<<endl;
    }

    void addWord(string word)
    {
        int row = 1;
        for(int i = 0; i < word.size(); i++)
        {
            int ch = word[i] - 'a';
            if(trie[row][ch] == 0)
            {
                trie[row][ch] = ++id;
            }
            row = trie[row][ch];
            pre[row]++;
        }
        endmark[row] = 1;

        cout<<"Word addded"<<endl;

    }

    bool search(string word)
    {
        int row = 1;
        for(int i = 0; i < word.size(); i++)
        {
            //additional part
            if(word[i] == '.') // if it is a dot
            {
                for(int j=0; j<26; j++)//search for the column with the input
                {
                    if(trie[row][j]!=0)//if you find an input
                    {
                        word[i]= j + 'a';
                        //search for that word
                        //m.d replaced by mad
                        if(search(word)) //if you found that word, it exists!
                        {
                            return true;
                        }
                        //if not continue to search for the next 'filled spot'
                    }
                }
            }
            //additional part ends
            else
            {
                int ch = word[i] - 'a';
                if(trie[row][ch] == 0)
                    return false;
                row = trie[row][ch];
            }

        }

        return (endmark[row] == 1);
    }

};

void foundWordMessage(bool found)
{
    if(found)
        cout<<"Word found"<<endl;
    else
        cout<<"Word not found"<<endl;
}


int main()
{
    WordDictionary* dictionary = new WordDictionary();

    dictionary->addWord("bad");
    dictionary->addWord("dad");
    dictionary->addWord("mad");
    foundWordMessage(dictionary->search("pad"));
    foundWordMessage(dictionary->search("bad"));
    foundWordMessage(dictionary->search(".ad"));
    foundWordMessage(dictionary->search("b.."));

    return 0;
}
