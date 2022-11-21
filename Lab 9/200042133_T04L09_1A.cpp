#include <bits/stdc++.h>
using namespace std;
#define P 29
#define MOD INT_MAX
#define ull unsigned long long
//s2 is the substring
int rabinKarpHashing(string s1, string s2){
    //if the substring size is smaller
    if(s2.length() > s1.length()){
        return -1;
    }
    
    
    //precalculated powers
    vector<ull> base_pow(1000); 
    base_pow[0] = 1; 
    int sz1 = s1.length();
    
    for (int i = 1; i < s1.length(); i++) {
        base_pow[i] = (base_pow[i-1] * P) % MOD;
        //cout<< base_pow[i]<<endl;
    }
        
    //calculating hash value of substring
    ull hash2 = 0;
    for(int i=0; i<s2.length(); i++){
        hash2 = (s2[i] * base_pow[i] + hash2) % MOD;
        //cout<<hash2<<endl;
    }
    
    
    //cout<< "hash1: "<< endl;
    ull hash1[sz1+1]; //10
    hash1[0] = 0; //for subtraction purposes
    for(int i=0; i<s1.length(); i++){ // 9 times iterate
        //hash1[1] = s * 1 + 0
        hash1[i+1]= (s1[i]*base_pow[i] + hash1[i]) % MOD;
        //cout<<hash1[i+1]<<endl;
    }
    

    //searching for first occurence of substring
    int occurence = -1;
    for(int i=s2.length(); i<sz1 + 1; i++){
        //cout<<"i-s2.length(): "<<i-s2.length()<<endl;
        ull curHash = (hash1[i] - hash1[i-s2.length()] + MOD) % MOD; //current hash (added MOD to it so it would not be negative)
        ull expHash = (hash2 * base_pow[i-s2.length()]) % MOD; // hash of substring multiplied by a certain power
        //cout<<"currHash: "<<curHash<<endl<<"expHash: "<<expHash<<endl;
        if(curHash == expHash){
            occurence = i-s2.length();
            break;
        }
    }
    
    return occurence;
    
}


int main(){
    string haystack, needle;
    cin>>haystack>>needle;
    
    
    cout<<rabinKarpHashing(haystack, needle)<<endl;

    return 0;
}