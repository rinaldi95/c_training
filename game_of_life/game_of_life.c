#include<stdio.h>
#include<unistd.h>

int main(void){
    int rows = 15;
    int cols = 21;
    int zi[rows*cols];
    int zf[rows*cols];
    int n_max=1000;
    for (int i = 0; i<rows; i++){
        for (int j = 0; j<cols; j++){
            zf[i*cols+j]=0;
        }
    }

        
    for (int i =5 ; i<rows-5; i++){
        for (int j = 8; j<cols-3; j++){
            zf[i*cols+j]=1;
        }
    }
    
  
    for (int n=0; n<n_max; n++){
        
        printf("\033[2J\033[H");
        fflush(stdout);  // assicura che la sequenza parta subito
        
        for (int i = 0; i<rows; i++){
            for (int j = 0; j<cols; j++){
                if (zf[i*cols+j]==1) printf("##");
                else printf("..");
            }
            printf("\n");
        }
        for (int i = 0; i<rows; i++){
            for (int j = 0; j<cols; j++){
                zi[i*cols+j]=zf[i*cols+j];
            }
        }
        for (int i = 0; i<rows; i++){
            for (int j = 0; j<cols; j++){
                zf[i*cols+j]=zi[((i-1+rows)%rows*cols)+(j-1+cols)%cols]+zi[((i+rows)%rows*cols)+(j-1+cols)%cols]+zi[((i+1+rows)%rows*cols)+(j-1+cols)%cols]+zi[((i-1+rows)%rows*cols)+(j+cols)%cols]+zi[((i+1+rows)%rows*cols)+(j+cols)%cols]+zi[((i-1+rows)%rows*cols)+(j+1+cols)%cols]+zi[((i+rows)%rows*cols)+(j+1+cols)%cols]+zi[((i+1+rows)%rows*cols)+(j+cols+1)%cols];
                if (zi[i*cols+j]==1) zf[i*cols+j]= (zf[i*cols+j]==2 || zf[i*cols+j]==3);
                else zf[i*cols+j]= (zf[i*cols+j]==3);
                }
            }
        usleep(1000000);
        }
        
    return(0);
}
