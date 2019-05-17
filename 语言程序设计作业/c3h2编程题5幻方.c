#include<stdio.h>
int main()
{
	int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p,r1,r2,r3,r4,C1,C2,C3,C4,D1,D2;
	printf("Enter the numbers from 1 to 16 in any order:\n\n");
	scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", &a,&b,&c,&d,&e,&f,&g,&h,&i,&j,&k,&l,&m,&n,&o,&p);
	r1 = a + b + c + d;
	r2 = e + f + g + h;
	r3 = i  + j + k + l;
	r4 =m + n +o + p;
	C1 = a + e + i + m;
	C2 = b + f + j + n;
	C3 = c + g + k + o;
	C4 = d + h + l + p;
	D1 = a + f + k + p;
	D2 = d + g + j + m;
	printf("%3d %3d %3d %3d\n", a, b, c, d);
	printf("%3d %3d %3d %3d\n", e, f, g,h);
	printf("%3d %3d %3d %3d\n", i, j, k, l);
	printf("%3d %3d %3d %3d\n", m, n, o, p);
	printf("\nRow sums: %4d%4d%4d%4d\n", r1, r2, r3, r4);
	printf("Column sums: %4d%4d%4d%4d\n", C1, C2, C3, C4);
	printf("Diagonal sums: %4d%4d\n", D1, D2);
	return 0;	
}

