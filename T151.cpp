#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    /*
    思路：1.去除多余的空格
          2.将字符串整个的反转
          3. 将每个单词反转
    */
    string reverseWords(string s) {
        int slow_index = 0;
        int fast_index = 0;
        for(fast_index = 0;fast_index<s.size()-1;fast_index++){
            if(s[fast_index] == ' ' && (s[fast_index+1] == ' ' || slow_index == 0)) continue;
            
            else {
                s[slow_index] = s[fast_index];
                slow_index++;
            }
        }
        if(s[fast_index] != ' ') {
            s[slow_index] = s[fast_index];
            slow_index++;
        }
        s.resize(slow_index);
        reverse_part_s(s,0,s.size());

        int start = 0;
        int end  = 0;
        while(end<s.size()){
            if(s[end] == ' '){
                reverse_part_s(s,start,end);
                start = end +1;
            }
            end++;
        }
        reverse_part_s(s,start,s.size());
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
    string res = s.reverseWords("  hello world  ");
    cout<<res<<endl;

    system("pause");
    return 0;
}