/*
 * Swan Garcia
 * Program 1 Part A
 * 10 September 2018
 * CS
 */

#include <stdio.h>

int main ()
{
    
    /* Print matrices starting at 1 and increasing by 1 */
    printf("Mat1:\n");
    printf("\n");
    
    /* Opens first file and writes to file */
    FILE *mat1File = fopen( "/Users/SkyAllure/Desktop/sgarcia_p1/sgarcia_p1/sgarcia_mat1.txt", "w");
    
    int array1[4][6]; // makes 4 x 6 array
    {
        int f, l = 1;
        int valueOne = 1; // matrix starts at 1
        
        /* Indice first over columns then rows */
        for (f = 0; f < 4; f++){
            for(l = 0; l < 6; l++)
            {
                array1[f][l] = valueOne;
                valueOne += 1; // increase by 1
                printf("%d ", array1[f][l]); // prints to console
                fprintf(mat1File, "%d ", array1[f][l]); // prints to text file
            }
            printf("\n");
            fprintf(mat1File, "\n");
        }
        fclose(mat1File); // closes text file
    }
    
    /* Print matrices starting at 3 and increasing by 3 */
    printf("\n");
    printf("Mat2:\n");
    printf("\n");
    
    /* Opens second file and writes to file */
    FILE *mat2File = fopen( "/Users/SkyAllure/Desktop/sgarcia_p1/sgarcia_p1/sgarcia_mat2.txt", "w");
    
    int array2[6][4]; // makes 6 x 4 array
    {
        int f2, l2 = 1;
        int valueTwo = 3; // matrix starts at 3
        
        /* Indice first over columns then rows */
        for (f2 = 0; f2 < 6; f2++){
            for(l2 = 0; l2 < 4; l2++)
            {
                array2[f2][l2] = valueTwo;
                valueTwo += 3; // increase by 3
                printf("%d ", array2[f2][l2]); // prints to console
                fprintf(mat2File, "%d ", array2[f2][l2]); // prints to text file
            }
            printf("\n");
            fprintf(mat2File, "\n");
        }
        fclose(mat2File); // closes text file
    }
    
    /* Print matrices starting at 3 and increasing by 3 */
    printf("\n");
    printf("Mat3:\n");
    printf("\n");
    
    /* Opens third file and writes to file */
    FILE *mat3File = fopen( "/Users/SkyAllure/Desktop/sgarcia_p1/sgarcia_p1/sgarcia_mat3.txt", "w");
    
    int array3[6][4]; // makes 6 x 4 array
    {
        int f3, l3 = 1;
        int valueThree = 3; // matrix starts at 3
        
        /* Indices rows first then columns */
        for(l3 = 0; l3 < 6; l3++) {
            for (f3 = 0; f3 < 4; f3++)
            {
                array3[l3][f3] = valueThree;
                valueThree += 3; // increase by 3
                printf("%d ", array3[f3][l3]); // prints to console
                fprintf(mat3File, "%d ", array2[f3][l3]); // prints to text file
            }
            printf("\n");
            fprintf(mat3File, "\n");
        }
        fclose(mat3File); // closes text file
    }
    
    /* Print matrices starting at 0.2 and increasing by 0.3 */
    printf("\n");
    printf("Mat4:\n");
    printf("\n");
    
    /* Opens fourth file and writes to file */
    FILE *mat4File = fopen( "/Users/SkyAllure/Desktop/sgarcia_p1/sgarcia_p1/sgarcia_mat4.txt", "w");
    
    double array4[6][4]; // makes 6 x 4 array
    {
        int f4, l4 = 1;
        double valueFour = 0.2; // matrix starts at 0.2
        
        /* Indice first over columns then rows */
        for (f4 = 0; f4 < 6; f4++){
            for(l4 = 0; l4 < 4; l4++)
            {
                array4[l4][f4] = valueFour;
                valueFour += 0.3; // increase by 0.3
                printf("%f ", array4[l4][f4]); // prints to console
                fprintf(mat4File, "%f ", array4[f4][l4]); // prints to text file
            }
            printf("\n");
            fprintf(mat4File, "\n");
        }
        fclose(mat4File); // closes text file
    }
    
    /* Print matrices starting at 2 and increasing by 2 */
    printf("\n");
    printf("Mat5:\n");
    printf("\n");
    
    /* Opens fifth file and writes to file */
    FILE *mat5File = fopen( "/Users/SkyAllure/Desktop/sgarcia_p1/sgarcia_p1/sgarcia_mat5.txt", "w");
    
    int array5[11][14]; // makes 11 x 14 array
    {
        int f5, l5 = 1;
        int valueFive = 2; // matrix starts at 2
        
        /* Indices rows first then columns */
        for(l5 = 0; l5 < 11; l5++) {
            for (f5 = 0; f5 < 14; f5++)
            {
                array5[f5][l5] = valueFive;
                valueFive += 2; // increase by 2
                printf("%d ", array5[l5][f5]); // prints to console
                fprintf(mat5File, "%d ", array5[f5][l5]); // prints to text file
            }
            printf("\n");
            fprintf(mat5File, "\n");
        }
        fclose(mat5File); // closes text file
    }
    
    /* Print matrices starting at 2 and increasing by 2 */
    printf("\n");
    printf("Mat6:\n");
    printf("\n");
    
    /* Opens sixth file and writes to file */
    FILE *mat6File = fopen( "/Users/SkyAllure/Desktop/sgarcia_p1/sgarcia_p1/sgarcia_mat6.txt", "w");
    
    int array6[11][14]; // makes 11 x 14 array
    {
        int f6, l6 = 1;
        int valueSix = -7; // matrix starts at -7
        
        /* Indice first over columns then rows */
        for(l6 = 0; l6 < 11; l6++)
        {
            for (f6 = 0; f6 < 14; f6++)
            {
                array6[l6][f6] = valueSix;
                valueSix += 1; // increase by 1
                printf("%d ", array6[l6][f6]); // prints to console
                fprintf(mat6File, "%d ", array6[f6][l6]); // prints to text file // switch l f
            }
            printf("\n");
            fprintf(mat6File, "\n");
        }
        fclose(mat6File); // closes text file
    }
    
    return 0;
}


