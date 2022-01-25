#include <stdio.h>
#define MAX 20

void acc(int a[10][10], int row, int column);
void disp(int a[10][10], int row, int column);
void print_sparse(int b[MAX][3]);
void create_sparse(int a[10][10], int row, int column, int b[MAX][3]);
void transpose(int b[MAX][3] , int c[MAX][3]);

int main()
{
    int a[10][10], b[MAX][3], c[MAX][3], row, column,d[MAX][3];
    int choice;
    while(choice != 6){
        printf("\n---Menu---");
        printf("\n1: Accept the sparse matrix");
        printf("\n2: Display the sparse matrix");
        printf("\n3: Convert Matrix into Compact form");
        printf("\n4: simple transpose of matrix");
        printf("\n5: fast transpose");
        printf("\n6: Exit the program");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            printf("Enter the number of rows: ");
            scanf("%d", &row);
            printf("Enter the number of columns: ");
            scanf("%d", &column);
            acc(a,row,column);
            break;
        case 2:
            printf("Sparse matrix\n");
            disp(a,row,column);
            break;
        case 3:
            create_sparse(a, row, column, b);
            printf("\nSparse form - list of 3 triples\n\n");
             print_sparse(b);
            break;
        case 4:
            transpose(b,c);
           printf("\nSimple transpose is:\n");
           print_sparse(c);
            break;
        case 5:
                FastTranspose(b,d);
                break;
        case 6:
            printf("\nProgram exited\n");
            exit(0);
        default:
            printf("\nInvalid Command\n");
            break;

}
    }}
void acc(int a[10][10], int row, int column)
{
    int i, j;
    printf("\nEnter elements of matrix:\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void disp(int a[10][10], int row, int column)
{
    printf("\n\nDisplaying the given matrix:\n");
    int i,j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

}

void create_sparse(int a[10][10], int row, int column, int b[MAX][3])
{
    int i, j, k;
    k = 1;
    b[0][0] = row;
    b[0][1] = column;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            if (a[i][j] != 0)
            {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }
        b[0][2] = k - 1;
    }
}

void print_sparse(int b[MAX][3])
{
    int i, column;
    column = b[0][2];
    for (i = 0; i <= column; i++)
    {
        printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);
    }
}

void transpose(int b[MAX][3],int c[MAX][3])
{
	int i,j,k,n;
	c[0][0]=b[0][1];//no of column
	c[0][1]=b[0][0];
	c[0][2]=b[0][2];

	k=1;
	n=b[0][2];

	for(i=0;i<b[0][1];i++)//travel through second column
		for(j=1;j<=n;j++)//travel through no of elements
			if(i==b[j][1])//search for column index in sequence from 0 to col-1
			{
				c[k][0]=b[j][1];
				c[k][1]=b[j][0];
				c[k][2]=b[j][2];
				k++;
			}
}
void FastTranspose(int b[50][3],int d[50][3])
{
		int m=b[0][0];
		int n=b[0][1];
		int t=b[0][2];

		int s[n],t1[n];

	    d[0][0]=n;
        d[0][1]=m;
	    d[0][2]=t;
	    int i;
	    for(i=0;i<n;i++)
	    {
	    	s[i]=0;//making all elements in array zero
		}
		for(i=1;i<=t;i++)
		{
			s[b[i][1]] = s[b[i][1]]+1;//calculate frequency of each column value
		}

		t1[0]=1;
		for(i=1;i<=n;i++)
	    {
	    	t1[i]=t1[i-1]+s[i-1];//find stating location of each column value
		}                        //addition of frequency of each column value + prev allocated rows
		int j;
		for(i=1;i<=t;i++)
		{
			j=b[i][1];
			d[t1[j]][0]=b[i][1];//according to starting pos ele are stored
			d[t1[j]][1]=b[i][0];
			d[t1[j]][2]=b[i][2];
			t1[j]=t1[j]+1;//inc position after storing for same column
		}
	int column=d[0][2];
   printf("Fast Transpose of Sparse Matrix Formed:\n");
   for(i=0;i<=column;i++)
   {
   	printf("%d\t%d\t%d\n",d[i][0],d[i][1],d[i][2]);
   }

}
