#include<iostream>
using namespace std;

class Solution {

public:
    Solution();
    bool isPalindrome(int x);//�жϻ���������

};
Solution::Solution() {}
//������Ϊ��ʱ����0�������벻Ϊ��ʱ���������������ԭ���Ƚϣ�����ȱ����1�����ȱ����0
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
