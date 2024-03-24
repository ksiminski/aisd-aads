/* [PL] Porównanie czasów wyszukania wartości 
 *      w posortowanej tablicy dwiema metodami:
 *      -- wyszukiwaniem liniowym, O(n),
 *      -- wyszukiwaniem połówkowym, O(log n).
 *
 * [EN] Comparision of the search time in 
 *      a sorted array with 
 *      -- linear search, O(n),
 *      -- binary search, O(log n).
 */ 

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>

#include "clock.h"

bool linear_search (const std::vector<int> & numbers, const int searched)
{
	std::size_t size = numbers.size();

	for (std::size_t i = 0; i < size; i++)
	{
		if (numbers[i] == searched)
			return true;
	}
	return false;
}

bool binary_search (const std::vector<int> & numbers, const int searched)
{
	std::size_t size = numbers.size();

	std::size_t left = 0;
	std::size_t right = size - 1;

	while (left <= right)
	{
		auto middle = (left + right) / 2;
		if (numbers[middle] == searched)
			return true;

		if (searched > numbers[middle])
			left = middle + 1;
		else 
			right = middle - 1;
	}
	return false;
}

int random_value ()
{
	static std::default_random_engine engine(std::chrono::system_clock::now().time_since_epoch().count());
	static std::uniform_int_distribution<int> distro (10'000'000, 99'999'999);

	return distro(engine);
}

std::vector<int> generate_numbers(const int size)
{
	std::vector<int> numbers;
	for (int i = 0; i < size; i++)
		numbers.push_back(random_value());

	std::sort (numbers.begin(), numbers.end());

	return numbers;
}

double average (const std::vector<std::size_t>& values)
{
	return (double) std::accumulate(values.begin(), values.end(), 0.0) / values.size();
}

int main ()
{
	ksi::clock stopwatch;

	const std::size_t S  {  50'000'000 };
	const std::size_t M  { 100'000'000 };
	const std::size_t L  { 150'000'000 };
	const std::size_t XL { 300'000'000 };

	auto repetitions { 10 };

	int m1, m2, m3;

	std::map<std::size_t, std::map<std::string, std::vector<std::size_t>>> times;

	for (const auto data_size : { S, M, L, XL })
	{
		std::cout << "data size: n = " << data_size << std::endl;
      std::cout << "---------+----------+--------" << std::endl;
      std::cout << "linear   | binary   |        " << std::endl;
      std::cout << "search   | search   | correct" << std::endl;
      std::cout << "O(n)     | O(log n) | result " << std::endl;
      std::cout << "---------+----------+--------" << std::endl;

		auto numbers = generate_numbers(data_size);
		for (decltype(repetitions) i = 0; i < repetitions; i++)
		{        
			auto searched = random_value();

			/////////////////////////
			{
            std::string method {"linear"};
				stopwatch.start();
				m1 = linear_search(numbers, searched);
				stopwatch.stop();

				auto time = stopwatch.elapsed_microseconds();
				times[data_size][method].push_back(time);
			}
			/////////////////////////
			{
            std::string method {"binary"};
				stopwatch.start();
				m2 = binary_search(numbers, searched);
				stopwatch.stop();

				auto time = stopwatch.elapsed_microseconds();
				times[data_size][method].push_back(time);
			}
			std::cout << m1 << "        | " << m2 << "        | ";
         std::cout << (m1 == m2 ? "OK" : "fadata_sized") << std::endl;
		}
      std::cout << std::endl;
	}

	// [PL] wypisujemy wyniki
   // [EN] print results

	for (const auto & data_size : times)
	{
		std::cout << "n = " << data_size.first  << '\t';
		for (const auto & method : data_size.second)
		{
			std::cout << method.first << ": ";
			auto srednia = average (method.second);
			std::cout << srednia  << " [ms]\t";
		}
		std::cout << std::endl;
	}

	return 0;    
}

