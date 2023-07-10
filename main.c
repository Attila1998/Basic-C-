#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
/*ki iratja a matrix fo illetve mellek atlojat
*/
int main()
{

    int **a,n,i,j;
    scanf("%d %d",n);
    printf("A nxn matrixnagysaga:",n);
    a=(int**)malloc(n*sizeof(int*));
    for(i=0; i<n,++i)
    {
        a[i]=(int*)malloc(n*sizeof(int));
        for(j=0; j<n; ++j)
        {
            a[i][j]=rand(h)
        }
    }

    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            printf("%i",a[i][j]);
        }
        printf("/n");
    }


    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            if(i==j)
            {
                printf("%d ",a[i][j]);
            }
            if(i+j==n-1)
            {
                printf("%i ",a[i][j]);
            }
        }
    }
    printf("Hello world!\n");
    return 0;
}
