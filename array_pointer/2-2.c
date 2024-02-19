#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 5
#define face 2
#define row 10
#define col 10


int count = 1;

void mem_alloc_3D_double (double **** A)
{
  srand(time(NULL)+count);
  count++;
  
  (*A) = (double ***) malloc(sizeof(double **) * face);
  for( int i = 0 ; i < face ; i ++)
    {
      (*A)[i] = (double **) malloc(sizeof(double *) * row);
      for( int j = 0 ; j < row ; j ++)
        {
          (*A)[i][j] = (double *)malloc(sizeof(double)*col);
          
          for(int k = 0 ; k < col ; k ++)
            {
              
              (*A)[i][j][k] = (double)(rand()%(100*MAX)) / 100;
            }
            
        }
    }
  
}

void addition_3D(double ****A, double ****B, double ****C)
{
  for(int i = 0 ; i < face ; i ++)
    {
      for (int j = 0 ; j < row ; j ++)
        {
          for (int k = 0 ; k < col ; k ++)
            {
              (*C)[i][j][k] = (*A)[i][j][k] + (*B)[i][j][k];
            }
        }
    } 
}

void print_3D(double ****A)
{
  for(int i = 0 ; i < face ; i ++)
    {
      for (int j = 0 ; j < row ; j ++)
        {
          for (int k = 0 ; k < col ; k ++)
            {
              printf("%4.2f ", (*A)[i][j][k]);
            }
          printf("\n");
        }
      printf("\n\n\n");
    }
  printf("\n\n\n\n\n");
}

void main (void)
{
  //Define two matrices A and B using ‘mem_alloc_3D_double’;
  double ***A;
  mem_alloc_3D_double(&A);
  print_3D(&A);
  
  double ***B;
  mem_alloc_3D_double(&B);
  print_3D(&B);

  double ***C;
  mem_alloc_3D_double(&C);
  
  //Perform addition of two matrices using ‘addition_3D()’
  addition_3D(&A, &B, &C);
  print_3D(&C);
  
  //Deallocate A and B
  if(A != NULL)
  {
    for(int i = 0 ; i < face ; i ++)
      {
        for(int j = 0 ; j < row ; j ++)
          {
            free(A[i][j]);
          }
        free(A[i]);
      }
    free(A);

    A = NULL;
  }

  if(B != NULL)
  {
    for(int i = 0 ; i < face ; i ++)
      {
        for(int j = 0 ; j < row ; j ++)
          {
            free(B[i][j]);
          }
        free(B[i]);
      }
    free(B);

    B = NULL;
  }

  if(C != NULL)
  {
    for(int i = 0 ; i < face ; i ++)
      {
        for(int j = 0 ; j < row ; j ++)
          {
            free(C[i][j]);
          }
        free(C[i]);
      }
    free(C);

    C = NULL;
  }
}