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
	int key;
	cout << "Enter key element : ";
	cin >> key;
	int position = -1;
	for (int i = 0; i < n; ++i) {
	if (arr[i] == key) {
		position = i;
		break;
	}
	}
	if (position != -1) {
		cout << "The key element " << key << " is found at the position : " << position << "\n";
	}
	else {
		cout << "The Key element " << key << " is not found in the array\n";
	}
	return 0;
}