#include<stdio.h>
#include<stdlib.h>
// @VietNC, Faculty of Physics, HUS
int main()
{
	int *x, *h, *y;
	int i,j,NX,NH,NY;
	
	printf("Nhap so phan tu cua x: "); 
	scanf("%d",&NX);
	printf("Nhap so phan tu cua h: "); 
	scanf("%d",&NH);
	
	x = (int*)malloc(NX*sizeof(int));
	h = (int*)malloc(NH*sizeof(int));
	y = (int*)malloc((NX+NH-1)*sizeof(int));

	if((x == NULL)||(h == NULL)||(y == NULL)) {
		printf("Khong cap duoc bo nho!\n");
		exit(1);
	}
		
	printf("Nhap cac gia tri cua x: \n"); 
	for(i=0; i<NX; i++)
	{
		printf("x[%d] = ",i);
		scanf("%d",x+i);
	}
	
	printf("Nhap cac gia tri cua h: \n"); 
	for(i=0; i<NH; i++)
	{
		printf("h[%d] = ",i);
		scanf("%d",h+i);
	}
	
	for(i=0; i<NX+NH-1; i++)
	{
		*(y+i)=0;
		for(j=0; j<NH; j++)
		{
			if((i-j<0)||(i-j>= NX)) continue;
			*(y+i) = *(y+i) + (*(h+j))*(*(x+i-j));
			//y[i] = y[i] + h[j]*x[i-j]	;
		}
	}
		
	printf("Ket qua tinh tich chap, y:\n");
	for(i=0;i<NX+NH-1;i++)	
		printf("%d ",y[i]);
		
	return 0;	
}
