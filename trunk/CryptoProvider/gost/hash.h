
#include "ippcp.h"

typedef unsigned char byte; // ��������� ��� byte = unsigned char

// byte arr[] - ������ �� ������� ������ - ���������� ������
// int len - ����� ���� ������� � ������
// byte res[] - ������ �� ������������ ������ �������� 32 ����� - ��������� �����������
void hash(const byte arr[], const int len, byte res[]);
