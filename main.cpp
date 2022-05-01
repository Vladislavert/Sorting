#include <sstream>
#include <vector>
#include <boost/algorithm/string.hpp>

#include "Console.hpp"

#define N 26

//std::vector<std::string> generate(int number) {
//	char a[N + 1];
//	std::vector<std::string> retArray;
//
////	for (int i = 0; i < number / N; ++i)
//	for (int k = 0; k < 2; ++k)
//	{
//		srand(time(nullptr) / 2);
//		for (int i = 0; i < N; i++)         // заполняем по порядку
//			a[i] = 'a' + i;
//		for (int i = N - 1; i > 0; i--)       // перемешиваем случайным образом
//			std::swap(a[i], a[rand() % i]);
//		for (int i = 0; i < N - 1; i++)       // чтобы символы не оставались на своих местах
//			if (a[i] == 'a' + i)
//				std::swap(a[i], a[i++ + 1]);
//		for (int i = 0; i < N; i++)         // выводим на экран
//			std::cout << a[i];
//		a[N] = ' ';
//		std::cout << " " << std::endl;
////		a[N] = ' ';
//		retArray.emplace_back(std::string(a));
//	}
//
//	std::cout << std::endl;
//
//	return (retArray);
//}

/**
 *
 * @param vec вектор для заполнения
 * @param number размерность вектора
 * @param elements размерность элемента вектора
 * @param isRandom генерировать каждый раз случайную последовательность
 */
void generateSequence(std::vector<std::string> &vec, int number, int elements, bool isRandom = false)
{
	std::string str;
	char c;

	if (isRandom == false)
		srand(0);
	else
		srand(time(nullptr) / 2);

	for(int i = 0; i < number; i++)
	{
		for (int j = 0; j < elements; j++)
		{
			c = rand() % 26 + 'A';
			str += c;
		}
		vec.push_back(str);
		str.clear();
	}
}

//template<class Iterator, class Compare>
//void checkSpeed(void (*sort)(Iterator, Iterator, bool, Compare), const std::vector<std::string> &vec)
//{
//	auto start_time = std::chrono::steady_clock::now();
//	sort(std::begin(vec), std::end(vec), false);
//	auto end_time = std::chrono::steady_clock::now();
//
//	auto elapsed_ns = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
//}


template<class Iterator, class Compare>
void checkSpeed(std::function<void(Iterator , Iterator, bool, Compare)> sort, const std::vector<std::string> &vec)
{
	auto start_time = std::chrono::steady_clock::now();
	sort(std::begin(vec), std::end(vec), false);
	auto end_time = std::chrono::steady_clock::now();

	auto elapsed_ns = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
}

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define N 26

#include "Sorting.hpp"

int main()
{
//	Console console;
//	while (console.startConsole()) {}

	// test binary heap

//	int a[] = {1, 10, 5, 13};
//	int a[] = {1, 6, 5, 10};
//	int a[] = {1, 7, 5, 10, 6, 8, 213, 3, -10};
//	std::vector<std::string> array = generate(4096*26);
	std::vector<std::string> array;
	// 4096
	// 4096 * 2
	// 4096 * 4
	// 4096 * 8
	// 4096 * 16
	// 4096 *32

	int number[] = {4096, 4096*2, 4096*4, 4096*8, 4096*16, 4096*32};




	std::ofstream file;

	file.open("../testSpeed/time");

	file << "name_sort" << ";";

	int numberIteration = 1;

	for (int i : number)
	{
		file << i << ";";
		for (int j = 0; j < numberIteration; ++j)
		{
			file << " " << ";";
		}
	}

	file << "\n";


//
//
	std::cout << "array" << std::endl;
//	std::cout << array[0];
	sort::display(std::begin(array), std::end(array));
//


	for (int i = 0; i < 3; ++i)
	{
		generateSequence(array, number[i], 26);
//		for (int k = 0; k < numberIteration; ++k)
//		{
//			auto start_time = std::chrono::steady_clock::now();
//			sort::binaryHeap(std::begin(array), std::end(array));
//			sort::bubbleSort(std::begin(array), std::end(array), false);
//			auto end_time = std::chrono::steady_clock::now();
//
//			auto elapsed_ns = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
//		}
		for (int k = 0; k < numberIteration; ++k)
		{
			file << "insertionSort" << ";";
			auto start_time = std::chrono::steady_clock::now();
			sort::insertionSort(std::begin(array), std::end(array), false);
			auto end_time = std::chrono::steady_clock::now();

			checkSpeed(sort::insertionSort(std::begin(array), std::end(array), false), array);

			auto elapsed_ns = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);

			file << elapsed_ns.count() << ";";
		}
		file << "\n";
		for (int k = 0; k < numberIteration; ++k)
		{
			file << "selectionSort" << ";";
			auto start_time = std::chrono::steady_clock::now();
			sort::selectionSort(std::begin(array), std::end(array), false);
			auto end_time = std::chrono::steady_clock::now();

			auto elapsed_ns = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
			file << elapsed_ns.count() << ";";
		}
		file << "\n";
		for (int k = 0; k < numberIteration; ++k)
		{
			file << "quickSort" << ";";
			auto start_time = std::chrono::steady_clock::now();
			sort::quickSort(std::begin(array), std::end(array), false);
			auto end_time = std::chrono::steady_clock::now();

			auto elapsed_ns = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
			file << elapsed_ns.count() << ";";
		}
		file << "\n";
		for (int k = 0; k < numberIteration; ++k)
		{
			file << "binaryHeap" << ";";
			auto start_time = std::chrono::steady_clock::now();
			sort::binaryHeap(std::begin(array), std::end(array), false);
			auto end_time = std::chrono::steady_clock::now();

			auto elapsed_ns = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
			file << elapsed_ns.count() << ";";
		}
		file << "\n";
	}


//	std::cout << elapsed_ns.count() << " s\n";
//	std::cout << "start" << std::endl;
//	sort::binaryHeap(std::begin(a), std::end(a), true);
//	std::cout << "sort array" << std::endl;
//	sort::display(std::begin(array), std::end(array));

	return (0);
}