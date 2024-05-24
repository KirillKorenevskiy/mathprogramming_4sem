#include <iostream>
#include <iomanip>
#include "Combi.h"
#include "Boat.h"
#include "Auxil.h"
#define N (sizeof(AA)/2)
#define M 3

#define NN (sizeof(v)/sizeof(int))
#define MM 5
int main()
{
	// генерация подмножеств
	setlocale(LC_ALL, "rus");
	char AA[][2] = { "A", "B", "C", "D" };
	std::cout << " - Генератор множества всех подмножеств -" << std::endl;
	std::cout << "Исходное множество: ";
	std::cout << "{ ";
	for (int i = 0; i < sizeof(AA) / 2; i++)
		std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
	std::cout << "}";
	std::cout << std::endl << "Генерация всех подмножеств ";
	combi::subset s1(sizeof(AA) / 2); // создание генератора
	
	int n = s1.getfirst(); // первое (пустое) подмножество
	
	while (n >= 0) // пока есть подмножества
	{
		std::cout << std::endl << "{ ";
		for (int i = 0; i < n; i++)
			std::cout << AA[s1.ntx(i)] << ((i < n - 1) ? ", " : " ");
		std::cout << "}";
		n = s1.getnext(); // cледующее подмножество
	};
	
	std::cout << std::endl << "всего: " << s1.count() << std::endl;
	
	// генерация сочетаний
	char AA2[][2] = { "A", "B", "C", "D", "E" };
	std::cout << std::endl << " --- Генератор сочетаний ---" << std::endl;
	
	std::cout << "Исходное множество: ";
	std::cout << "{ ";
	for (int i = 0; i < sizeof(AA2) / 2; i++)
		std::cout << AA2[i] << ((i < sizeof(AA2) / 2 - 1) ? ", " : " ");
	std::cout << "}";
	std::cout << std::endl << "Генерация сочетаний ";
	combi::xcombination xc(sizeof(AA2) / 2, 3);
	std::cout << "из " << xc.n << " по " << xc.m;
	
	int n2 = xc.getfirst();
	
	while (n2 >= 0)
	{
		std::cout << std::endl << xc.nc << ": { ";
		for (int i = 0; i < n2; i++)
			std::cout << AA2[xc.ntx(i)] << ((i < n2 - 1) ? ", " : " ");
		std::cout << "}";
		n2 = xc.getnext();
	};
	std::cout << std::endl << "всего: " << xc.count() << std::endl;
	
	// генерация перестановок
	char AA3[][2] = { "A", "B", "C", "D" };
	std::cout << std::endl << " --- Генератор перестановок ---" << std::endl;
	std::cout << "Исходное множество: ";
	std::cout << "{ ";
	for (int i = 0; i < sizeof(AA3) / 2; i++)
		std::cout << AA3[i] << ((i < sizeof(AA3) / 2 - 1) ? ", " : " ");
	std::cout << "}";
	std::cout << std::endl << "Генерация перестановок ";
	combi::permutation p(sizeof(AA3) / 2);
	
	__int64 n3 = p.getfirst();
	
	while (n3 >= 0)
	{
		std::cout << std::endl << std::setw(4) << p.np << ": { ";
		for (int i = 0; i < p.n; i++)
			std::cout << AA3[p.ntx(i)] << ((i < p.n - 1) ? ", " : " ");
		std::cout << "}";
		n3 = p.getnext();
	};
	std::cout << std::endl << "всего: " << p.count() << std::endl;
	
	// генерация размещений
	char AA4[][2] = { "A", "B", "C", "D" };
	std::cout << std::endl << " --- Генератор размещений ---";
	std::cout << std::endl << "Исходное множество: ";
	std::cout << "{ ";
	for (int i = 0; i < N; i++)
		std::cout << AA4[i] << ((i < N - 1) ? ", " : " ");
	std::cout << "}";
	std::cout << std::endl << "Генерация размещений из " << N << " по " << M;
	combi::accomodation s(N, M);
	
	int n4 = s.getfirst();
	
	while (n4 >= 0)
	{
		std::cout << std::endl << std::setw(2) << s.na << ": { ";
		for (int i = 0; i < 3; i++)
			std::cout << AA4[s.ntx(i)] << ((i < n4 - 1) ? ", " : " ");
		std::cout << "}";
		n4 = s.getnext();
	};
	std::cout << std::endl << "всего: " << s.count() << std::endl;
	
	
	 //задача об оптимальной загрузке судна

	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	const int count = 25;
	int v[count];

	// Генерация указанного количества случайных чисел и заполнение массива
	for (int i = 0; i < count; ++i) {
		v[i] = std::rand() % 801 + 100;
	}

	int V = 1500,

		c[NN] = { 10, 10, 20, 54, 111, 25,
			  11, 15, 22, 120, 67, 26,
			  14, 18, 100, 90, 83, 27,
			  19, 99, 61, 87, 30, 25,
			  50
		};
	
	short r[MM];

	clock_t t1 = 0, t2 = 0;

	t1 = clock();
	int cc = boat(
		V,   // [in]  максимальный вес груза
		MM,  // [in]  количество мест для контейнеров     
		NN,  // [in]  всего контейнеров  
		v,   // [in]  вес каждого контейнера  
		c,   // [in]  доход от перевозки каждого контейнера     
		r    // [out] результат: индексы выбранных контейнеров  
	);
	t2 = clock();


	std::cout << std::endl << "- Задача о размещении контейнеров на судне";
	std::cout << std::endl << "- общее количество контейнеров    : " << NN;
	std::cout << std::endl << "- количество мест для контейнеров : " << MM;
	std::cout << std::endl << "- ограничение по суммарному весу  : " << V;
	std::cout << std::endl << "- вес контейнеров                 : ";

	for (int i = 0; i < NN; i++)
		std::cout << std::setw(3) << v[i] << " ";
	std::cout << std::endl << "- доход от перевозки              : ";

	for (int i = 0; i < NN; i++)
		std::cout << std::setw(3) << c[i] << " ";
	std::cout << std::endl << "- выбраны контейнеры (0,1,...,m-1): ";

	for (int i = 0; i < MM; i++)
		std::cout << r[i] << " ";
	std::cout << std::endl << "- доход от перевозки              : " << cc;

	std::cout << std::endl << "- общий вес выбранных контейнеров : ";

	int sum = 0;
	for (int i = 0; i < MM; i++)
		sum += v[r[i]];
	std::cout << sum;

	std::cout << std::endl << "- время расчёта алгоритма : " << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);

	return 0;
}
