//
//  main.c
//  LSAtext
//
//  Created by Swan Garcia on 11/29/18.
//  Copyright © 2018 Swan Garcia. All rights reserved.
//

/*
 * I was having difculty implementing my program in C#, so I decided to use C
 * I have some code bellow from a libary that I am using.
 * I did not use an actual libary, becasue I did not mention a libary for C
 * and I know we could not use what we did not mention in our documentation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ROWS 50
#define COLUMNS 50
#define BUFFER 50

/* Prototypes */
void alphabetDoc( int wordCount );
void removeSW(char *fp2, const char * removeSW);
void createsVector( int wordCount );
void printWordsArray( int wordCount );

static double PYTHAG(double a, double b);
int dsvd(float **a, int m, int n, float *w, float **v);

static char word[ROWS][COLUMNS] = {{'\0','\0'}};
double A[50]; // text document array
double q[50]; // query array


/******************************** Main Function *****************************************/

int main(void)
{
    
    int i = 0;
    char path[50], removeSW[50], buf[50];
    
    FILE *fp1 = NULL;
    // can not open queries document
    if( NULL == (fp1 = fopen("/Users/SkyAllure/Desktop/Prog5-queries.txt", "r") ) )
    {
        printf("Failed to open Prog5-queries.txt");
        exit(EXIT_FAILURE);
    }
    
    // if queries document is open read each line from file into array
    while(fgets(word[i], COLUMNS, fp1 ))
    {
        word[i][strlen(word[i])-1] = '\0';
        i++;
    }

   // open files
    FILE *fp2 =fopen("/Users/SkyAllure/Desktop/A_NOVEL_ALGORITHM_WITH.pdf.txt", "r");
    FILE *fp3 =fopen("/Users/SkyAllure/Desktop/stop.txt", "r");
    FILE *fp4 =fopen("/Users/SkyAllure/Desktop/DocWithoutStopWord.txt", "w");

    // can not open queries document
    if (fp2 == NULL || fp4 == NULL)
    {
        printf( "Failed to open text documents" );
        exit(EXIT_FAILURE);
    }
    
    // reads line from text file after the stop words are removed
    while ((fgets(buf, BUFFER, fp2)) != NULL)
    {
        //removeSW(buf, fp3);
        fputs(buf,fp4);
    }
    
    alphabetDoc(i);
    
    printWordsArray(i);
    
    createsVector(i);
    
    //A = U S VT
    int MatrixU = dsvd;
    int MatrixS = dsvd;
    int MatrixV = dsvd;
    int MatrixVT = dsvd;
    
    long A = MatrixU * MatrixS * MatrixVT;
    printf("A = %i", A);
     //q = qT Uk Sk-1
     //long q = qt * MatrixU * (MatrixS - 1);
    
    return(0);
}

/******************************* Sort Alphabetically *****************************************/

void alphabetDoc( int wordCount )
{
    char swap[COLUMNS] = {'\0'};
    int i, j;
    
    for (i = 0 ; i < ( wordCount - 1 ); i++)
    {
        for (j = 0 ; j <  (wordCount - i - 1); j++)
        {
            if(  0 > strcmp( word[j], word[j+1] ) )
            { // swaps words int alphabetical order
                strcpy( swap, word[j]  );
                strcpy( word[j], word[j+1]);
                strcpy( word[j+1], swap );
            }
        }
    }
}

/********************************* Stop Words Removal ***************************************/

void removeSW(char *fp2, const char *removeSW)
{
    int i, j, length, remove;
    int found;
    
    length   = strlen(fp2);
    remove = strlen(removeSW);
    
    for(i = 0; i <= length - remove; i++)
    {
        // finds stop word in the string
        found = 1;
        for(j = 0; j < remove; j++)
        {
            if(fp2[i + j] != removeSW[j])
            {
                found = 0;
                break;
            }
        }
        
        // ignore punctions and blank spaces
        if(fp2[i + j] != ' ' && fp2[i + j] != '\t' && fp2[i + j] != '\n' && fp2[i + j] != '\0')
        {
            found = 0;
        }
        
       // deletes stop word and shifts the string
        if(found == 1)
        {
            for(j = i; j <= length - remove; j++)
            {
                fp2[j] = fp2[j + remove];
            }
            length = length - remove;
            i--;
        }
    }
}

/***************************** Creates Vector/ Matrix ***************************************/

void createsVector( int wordCount )
{
    int i = 0, j = 0, query = 0;
    char string[100][20], transpose[100][20];
    double qt = transpose[j][i];
    
    // open text file quries and puts string into an array
    FILE *pt1 =fopen("/Users/SkyAllure/Desktop/Prog5-queries.txt", "r");
    
    while(fgets(string[i], BUFFER, pt1))
    {
        string[i][strlen(string[i]) - 1] = '\0';
        i++;
    }
    
    query = i;
    
    for(i = 0; i < query; ++i)
        printf("%s\n", string[i]);

    // creates vector
    for (j = 0; j < wordCount; j++)
    {
        double queryvector [wordCount];
        for (i = 0; i < wordCount; i++)
        {
            double k = string[i][j];
            
            if (j == 0) //query is apart of array
            {
                q[i] = k;
                printf("%i  ", q[i]);
            }
            else
            {
                A[i, j-1] = k;
                printf("%i  ", A[i, j-1]);
            }
        }
    }
    
    // transpose the matrix
    for (int i; i < wordCount; ++i)
    {
        for (int j; j < wordCount; ++i)
        {
            printf(" %i", qt);
        }
        printf("\n");
    }
}

