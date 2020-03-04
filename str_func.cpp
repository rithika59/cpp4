/* Implement following string functions. do not use any library function from string.h. Use subscript operator to implement them.

char *Strcpy(char *dest , const char *src);
int strCmp(const char *s1, const char *s2);
char *StrCat(char *dest , const char *src);*/

#include<iostream>

using namespace std;

int strLen(const char *str)
{
			int i=0;
			while(str[i] != 0)
			{
				i++;
			}
			return i;
}	

char *StrCpy(char *dest , const char *src)
{
	int i = 0,count =0;
	count = strLen(src);
	while(i != count)
	{
		dest[i] = src[i];
		dest[i+1] = 0;
		i++;
	}
	return dest;
}

int StrCmp(const char *s1 , const char *s2)
{

	int r = 23;
	int _lens1 = strLen(s1);
	int _lens2 = strLen(s2);
	if(_lens1 == _lens2)
	{
	for(int i=0;i<_lens1;i++)
	{
		r = s1[i]-s2[i];
		if(r != 0)
			{
//			cout<<i<<s1[i]<<s2[i];
//			cout<<"getting here";
			break;
			}
	}
		cout<<"r value is "<<r<<endl;
		(r<0)?r = -1:r =1;
		return r;
	}else if(_lens1>_lens2)
	{
		return 1;
	}
	else if(_lens2>_lens1)
	{
		return -1;
	}
}

char *StrCat(char *dest , const char *src)
{

	int len = strLen(dest);
	int len2 = strLen(src);
	for(int i=len;i<(len+len2);i++)
	{
		dest[i]=src[i-(len)];	
		dest[i+1]=0;
	//	cout<<i<<endl;
	//	cout<<dest[i]<<endl;
	}
	return dest;

}

int main()
{
	const char* s1 = "stsing";
	const char* s2 = "string";
	const char* src = "sorting";
	char* dest = NULL;
	char* dest2 = NULL;
	dest = new char[50];	
	dest2 = new char[50];
	int res=0;
	int res2 = strLen(src);

	cout<<"The length of the string "<<src<<" is "<<res2<<endl;
	dest = StrCpy(dest,src);
	cout<<"Copy function result: \n";
	cout<<dest<<endl;
	res = StrCmp(s1,s2);
	cout<<"Compare function result: \n";
	cout<<res<<endl;
	delete[] dest;
	cout<<"Enter a string to concat\n";
	cin>>dest2;
	dest2 = StrCat(dest2,src);
	cout<<"Concat function result: \n";
	cout<<dest2<<endl;
	delete[] dest2;
	return 0;
}
