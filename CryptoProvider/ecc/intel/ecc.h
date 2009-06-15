
#include "ippcp.h"
#include "types.h"


// ������� ����� ������������ ������: �������� ��� ��� ������ � �������������� ��, 
// � ������, ���� ��������� pPX, pPY ������������ �� NULL
// ���������:
//		feBitSize	-	������ � ����� �������� ����
//		pPX, pPY	-	x � y ���������� �����
//		pECC		-	������� ������������� ������
// ������������ ��������:
//		��������� �� ���������� � �������� ������������������ �������� ����� ���. ������

IppsECCPPointState* eccPointNew( const IppsBigNumState *pPX, const IppsBigNumState* pPY, IppsECCPState *pECC);

// ������� ����� ������������ ������: �������� ��� ��� ������ 
// � �������������� �� ��� ����� � ������������� ( � ��������������� ������������),
// ���� ������ ����� ������������� ������)
// ���������:
//		feBitSize	-	������ � ����� �������� ����
//		pECC		-	������� ������������� ������ (���� ���������� NULL, �� ���������� �� �����������)
// ������������ ��������:
//		��������� �� ���������� �������� ����� ���. ������, ������������������ ��� ����������-��������� �����

IppsECCPPointState* eccPointNew( IppsECCPState *pECC);

// ����������� ������, ���������� ��� �������� ����� ������������� ������ 

void eccPointRelease( IppsECCPPointState* pPoint);

void eccPointToOctet( IppsECCPPointState *pPoint, Ipp8u *pRawKey, IppsECCPState *pECC );

// ������� ����� ������������� ������ �� ��������� ��������� - 
// �������� �������, ����������� ���������� ���� �����.
// ���������:
//		baseData		- �������� ��������: ������� ������ ����� keyLengt, h���������� ���������� ����� (X||Y)
//		byteDataLength	- ����� � ������ �������� ���������
//		pECC			- �������� ������������� ������
IppsECCPPointState* eccPointNew( const Ipp8u* baseData, const int byteDataLength, IppsECCPState* pECC);