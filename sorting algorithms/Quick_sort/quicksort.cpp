void quicksort(int a[], int first, int last ){
	
	int lower = first+1, upper = last;
	swap(a[first], a[(first + last) /2 ]);
	int pivot = a[first];
	
	while(lower <= upper){
		while(pivot >= a[lower])
			lower++;
		while(pivot < a[upper])
			upper--;
		if(lower< upper)
			swap(a[lower++], a[upper--]);
		else lower++;
	}
	
	swap(a[upper],a[first]);
	if(first < upper-1){
		quicksort(a,first, upper -1);
	}
	if(upper +1 < last){
		quicksort(a,upper+1, last);
	}
}
