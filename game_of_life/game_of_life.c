#include<stdio.h>
#include<unistd.h>
int main(void){
	int col=35;
	int row=30;
	int nmax=1000;
	int mi[col*row];
	int mf[col*row];
	int *tp;
	int *pmi=mi;
	int *pmf=mf;
	int di[8]={row-1,row-1,row-1,0,0,1,1,1};
	int dj[8]={col-1,0,1,col-1,1,col-1,0,1};
	for (int i=0;i<row*col;i++) mf[i]=0;
	for (int i=0;i<row*col-566;i++) mf[i]=1;
	for (int n=0;n<nmax;n++){
		tp=pmi;
		pmi=pmf;
		pmf=tp;
		printf("\033[2J\033[H");
		for (int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				pmf[i*col+j]=0;
				for (int k=0;k<8;k++){
					pmf[i*col+j]+=pmi[(i+di[k])%row*col+(j+dj[k])%col];
					}
				printf("%s",(pmi[i*col+j]==0)? ".." : "##");
				if (pmi[i*col+j]==0) pmf[i*col+j]=(pmf[i*col+j]==3);
				else pmf[i*col+j]=(pmf[i*col+j]==2 || pmf[i*col+j]==3);
			}
			printf("\n");
		}
	usleep(200000);
	}
	return 0;
}
