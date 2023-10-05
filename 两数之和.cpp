#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2, -1);

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == complement) {
                    result[0] = i;
                    result[1] = j;
                    return result;
                }
            }
        }

        return result;
    }
};

int main() {
    vector<int> nums;
    int num;
    freopen("in.txt", "r", stdin);
    while (cin >> num) {
        nums.push_back(num);
        if (cin.get() == '\n') {
            break;
        }
    }

    int target;
    cin >> target;

    Solution solution;
    vector<int> result = solution.twoSum(nums, target);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}

