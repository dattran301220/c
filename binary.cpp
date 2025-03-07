#include <bits/stdc++.h>
using namespace std;

vector<int> Problem2(vector<int>& nums, int k) {
    int first = -1, last = -1;
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= k) {  
            if (nums[mid] == k) first = mid;  
            right = mid - 1;  
        } else {
            left = mid + 1;
        }
}   
    left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= k) {  
            if (nums[mid] == k) last = mid;  
            left = mid + 1;  
        } else {
            right = mid - 1;
        }
    }

    return {first, last};
}



int problem3(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        
        if (nums[mid] == target) return mid;

        if (nums[left] <= nums[mid]) {  
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;  
            }
        } else {  
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;  
            } else {
                right = mid - 1; 
            }
        }
    }

    return -1; 
}



int problem4(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[mid + 1]) {
            right = mid;  
        } else {
            left = mid + 1;
        }
    }
    return left;
}


int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort (a.begin(),a.end());

    int k;
    cin >> k; 
    vector<int> result = Problem2(a, k);
    cout << result[0] << " " << result[1] << endl;

    return 0;
}

