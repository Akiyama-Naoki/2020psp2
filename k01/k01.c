#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave)
extern double var_online(double val,double ave)

int main(void)
{
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
    
    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        ave_online(val,ave);
        var_online(val,ave);
    



    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    return 0;


}

double ave_online(double val,double ave);
{
    int N;
    double f;
    for(N = 1,N <= 14,N++)
    {
        f = (N - 1) / N * ave + 1 / N * val;
    }
    return f;
}

double var_online(double val,double ave);
{
     int N;
     double ave2, g;
     for(N = 1,N <= 14,N++)
     {
         ave2 = (N - 2) / (N - 1) * ave * ave + 1 / (N - 1) * val * val; 
        g = (N - 1) / N *  1 / N * val * val - ave_online(val,ave) * ave_online(val,ave);
     } 
     return g;
}