/****************************** Print Function *******************************************/
void printWordsArray( int wordCount )
{
    int i;
    
    printf( "\n" );
    
    for( i=0; i<wordCount; i++ )
    {
        printf( "%s\n", word[i] );
    }
}

/****************************************************************************************/
/*
 * svdcomp - SVD decomposition routine.
 * Takes an mxn matrix a and decomposes it into udv, where u,v are
 * left and right orthogonal transformation matrices, and d is a
 * diagonal matrix of singular values.
 *
 * This routine is adapted from svdecomp.c in XLISP-STAT 2.1 which is
 * code from Numerical Recipes adapted by Luke Tierney and David Betz.
 *
 * Input to dsvd is as follows:
 *   a = mxn matrix to be decomposed, gets overwritten with u
 *   m = row dimension of a
 *   n = column dimension of a
 *   w = returns the vector of singular values of a
 *   v = returns the right orthogonal transformation matrix
 */
static double PYTHAG(double a, double b)
{
    double at = fabs(a), bt = fabs(b), ct, result;
    
    if (at > bt)       { ct = bt / at; result = at * sqrt(1.0 + ct * ct); }
    else if (bt > 0.0) { ct = at / bt; result = bt * sqrt(1.0 + ct * ct); }
    else result = 0.0;
    return(result);
}


