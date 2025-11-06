#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(void){
	int row=15;
	int col=20;
	int *mi=malloc(row*col*sizeof(int));
	int *mf=malloc(row*col*sizeof(int));
	if (mi==NULL || mf ==NULL ){
		perror("malloc failure");
		return 1;	
	}
	for(int i=0;i<45;i++) mf[i]=1;
	int *temp;
	int di[8]={1,1,1,0,0,row-1,row-1,row-1};
	int dj[8]={1,0,col-1,1,col-1,1,0,col-1};
	for (int n=0; n<10; n++){
		temp=mi;
		mi=mf;
		mf=temp;
		printf("\033[2J\033[H");
		for (int i =0 ; i<row; i++){
			for(int j=0;j<col; j++){
				mf[i*col+j]=0;
				for(int k=0; k<8;k++){ 
					mf[i*col+j]+=mi[(i+di[k])%row*col+(j+dj[k])%col];
				}
				if (mi[i*col+j]==1){
					mf[i*col+j]=(mf[i*col+j]==2 || mf[i*col+j]==3);
					printf("##");
				}
				else{
					mf[i*col+j]=(mf[i*col+j]==3);
					printf("..");
				}
			
			}
			printf("\n");
		}
		usleep(500000);
	}
	return 0;
}
	
