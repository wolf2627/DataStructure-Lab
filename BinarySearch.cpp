#include <iostream>
using namespace std;
int main() {
	int n;
    cout << "Enter value of n : ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements : ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(arr[i]>arr[j]){
				int t=arr[i];
				arr[i]=arr[j];
				arr[j]=t;
			}
		}
	}
    int key;
    cout << "Enter key element : ";
    cin >> key;
    int position = -1;
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            position = mid;
            break;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
        cout << "After sorting the elements in the array : ";
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
	if (position != -1) {
        cout << "\nThe key element " << key << " is found at the position : " << position << endl;
    } else {
        cout << "\nThe Key element " << key << " is not found in the array\n";
    }
    return 0;	
}
