#include "Func.h"


int Gauss(double* Matrix, double* InvMatrix, int n){


        double eps = 1.0;
        while (1.0 + eps/ 2.0 > 1.0)
        {
                eps /= 2.0;
        }
        //int IntSwap;
        eps=eps*100;

        double max;
        int maxJ;
        double prob;
        double Del;
        int k;
        double* MultInd;
        //double* MultInd1;
        //int* swap= (int *)malloc(n*(sizeof(int)));
        // определение переменных

        for(int i=0; i<n; i++){
                max=0;
                // поиск максимального по строчке
                MultInd= Matrix+i*n;
                maxJ=i;
                for(int j=i; j<n; j++){
                        if(fabs(max)<fabs(MultInd[j])){
                                max=MultInd[j];
                                maxJ=j;
                        }
                }
                if(fabs(MultInd[maxJ])<eps){
                        return -2;
                }
                // поиск максимального по строчке
                //меняем столбцы
                for(k=0; k<n; k++){
                        prob=Matrix[k*n+i];
                        Matrix[k*n+i]=Matrix[k*n+maxJ];
                        Matrix[k*n+maxJ]=prob;

                        prob=InvMatrix[k*n+i];
                        InvMatrix[k*n+i]=InvMatrix[k*n+maxJ];
                        InvMatrix[k*n+maxJ]=prob;

                }
                //меняем столбцы
                // диагонализируем
		Del=(double)(Matrix[i*n+i]);
                Del=1/Matrix[i*n+i];
                for(int t=0; t<n; t++){
                        Matrix[t*n+i]=Del*Matrix[t*n+i];
                        InvMatrix[t*n+i]=Del*InvMatrix[t*n+i];
                }
                for(k=0; (k<n); k++){
                        if(k!=i){
                                Del = Matrix[i*n+k];
                                if(eps<fabs(Del)){
                                        for(int t=0; t<n; t++){
                                                Matrix[t*n+k]=Matrix[t*n+k]-Del*Matrix[t*n+i];
                                                InvMatrix[t*n+k]=InvMatrix[t*n+k]-Del*InvMatrix[t*n+i];
                                        }
                                }
                        }
                }
                // диагонализируем	
        }
        return 0;
}


