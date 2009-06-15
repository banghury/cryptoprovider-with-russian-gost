#ifndef TYPES_HEADER_FILE
#define TYPES_HEADER_FILE

#include <limits>
typedef unsigned short int DIGIT;
typedef unsigned long int TWODIGIT;

const unsigned baseDigits = std::numeric_limits<DIGIT>::digits;
const DIGIT MAX_DIGIT = std::numeric_limits<DIGIT>::max();
const unsigned MAX_SIZE = 256 / baseDigits;

typedef DIGIT BigNum[MAX_SIZE];
/*inline DIGIT lodigit( const TWODIGIT T ){
	return DIGIT(T);
}

inline DIGIT hidigit( const TWODIGIT T ){
	return DIGIT(T >> baseDigits);
}
inline TWODIGIT makelong( DIGIT d1, DIGIT d2){
	return (d1 | TWODIGIT(d2) << baseDigits );
}
*/

#define lodigit(T) ( DIGIT(T) )
#define hidigit(T) ( DIGIT(T>>baseDigits) )
#define makelong(d1, d2) ( (d1) | (TWODIGIT(d2) << baseDigits) )


// ������������ ������, ���������� 16-������ ������������ �������� ����� 
// � ������� ����� ������ N
// � ������ ������������ ������ ����� ��������, ����� - ������������ ����������� ������
// ����������
//   -1  � ������ ������
//    0  � ������ ������������
//    1  � ������ ������
int strtodigitn( const char* s, DIGIT bn[], const unsigned num);


#endif // TYPES_HEADER_FILE