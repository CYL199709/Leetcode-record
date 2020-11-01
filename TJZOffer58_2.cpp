#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    /*
    思路：先反转[0,n),再反转[n,end),最后再反转整个字符串
    */
    string reverseLeftWords(string s, int n) {
        reverse_part_s(s,0,n);
        reverse_part_s(s,n,s.size());
        reverse_part_s(s,0,s.size());
        return s;

    }
    //翻转[start,end)的字符串s
    void reverse_part_s(string &s,int start, int end){
        for(int i=start,j=end-1;i<(start+end)/2;i++,j--){
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
    }
};

int main(){
    Solution s;
    string res = s.reverseLeftWords("abcedfg",2);
    cout<<res<<endl;

    system("pause");
    return 0;
}