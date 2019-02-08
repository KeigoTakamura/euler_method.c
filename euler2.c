#include<stdio.h>
#include<math.h>
#define	n  600

void main(){
	FILE *fp1,*fp2;
	double k=2.880;//バネ係数
	double m=2.0;//室力
	double sqrt_omega=k/m;//kx
	double x_t[n];//x_t,x軸
	double v_t[n];//速度　v(t)
	double dt=0.05;//⊿
	x_t[0]=0.5;
	v_t[0]=0.0;
	for(int i=1;i<n;i++){
		v_t[i]=v_t[i-1]-sqrt_omega*x_t[i-1]*dt;
		x_t[i]=x_t[i-1]+dt*v_t[i-1];
		}

	fp1=fopen("euler2_vt.txt","w+");
	fp2=fopen("euler2_xt.txt","w+");

	for(int i=0;i<n;i++)
		fprintf(fp1,"%d %lf\n",i,v_t[i]);

	for(int i=0;i<n;i++)
		  fprintf(fp2,"%d %lf\n",i,x_t[i]);

fclose(fp1);
fclose(fp2);
return;
}
