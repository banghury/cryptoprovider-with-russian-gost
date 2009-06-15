
#include "ippcp.h"
#include "bignum/bignum.h"

#ifndef _RAND_HEADER_FILE
#define _RAND_HEADER_FILE

// ��������� ��������� ��������� �����
class Rand {
public:
	// ������� � �������������� ��������� ��������� �����
	// ���������:
	//		iSeedSize	- ������ ����������������� �������� � ������
	//							���� 0 - �� �������������� �� �������� ���������
	//		pSeedValue	- ��������� �� ���������������� ��������,
	//							���� NULL - �� �������������� �� �������� ���������
	Rand(const int iSeedSize = 0, unsigned char *pSeedValue = NULL);

	~Rand();

	IppsPRNGState* getPRNG(){ return pPRNG; }

	// ���������� ��������� ����� ����� iSize ����
	IppsBigNumState* operator()(const int iSize);
protected:
	IppsPRNGState* pPRNG;
};

/*
// ������� � �������������� ��������� ��������� �����
// ���������:
//		pPRNG		- �������� ��������� ��������������� �����
//		iSeedSize	- ������ ����������������� �������� � 32-� ������ ������
//							���� 0 - �� �������������� �� �������� ���������
//		pSeedValue	- ��������� �� ���������������� ��������,
//							���� NULL - �� �������������� �� �������� ���������
void randInit(IppsPRNGState* pPRNG, const int iSeedSize = 0, IppsBigNumState *pSeedValue = NULL);

// �������������� ��������� ��������� �����
// ���������:
//		seedValue	- ��������� �� ���������������� ��������
// ���������:
//		- ������ ����������������� �������� �� ������ ��������� ��������� ��� �������� ���������� �������� seedBits
//		- ��������� ������ ���� ��� ������ �������� randInit
void randSetSeed(IppsPRNGState* pPRNG, IppsBigNumState *pSeedValue );

// �������� ������ � ���������� ��������������� �����
// ���������:
//		iSize		- ����� � 32-� ������ ������ ������������� ���������������� �����
// ���������:
//		- ���������� ������ ���� ��� ������ �������� randInit
//		- ������ ��� ������������ ��� ���������� ���� �� ��������
IppsBigNumState* bnRand(int iSize, IppsPRNGState* pPRNG);

*/

#endif //_RAND_HEADER_FILE