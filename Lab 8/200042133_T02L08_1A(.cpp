#include <bits/stdc++.h>
using namespace std;


class Products
{
public :
    int trie[300005][50];
    int id = 1;
    int endmark[300005];
    int pre[300005];
    Products()
    {
        memset(trie,0,sizeof(trie));
        memset(endmark,0,sizeof(endmark));
        memset(pre,0,sizeof(pre));
    }

    void addProducts(string word)
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
    }


    //modified version of starts with
    int findRowNum(string prefix)
    {
        int row = 1;
        for (int i=0; i<prefix.size(); i++)
        {
            int ch = prefix[i] - 'a';
            if (trie[row][ch] == 0)
            {
                return -1;
            }
            row = trie[row][ch];
        }
        return row;
    }



    vector<string> suggestWords(vector<string> vs, int row, string s)
    {
        if(row >= id || vs.size()==3)//check if it did exceed the limit of 3
            return vs;

        for(int i=0; i<26; i++)//for 26 places in that row
        {
            if(trie[row][i]!=0)//if there is an input
            {
                s+= i + 'a';
                if(endmark[trie[row][i]]==1)//if this is an end word
                {
                    vs.push_back(s);//add the word to the vector
                }

                int temp = trie[row][i];//update row for row jump

                vs = suggestWords(vs, temp, s); //recursively call onto the next row to do the same thing

                //when it returns to the last point where it branched
                //for mobile, after it comes back from mo
                //the string still has mob
                //so we remove the last letter
                if (s.size () > 0)
                    s.resize (s.size () - 1);


            }
        }
        //after finishing the entire loop
        return vs;
    }



    ///START HERE!!!!!!!!!!!!!!!!!!!!!
    //we want to iterate by imitating keystroke
    //m er jonno then mo er jonno
    //for this we need to know where this 'mo' lies
    //thus we modify the startsWith function to above
    //for m we call the suggestWords function below this one

    //since we get a vector of strings, we will use a function
    //for printing vector
    vector<vector<string> > printSuggestions(string searchWord)
    {
        vector<vector<string> > vvs;
        string temp = "";
        int row;
        for(int i=0; i<searchWord.length(); i++)
        {
            temp+=searchWord[i]; //working
            row = findRowNum(temp); //working
            cout<<"row: "<<row<<endl;
            cout<<trie[row][temp[i] -'a']<<endl;

            vector<string> suggestions;
            if(row==-1)
            {
                suggestions.push_back("n/a");
                vvs.push_back(suggestions);
                continue;
            }

            suggestions = suggestWords(suggestions, row, temp);


            //for the last time in the loop, the word will also be in the suggestions
            //if the word exists in the productList
            if(i==searchWord.length()-1 && endmark[row]==1)
            {
                suggestions.push_back(searchWord);
                sort(suggestions.begin(), suggestions.end());
                suggestions.resize(3);
            }


            vvs.push_back(suggestions);
        }

        return vvs;
    }


};



class Solution
{
public:
    vector<vector<string> > suggestedProducts(vector<string>& products, string searchWord)
    {
        Products* productList = new Products();
        vector<vector<string> > rs;

        for(int i=0; i<products.size(); i++)
        {
            productList->addProducts(products[i]);
        }

        rs = productList->printSuggestions(searchWord);
        return rs;
    }
};



string printVector(vector<vector<string> > vvs)
{
    string output="";
    for(int i=0; i<vvs.size(); i++)
    {
        vector<string> vs = vvs[i];
        for(int j=0; j<vs.size(); j++)
        {
            output+=vs[j];
            output+=" ";
        }
        output+="\n";
    }
    return output;
}



int main()
{

    string s;
    cin>>s;

    vector<string> products;
    while(cin>>s)
    {
        products.push_back(s);
    }
    string searchWord = products.back();

    Solution sol;
    cout<<printVector(sol.suggestedProducts(products, searchWord));


    return 0;
}
