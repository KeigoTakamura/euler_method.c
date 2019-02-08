#include<stdio.h>
#define n (int)(5/0.05)

double func(double x);

void main(){
FILE *fp1,*fp2;
double a[n];
double b[n];
double c[n];
double h	=	0.05;
double x	=	0;
a[0]=20;
b[0]=0.0;
c[0]=0;
	for(int i=1; i< n+1 ;i++){
		x+=h;
		a[i] =a[i-1]-h*9.8;//v(t)
		b[i]=x;//時間軸
		c[i]=c[i-1]+h*a[i];//x(t)
	}

	for(int i=0;i<n+1;i++)
		printf("%lf %lf %lf \n",b[i],c[i],a[i]);

	fp1=fopen("euler_vt.txt","w+");//v(t)出力
	fp2=fopen("euler_x.txt","w+");//x(t)出力

 for(int i=0;i<n+1;i++){
 	  fprintf(fp1,"%lf %lf %lf \n",b[i],a[i]);
 	  fprintf(fp2,"%lf %lf %lf \n",b[i],c[i]);
		}
return;
}


double func(double x){
return	9.8*x;
}
