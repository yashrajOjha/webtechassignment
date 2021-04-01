#include<stdio.h>
#include<string.h>
int max(int a, int b);
int lcs( char *A, char *B, int i, int j)
{
if (i == 0 || i == 0)
	return 0;
if (A[i-1] == B[j-1])
	return 1 + lcs(A, B, i-1, j-1);
else
	return max(lcs(A, B, i, j-1), lcs(A, B, i-1, j));
}

int max(int a, int b)
{
	return (a > b)? a : b;
}

int main()
{
char a[] = "bd";
char b[] = "abcd";

int i = strlen(a);
int j = strlen(b);

printf("Length of LCS is %d", lcs( a, b, i, j ) );

return 0;
}
