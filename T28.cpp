#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len_n = needle.size();
        int *next = new int(len_n);
        cal_next(needle,next,len_n);


    }
    void cal_next(string needle,int *next,int len_n){
        int i=0;
        next[0] = 0;
        int j=1;
        while(j<len_n){
            if(needle[j] == needle[i]){
                next[j] = next[i]+1;
                i = next[j];
                j++;
                continue;
            }
            else{
                i = next[ needle[i] ];
            }
            if(i==0){
                if(needle[j] == needle[i]) needle[j] = 1;
            }
            

        }
    }
};



int main(){
    Solution s;
    int res = s.strStr("abacababcabacababd","abacababd");
    cout<<res<<endl;

    system("pause");
    return 0;
}