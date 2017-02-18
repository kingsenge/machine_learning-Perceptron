#include "stdafx.h"
#include<vector>

using namespace std;

typedef struct
{
	int	coordinate[2];
	int	y;
}STDATA;

class CPerceptron
{
public:
	void ini(vector<STDATA>*);
	void cal();
	void display();
private:
	void update(int);
	vector<STDATA>* m_pData;	
	int	m_w[2];
	int	m_b;
};

void CPerceptron::ini(vector<STDATA>* pData)
{
	m_pData = pData;
	m_w[0] = 0;
	m_w[1] = 0;
	m_b = 0;
}

void CPerceptron::update(int i)
{
	m_w[0] = m_w[0] + (*m_pData)[i].y * (*m_pData)[i].coordinate[0];
	m_w[1] = m_w[1] + (*m_pData)[i].y * (*m_pData)[i].coordinate[1];

	m_b = m_b + (*m_pData)[i].y;
}

void CPerceptron::display()
{
	printf("\nf(X)=%d*X1 + %d*X2 ",m_w[0],m_w[1]);

	if(m_b>=0)
		printf("+ %d",m_b);
	else
		printf("- %d",-1*m_b);
}

void CPerceptron::cal()
{
	int nSize = m_pData->size();
	int i =0 ;
	int iRet= 0;

	while(i< nSize)
	{
		iRet = (*m_pData)[i].y * ((*m_pData)[i].coordinate[0]*m_w[0]+(*m_pData)[i].coordinate[1]*m_w[1]+m_b);
		if(iRet>0)
		{
			i++;
			continue;
		}
		
		update(i);
		i = 0;
		display();
	}
}

void test()
{
	vector<STDATA> ovecData(3);

	ovecData[0].coordinate[0] = 3;
	ovecData[0].coordinate[1] = 3;
	ovecData[0].y =1;

	ovecData[1].coordinate[0] = 4;
	ovecData[1].coordinate[1] = 3;
	ovecData[1].y =1;

	ovecData[2].coordinate[0] = 1;
	ovecData[2].coordinate[1] = 1;
	ovecData[2].y =-1;

	CPerceptron oPer;

	oPer.ini(&ovecData);
	oPer.cal();
}


int _tmain(int argc, _TCHAR* argv[])
{
	test();
	getchar();
	return 0;
}

