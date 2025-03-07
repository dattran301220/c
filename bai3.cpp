#include <iostream>
#include <vector>

class SortingAlgorithms {
private:
    // Hàm tiện ích cho thuật toán sắp xếp trộn (Merge Sort)
    static void merge(std::vector<int>& arr, int left, int mid, int right) {
        // TODO: Cài đặt hàm trộn
        // 1. Tạo mảng tạm thời L[] và R[]
        // 2. Sao chép dữ liệu vào các mảng tạm thời
        // 3. Trộn các mảng tạm thời vào lại arr[left..right]
        int n1 = mid -left +1;
        int n2= right -mid;
        std::vector<int> L(n1), R(n2);
        for (int i=0;i<n1;i++) {
            L[i]= arr[left+i];
        }
        for (int j=0;j<n2;j++){
            R[j]=arr[mid+1+j];
        }
        int i=0,j=0, k =left;
        while (i<n1&&j<n2){
            if (L[i]<= R[j]){
                arr[k]=L[i];
                i++;
            }else{
                arr[k]=R[j];
                j++;
            }
            k++;
        }
        while (i<n1){
            arr[k]=L[i];
            i++;
            k++;
        }
        while (j<n2){
            arr[k]= R[j];
            j++;
            k++;
        }
    }

    // Hàm tiện ích cho thuật toán sắp xếp nhanh (Quick Sort)
    static int partition(std::vector<int>& arr, int low, int high) {
        // TODO: Cài đặt hàm phân đoạn
        // 1. Chọn phần tử chốt (thường là phần tử cuối cùng)
        // 2. Đặt chốt vào đúng vị trí của nó
        // 3. Đưa các phần tử nhỏ hơn sang bên trái, lớn hơn sang bên phải
        int pivot = arr[high]; 
        int i = low - 1; 
    
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) { 
                i++;
                std::swap(arr[i], arr[j]); 
            }
        }
    
        std::swap(arr[i + 1], arr[high]); 
        return i + 1; 
    }

    // Hàm đệ quy cho sắp xếp trộn
    static void mergeSortRecursive(std::vector<int>& arr, int left, int right) {
        // TODO: Cài đặt thuật toán sắp xếp trộn đệ quy
        // 1. Kiểm tra nếu left < right
        // 2. Tìm điểm giữa
        // 3. Sắp xếp hai nửa mảng
        // 4. Trộn hai nửa đã sắp xếp
            if (left < right) {
                int mid = left + (right - left) / 2;
        
                mergeSortRecursive(arr, left, mid);
                mergeSortRecursive(arr, mid + 1, right);
                merge(arr, left, mid, right);
            }
    }

    // Hàm đệ quy cho sắp xếp nhanh
    static void quickSortRecursive(std::vector<int>& arr, int low, int high) {
        // TODO: Cài đặt thuật toán sắp xếp nhanh đệ quy
        // 1. Kiểm tra nếu low < high
        // 2. Lấy chỉ số phân đoạn
        // 3. Sắp xếp các phần tử trước và sau phần tử chốt
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSortRecursive(arr, low, pi - 1);
            quickSortRecursive(arr, pi + 1, high);
        }
    }

public:
    // Thuật toán sắp xếp nổi bọt (Bubble Sort)
    static void bubbleSort(std::vector<int>& arr) {
        // TODO: Cài đặt thuật toán sắp xếp nổi bọt
        // 1. Dùng vòng lặp lồng nhau
        // 2. So sánh các phần tử liền kề
        // 3. Hoán đổi nếu sai thứ tự
        int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
    }

    // Thuật toán sắp xếp chọn (Selection Sort)
    static void selectionSort(std::vector<int>& arr) {
        // TODO: Cài đặt thuật toán sắp xếp chọn
        // 1. Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
        // 2. Đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên của phần chưa sắp xếp
        // 3. Di chuyển ranh giới của mảng chưa sắp xếp
        int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(arr[i], arr[min_idx]);
    }
    }

    // Thuật toán sắp xếp chèn (Insertion Sort)
    static void insertionSort(std::vector<int>& arr) {
        // TODO: Cài đặt thuật toán sắp xếp chèn
        // 1. Duyệt qua mảng
        // 2. Chèn mỗi phần tử vào vị trí đúng trong phần đã sắp xếp
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    // Hàm gọi sắp xếp trộn (Merge Sort) từ bên ngoài
    static void mergeSort(std::vector<int>& arr) {
        mergeSortRecursive(arr, 0, arr.size() - 1);
    }

    // Hàm gọi sắp xếp nhanh (Quick Sort) từ bên ngoài
    static void quickSort(std::vector<int>& arr) {
        quickSortRecursive(arr, 0, arr.size() - 1);
    }
};

// Hàm tiện ích để in mảng
void printArray(const std::vector<int>& arr) {
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// Hàm kiểm tra các thuật toán sắp xếp - KHÔNG ĐƯỢC SỬA ĐỔI
void testSortingAlgorithms() {
    std::vector<std::vector<int>> testArrays = {
        {64, 34, 25, 12, 22, 11, 90},
        {38, 27, 43, 3, 9, 82, 10},
        {8, 4, 23, 42, 16, 15},
        {122, 45, 75, 90, 32, 11},
        {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
    };

    std::cout << "Kiểm tra thuật toán Sắp xếp nổi bọt:\n";
    std::vector<int> arr1 = testArrays[0];
    std::cout << "Mảng ban đầu: ";
    printArray(arr1);
    SortingAlgorithms::bubbleSort(arr1);
    std::cout << "Mảng sau khi sắp xếp: ";
    printArray(arr1);
    std::cout << std::endl;

    std::cout << "Kiểm tra thuật toán Sắp xếp chọn:\n";
    std::vector<int> arr2 = testArrays[1];
    std::cout << "Mảng ban đầu: ";
    printArray(arr2);
    SortingAlgorithms::selectionSort(arr2);
    std::cout << "Mảng sau khi sắp xếp: ";
    printArray(arr2);
    std::cout << std::endl;

    std::cout << "Kiểm tra thuật toán Sắp xếp chèn:\n";
    std::vector<int> arr3 = testArrays[2];
    std::cout << "Mảng ban đầu: ";
    printArray(arr3);
    SortingAlgorithms::insertionSort(arr3);
    std::cout << "Mảng sau khi sắp xếp: ";
    printArray(arr3);
    std::cout << std::endl;

    std::cout << "Kiểm tra thuật toán Sắp xếp trộn:\n";
    std::vector<int> arr4 = testArrays[3];
    std::cout << "Mảng ban đầu: ";
    printArray(arr4);
    SortingAlgorithms::mergeSort(arr4);
    std::cout << "Mảng sau khi sắp xếp: ";
    printArray(arr4);
    std::cout << std::endl;

    std::cout << "Kiểm tra thuật toán Sắp xếp nhanh:\n";
    std::vector<int> arr5 = testArrays[4];
    std::cout << "Mảng ban đầu: ";
    printArray(arr5);
    SortingAlgorithms::quickSort(arr5);
    std::cout << "Mảng sau khi sắp xếp: ";
    printArray(arr5);
}

int main() {
    testSortingAlgorithms();
    return 0;
}
