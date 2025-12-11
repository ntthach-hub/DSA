int binary_search(const int arr[], int n, const int &item){
	int first = 0;
	int last = n - 1;
	int mid ;
	bool found = false;
	while (first <= last && !found){
		mid = (first + last) / 2;
		if(arr[mid] == item)
			found = true;
		else if(arr[mid] > item)
			last = mid -1;
		else
			first = mid +1;
	}
	if(found)
		return mid;
	else
		return -1;
}
