
#ifndef BIGNUMBER_HEADER_FILE
#define BIGNUMBER_HEADER_FILE

#include "types.h"
#include <limits>
#include <memory.h>
#include <iostream>

/*void assign( DIGIT bn1[], const DIGIT bn2[], const unsigned num );
void assignDigit( DIGIT bn[], DIGIT value, const unsigned num );
void zero( DIGIT bn[], const unsigned num );
*/
bool isZero( const DIGIT bn[], const unsigned num );
int bncmp( const DIGIT bn1[], const DIGIT bn2[], const unsigned num );

// �������� ���� ������� �����: 
//		res = bn1 + bn2
// ����������:
//		��� ��������
DIGIT add( DIGIT res[], const DIGIT bn1[], const DIGIT bn2[], const unsigned num );

// �������� ���� ������� �����: 
//		res = bn1 + bn2
// ����������:
//		��� ��������
DIGIT addDigit( DIGIT res[], const DIGIT bn1[], const DIGIT x, const unsigned num );


// ��������� ���� ������� �����:
//		res = bn1 - bn2
// ����������:
//		��� �����
DIGIT sub( DIGIT res[], const DIGIT bn1[], const DIGIT bn2[], const unsigned num );

// ��������� ����� �� �������� �����:
//		res = bn1 - bn2
// ����������:
//		��� �����
DIGIT subDigit( DIGIT res[], const DIGIT bn1[], const DIGIT x, const unsigned num );

// ��������� ���� ������� �����:
//		res = bn1*bn2;
// ���������� �������� ��������� ���������
// ����������:
//		<������>
void mul( DIGIT res[], const DIGIT bn1[], const DIGIT bn2[], const unsigned num );

// ��������� ����� �� ������� �����:
//		res = bn1*bn2;
// ����������:
//		<������>
void shortMul( DIGIT res[], const DIGIT bn[], const DIGIT x, const unsigned num );

// ���������� �������� �������� �����
//		res = bn^2;
// ����������:
//		<������>
void square( DIGIT res[], const DIGIT bn[], const unsigned num );

// ������� �������� ����� �� ����� � ����������� ������� �� �������:
//      bnQuo = [bn1/bn2]
//		bnRem = bn1 mod bn2;
// ����������:
//		<������>
void shortDiv( DIGIT *res, const DIGIT bn[], DIGIT x, DIGIT *rem, unsigned num );

// ������� �������� ����� �� ������� ����� � ����������� ������� �� �������:
//      bnQuo = [bn1/bn2]
//		bnRem = bn1 mod bn2 == (bn1 - bnQuo*bn2);
// ����������:
//		<������>
void div( const DIGIT bn1[], const DIGIT bn2[], DIGIT *bnQuo, DIGIT *bnRem, const unsigned num1, const unsigned num2 );

// �������� ���� ������� ����� �� ������:
//		res = bn1+bn2 (mod bnMod);
// ����������:
//		<������>
void modadd( DIGIT res[], const DIGIT bn1[], const DIGIT bn2[], const DIGIT bnMod[], const unsigned num );

// ��������� ���� ������� ����� �� ������:
//		res = bn1-bn2 (mod bnMod);
// ����������:
//		<������>
void modsub( DIGIT res[], const DIGIT bn1[], const DIGIT bn2[], const DIGIT bnMod[], const unsigned num );


// ��������� ���� ������� ����� �� ������:
//		res = bn1*bn2 (mod bnMod);
// ����������:
//		<������>
void modmul( DIGIT res[], const DIGIT bn1[], const DIGIT bn2[], const DIGIT bnMod[], const unsigned num );

// ���������� �������� �������� ����� �� ������
//		res = bn^2 (mod bnMod);
// ����������:
//		<������>
void modSquare( DIGIT res[], const DIGIT bn[], const DIGIT bnMod[], const unsigned num );

// ������� ���� ������� ����� �� ������:
//		res = bn1/bn2 (mod bnMod);
// ����������:
//		<������>
void moddiv( DIGIT res[], const DIGIT bn1[], const DIGIT bn2[], const DIGIT bnMod[], const unsigned num );

// ��������� ���� ������� ����� �� ����������:
//		res = bn1*bn2 (mod bnMod);
// ����������:
//		<������>
void montMul( DIGIT res[], const DIGIT bn1[], const DIGIT bn2[], const DIGIT bnMod[], DIGIT z, const unsigned num );

// ��������� ����� �� ������� ����� �� ������:
//		res = x*bn2 (mod bnMod);
// ����������:
//		<������>
void modmulShort( DIGIT res[], const DIGIT bn1[], const DIGIT x, const DIGIT bnMod[], const unsigned num );

// ���������� � ������� �������� ����� �� ������:
//		res = bnBase^bnDegree (mod bnMod);
// ����������:
//		<������>
//void modPower( DIGIT res[], const DIGIT bnBase[], const DIGIT bnDegree[], const DIGIT bnMod[], const unsigned numDegree, const unsigned numMod );

// ���������� � ������� �������� ����� �� ������ � �������������� �������� ����������:
//		res = bnBase^bnDegree (mod bnMod);
// ����������:
//		<������>
void modPowerMont( DIGIT res[], const DIGIT bnBase[], const DIGIT bnDegree[], const DIGIT bnMod[], const unsigned numDegree, const unsigned numMod );

