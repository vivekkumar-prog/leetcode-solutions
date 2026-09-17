class Solution {
public:
int sum(string word) {
    int n=word.length();
    int num=0;
    for(int i=0;i<n;i++) {
        int digit=word[i]-'a';
        num=num*10+digit;
    }
    return num;
}
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        if(sum(firstWord) + sum(secondWord) == sum(targetWord)) {
            return true;
        }
        else return false;
        
    }
};