//277. Find the Celebrity.cc


int findCelebrity(int n) {
	if(n<=1)return 0;
	int Celebrity = 0;

	for(int i=1;i<n;i++){
		if(knows(i, Celebrity) == false)//i does not know Celeb, i is the celeb
			Celebrity = i;
	}

	for(int j=0;j<n;j++){
		if(j == Celebrity)continue;
		if(knows(Celebrity,j) || !knows(j, Celebrity))return -1;
	}
	return Celebrity;
}