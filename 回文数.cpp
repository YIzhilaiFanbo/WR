#include<iostream>
using namespace std;

class Solution {

public:
    Solution();
    bool isPalindrome(int x);//判断回文数方法

};
Solution::Solution() {}
//当输入为负时返回0；当输入不为负时，将输入逆序后与原数比较，若相等便输出1，不等便输出0
bool Solution::isPalindrome(int num) {
    if (num < 0) {
        return false;
    }
    else {
        int x = num;
        int m = 0;
        while(num>0){
            m = num % 10 + m * 10;
            num /= 10;
        }
        if (m == x) {
            return true;
        }
        else return false;
    }
}
int main() {
    int n;
    freopen("in.txt", "r", stdin);
    cin >> n;
    Solution s;
    cout << s.isPalindrome(n);
	return 0;
}
