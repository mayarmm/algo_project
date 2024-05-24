//
//
//
//
//
//
//// aliaaa
////
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
// //Function to check if the current element can be added to the current subsequence
//bool promising(const vector<int>& current, int num) {
//    return current.empty() || num > current.back();
//}
//
// //Function to find the longest increasing subsequence using backtracking
//void findLIS(const vector<int>& nums, int index, vector<int>& current, vector<int>& longest) {
//    if (index == nums.size()) {
//        if (current.size() > longest.size()) {
//            longest = current;
//        }
//        return;
//    }
//
//   /*  If the current element is promising, include it in the current subsequence*/
//    if (promising(current, nums[index])) {
//        current.push_back(nums[index]);
//        findLIS(nums, index + 1, current, longest);
//        current.pop_back();
//    }
//
//   /*  Exclude the current element and move to the next*/
//    findLIS(nums, index + 1, current, longest);
//}
//
//vector<int> longestIncreasingSubsequence(const vector<int>& nums) {
//    vector<int> current;
//    vector<int> longest;
//    findLIS(nums, 0, current, longest);
//    return longest;
//}
//
///////////////////////modified main/////////////////////
//
//
//
// int main() {
//int x;
//cout << "Enter the number of elements in the array: ";
//cin >> x;
//vector<int> arr(x); // Use vector to avoid manual memory management
//cout << "Enter the elements of the array: ";
//for (int i = 0; i < x; i++) {
//    cin >> arr[i];
//}
//
//vector<int> lis = longestIncreasingSubsequence(arr); // Pass the vector arr
//int lengthOfLIS = lis.size();
//
//// Output the length and the LIS itself
//cout << "Length of the longest increasing subsequence is: " << lengthOfLIS << endl;
//cout << "The longest increasing subsequence using backtracking is: ";
//for (int num : lis) {
//    cout << num << " ";
//}
//cout << endl;
//
//return 0;
//}
// 
//




///////////////////////////////////////////////   mayar 1

//#include <iostream>
//using namespace std;
//
//void LargestIncreasingSubsequence_dynamic_programming(int* arr, int n) {
//    int max_length = 1, end_point = 0;
//    int* array1 = new int[n];
//    int* array2 = new int[n];
//
//    // Initialize dp and prev arrays
//    for (int i = 0; i < n; i++) {
//        array1[i] = 1;
//        array2[i] = -1; // Initialize prev array with -1 indicating no previous element
//    }
//
//    for (int i = 1; i < n; i++) {
//        for (int j = 0; j < i; j++) {
//            if (arr[i] > arr[j] && array1[i] < array1[j]+ 1) {
//                array1[i] = array1[j] + 1;
//                array2[i] = j;
//            }
//        }
//        if (array1[i] > max_length) {
//            max_length = array1[i];
//            end_point = i; // Update the end point when a longer sequence is found
//        }
//    }
//
//    cout << "Length of the longest increasing subsequence is: " << max_length << endl;
//    cout << " the longest increasing subsequences using dynamic programming is: ";
//
//    // Allocate an array to store the elements of the LIS in ascending order
//    int* lis = new int[max_length];
//    int k = max_length - 1; // Index for placing elements into the lis array
//
//    // Trace back from the end point to construct the LIS
//    while (end_point != -1) {
//        lis[k--] = arr[end_point];
//        end_point = array2[end_point];
//    }
//
//    // Print the LIS in ascending order
//    for (int i = 0; i < max_length; i++) {
//        cout << lis[i] << " ";
//    }
//    cout << endl;
//
//    // Deallocate memory reserved for the lis array
//    delete[] lis;
//
//    // Deallocate memory reserved for the dp and prev arrays
//    delete[] array1;
//    delete[] array2;
//}
//
//int main() {
//    int n;
//    cout << "Enter the number of elements in the array: ";
//    cin >> n;
//    int* arr = new int[n];
//    cout << "Enter the elements of the array: ";
//    for (int i = 0; i < n; i++) {
//        cin >> arr[i];
//    }
//    LargestIncreasingSubsequence_dynamic_programming(arr, n);
//    delete[] arr;
//    return 0;
//}




/////////////////////////////////

#include <iostream>
using namespace std;

void LargestIncreasingSubsequence_dynamic_programming(int* arr, int n) {
    if (n == 0) {
        cout << "The array is empty." << endl;
        return;
    }

    int* lis_length = new int[n]; // Length of LIS ending at each index
    int* prev_index = new int[n]; // Previous index in the LIS ending at each index

    // Initialize lis_length and prev_index arrays
    for (int i = 0; i < n; i++) {
        lis_length[i] = 1; // Each element is an LIS of length 1 by itself
        prev_index[i] = -1; // No previous element initially
    }

    int max_length = 1; // Length of the longest increasing subsequence
    int end_point = 0; // End index of the longest increasing subsequence

    // Calculate lis_length and prev_index arrays
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis_length[i] < lis_length[j] + 1) {
                lis_length[i] = lis_length[j] + 1;
                prev_index[i] = j;
            }
        }
        if (lis_length[i] > max_length) {
            max_length = lis_length[i];
            end_point = i;
        }
    }

    cout << "Length of the longest increasing subsequence is: " << max_length << endl;
    cout << "The longest increasing subsequence is: ";

    // Trace back the LIS from the end_point
    int* lis = new int[max_length];
    int k = max_length - 1; // Index for placing elements into the lis array
    for (int i = end_point; i != -1; i = prev_index[i]) {
        lis[k--] = arr[i];
    }

    // Print the LIS in ascending order
    for (int i = 0; i < max_length; i++) {
        cout << lis[i] << " ";
    }
    cout << endl;

    // Deallocate memory reserved for dynamic arrays
    delete[] lis;
    delete[] lis_length;
    delete[] prev_index;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    LargestIncreasingSubsequence_dynamic_programming(arr, n);

    // Deallocate memory reserved for the array
    delete[] arr;

    return 0;
}
