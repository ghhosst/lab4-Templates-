#include <iostream>
#include "selection_sort.h"
#include "Element.h"
#include "List.h"
#include "getString.h" 
#include "ListStr.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	cin.exceptions(std::istream::failbit);

	int choice, n1, n2, size_arr, n3;
	int n3_1, n3_2, n3_3, n3_4, n3_5;
	int n3_1_1, n3_1_2, n3_1_3, n3_1_4, n3_1_5;
	int nPlus1, nPlus2, nPlus3, nPlus4, nPlus5;
	int i; // i - индекс для доступа к элементам
	int* arr_int = nullptr;
	char* arr_char = nullptr;
	float* arr_float = nullptr;
	double* arr_double = nullptr;

	char* Str1;
	char* Str2;

	List <int> IntList; 
	List <char> CharList; 
	List <float> FloatList;
	List <double> DoubleList;
	List <char*> StrList;

	/*Объекты для объединения списков*/
	List<int> firstInt_list;
	List<int> secondInt_list;
	List<int> IntInt_list;

	List<char> firstChar_list;
	List<char> secondChar_list;
	List<char> CharChar_list;

	List<float> firstFloat_list;
	List<float> secondFloat_list;
	List<float> FloatFloat_list;

	List<double> firstDouble_list;
	List<double> secondDouble_list;
	List<double> DoubleDouble_list;

	List<char*> firstStr_list;
	List<char*> secondStr_list; 
	List<char*> StrStr_list; 


	do {
		m:
		system("cls");
		cout << "Меню" << endl
			 << "1) Задание 1 (сортировка выбором)" << endl
			 << "2) Задание 2" << endl
			 << "3) Выйти из программы" << endl
			 << "Выбранный пункт: "; 
		try {
			cin >> choice;

			switch (choice) {
			case 1:
				system("cls");
				cout << "Выберете тип данных, для которого нужно выполнить сортировку" << endl
					<< "1) int" << endl
					<< "2) char" << endl
					<< "3) float" << endl
					<< "4) double" << endl
					<< "5) Выйти из программы" << endl 
					<< "Выбранный пункт: ";
				cin >> n1;
				if (n1 == 1 || n1 == 2 || n1 == 3 || n1 == 4) {
					cout << "\nРазмер массива: ";
					cin >> size_arr;
				}

				switch (n1) {
				case 1:
					arr_int = new int[size_arr];
					break;
				case 2:
					arr_char = new char[size_arr];
					break;
				case 3:
					arr_float = new float[size_arr];
					break;
				case 4:
					arr_double = new double[size_arr];
					break;
				case 5:
					goto m;
					break;
				default:
					cout << "\nНекорректный выбор !!!\nПожауйста, выберете пункт от 1 до 5.\n\n";
					system("pause");
					goto m;
					break;
				}

				cout << "\nДля выполнения сортировки, введите массив, который необходимо отсортировать." << endl;
				cout << "Массив: ";
				switch (n1) {
				case 1:
					for (int i = 0; i < size_arr; i++)
						cin >> arr_int[i];
					break;
				case 2:
					for (int i = 0; i < size_arr; i++)
						cin >> arr_char[i];
					break;
				case 3:
					for (int i = 0; i < size_arr; i++)
						cin >> arr_float[i];
					break;
				case 4:
					for (int i = 0; i < size_arr; i++)
						cin >> arr_double[i];
					break;
				default:
					break;
				}
				cout << "\n\n";
				cout << "Отсортировать" << endl
					<< "1) По возрастанию" << endl
					<< "2) По убыванию" << endl
					<< "3) Выйти из программы" << endl
					<< "Выбранный пункт: ";
				cin >> n2;

				switch (n2) {
				case 1:
					switch (n1) {
					case 1:
						SelectionSort(arr_int, size_arr, n2, n1);
						break;
					case 2:
						SelectionSort(arr_char, size_arr, n2, n1);
						break;
					case 3:
						SelectionSort(arr_float, size_arr, n2, n1);
						break;
					case 4:
						SelectionSort(arr_double, size_arr, n2, n1);
						break;
					default:
						break;
					}
					break;
				case 2:
					switch (n1) {
					case 1:
						SelectionSort(arr_int, size_arr, n2, n1);
						break;
					case 2:
						SelectionSort(arr_char, size_arr, n2, n1);
						break;
					case 3:
						SelectionSort(arr_float, size_arr, n2, n1);
						break;
					case 4:
						SelectionSort(arr_double, size_arr, n2, n1);
						break;
					default:
						break;
					}
					break;
				case 3:
					break;
				default:
					cout << "\nНекорректный выбор !!!\nПожалуйста, выберете пункт от 1 до 3.\n\n";
					system("pause");
					break;
				}
				break;
			case 2:
				system("cls");
				cout << "Выберете тип данных, для которого необходимо выполнить задание" << endl
					<< "1) int" << endl
					<< "2) char" << endl
					<< "3) float" << endl
					<< "4) double" << endl
					<< "5) char*" << endl 
					<< "6) Выйти из программы" << endl 
					<< "Выбранный пункт: ";
				cin >> n3;
				switch (n3) {
				case 1: // int
					do {
						int cntForIntNum = 0;
						system("cls");
						cout << "int\n\n1) Добавить элемент в список" << endl
							<< "2) Вывести список на экран" << endl
							<< "3) Доступ к элементу заданной позиции через оператор [ ]" << endl
							<< "4) Объединить два списка" << endl
							<< "5) Выйти из программы" << endl
							<< "Выбранный пункт: ";
						cin >> n3_1;

						switch (n3_1) {
						case 1:
							// перегрузим оператор >>
							cout << "\nЭлемент: ";
							cin >> IntList;
							break;
						case 2:
							// перегрузим оператор <<
							if (IntList.Empty()) {
								system("pause");
								break;
							}
							cout << IntList;
							system("pause");
							break;
						case 3:
							// оператор []
							if (IntList.Empty()) {
								system("pause");
								break;
							}
							IntList.funcNumbering(cntForIntNum);
							system("cls");
							cout << "Доступ к элементу заданной позиции через оператор [ ]\n" << endl
								<< "1) Вывести элемент на экран" << endl
								<< "2) Извлечь элемент из списка" << endl
								<< "3) Выйти из программы" << endl
								<< "Выбранный пункт: ";
							cin >> n3_1_1;
							switch (n3_1_1) {
							case 1:
								cout << IntList;
								cout << "Введите нужный индекс [i] = ";
								cin >> i;
								cout << "\nIntList[" << i << "] = " << IntList[i]->GetData() << "\n\n";
								system("pause");
								break;
							case 2:
								cout << IntList;
								cout << "Введите нужный индекс [i] = ";
								cin >> i;
								IntList.Retrieve(IntList[i]);
								system("pause");
								break;
							case 3:
								break;
							default:
								cout << "\n\nНекорректный выбор !!!\nПожалуйста, выберете пункт от 1 до 3.\n\n";
								system("pause");
								break;
							}
							break;
						case 4:
							// оператор +
							do {
								system("cls");
								cout << "Cписок, который вы хотите добавить...\n\n";
								cout << "1) Вставить элемент" << endl
									<< "2) Вывести список на экран" << endl
									<< "3) Очистить список" << endl
									<< "4) Закончить добавление" << endl 
									<< "Выбранный пункт: ";
								cin >> nPlus1;
								switch (nPlus1) {
								case 1:
									cout << "\nЭлемент: ";
									cin >> secondInt_list;
									break;
								case 2:
									if (secondInt_list.Empty()) {
										system("pause");
										break;
									}
									cout << secondInt_list;
									system("pause");
									break;
								case 3:
									if (secondInt_list.Empty()) {
										system("pause");
										break;
									}
									secondInt_list.DeleteList();
									system("pause");
									break;
								case 4:
									if (secondInt_list.Empty()) {
										system("pause");
										break;
									}

									firstInt_list = IntList;

									IntInt_list = firstInt_list + secondInt_list;

									if (IntInt_list.Empty()) {
										system("pause");
										break;
									}
									if (IntList.Empty())
										cout << "(первый список пустой, на экран выведется второй список)";
									cout << "\n\nРезультат объединения двух списков:";
									cout << IntInt_list;
									system("pause");
									break;
								default:
									cout << "\n\nНекорректный выбор !!!\nПожалуйста, выберете пункт от 1 до 3.\n\n";
									system("pause");
									break;
								}
							} while (nPlus1 != 4);
							break;
						case 5:
							break;
						default:
							cout << "\n\nНекорректный выбор !!!\nПожалуйста, выберете пункт от 1 до 5.\n\n";
							system("pause");
							break;
						}


					} while (n3_1 != 5);
					break;
				case 2: // char
					do {
						int cntForCharNum = 0;
						system("cls");
						cout << "char\n\n1) Добавить элемент в список" << endl
							<< "2) Вывести список на экран" << endl
							<< "3) Доступ к элементу заданной позиции через оператор [ ]" << endl
							<< "4) Объединить два списка" << endl
							<< "5) Выйти из программы" << endl
							<< "Выбранный пункт: ";
						cin >> n3_2;

						switch (n3_2) {
						case 1:
							// попробуем перегрузить оператор >>
							cout << "\nЭлемент: ";
							cin >> CharList;
							break;
						case 2:
							// перегрузим оператор <<
							if (CharList.Empty()) {
								system("pause");
								break;
							}
							cout << CharList;
							system("pause");
							break;
						case 3:
							// оператор []
							if (CharList.Empty()) {
								system("pause");
								break;
							}
							CharList.funcNumbering(cntForCharNum);
							system("cls");
							cout << "Доступ к элементу заданной позиции через оператор [ ]\n" << endl
								<< "1) Вывести элемент на экран" << endl
								<< "2) Извлечь элемент из списка" << endl
								<< "3) Выйти из программы" << endl
								<< "Выбранный пункт: ";
							cin >> n3_1_2;
							switch (n3_1_2) {
							case 1:
								cout << CharList;
								cout << "Введите нужный индекс [i] = ";
								cin >> i;
								cout << "\nCharList[" << i << "] = " << CharList[i]->GetData() << "\n\n";
								system("pause");
								break;
							case 2:
								cout << CharList;
								cout << "Введите нужный индекс [i] = ";
								cin >> i;
								CharList.Retrieve(CharList[i]);
								system("pause");
								break;
							case 3:
								break;
							default:
								cout << "\n\nНекорректный выбор !!!\nПожалуйста, выберете пункт от 1 до 3.\n\n";
								system("pause");
								break;
							}
							break;
						case 4:
							// оператор +
							do {
								system("cls");
								cout << "Список, который вы хотите добавить...\n\n";
								cout << "1) Вставить элемент" << endl
									<< "2) Вывести список на экран" << endl
									<< "3) Очистить список" << endl
									<< "4) Закончить добавление" << endl
									<< "Выбранный пункт: ";
								cin >> nPlus2;
								switch (nPlus2) {
								case 1:
									cout << "\nЭлемент: ";
									cin >> secondChar_list;
									break;
								case 2:
									if (secondChar_list.Empty()) {
										system("pause");
										break;
									}
									cout << secondChar_list;
									system("pause");
									break;
								case 3:
									if (secondChar_list.Empty()) { 
										system("pause");
										break;
									} 
									secondChar_list.DeleteList();
									system("pause");
									break;
								case 4:
									if (secondChar_list.Empty()) {
										system("pause");
										break;
									}

									firstChar_list = CharList;

									CharChar_list = firstChar_list + secondChar_list;

									if (CharChar_list.Empty()) {
										system("pause");
										break;
									}
									if (CharList.Empty())
										cout << "(первый список пустой, на экран выведется второй список)";
									cout << "\n\nРезультат объединения двух списков:";
									cout << CharChar_list;
									system("pause");
									break;
								default:
									cout << "\n\nНекорректный выбор !!!\nПожалуйста, выберете пункт от 1 до 3.\n\n";
									system("pause");
									break;
								}
							} while (nPlus2 != 3);
							break;
						case 5:
							break;
						default:
							cout << "\n\nНекорректный выбор !!!\nПожалуйста, выберете пункт от 1 до 5.\n\n";
							system("pause");
							break;
						}
					} while (n3_2 != 5);
					break;
				case 3: // float
					do {
						int cntForFloatNum = 0;
						system("cls");
						cout << "float\n\n1) Добавить элемент в список" << endl
							<< "2) Вывести список на экран" << endl
							<< "3) Доступ к элементу заданной позиции через оператор [ ]" << endl
							<< "4) Объединить два списка" << endl
							<< "5) Выйти из программы" << endl
							<< "Выбранный пункт: ";
						cin >> n3_3;

						switch (n3_3) {
						case 1:
							// попробуем перегрузить оператор >>
							cout << "\nЭлемент: ";
							cin >> FloatList;
							break;
						case 2:
							// перегрузим оператор <<
							if (FloatList.Empty()) {
								system("pause");
								break;
							}
							cout << FloatList;
							system("pause");
							break;
						case 3:
							// оператор []
							if (FloatList.Empty()) {
								system("pause");
								break;
							}
							FloatList.funcNumbering(cntForFloatNum);
							system("cls");
							cout << "Доступ к элементу заданной позиции через оператор [ ]\n" << endl
								<< "1) Вывести элемент на экран" << endl
								<< "2) Извлечь элемент из списка" << endl
								<< "3) Выйти из программы" << endl
								<< "Выбранный пункт: ";
							cin >> n3_1_3;
							switch (n3_1_3) {
							case 1:
								cout << FloatList;
								cout << "Введите нужный индекс [i] = ";
								cin >> i;
								cout << "\nFloatList[" << i << "] = " << FloatList[i]->GetData() << "\n\n";
								system("pause");
								break;
							case 2:
								cout << FloatList;
								cout << "Введите нужный индекс [i] = ";
								cin >> i;
								FloatList.Retrieve(FloatList[i]);
								system("pause");
								break;
							case 3:
								break;
							default:
								cout << "\n\nНекорректный выбор !!!\nПожалуйста, выберете пункт от 1 до 3.\n\n";
								system("pause");
								break;
							}
							break;
						case 4:
							// оператор +
							do {
								system("cls");
								cout << "Список, который вы хотите добавить...\n\n";
								cout << "1) Вставить элемент" << endl
									<< "2) Вывести список на экран" << endl
									<< "3) Очистить список" << endl
									<< "4) Закончить добавление" << endl
									<< "Выбранный пункт: ";
								cin >> nPlus3;
								switch (nPlus3) {
								case 1:
									cout << "\nЭлемент: ";
									cin >> secondFloat_list;
									break;
								case 2:
									if (secondFloat_list.Empty()) {
										system("pause");
										break;
									}
									cout << secondFloat_list;
									system("pause");
									break;
								case 3:
									if (secondFloat_list.Empty()) {
										system("pause");
										break;
									}
									secondFloat_list.DeleteList();
									system("pause");
									break;
								case 4:
									if (secondFloat_list.Empty()) {
										system("pause");
										break;
									}

									firstFloat_list = FloatList;

									FloatFloat_list = firstFloat_list + secondFloat_list;

									if (FloatFloat_list.Empty()) {
										system("pause");
										break;
									}
									if (FloatList.Empty())
										cout << "(первый список пустой, на экран выведется второй список)";
									cout << "\n\nРезультат объединения двух списков:";
									cout << FloatFloat_list;
									system("pause");
									break;
								default:
									cout << "\n\nНекорректный выбор !!!\nПожалуйста, выберете пункт от 1 до 3.\n\n";
									system("pause");
									break;
								}
							} while (nPlus3 != 3);
							break;
						case 5:
							break;
						default:
							cout << "\n\nНекорректный выбор !!!\nПожалуйста, выберете пункт от 1 до 5.\n\n";
							system("pause");
							break;
						}
					} while (n3_3 != 5);
					break;
				case 4: // double
					do {
						int cntForDoubleNum = 0;
						system("cls");
						cout << "double\n\n1) Добавить элемент в список" << endl
							<< "2) Вывести список на экран" << endl
							<< "3) Доступ к элементу заданной позиции через оператор [ ]" << endl
							<< "4) Объединить два списка" << endl
							<< "5) Выйти из программы" << endl
							<< "Выбранный пункт: ";
						cin >> n3_4;

						switch (n3_4) {
						case 1:
							// попробуем перегрузить оператор >>
							cout << "\nЭлемент: ";
							cin >> DoubleList;
							break;
						case 2:
							// перегрузим оператор <<
							if (DoubleList.Empty()) {
								system("pause");
								break;
							}
							cout << DoubleList;
							system("pause");
							break;
						case 3:
							// оператор []
							if (DoubleList.Empty()) {
								system("pause");
								break;
							}
							DoubleList.funcNumbering(cntForDoubleNum);
							system("cls");
							cout << "Доступ к элементу заданной позиции через оператор [ ]\n" << endl
								<< "1) Вывести элемент на экран" << endl
								<< "2) Извлечь элемент из списка" << endl
								<< "3) Выйти из программы" << endl
								<< "Выбранный пункт: ";
							cin >> n3_1_4;
							switch (n3_1_4) {
							case 1:
								cout << DoubleList;
								cout << "Введите нужный индекс [i] = ";
								cin >> i;
								cout << "\nDoubleList[" << i << "] = " << DoubleList[i]->GetData() << "\n\n";
								system("pause");
								break;
							case 2:
								cout << DoubleList;
								cout << "Введите нужный индекс [i] = ";
								cin >> i;
								DoubleList.Retrieve(DoubleList[i]);
								system("pause");
								break;
							case 3:
								break;
							default:
								cout << "\n\nНекорректный выбор !!!\nПожалуйста, выберете пункт от 1 до 3.\n\n";
								system("pause");
								break;
							}
							break;
						case 4:
							// оператор +
							do {
								system("cls");
								cout << "Список, который вы хотите добавить...\n\n";
								cout << "1) Вставить элемент" << endl
									<< "2) Вывести список на экран" << endl
									<< "3) Очистить список" << endl
									<< "4) Закончить добавление" << endl
									<< "Выбранный пункт: ";
								cin >> nPlus4;
								switch (nPlus4) {
								case 1:
									cout << "\nЭлемент: ";
									cin >> secondDouble_list;
									break;
								case 2:
									if (secondDouble_list.Empty()) {
										system("pause");
										break;
									}
									cout << secondDouble_list;
									system("pause");
									break;
								case 3:
									if (secondDouble_list.Empty()) {
										system("pause");
										break;
									}
									secondDouble_list.DeleteList();
									system("pause");
									break;
								case 4:
									if (secondDouble_list.Empty()) {
										system("pause");
										break;
									}

									firstDouble_list = DoubleList;

									DoubleDouble_list = firstDouble_list + secondDouble_list;

									if (DoubleDouble_list.Empty()) {
										system("pause");
										break;
									}
									if (DoubleList.Empty())
										cout << "(первый список пустой, на экран выведется второй список)";
									cout << "\n\nРезультат объединения двух списков:";
									cout << DoubleDouble_list;
									system("pause");
									break;
								default:
									cout << "\n\nНекорректный выбор !!!\nПожалуйста, выберете пункт от 1 до 3.\n\n";
									system("pause");
									break;
								}
							} while (nPlus4 != 3);
							break;
						case 5:
							break;
						default:
							cout << "\n\nНекорректный выбор !!!\nПожалуйста, выберете пункт от 1 до 5.\n\n";
							system("pause");
							break;
						}
					} while (n3_4 != 5);
					break;
				case 5:
					//char*
					do {
						int cntForStrNum = 0; 
						system("cls");
						cout << "char*\n\n1) Добавить элемент в список" << endl
							<< "2) Вывести список на экран" << endl
							<< "3) Доступ к элементу заданной позиции через оператор [ ]" << endl
							<< "4) Объединить два списка" << endl
							<< "5) Выйти из программы" << endl
							<< "Выбранный пункт: ";
						cin >> n3_5;

						switch (n3_5) {
						case 1:
							// перегрузим оператор >>
							cout << "\nЭлемент: ";
							int lenStr1;
							Str1 = getString(&lenStr1);
							Str1 >> StrList;  
							break;
						case 2:
							// перегрузим оператор <<
							if (StrList.Empty()) { 
								system("pause");
								break;
							}
							cout << StrList;
							system("pause");
							break;
						case 3:
							// оператор []
							if (StrList.Empty()) { 
								system("pause");
								break;
							}
							StrList.funcNumbering(cntForStrNum); 
							system("cls");
							cout << "Доступ к элементу заданной позиции через оператор [ ]\n" << endl
								<< "1) Вывести элемент на экран" << endl
								<< "2) Извлечь элемент из списка" << endl
								<< "3) Выйти из программы" << endl
								<< "Выбранный пункт: ";
							cin >> n3_1_5; 
							switch (n3_1_5) {
							case 1:
								cout << StrList; 
								cout << "Введите нужный индекс [i] = ";
								cin >> i;
								cout << "\nIntList[" << i << "] = " << StrList[i]->GetData() << "\n\n"; 
								system("pause");
								break;
							case 2:
								cout << StrList; 
								cout << "Введите нужный индекс [i] = ";
								cin >> i;
								StrList.Retrieve(StrList[i]); 
								system("pause");
								break;
							case 3:
								break;
							default:
								cout << "\n\nНекорректный выбор !!!\nПожалуйста, выберете пункт от 1 до 3.\n\n";
								system("pause");
								break;
							}
							break;
						case 4:
							// оператор +
							do {
								system("cls");
								cout << "Cписок, который вы хотите добавить...\n\n";
								cout << "1) Вставить элемент" << endl
									<< "2) Вывести список на экран" << endl
									<< "3) Очистить список" << endl
									<< "4) Закончить добавление" << endl
									<< "Выбранный пункт: ";
								cin >> nPlus5; 
								switch (nPlus5) {
								case 1:
									cout << "\nЭлемент: ";
									int lenStr2;
									Str2 = getString(&lenStr2);
									Str2 >> secondStr_list;
									break;
								case 2:
									if (secondStr_list.Empty()) {
										system("pause");
										break;
									}
									cout << secondStr_list;
									system("pause");
									break;
								case 3:
									if (secondStr_list.Empty()) {
										system("pause");
										break;
									}
									secondStr_list.DeleteList(); 
									system("pause");
									break;
								case 4:
									if (secondStr_list.Empty()) { 
										system("pause");
										break;
									}

									firstStr_list = StrList; 

									StrStr_list = firstStr_list + secondStr_list; 

									if (StrStr_list.Empty()) { 
										system("pause");
										break;
									}
									if (StrList.Empty()) 
										cout << "(первый список пустой, на экран выведется второй список)";
									cout << "\n\nРезультат объединения двух списков:";
									cout << StrStr_list; 
									system("pause");
									break;
								default:
									cout << "\n\nНекорректный выбор !!!\nПожалуйста, выберете пункт от 1 до 3.\n\n";
									system("pause");
									break;
								}
							} while (nPlus5 != 4);
							break;
						case 5:
							break;
						default:
							cout << "\n\nНекорректный выбор !!!\nПожалуйста, выберете пункт от 1 до 5.\n\n";
							system("pause"); 
							break;
						}
					} while (n3_5 != 5); 
					break; 
				case 6:
					break;
				default:
					cout << "\n\nНекорректный выбор !!!\nПожалуйста, выберете пункт от 1 до 5.\n\n";
					system("pause");
					break;
				}
				break;
			case 3:
				break;
			default:
				cout << "\nНекорректный выбор !!!\nПожалуйста, выберете пункт меню от 1 до 3.\n\n";
				system("pause");
				break;
			}
		}
		catch (const std::istream::failure& ex) {
			system("cls");
			cout << "\n\nВведено некорректное значение !!!" << endl
				<< ex.what() << "\n" << ex.code() << endl
				<< "Повторите ввод...\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("pause");
		}; 
	} while (choice != 3);


	delete[] arr_int;
	delete[] arr_char;
	delete[] arr_float;
	delete[] arr_double;

	return 0;
}