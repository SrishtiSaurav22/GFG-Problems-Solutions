int searchKey(int arr[], int arrSize, int key)
{
    int i;
    
    for(i=0;i<arrSize;i++)
    {
        if(arr[i]==key)
            return 1;
    }
    
    return 0;
}

//Function to modify the matrix such that if a matrix cell matrix[i][j]
//is 1 then all the cells in its ith row and jth column will become 1.
void booleanMatrix(int R, int C, int matrix[][C])
{
    if(R==C && R==1)
        return;
    
    int i, j;
    int rowWithOne[R], colWithOne[C];
    int rowWithOneSize=0, colWithOneSize=0;
    
    for(i=0;i<R;i++)
    {
        rowWithOne[i]=-1;
    }
        
    for(j=0;j<C;j++)
    {
        colWithOne[j]=-1;
    }
    
    for(i=0;i<R;i++)
    {
        for(j=0;j<C;j++)
        {
            if(matrix[i][j]==1)
            {
                if( searchKey ( rowWithOne, rowWithOneSize, i ) == 0 )
                {
                    rowWithOne[rowWithOneSize]=i;
                    ++rowWithOneSize;
                }
                
                if( searchKey ( colWithOne, colWithOneSize, j ) == 0 )
                {
                    colWithOne[colWithOneSize]=j;
                    ++colWithOneSize;
                }
            }
        }
    }
    
    for(i=0;i<rowWithOneSize;i++)
    {
        for(j=0;j<C;j++)
        {
            matrix [ rowWithOne[i] ] [j]=1;
        }
    }
    
    for(i=0;i<R;i++)
    {
        for(j=0;j<colWithOneSize;j++)
        {
            matrix[i] [ colWithOne[j] ]=1;
        }
    }
}
