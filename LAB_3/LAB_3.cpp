#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double	e = 0.0001;		//погрешность
	double	a = 0.1;		//начальное Х
	double	b = 0.8;		//конечное Х
	int		k = 10;			//количество интервалов по Х
	int		n = 3;			//фиксированное число итераций 
	int		i1, i2, i3;		//переменные для циклов
	double	h = (b - a) / k;	//шаг по Х
	double	x;				//текущий Х
	double	sn;				//один элемент ряда
	double	S1;				//сумма ряда из n элементов
	double	S2;				//сумма ряда, пока очередной элемент больше погрешности
	double	f;				//точное значение функции
	for (i1 = 0; i1 <= k; i1++) 
	{
		x = a + i1 * h;
		f = 0.25 * log((1 + x) / (1 - x)) + 0.5 * atan(x);

		for (S1 = 0, i2 = 1; i2 <= n; i2++)
		{
			
			S1 += pow(x, 4 * i1 + 1) / (4 * i1 + 1);
		}
		for (S2 = 0, sn = 1, i3 = 1; fabs(sn) >= e; i3++)
		{
			
			sn = pow(x, 4 * i2 + 1) / (4 * i2 + 1);
			S2 += sn;
		}
		printf("x=%.2f SN=%f SE=%f Y=%f\n", x, S1, S2, f);
	}
	return 0;
}

