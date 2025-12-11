int seqSearch(const int arr[], int n, const int & item ){
	int loc ;
	bool found = false;
	loc = 0;
	
	while(loc < n && !found){
		if(arr[loc] == item)
			found = true;
		else	
			loc++;
	}
	if(found)
		return loc;
	else
		return -1;
}


