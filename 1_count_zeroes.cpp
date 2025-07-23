//given an array of 1's and 0's, which has all 1's first followed by all 0's.find the number of 0's in the array using binary search.
#include<iostream>
using namespace std;

class count_zeroes {
    int size;
    int arr[100];
public:
    void accept();
    void count_zero();

}C;

void count_zeroes::accept() {
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter the keys:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}
void count_zeroes::count_zero() {
    int low = 0, high = size - 1;
    int mid, count = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == 0) {
            count++;
            
            int left = mid - 1;
            while (left >= low && arr[left] == 0) {
                count++;
                left--;
            }
            
            int right = mid + 1;
            while (right <= high && arr[right] == 0) {
                count++;
                right++;
            }
            break; 
        }
         else if (arr[mid] = 1) 
        {
            low = mid + 1;
        } 
        else 
        {
            high = mid - 1;
        }
    }
    if (count > 0) {
        cout << "Number of 0's in the array: " << count << endl;
    } else {
        cout << "No 0's found in the array." << endl;
    }
}

int main() {
    C.accept();
    C.count_zero();
    return 0;
}