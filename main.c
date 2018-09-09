/*
 * Swan Garcia
 * Program 1 Part B
 * 10 September 2018
 * CS
 */

#include <stdio.h>

int main()
{
    
    /* Reads files */
    FILE *mat1File = fopen("/Users/SkyAllure/Desktop/sgarcia_p1/sgarcia_p1/sgarcia_mat1.txt", "r");
    FILE *mat2File = fopen("/Users/SkyAllure/Desktop/sgarcia_p1/sgarcia_p1/sgarcia_mat2.txt", "r");
    FILE *mat3File = fopen("/Users/SkyAllure/Desktop/sgarcia_p1/sgarcia_p1/sgarcia_mat3.txt", "r");
    FILE *mat4File = fopen("/Users/SkyAllure/Desktop/sgarcia_p1/sgarcia_p1/sgarcia_mat4.txt", "r");
    FILE *mat5File = fopen("/Users/SkyAllure/Desktop/sgarcia_p1/sgarcia_p1/sgarcia_mat5.txt", "r");
    FILE *mat6File = fopen("/Users/SkyAllure/Desktop/sgarcia_p1/sgarcia_p1/sgarcia_mat6.txt", "r");
    
    /* Writes to files */
    FILE *mat12File = fopen("/Users/SkyAllure/Desktop/sgarcia_p2/sgarcia_p2/sgarcia_mat12.txt", "w");
    FILE *mat13File = fopen("/Users/SkyAllure/Desktop/sgarcia_p2/sgarcia_p2/sgarcia_mat13.txt", "w");
    FILE *mat14File = fopen("/Users/SkyAllure/Desktop/sgarcia_p2/sgarcia_p2/sgarcia_mat14.txt", "w");
    FILE *mat15File = fopen("/Users/SkyAllure/Desktop/sgarcia_p2/sgarcia_p2/sgarcia_mat15.txt", "w");
    FILE *mat16File = fopen("/Users/SkyAllure/Desktop/sgarcia_p2/sgarcia_p2/sgarcia_mat16.txt", "w");
    FILE *mat23File = fopen("/Users/SkyAllure/Desktop/sgarcia_p2/sgarcia_p2/sgarcia_mat23.txt", "w");
    FILE *mat24File = fopen("/Users/SkyAllure/Desktop/sgarcia_p2/sgarcia_p2/sgarcia_mat24.txt", "w");
    FILE *mat25File = fopen("/Users/SkyAllure/Desktop/sgarcia_p2/sgarcia_p2/sgarcia_mat25.txt", "w");
    FILE *mat26File = fopen("/Users/SkyAllure/Desktop/sgarcia_p2/sgarcia_p2/sgarcia_mat26.txt", "w");
    FILE *mat34File = fopen("/Users/SkyAllure/Desktop/sgarcia_p2/sgarcia_p2/sgarcia_mat34.txt", "w");
    FILE *mat35File = fopen("/Users/SkyAllure/Desktop/sgarcia_p2/sgarcia_p2/sgarcia_mat35.txt", "w");
    FILE *mat36File = fopen("/Users/SkyAllure/Desktop/sgarcia_p2/sgarcia_p2/sgarcia_mat36.txt", "w");
    FILE *mat45File = fopen("/Users/SkyAllure/Desktop/sgarcia_p2/sgarcia_p2/sgarcia_mat45.txt", "w");
    FILE *mat46File = fopen("/Users/SkyAllure/Desktop/sgarcia_p2/sgarcia_p2/sgarcia_mat46.txt", "w");
    FILE *mat56File = fopen("/Users/SkyAllure/Desktop/sgarcia_p2/sgarcia_p2/sgarcia_mat56.txt", "w");
    
    
    
    //int numberArray[100][100];
    int array2[100][100];
    int array3[100][100];
    float array4[100][100];
    int array5[100][100];
    int array6[100][100];
    int f, l;
    int sum23, sum56;
    float sum24, sum34;
    
    printf("Sum of sgarcia_mat1.txt + sgarcia_mat2.txt IS NOT POSSIBLE!\n ");
    fprintf(mat12File, "Sum of sgarcia_mat1.txt + sgarcia_mat2.txt IS NOT POSSIBLE!\n");
    
    printf("Sum of sgarcia_mat1.txt + sgarcia_mat3.txt IS NOT POSSIBLE!\n ");
    fprintf(mat13File, "Sum of sgarcia_mat1.txt + sgarcia_mat3.txt IS NOT POSSIBLE!\n");
    
    printf("Sum of sgarcia_mat1.txt + sgarcia_mat3.txt IS NOT POSSIBLE!\n ");
    fprintf(mat14File, "Sum of sgarcia_mat1.txt + sgarcia_mat3.txt IS NOT POSSIBLE!\n");
    
    printf("Sum of sgarcia_mat1.txt + sgarcia_mat3.txt IS NOT POSSIBLE!\n ");
    fprintf(mat15File, "Sum of sgarcia_mat1.txt + sgarcia_mat3.txt IS NOT POSSIBLE!\n");
    
    printf("Sum of sgarcia_mat1.txt + sgarcia_mat3.txt IS NOT POSSIBLE!\n ");
    fprintf(mat16File, "Sum of sgarcia_mat1.txt + sgarcia_mat3.txt IS NOT POSSIBLE!\n");
    
    /* Finds matrix 2 and 3 */
    for (f = 0; f < 6; f++)
    {
        for (l = 0; l < 4; l++)
        {
            //fscanf(mat1File, "%d", &numberArray[i][j]);
            fscanf(mat2File, "%d", &array2[f][l]); // pulls matrix 2 from file
            fscanf(mat3File, "%d", &array3[f][l]); // pulls matrix 3 from file
        }
    }
    
    /* Writes the sum of matrix 2 and matrix 3 */
    printf("Sum of sgarcia_mat2.txt + sgarcia_mat3.txt\n ");
    fprintf(mat23File,"Sum of sgarcia_mat2.txt + sgarcia_mat3.txt\n");
    {
        
        for (f = 0; f < 6; f++)
        {
            for (l = 0; l < 4; l++)
            {
                sum23 = array2[f][l] + array3[f][l]; // adds matrix 2 and 3
                printf("%d ", sum23); // prints sum to console
                fprintf(mat23File, "%d ", sum23); // prints sum of matrix to text file
            }
            
            printf("\n");
            fprintf(mat23File, "\n");
        }
        
        fclose(mat23File); // close file
    }
    
    /* Finds matrix 2 and 4 */
    for (f = 0; f < 6; f++)
    {
        for (l = 0; l < 4; l++)
        {
            fscanf(mat2File, "%d", &array2[f][l]); // pulls matrix 2 from file
            fscanf(mat4File, "%f", &array4[f][l]); // pulls matrix 4 from file
        }
    }
    
    /* Writes the sum of matrix 2 and matrix 4 */
    printf("Sum of sgarcia_mat2.txt + sgarcia_mat4.txt:\n ");
    fprintf(mat24File,"Sum of sgarcia_mat2.txt + sgarcia_mat4.txt:\n");
    {
        
        for (f = 0; f < 6; f++)
        {
            for (l = 0; l < 4; l++)
            {
                sum24 = array2[f][l] + array4[f][l]; // adds matrix 2 and 4
                printf("%f ", sum24); // prints sum to console
                fprintf(mat24File, "%f ", sum24); // prints sum of matrix to text file
            }
            
            printf("\n");
            fprintf(mat24File, "\n");
        }
        
        fclose(mat24File); // close file
    }
    
    printf("Sum of sgarcia_mat1.txt + sgarcia_mat3.txt IS NOT POSSIBLE!\n ");
    fprintf(mat25File, "Sum of sgarcia_mat1.txt + sgarcia_mat3.txt IS NOT POSSIBLE!\n");
    
    printf("Sum of sgarcia_mat1.txt + sgarcia_mat3.txt IS NOT POSSIBLE!\n ");
    fprintf(mat26File, "Sum of sgarcia_mat1.txt + sgarcia_mat3.txt IS NOT POSSIBLE!\n");
    
    /* Finds matrix 3 and 4 */
    for (f = 0; f < 6; f++)
    {
        for (l = 0; l < 4; l++)
        {
            fscanf(mat3File, "%d", &array3[f][l]); // pulls matrix 3 from file
            fscanf(mat4File, "%f", &array4[f][l]); // pulls matrix 4 from file
        }
    }
    
    /* Writes the sum of matrix 3 and matrix 4 */
    printf("Sum of sgarcia_mat3.txt + sgarcia_mat4.txt:\n ");
    fprintf(mat34File,"Sum of sgarcia_mat3.txt + sgarcia_mat4.txt:\n");
    {
        
        for (f = 0; f < 6; f++)
        {
            for (l = 0; l < 4; l++)
            {
                sum34 = array3[f][l] + array4[f][l]; // adds matrix 2 and 4
                printf("%f ", sum34); // prints sum to console
                fprintf(mat34File, "%f ", sum34); // prints sum of matrix to text file
            }
            
            printf("\n");
            fprintf(mat34File, "\n");
        }
        
        fclose(mat34File); // close file
    }
    
    printf("Sum of sgarcia_mat1.txt + sgarcia_mat3.txt IS NOT POSSIBLE!\n ");
    fprintf(mat35File, "Sum of sgarcia_mat1.txt + sgarcia_mat3.txt IS NOT POSSIBLE!\n");
    
    printf("Sum of sgarcia_mat1.txt + sgarcia_mat3.txt IS NOT POSSIBLE!\n ");
    fprintf(mat36File, "Sum of sgarcia_mat1.txt + sgarcia_mat3.txt IS NOT POSSIBLE!\n");
    
    printf("Sum of sgarcia_mat1.txt + sgarcia_mat3.txt IS NOT POSSIBLE!\n ");
    fprintf(mat45File, "Sum of sgarcia_mat1.txt + sgarcia_mat3.txt IS NOT POSSIBLE!\n");
    
    printf("Sum of sgarcia_mat1.txt + sgarcia_mat3.txt IS NOT POSSIBLE!\n ");
    fprintf(mat46File, "Sum of sgarcia_mat1.txt + sgarcia_mat3.txt IS NOT POSSIBLE!\n");
    
    /* Finds matrix 5 and 6 */
    for (f = 0; f < 6; f++)
    {
        for (l = 0; l < 4; l++)
        {
            fscanf(mat5File, "%d", &array5[f][l]); // pulls matrix 5 from file
            fscanf(mat6File, "%d", &array6[f][l]); // pulls matrix 6 from file
        }
    }
    
    /* Writes the sum of matrix 5 and matrix 6 */
    printf("Sum of sgarcia_mat5.txt + sgarcia_mat6.txt:\n ");
    fprintf(mat56File,"Sum of sgarcia_mat5.txt + sgarcia_mat6.txt:\n");
    {
        
        for (f = 0; f < 14; f++)
        {
            for (l = 0; l < 11; l++)
            {
                sum56 = array5[f][l] + array6[f][l]; // adds matrix 2 and 4
                printf("%d ", sum56); // prints sum to console
                fprintf(mat56File, "%d ", sum56); // prints sum of matrix to text file
            }
            
            printf("\n");
            fprintf(mat56File, "\n");
        }
        
        fclose(mat56File); // close file
    }
    
    return 0;
}
