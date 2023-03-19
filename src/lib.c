#include "lib.h"
#include "stdio.h"

//Что за функция
double get_subarray(double arr1[], int number)
{
	int n = 8;
	double arr2[8];
	unsigned long int b = 0;
	int first_neg_index = -1;
	int second_neg_index = -1;
	double res;
	double *array1 = arr1;
	double *array2 = arr2;
	//цикл для знаходження першого від'ємного чсила та другого
	for (int a = 0; a < n; a++) {
		if (*(array1 + a) < 0) {
			if (first_neg_index == -1) {
				first_neg_index = a;
			} else {
				second_neg_index = a;
				break;
			}
		}
	}
	
	//Блок коду який записує у масив аrr2 числа між від'ємними.
	if (first_neg_index != -1 && second_neg_index != -1) {
		for (int a = first_neg_index + 1; a < second_neg_index; a++) {
			*(array2 + (b++)) = *(array1 + a);
		}
	}

        
	res = *(array2 + number);

	return res;
}
