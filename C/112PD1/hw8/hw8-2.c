void modify(int *a, int val)
{
		*a = val + 1;
}

int query(int (*mp)[131][131][131], char a[4], char b[4])
{
		int avalue = (*mp)[a[0]][a[1]][a[2]], bvalue = (*mp)[b[0]][b[1]][b[2]];
		int check = avalue + bvalue;
		return (check % 2 == 0) ? 0 : 1;
}
