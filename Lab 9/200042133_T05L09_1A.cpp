#include <bits/stdc++.h>
using namespace std;
#define P 29
#define MOD INT_MAX
#define ull unsigned long long


string genUniqueCharSet(string s){
    
    string charSet = "";
    
    for(char c: s){
        //ignoring repition, saved the word in charSet
        if(charSet.find(c) == std::string::npos){
            charSet+=c;
        }
    }
    
    return charSet;
}



vector<ull> hashThis(string s){
    vector<ull> hashes;
    for(char c: s){
        hashes.push_back( (c * P) % MOD);
    }
    
    return hashes;
}



bool matchHashes(string s, vector<ull> vw){
    vector<ull> vs = hashThis(s);
    sort(vs.begin(), vs.end());
    sort(vw.begin(), vw.end());
    if(vs == vw)
        return true;
    else 
        return false;
}




void ansStrings (vector<string> sentence){
    string word = sentence.back();
    sentence.pop_back();//separate the word
    
    for(string s: sentence){
        string uniqueS = genUniqueCharSet(s);
        string uniqueWord = genUniqueCharSet(word);
            
        if(matchHashes(uniqueS, hashThis(uniqueWord))){
            cout<<s<<" ";
        }
    }
    
}


int main(){
    vector<string> vs;
    
    string s;
    while(cin>>s){
        vs.push_back(s);
    }
    
    ansStrings(vs);

    return 0;
}