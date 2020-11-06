#include<string>
#include<iostream>

using namespace std;


class Solution {
public:
	int strStr(string haystack, string needle) {

		int len_n = needle.size();
		if (len_n == 0) return 0;
		int *next = new int[len_n];
		cal_next(needle, next, len_n);
		int j = 0;
		for (int i = 0; i < haystack.length(); i++){
			if (haystack[i] != needle[j]){
				i--;
				j = next[j];
				if (j == -1){
					j = 0;
					i++;
				}
			}
			else{
				j++;
				if (j == len_n) return i - len_n + 1;
			}

		}
		return -1;
	}
	void cal_next(string needle, int *next, int len_n){
		int i = -1;
		next[0] = -1;
		int j = 0;
		while (j<len_n - 1){
			if (i == -1 || needle[j] == needle[i]){

				i++;
				j++;
				next[j] = i;
			}
			else{
				i = next[i];
			}
		}

	}

};



int main(){
	Solution s;
	int res = s.strStr("hello", "ll");
	cout << res << endl;

	system("pause");
	return 0;

}
