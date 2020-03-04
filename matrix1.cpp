/* Assignment -1 Write a program to accept two NXM matrix input from the user and add them and print the result matrix. Implement three functions for the above operations . (Use a 2D array of max size 100X100)*/

#include<iostream>
using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

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
			if(row<1 || row>100)
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
			if(col<1 || col>100)
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
				cout<<"Enter "<<i+1<<"row "<<j+1<<"column element:\n";
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
		void Add(const Matrix &b)
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
			}
			else
			{
				cout<<"Both matrices have different sizes cannot perform addition.\n";
			}
		}
};

int main()
{
	Matrix m1;
	m1.Read();
	m1.Print();
	Matrix m2;
	m2.Read();
	m2.Print();
	m1.Add(m2);
//	m1.Print();
//	m2.Print();
	return 0;
}
