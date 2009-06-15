
#include "types.h"
#include <limits>
#include <stdexcept>
#include <cctype>


// ������������ ������, ���������� ����������������� ������������� ����� � ������ byte*
inline DIGIT chartobyte ( const char c ){
	int i = toupper( c );
	if (  i  >= int('A') )
		return i - int('A')+0xA;
	else
		return i - int('0');

}

// ������������ ������, ���������� 16-������ ������������ �������� ����� 
// � ������� ����� ������ N
// � ������ ������������ ������ ����� ��������, ����� - ������������ ����������� ������
// ����������
//   -1  � ������ ������
//    0  � ������ ������������ (�� ��� ����� �����������)
//    1  � ������ ������
int strtodigitn( const char* s, DIGIT bn[], const unsigned num){
	const unsigned charPerByte = baseDigits / 4;
	const char* const p = s-1;
	while ( *s != '\0' )
		s++;
	s--;
	// s ��������� �� ����� ������
	for (unsigned i=0; i<num; i++){
		bn[i] = 0;
		unsigned count=0;
		DIGIT degree = 1;
		while (s !=p && count < charPerByte ) {
			if ( !isxdigit(*s) )
				return -1;
			bn[i]= bn[i]+ chartobyte(*s)*degree;
			degree*=16;
			count++;
			s--;
		}
	}
	return int( s == p );
}

