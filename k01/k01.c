#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave,double n);
extern double var_online(double val,double ave,double ave_square,double n);

int main(void)
{
    double val,ave,ave_square,n,var,u;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    n = 1;
    ave = 0;
    ave_square = 0;

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
        var = var_online(val,ave,ave_square,n);
        ave = ave_online(val,ave,n);
        u = n / (n - 1) * var;
        ave_square = ave_online(val*val,ave_square,n);
        n++;


    }

    printf("sample mean:%.2lf\n",ave);
    printf("sample variance:%.2lf\n",var);
    printf("population mean (estimated):%.2lf\n",ave);
    printf("population variance (estimated):%.2lf\n",u);

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    return 0;


}

double ave_online(double val,double ave,double n)
{
    double f;
   f = (n - 1) / n * ave + 1 / n * val;
   return f;
}

double var_online(double val,double ave,double ave_square,double n)
{ 
    double g;
    g = (n - 1) / n * ave_square + 1 / n * val * val - ave_online(val,ave,n) * ave_online(val,ave,n);
    return g;
}