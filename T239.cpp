#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        MyQueue que;
        vector<int> res;
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        for (int i = k; i < nums.size(); i++) {
            res.push_back(que.front());
            que.pop(nums[i - k]);
            que.push(nums[i]);
        }
        res.push_back(que.front());
        return res;
    }

  private:
    class MyQueue {
      public:
        deque<int> que;
        void pop(int value) {
            if (!que.empty() && value == que.front())
                que.pop_front(); //保证队列长度不超过k
        }
        void push(int value) {
            while (!que.empty() && que.back() < value)
                que.pop_back();
            que.push_back(value);
        }
        int front() { return que.front(); }
    };
};

void main() {
    Solution s;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> res = s.maxSlidingWindow(nums, k);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
    system("pause");
}