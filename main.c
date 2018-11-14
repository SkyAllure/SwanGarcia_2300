//
//  main.c
//  MachineLearning
//
//  Created by Swan Garcia on 11/5/18.
//  Copyright © 2018 Swan Garcia. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Random() ((double)rand() / ((double)RAND_MAX + 1))

int main(void){
    
    
    FILE *fp1 = fopen("/Users/SkyAllure/Desktop/Output.txt", "w");
    FILE *fp2 = fopen("/Users/SkyAllure/Desktop/TestFile.txt", "r");
    FILE *fp3 = fopen("/Users/SkyAllure/Desktop/TestFile2.txt", "r");
    FILE *fp4 = fopen("/Users/SkyAllure/Desktop/Output2.txt", "w");
    
    double Input[50][30],
           Target[50][20],
           WeightInput1[30][30],
           WeightInput2[30][30],
           Hid[30],
           Hidden[50][30],
           HiddenWeight1[30][20],
           HiddenWeight2[30][20],
           Out[20],
           Output[50][20],
           HiddenSum[50][30],
           OutputSum[50][20],
           Sum[50];
    
    /* Generates a weight */
    for( int i = 0 ; i <= 20 ; i++ ) {
        for( int j = 1 ; j <= 20 ; j++ ) {
            WeightInput1[i][j] = 0.0;
            WeightInput2[i][j] = 2.0 * (Random() - 0.5) / 2 ;
            fscanf(fp2, "%lf", &Input[i][j]);
            float Sum = (Input[i][j] + (Input[i][j] * WeightInput2[i][j])); // Dot product
            fprintf(fp4, " %f\n", Sum); // output file
            
            /* creates prediction */
            // if the weight is greater than 0 it
            // predicts a 1 otherwise predicts a 0
            if (Sum > 0){
                fprintf(fp4, "1 "); // output file
            }
            if (Sum <= 0){
                fprintf(fp4, "0 ");
            }
        }
    }
    
    /* The functions from above and bellow will generate the weights */
    for( int j = 0 ; j <= 20 ; j++ ) {
        for( int k = 1 ; k <= 50 ; k ++ ) {
            HiddenWeight1[j][k] = 0.0 ;
            HiddenWeight2[j][k] = 2.0 * (Random() - 0.5) / 2 ;
            fscanf(fp2, "%lf", &Input[j][k]);
            float Sum = (Input[j][k] + (Input[j][k] * WeightInput2[j][k])); // Dot product
            /* itereates through all training files */
            for( int r = 1 ; r <= 4 ; r++ ) {
                //  r = weightRandom[r];
                /* finds hidden numbers */
                for( int j = 1 ; j <= 2 ; j++ ) {
                    HiddenSum[r][j] = WeightInput2[0][j] ;
                    for( int i = 1 ; i <= 20 ; i++ ) {
                        fscanf(fp2, "%lf", &Input[r][i]);
                        HiddenSum[r][j] += Input[r][i] * WeightInput2[i][j] ;
                    }
                    Hidden[r][j] = 1.0/(1.0 + (HiddenSum[r][j])) ;
                }
                /* finds output */
                for( int k = 1 ; k <= 5 ; k++ ) {
                    OutputSum[r][k] = HiddenWeight2[0][k] ;
                    for( int j = 1 ; j <= 2 ; j++ ) {
                        OutputSum[r][k] += Hidden[r][j] * HiddenWeight2[j][k] ;
                    }
                    Output[r][k] = 1.0/(1.0 + (OutputSum[r][k])) ;
                    fscanf(fp3, "%lf", &Target[r][k]);
                    Out[k] = (Target[r][k] - Output[r][k]) * Output[r][k] * (1.0 - Output[r][k]) ;
                }
                
                /* back propgation */
                for( int j = 1; j <= 2; j ++){
                    Sum = 0.0;
                    for (int k = 1; k <= 5; k++){
                        Sum +=  WeightInput2[j][k] * Out[k];
                    }
                    Hid[j] = Sum * Hidden[r][j] * (1.0 - Hidden[r][j]);
                }
             
                fprintf(fp1, " %f  %f\n", Output[r][k], Hid[r]); // output file
            }
        }
    }
    
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
  
    return 0 ;

}