// ���������� ����������� ������ �������� �� ������������ ��������� �������:
//		bnGCD = ���( bnA, bnB );
// ������� ���������:
//		bnA, bnB	- ��� ������� ����� ����� num
//		num			- ����� ������� ����� (unsigned)
// �������� ���������:
//		bnGCD		- ���������� ����� �������� ����� bnA, bnB
//		bnX, bnY	- ����� ����� (����� num) �����, ��� bnX * bnA + bnY * bnB = 1
//		bXNegative  - ��������������� ������ �������� ����� bnX
//		bYNegative  - ��������������� ������ �������� ����� bnY
// ����������:
//		<������>
void gcd(DIGIT bnGCD[], const DIGIT bnA[], const DIGIT bnB[], DIGIT bnX[], DIGIT bnY[], bool &bXNegative, bool &bYNegative, const unsigned num );

// ���������� ������������������ ��������� �������� � ���� ������� ������� (�� ������):
//		res = bnA^{-1} (mod bnMod) = 1/bnA (mod bnMod);
// ������� ���������:
//		bnA			- ������� ����� ����� num
//		bnMod		- ������ �� �������� ����������� ��������
//		num			- ����� ������� ����� (unsigned)
// �������� ���������:
//		res	- ������� �����, ����������������� �������� bnA �� ������ bnMod
// ����������:
//		<������>
void modInvert(DIGIT res[], const DIGIT bnA[], const DIGIT bnMod[], const unsigned num );

// ���������� ���������������� �������� � ���� ������� ������� (�� ������):
//		res = -bnA (mod bnMod);
// ������� ���������:
//		bnA			- ������� ����� ����� num
//		bnMod		- ������ �� �������� ����������� ��������
//		num			- ����� ������� ����� (unsigned)
// �������� ���������:
//		res	- ������� �����, ��������������� ������� bnA �� ������ bnMod
// ����������:
//		<������>
void modNegative(DIGIT bnNegative[], const DIGIT bnA[], const DIGIT bnMod[], const unsigned num );

void print( const DIGIT bn[], const unsigned num );

std::ostream& operator<<( std::ostream &os, const BigNum &bn);


////////////////////////////////////////////////////////////////////////////////////////////////
///////////																	////////////////////
///////////					INLINE FUNCTION IMPLEMENTATION					////////////////////
///////////																	////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

inline void assign( DIGIT bn1[], const DIGIT bn2[], const unsigned num ){
	//memcpy( bn1, bn2, num*sizeof(DIGIT) );
	for (unsigned i=0; i<num; i++)
		bn1[i] = bn2[i];
}

inline void assignDigit( DIGIT bn[], DIGIT value, const unsigned num ){
	bn[0] = value;
	//memset( &bn[1], 0, (num-1)*sizeof(DIGIT) );
	for (unsigned i=1; i<num; i++)
		bn[i] = 0;
}

inline void zero( DIGIT bn[], const unsigned num ){
	//memset( bn, 0, num*sizeof(DIGIT) );
	for (unsigned i=0; i<num; i++)
		bn[i] = 0;
}

inline void modNegative(DIGIT bnNegative[], const DIGIT bnA[], const DIGIT bnMod[], const unsigned num ){
#ifdef _VERBOSE_CHECKING
	if ( bncmp(bnA, bnMod, num)>0 ){
		throw std::invalid_argument( "modNegative: Invalid params - bnA > bnMod" );
	}
#endif
	sub( bnNegative, bnMod, bnA, num );
}

inline void modadd( DIGIT res[], const DIGIT bn1[], const DIGIT bn2[], const DIGIT bnMod[], const unsigned num ){
	DIGIT bnTemp[MAX_SIZE];
	DIGIT shift = add( bnTemp, bn1, bn2, num );
	if ( shift > 0 || bncmp(bnTemp, bnMod , num) >= 0 ){
#ifdef _VERBOSE_CHECKING
		DIGIT borrow = sub( res, bnTemp, bnMod, num );
		if ( (borrow > 0 && shift == 0) ||
			(borrow ==0 && shift > 0) ){
				throw std::domain_error( "modadd: something weird - shift and borrow flags do not match" );
		}
#else
		sub( res, bnTemp, bnMod, num );
#endif
	} else {
		assign( res, bnTemp, MAX_SIZE );
	}
}

inline void modsub( DIGIT res[], const DIGIT bn1[], const DIGIT bn2[], const DIGIT bnMod[], const unsigned num ){
	DIGIT bnTemp[MAX_SIZE];
	modNegative( bnTemp, bn2, bnMod, num );
	modadd( res, bn1, bnTemp, bnMod, num );
}

inline void modSquare( DIGIT res[], const DIGIT bn[], const DIGIT bnMod[], const unsigned num ){
	DIGIT bnTemp[MAX_SIZE*2];
	square( bnTemp, bn, num);
	div( bnTemp, bnMod, NULL, res, 2*num, num );
}

inline void square( DIGIT res[], const DIGIT bn[], const unsigned num ){
	mul( res, bn, bn, num );
}

inline bool isEven( const DIGIT bn[], const unsigned num ){
	return bn[0] & 1;
}

inline void halfDiv( DIGIT bn[], const unsigned num ){
	static DIGIT mask = 1 << (baseDigits-1);
	for (unsigned i=0; i<num; i++){
		bn[i] >>= 1;
		bn[i] |= (mask & bn[i+1]);
	}
	bn[num-1] &= DIGIT(-1)>>1;
}

#endif //BIGNUMBER_HEADER_FILE

