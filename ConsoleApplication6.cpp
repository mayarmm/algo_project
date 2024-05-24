#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findLIS(const vector<int>& nums, int index, vector<int>& current, vector<int>& longest) {
    if (index == nums.size()) {
        if (current.size() > longest.size()) {
            longest = current;
        }
        return;
    }

    if (current.empty() || nums[index] > current.back()) {
        current.push_back(nums[index]);
        findLIS(nums, index + 1, current, longest);
        current.pop_back();
    }

    findLIS(nums, index + 1, current, longest);
}

vector<int> longestIncreasingSubsequence(const vector<int>& nums) {
    vector<int> current;
    vector<int> longest;
    findLIS(nums, 0, current, longest);
    return longest;
}

void traceAndPrintLIS(const vector<int>& nums, const vector<int>& prev, int end_point) {
    vector<int> lis;
    while (end_point != -1) {
        lis.push_back(nums[end_point]);
        end_point = prev[end_point];
    }
    reverse(lis.begin(), lis.end());
    cout << "The longest increasing subsequence using dynamic programming is: ";
    for (int num : lis) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Using backtracking
    vector<int> longest_increasing_subsequence = longestIncreasingSubsequence(nums);
    cout << "Length of LIS (backtracking): " << longest_increasing_subsequence.size() << endl;
    cout << "The longest increasing subsequence using backtracking is: ";
    for (int num : longest_increasing_subsequence) {
        cout << num << " ";
    }
    cout << endl;

    // Using dynamic programming
    vector<int> array1(n, 1); // array to store lengths of LIS
    vector<int> array2(n, -1); // array to store previous indices

    int max_len = 1, end = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j] && array1[i] < array1[j] + 1) {
                array1[i] = array1[j] + 1;
                array2[i] = j;
            }
        }
        if (array1[i] > max_len) {
            max_len = array1[i];
            end = i;
        }
    }
    cout << "Length of LIS (dynamic programming): " << max_len << endl;
    traceAndPrintLIS(nums, array2, end);

    return 0;
}


