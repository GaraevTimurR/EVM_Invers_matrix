#include "Func.h"
void POut(double *Matrix,int l,int n,int m)
{
        int c,d;
        double *f;
        c = l+m-(fabs(l-m)+l+m)/2;
        d = n+m-(fabs(n-m)+n+m)/2;

        for(int i = 0;i<c;i++)
        {
                f = Matrix+i*n;
                for(int j = 0;j<d;j++){
                        printf("%e ",f[j]);
		}
                printf("\n");
   }
}
