#include <stdio.h>

void findprice(int [],int [],int);
int M,N,i,j;
float sum=0;
void swap(int *x, int *y){
	int t;
	t = *x;
	*x = *y;
	*y = t;
}
void swap1(float *x, float *y){
	float t;
	t = *x;
	*x = *y;
	*y = t;
}
int main(){
	int u,w;
	
	//inserting number of bottle bought and number of barrels in the wine yard
	printf("Number of bottles brought: ");
	scanf("%d",&M);
	printf("Number of barrels in the wine yard: ");
	scanf("%d",&N);
	printf ("!--Preprocessing--!\n");
	int s[N],t[N];
	//inserting volume of the barrels
   
	for(i = 0; i < N; i++) {
		printf("Volume of the %d barrel in bottles: ",i+1);
		scanf("%d", &s[i]);
	}
	
	//inserting price of the each barrels
	printf ("!--Preprocessing--!\n");
	for(j = 0; j < N; j++) {
		printf("Price of the %d barrel in bottles: ",j+1);
		scanf("%d", &t[j]);
	}
	findprice(s,t,N);
	
}
 
void findprice(int s[],int t[],int N)
{
	
	float r[N];
		
	float x[N],vt=0;
		printf ("!--Preprocessing--!\n");
	
	for(i = 0; i < N; i ++)
	    r[i] = t[i]/s[i];
	
	for(i = 0; i < N; i++){
		for(j = i+1; j < N  ; j++){
			if (r[i] < r[i+1]){
				swap1(&r[i],&r[j]);
				swap(&s[i],&s[j]);
				swap(&t[i],&t[j]);
			}
		}
	}

	for(i=0;i<N;i++)
	{
		x[i]=0;
		if(vt+s[i]<=M)
		{
			x[i]=1;
			vt=vt+s[i];
			sum=sum+x[i]*t[i];
	
		}
		else
		{
			x[i]=(M-vt)/s[i];
			sum=sum+x[i]*t[i];
			break;
		}
	}
 
	printf("\n Maximum value of wines: %.0f ",sum);	
}
