
#include "ecc/ecc.h"
#include "bignum/bignum.h"
#include "Params.h"
#include "rand/rand.h"

// ������� ���������� ���� ��� ������������� ����� ������, ������������� � ������ buf ����� iBufSize
// ���������:
//		pBuf		- ��������� �� ����� ������, ��� ������� ����������� ���
//		iBufSize	- ������ ������ ������ � ������
//		pDigestMsg	- ��������� �� ����� �������� 256 ���, � ������� ����� �������� �������� ���-�������
//		params		- ��������� ���������� ���-�������
void digest(const BYTE *pBuf, const int iBufSize, BYTE *pDigestMsg, const Params341194 *params);

// ������� ���������� ��� �� ���� � 34.10-2001
// ���������:
//		pDigestMsg	- ��������� �� ����� �������� 256 ���, ���������� �������� ���-�������
//		pPrivateKey - ��������� �� �������� ���� ������������
//		pSignature	- ��������� �� ����� ����� 512 ���, � ������� ����� �������� �������� ��� 
//		params		- ��������� ����� ���
//		rand		- ��������� ��������� �����
void sign(const BYTE *pDigestMsg, const IppsBigNumState *pPrivateKey, BYTE *pSignature, const Params34102001 *params, Rand & rand);

// ������� �������� ��� �� ���� � 34.10-2001
// ���������:
//		pDigestMsg	- ��������� �� ����� �������� 256 ���, ���������� �������� ���-�������
//		pPublicKey	- ��������� �� �������� ���� ������������ (����� ���. ������)
//		pSignature	- ��������� �� ����� ����� 512 ���, ���������� ����������� �������� ���
//		params		- ��������� ����� ���
bool verify(const BYTE *pDigestMsg, const IppsECCPPointState *pPublicKey, const BYTE *pSignature, const Params34102001 *params);

// ���������� �������� ����
// ���������:
//		pPublicKey	- ��������� �� �������� ���� ������������ (����� ���. ������)
//		pPrivateKey - ��������� �� �������� ���� ������������
//		params		- ��������� ����� ���
//		rand		- ��������� ��������� �����
// ���������:
//		- ������ ��� ����� ������� �������� �� ����, ��� ����� �������� �������������
bool genKeyPair(IppsECCPPointState *&pPublicKey, IppsBigNumState *&pPrivateKey, const Params34102001 &params, Rand & rand);
