
#include "ippcp.h"

typedef unsigned char byte; // ��������� ��� byte = unsigned char

// byte arr[] - ������ �� ������� ������ - ���������� ������
// int len - ����� ���� ������� � ������
// byte res[] - ������ �� ������������ ������ �������� 32 ����� - ��������� �����������
void hash(const byte arr[], const int len, byte res[]);


/*	\brief Implements step hash function from GOST.
 *
 *	\param	H		- the hash value already calculated (256 bits length).
 *	\param	M		- a piece of message 256 bits length to feed to the hash.
 *	\param	newH	- buffer to store the new hash value (with M feeded).
 *	
 *	\return	<nothing>
 *
 */
void stephash(const byte H[], const byte M[], byte newH[]);