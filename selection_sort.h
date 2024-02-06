#pragma once
#include <iostream>
using namespace std;


template <typename Tarr, typename T2, typename T3, typename T4>
void SelectionSort(Tarr arr, T2 size, T3 n2, T4 n1) {
	int tmp1;
	char tmp2;
	float tmp3;
	double tmp4;
	int min_index;
	int max_index;
	switch (n2)
	{
	case 1: // по возрастанию
		for (int i = 0; i < size - 1; i++) {
			min_index = i;
			for (int j = i + 1; j < size; j++) {
				if (arr[j] < arr[min_index]) {
					min_index = j;
				}
			}
			if (min_index != i) {
				switch (n1){
				case 1:
					tmp1 = arr[i];
					arr[i] = arr[min_index];
					arr[min_index] = tmp1;
					break;
				case 2:
					tmp2 = arr[i];
					arr[i] = arr[min_index];
					arr[min_index] = tmp2;
					break;
				case 3:
					tmp3 = arr[i];
					arr[i] = arr[min_index];
					arr[min_index] = tmp3;
					break;
				case 4:
					tmp4 = arr[i];
					arr[i] = arr[min_index];
					arr[min_index] = tmp4;
					break;
				default:
					break;
				}
			}
		}
		cout << "\nОтсортированный по возрастанию массив: ";
		for (int i = 0; i < size; i++)
			cout << arr[i] << " ";
		cout << "\n\n";
		system("pause");
		break;
	case 2: // по убыванию 
		for (int i = 0; i < size - 1; i++) {
			max_index = i;
			for (int j = i + 1; j < size; j++) {
				if (arr[j] > arr[max_index]) {
					max_index = j;
				}
			}
			if (max_index != i) {
				switch (n1) {
				case 1:
					tmp1 = arr[i];
					arr[i] = arr[max_index];
					arr[max_index] = tmp1;
					break;
				case 2:
					tmp2 = arr[i];
					arr[i] = arr[max_index];
					arr[max_index] = tmp2;
					break;
				case 3:
					tmp3 = arr[i];
					arr[i] = arr[max_index];
					arr[max_index] = tmp3;
					break;
				case 4:
					tmp4 = arr[i];
					arr[i] = arr[max_index];
					arr[max_index] = tmp4;
					break;
				default:
					break;
				}
			}
		}
		cout << "\nОтсортированный по убыванию массив: ";
		for (int i = 0; i < size; i++)
			cout << arr[i] << " ";
		cout << "\n\n";
		system("pause");
		break;
	default:
		break;
	}
}