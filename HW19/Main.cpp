#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

int delitel(int num1, int num2) {
	int min = num1;
	if (min > num2) {
		min = num2;
		num2 = num1;
	}
	for (int i = min; i > 0; i--) {
		if (min % i == 0 && num2 % i == 0)
			return i;
	}


}

int mirror_number(int num1) {
	int numb = 0;
	while (num1) {
		numb = numb * 10 + num1 % 10;
		num1 /= 10;
	}
	return numb;
}

void arr_sortN(int arr[], const int length, int num1) {
	int fpos = 0;
	for (int i = 0; i < length; i++) {
		if (arr[i] == num1) {
			fpos = i;
			std::cout << "Первая позиция -> " << num1 << " = " << fpos << std::endl; break;
		}
	}
	for (int i = length - 1; i > fpos; i--) {
		for (int j = fpos + 1; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
	}
}
void print_arr(int arr[], const int length) {
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	
}

void fill_arr(int arr[], const int length, int num1, int num2) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (num2 + 1 - num1) + num1;
}


int main() {
	setlocale(0, "");
	int n;

	//Задача 1.
	std::cout << "Задача 1.\n\n";
	std::cout << "Найбольший средний делитель -> ";
	std::cout << delitel(28, 64) << std::endl;

	//Задача 2. 
	std::cout << "Задача 1.\n\n";

	int num1 = 548;
	std::cout << "Изначальное число -> " << num1 << std::endl;
	std::cout << "Отраженное число -> " << mirror_number(num1) << std::endl;

	//Задача 3.
	
	std::cout << "Задача 3.\n\n";
	const int size1 = 10;
	int arr[size1]{5,21, 12, 32, 16, 27, 33, 1, 0, 22};
	print_arr(arr, size1);
	arr_sortN(arr, size1, 32);
	print_arr(arr, size1);

	//Задача 4.
	std::cout << "Задача 4.\n\n";
	const int size2 = 10;
	int arr1[size2]{};
	std::cout << "Заполненный массив:\n";
	fill_arr(arr1, size2, 1, 20);
	print_arr(arr1, size2);





	return 0;
}