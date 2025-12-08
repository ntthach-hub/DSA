void Shell_sort(int arr[], int n){
	int i, j,hcnt, h;
	int increments[20],k;
	
	for(h = 1,i =0; h < n; i++){
		increments[i] = h;
		h = 3*h+1;
	}
	
	for(i-- ; i >= 0; i--){
		h = increments[i];
		
		for(hcnt = h; hcnt < n; hcnt ++){
			for(j = hcnt ; j < n;){
				int tmp = arr[j];
				k = j;
				while( k-h >=0 && arr[k-h] > tmp){   // sap xep tang dan
					arr[k] = arr[k-h];
					k-=h;
				}
				arr[k] = tmp;
				j += h;
			}
		}
	}
}