int dsvd(float **a, int m, int n, float *w, float **v)
{
    int flag, i, its, j, jj, k, l, nm;
    double c, f, h, s, x, y, z;
    double anorm = 0.0, g = 0.0, scale = 0.0;
    double *rv1;
    
    if (m < n)
    {
        fprintf(stderr, "#rows must be > #cols \n");
        return(0);
    }
    
    rv1 = (double *)malloc((unsigned int) n*sizeof(double));
    
    /* Householder reduction to bidiagonal form */
    for (i = 0; i < n; i++)
    {
        /* left-hand reduction */
        l = i + 1;
        rv1[i] = scale * g;
        g = s = scale = 0.0;
        if (i < m)
        {
            for (k = i; k < m; k++)
                scale += fabs((double)a[k][i]);
            if (scale)
            {
                for (k = i; k < m; k++)
                {
                    a[k][i] = (float)((double)a[k][i]/scale);
                    s += ((double)a[k][i] * (double)a[k][i]);
                }
                f = (double)a[i][i];
                //g = -SIGN(sqrt(s), f);
                h = f * g - s;
                a[i][i] = (float)(f - g);
                if (i != n - 1)
                {
                    for (j = l; j < n; j++)
                    {
                        for (s = 0.0, k = i; k < m; k++)
                            s += ((double)a[k][i] * (double)a[k][j]);
                        f = s / h;
                        for (k = i; k < m; k++)
                            a[k][j] += (float)(f * (double)a[k][i]);
                    }
                }
                for (k = i; k < m; k++)
                    a[k][i] = (float)((double)a[k][i]*scale);
            }
        }
        w[i] = (float)(scale * g);
        
        /* right-hand reduction */
        g = s = scale = 0.0;
        if (i < m && i != n - 1)
        {
            for (k = l; k < n; k++)
                scale += (fabs((double)a[i][k]));
            if (scale)
            {
                for (k = l; k < n; k++)
                {
                    a[i][k] = (float)((double)a[i][k]/scale);
                    s += ((double)a[i][k] * (double)a[i][k]);
                }
                f = (double)a[i][l];
                // g = -SIGN(sqrt(s), f);
                h = f * g - s;
                a[i][l] = (float)(f - g);
                for (k = l; k < n; k++)
                    rv1[k] = (double)a[i][k] / h;
                if (i != m - 1)
                {
                    for (j = l; j < m; j++)
                    {
                        for (s = 0.0, k = l; k < n; k++)
                            s += ((double)a[j][k] * (double)a[i][k]);
                        for (k = l; k < n; k++)
                            a[j][k] += (float)(s * rv1[k]);
                    }
                }
                for (k = l; k < n; k++)
                    a[i][k] = (float)((double)a[i][k]*scale);
            }
        }
        //anorm = MAX(anorm, (fabs((double)w[i]) + fabs(rv1[i])));
    }
    
    /* accumulate the right-hand transformation */
    for (i = n - 1; i >= 0; i--)
    {
        if (i < n - 1)
        {
            if (g)
            {
                for (j = l; j < n; j++)
                    v[j][i] = (float)(((double)a[i][j] / (double)a[i][l]) / g);
                /* double division to avoid underflow */
                for (j = l; j < n; j++)
                {
                    for (s = 0.0, k = l; k < n; k++)
                        s += ((double)a[i][k] * (double)v[k][j]);
                    for (k = l; k < n; k++)
                        v[k][j] += (float)(s * (double)v[k][i]);
                }
            }
            for (j = l; j < n; j++)
                v[i][j] = v[j][i] = 0.0;
        }
        v[i][i] = 1.0;
        g = rv1[i];
        l = i;
    }
    
    /* accumulate the left-hand transformation */
    for (i = n - 1; i >= 0; i--)
    {
        l = i + 1;
        g = (double)w[i];
        if (i < n - 1)
            for (j = l; j < n; j++)
                a[i][j] = 0.0;
        if (g)
        {
            g = 1.0 / g;
            if (i != n - 1)
            {
                for (j = l; j < n; j++)
                {
                    for (s = 0.0, k = l; k < m; k++)
                        s += ((double)a[k][i] * (double)a[k][j]);
                    f = (s / (double)a[i][i]) * g;
                    for (k = i; k < m; k++)
                        a[k][j] += (float)(f * (double)a[k][i]);
                }
            }
            for (j = i; j < m; j++)
                a[j][i] = (float)((double)a[j][i]*g);
        }
        else
        {
            for (j = i; j < m; j++)
                a[j][i] = 0.0;
        }
        ++a[i][i];
    }
    
    /* diagonalize the bidiagonal form */
    for (k = n - 1; k >= 0; k--)
    {                             /* loop over singular values */
        for (its = 0; its < 30; its++)
        {                         /* loop over allowed iterations */
            flag = 1;
            for (l = k; l >= 0; l--)
            {                     /* test for splitting */
                nm = l - 1;
                if (fabs(rv1[l]) + anorm == anorm)
                {
                    flag = 0;
                    break;
                }
                //(fabs((double)w[nm]) + anorm == anorm)
                // break;
                
            }
            if (flag)
            {
                c = 0.0;
                s = 1.0;
                for (i = l; i <= k; i++)
                {
                    f = s * rv1[i];
                    if (anorm != 0) //(fabs(f) + anorm != anorm)
                    {
                        g = (double)w[i];
                        h = PYTHAG(f, g);
                        w[i] = (float)h;
                        h = 1.0 / h;
                        c = g * h;
                        s = (- f * h);
                        for (j = 0; j < m; j++)
                        {
                            y = (double)a[j][nm];
                            z = (double)a[j][i];
                            a[j][nm] = (float)(y * c + z * s);
                            a[j][i] = (float)(z * c - y * s);
                        }
                    }
                }
            }
            z = (double)w[k];
            if (l == k)
            {                  /* convergence */
                if (z < 0.0)
                {              /* make singular value nonnegative */
                    w[k] = (float)(-z);
                    for (j = 0; j < n; j++)
                        v[j][k] = (-v[j][k]);
                }
                break;
            }
            if (its >= 30) {
                free((void*) rv1);
                fprintf(stderr, "No convergence after 30,000! iterations \n");
                return(0);
            }
            
            /* shift from bottom 2 x 2 minor */
            x = (double)w[l];
            nm = k - 1;
            y = (double)w[nm];
            g = rv1[nm];
            h = rv1[k];
            f = ((y - z) * (y + z) + (g - h) * (g + h)) / (2.0 * h * y);
            g = PYTHAG(f, 1.0);
            // f = ((x - z) * (x + z) + h * ((y / (f + SIGN(g, f))) - h)) / x;
            
            /* next QR transformation */
            c = s = 1.0;
            for (j = l; j <= nm; j++)
            {
                i = j + 1;
                g = rv1[i];
                y = (double)w[i];
                h = s * g;
                g = c * g;
                //z = PYTHAG(f, h);
                rv1[j] = z;
                c = f / z;
                s = h / z;
                f = x * c + g * s;
                g = g * c - x * s;
                h = y * s;
                y = y * c;
                for (jj = 0; jj < n; jj++)
                {
                    x = (double)v[jj][j];
                    z = (double)v[jj][i];
                    v[jj][j] = (float)(x * c + z * s);
                    v[jj][i] = (float)(z * c - x * s);
                }
                z = PYTHAG(f, h);
                w[j] = (float)z;
                if (z)
                {
                    z = 1.0 / z;
                    c = f * z;
                    s = h * z;
                }
                f = (c * g) + (s * y);
                x = (c * y) - (s * g);
                for (jj = 0; jj < m; jj++)
                {
                    y = (double)a[jj][j];
                    z = (double)a[jj][i];
                    a[jj][j] = (float)(y * c + z * s);
                    a[jj][i] = (float)(z * c - y * s);
                }
            }
            rv1[l] = 0.0;
            rv1[k] = f;
            w[k] = (float)x;
        }
    }
    free((void*) rv1);
    return 0;
}




