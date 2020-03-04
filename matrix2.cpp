/* Assignment -2 Write a program to accept two NXM matrix input from the user and add them and print the result matrix. Implement three functions for the above operations . (Use a 2D array of max size 100X100) 

Extend the above program to work with X number of NXM matrices. Use a 3D array with max 50 matrices.

*/

#include<iostream>
using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;
const int MAX_MATRIX = 50;

class Matrix
{
	int row;
	int col;
	int a[100][100];
	public:
		Matrix():row(0),col(0)
		{
			cout<<"default cstructor \n";
			for(int i=0;i<row;i++)
			{
				for(int j= 0;j<col;j++)
				{
					a[i][j]=0;
				}
			}
			
		}
		void Read()
		{
			while(1)
			{
			cout<<"Print number of rows \n";
			cin>>row;
			if(row<1 || row>MAX_ROWS)
			{
				cout<<"Enter valid number of rows (1-100)\n";
			}
			else
				break;
			}
			while(1)
			{
			cout<<"Print number of columns \n";
			cin>>col;
			if(col<1 || col>MAX_COLS)
			{
				cout<<"Enter valid number of columns (1-100)\n";
			}
			else
				break;
			}
			for(int i=0;i<row;i++)
			{
				for(int j=0;j<col;j++)
				{
				cout<<"Enter"<<i+1<<"row"<<j+1<<"column element:\n";
				cin>>a[i][j];
				}
			}
		}
		void Print()
		{
			cout<<"The matrix is :\n";
			for(int i=0;i<row;i++)
			{
				for(int j= 0;j<col;j++)
				{
					cout<<a[i][j]<<" ";
				}
				cout<<"\n";
			}
		}
		Matrix Add(const Matrix &b)
		{
			Matrix x;
			// check for same size
			if(row == b.row && col == b.col)
			{
				cout<<"Same size adding \n";
				for(int i=0;i<row;i++)
				{
					for(int j= 0;j<col;j++)
					{
						x.a[i][j] = a[i][j] + b.a[i][j];
					}
				
				}	 
				cout<<"Result is :\n";
			
				for(int i=0;i<row;i++)
				{
					for(int j= 0;j<col;j++)
					{
						cout<<x.a[i][j]<<" ";
					}
					cout<<"\n";
				}

				return x;
			}
			else
			{
				cout<<"Both matrices have different sizes cannot perform addition.\n";
				return b;
			}
	
		}
};

Matrix _addMat(Matrix *iarr,int _count)
{
	Matrix ires= iarr[0];
	for(int i=1;i<_count;i++)
	{
		ires = iarr[i].Add(ires);
	}
	return ires;
}

int main()
{
	int _matrixCount;
	while(1)
	{
	cout<<"Enter the number of matrices you want to add. \n";
	cin>>_matrixCount;
	
	if(_matrixCount > 50 || _matrixCount < 2)
	{
		cout<<"Enter valid number of matrices(1-50)."<<endl;
	}
	else
		break;
	}

	Matrix arr[_matrixCount];
	Matrix res;
	
	//input reading X matrices
	for(int i = 0; i < _matrixCount; i++)
	{
		cout<<"Enter "<<i+1<<"matrix"<<endl;
		arr[i].Read();
	}
	res = _addMat(arr,_matrixCount);	
	res.Print();
	return 0;
}
