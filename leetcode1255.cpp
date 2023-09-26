//1255.Maximum score words formed by letters(IMP*****)

//GO THROUGH EVERY SOLUTION SUBMITTED BY OTHER LEETCODERS COPIED HERE
//try 2151. Maximum Good People Based on Statements

#include<bits/stdc++.h>
using namespace std;


//BACKTRACKING
//LEETCODE SOLVER alpha0610

class Solution {
public:
    int ans=INT_MIN;
unordered_map<char,int>val;
unordered_map<char,int>freq;
int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) 
{
	//getting the freq of all the avail char's
	for(int i=0;i<(letters.size());i++)
	{
		char ch = letters[i];
		freq[ch]++;
	}
	//getting the val of all the alphabets
	for(int i=0;i<(score.size());i++)
	{
		char ch = 'a' + i;
		val[ch] = score[i];
	}
	int idx=0;
	string temp="";
	fun(idx,temp,words,letters,score);
	return ans;
}
void fun(int idx,string &temp,vector<string>&words,vector<char>&letters,vector<int>&score)
{
	//trying to get all the subsets of the given words array
	//ans then trying to make the ans
	if(idx >= words.size())
	{
		//try to make the ans with the help of val and freq map
		unordered_map<char,int>temp_freq;
		for(int i=0;i<temp.length();i++)
		{
			char ch = temp[i];
			temp_freq[ch]++;
			
			if(temp_freq[ch] > freq[ch])
			{
				return;
			}
		}
		int sum=0;
		for(auto it=temp_freq.begin();it!=temp_freq.end();it++)
		{
		    sum = sum + (it->second * val[it->first]);	
		}
		if(sum > ans)
		ans=sum;
		return;
	}
	string prvstr=temp;
	
	temp=temp+words[idx];
	fun(idx+1,temp,words,letters,score);
	
	temp=prvstr;
	fun(idx+1,temp,words,letters,score);
}

};



//SOLUTION 2
//New_ganesh

class Solution {
public:
    void solve(int i,int &n,vector<int> &v,vector<int> &score,int &ans,int sum,vector<string> &words){
        ans = max(ans,sum);
        if(i>=n)return;
        vector<int> tmp = v;
        int j=0,sum1=0;
        for(j = 0; j < words[i].length(); j++){
            tmp[words[i][j]-'a']--;
            sum1 += score[words[i][j]-'a'];
            if(tmp[words[i][j]-'a']<0)break;
        }
        if(j==words[i].length()){
            solve(i+1,n,tmp,score,ans,sum+sum1,words);
        }
        solve(i+1,n,v,score,ans,sum,words);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> v(26,0);
        for(auto &i: letters){
            v[i-'a']++;
        }
        int ans = 0,n=words.size();
        solve(0,n,v,score,ans,0,words);
        return ans;
    }
};




//SOLUTION 3 RECURSION
//imsulekh



class Solution {
public:
    int ans = 0;
    void f(vector<string>& words, vector<int>& score, vector<int> freq, int i, int cur_score){
	//if our cotrol reaches to end just take the maximum and store it in ans
        if(i == words.size()){
            ans = max(ans, cur_score);
            return;
        }
		//current word = words[i]
        string cw = words[i];
		//ok will denote that wheter we are able to form this current word with the remaining letters
        bool ok = true;
        int cs = 0;
		//store the current freq in another vector as we will need it on a function call where we are not considering the current word
        vector<int> curfrq = freq; 
		//This loop will check if we are able to form current word with the remaining frequencies and accordingly count the score
        for(int i=0; i<cw.size(); ++i){
		//if we have ran out of frequency then we cannot form this word so toggle ok to false
            if(freq[cw[i] - 'a'] <= 0){
                ok = false;
                break;
            }
			//else count the resultant score and decrease the frequency of current character as we have used it.
            cs += score[cw[i] - 'a'];
            freq[cw[i] - 'a']--;
        }
		//if we can form this word then prooceed to check another word and add this word's score to  the current score, remember to pass the updated frequency vector as we have considered this word
        if(ok) f(words, score, freq, i+1, cs + cur_score);
		//also we will proceed without considering this word, in this case, there will be no change in cur_score and freq thats why we maintained the copy of freq in curfrq, remember ?
        f(words, score, curfrq, i+1, cur_score);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26, 0);
		//store the frequency of all the letters present in letters vector
        for(auto& it: letters) freq[it - 'a']++;
        f(words, score, freq, 0, 0);
        return ans;
        
    }
};