#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave,int n);
extern double var_online(double val,double ave,double ave_square,int n);

int main(void)
{
    double val,ave,ave_square;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    int n;
    n = 1;
    ave = 0;

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
        ave_square = ave_online(val*val,ave,n);
        ave = ave_online(val,ave,n);
        var_online(val,ave,ave_square,n);
        n++;


    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    return 0;


}

double ave_online(double val,double ave,int n)
{
    double f;
   f = (n - 1) / n * ave + 1 / n * val;
   return f;
}

double var_online(double val,double ave,double ave_square,int n)
{ 
    double g;
    g = (n - 1) / n * ave_square + 1 / n * val * val - ave_online(val,ave,n) * ave_online(val,ave,n);
    return g;
}