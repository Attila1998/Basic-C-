int *Create1D(int x)//x formalis parameter
{
    int *b=(int*)calloc(x,sizeof(int));
    return b;
}


int *Create1DRand(int x)
{
    for(int i=0; i<x; ++i)
    {
        b[i+1]=b[i]+1+rand();
    }
}

void Print1D(int *b,int x)
{
    for(int i=0; i<x; ++i)
    {
        printf("%i ",b[i]);
    }
}

void osszefesules(int *a,int n, int *b,int m, int*c)

{

    int i, j, k;
    i= j = k = 0;
    while(i< n && j < m )
    {
        if( a[i] < b[j] )
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = b[j++];
        }
    }
    while(j < m )
    {
        c[k++] = b[j++];
    }
    while(i<n)
    {
        c[k++] = a[i++];
    }
}
