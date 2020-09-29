#include "stdafx.h"
#include "CalcManager.h"

TCHAR* CalcManager::calculateQuadricEquation(double a, double b, double c)
{
	TCHAR buff[100];

	if (a == 0 && b == 0 && c == 0)
		lstrcpy(buff, L"��������� ����� ����������� ��������� �������");
	else if (a == 0)
	{
		double x = -c / b;
		swprintf_s(buff, 100, L"��������� ����� ���� ������: x = %.2f", x);
	}
	else
	{
		double D = b * b - 4 * a * c;
		if (D < 0)
			lstrcpy(buff, L"��������� �� ����� ������");
		else if (D == 0)
		{
			double x = -b / 2 / a;
			swprintf_s(buff, 100, L"��������� ����� ���� ������: x = %.2f", x);
		}
		else
		{
			double x1 = (-b - sqrt(D)) / 2 / a;
			double x2 = (-b + sqrt(D)) / 2 / a;
			swprintf_s(buff, 100, L"��������� ����� ��� �����: x1 = %.2f; x2 = %.2f", x1, x2);
		}
	}
	return buff;
}
