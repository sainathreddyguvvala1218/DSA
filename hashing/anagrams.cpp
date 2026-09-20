class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int> snr1,snr2;
        for(char ch:s){
        snr1[ch]++;
        }
        for(char ch:t){
        snr2[ch]++;
        }
    for(char ch:s){
       if(snr1[ch] !=snr2[ch]) return false;
    }
    for(char ch:t){
       if(snr1[ch] !=snr2[ch]) return false;
    }
    return true;
    }
};