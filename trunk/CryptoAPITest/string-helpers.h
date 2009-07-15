

#ifndef _STRING_HELPERS_HEADER_FILE
#define _STRING_HELPERS_HEADER_FILE

#include <windows.h>
#include <iostream>

// ������������ ������ � ����������������� �������������� ����� 
// � 'octet string' - ������������ ������ ��������.
void strtobyte(const char* sChar, BYTE* sOctet);

void print( std::ostream &os, const BYTE* pbData, const unsigned uiLen );


#endif //_STRING_HELPERS_HEADER_FILE