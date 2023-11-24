void modify(int *a, int val) {
	*a = val;
}

int query(int (*mp)[131][131][131], char a[4], char b[4]) {
	int avalue = (*mp)[a[0]][a[1]][a[2]], bvalue = (*mp)[b[0]][b[1]][b[2]];
	int check = 0;
	if (avalue == 0)
		check++;
	else
		check += avalue;
	if (bvalue == 0)
		check++;
	else
		check += bvalue;
	return (check % 2 == 0) ? 0 : 1;
}
