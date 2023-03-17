

/* [PL] Program porównuje czas wyszukania elementów w posortowanej tablicy z wykorzystaniem wyszukiwania liniowego i wyszukiwania połówkowego.
   [EN] The program compares execution times of linear and binary search in a sorted array. */

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>

#include "clock.h"


/** [PL] wyszukiwanie liniowe 
	[EN] linear search 
	@return true: znaleziona | found 
			false: nieznaleziona | not found
    */
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

/** [PL] wyszukiwanie połówkowe 
	[EN] binary search 
	@return true: znaleziona | found 
			false: nieznaleziona | not found 
	*/
bool binary_search (const std::vector<int> & numbers, const int search)
{
	std::size_t size = numbers.size();

	std::size_t left = 0;
	std::size_t right = size - 1;

	while (left <= right)
	{
		auto middle = (left + right) / 2;
		if (numbers[middle] == search)
			return true;

		if (search > numbers[middle])
			left = middle + 1;
		else 
			right = middle - 1;
	}
	return false;
}

/** @return [PL] Funkcja zwraca wartość losową z rozkładu normalnego. | [EN] The function returns a random uniform numbers. */
int random_number ()
{
	static std::default_random_engine engine(std::chrono::system_clock::now().time_since_epoch().count());
	static std::uniform_int_distribution<int> distribution (10000000, 99999999);

	return distribution(engine);
}


std::vector<int> get_random_numbers(const int size)
{
	std::vector<int> numbers;
	for (int i = 0; i < size; i++)
		numbers.push_back(random_number());

	std::sort (numbers.begin(), numbers.end());

	return numbers;
}

double average (const std::vector<std::size_t>& values)
{
	return (double) std::accumulate(values.begin(), values.end(), 0.0) / values.size();
}

int main ()
{
	ksi::clock clock;

	/** [PL] rozmiary trzech tablic 
        [EN] sizes of three arrays */
	const std::size_t LOW      {  50'000'000 };
	const std::size_t MODERATE { 100'000'000 };
	const std::size_t HIGH     { 150'000'000 };

	auto repetitions { 15 };

	int number_found_linear, number_found_binary, m3;

	std::map<std::size_t, std::map<std::string, std::vector<std::size_t>>> execution_times;


	for (const auto number_of_numbers : { LOW, MODERATE, HIGH })
	{
		std::cout << "n = " << number_of_numbers << std::endl;

		/** [PL] utworzenie tablicy
			[EN] create an array */
		auto numbers = get_random_numbers(number_of_numbers);
		for (decltype(repetitions) i = 0; i < repetitions; i++)
		{        
			/** [PL] liczba do wyszukania w tablicy
				[EN] a number to search in an array */
			auto searched = random_number();

			/////////////////////////
			{
				std::string method { "O(n)" };
				std::cout << method << '\t';

				clock.start();
				number_found_linear = linear_search(numbers, searched);
				clock.stop();

				auto elapsed_time = clock.elapsed_microseconds();
				execution_times[number_of_numbers][method].push_back(elapsed_time);
			}
			/////////////////////////
			{
				std::string method { "O(log n)" };
				std::cout << method << '\t';

				clock.start();
				number_found_binary = binary_search(numbers, searched);
				clock.stop();

				auto elapsed_time = clock.elapsed_microseconds();
				execution_times[number_of_numbers][method].push_back(elapsed_time);
			}
			std::cout << number_found_linear << '\t' << number_found_binary << '\t' << std::endl;
		}
	}

	// final results:

	for (const auto & number_of_numbers : execution_times)
	{
		std::cout << "n = " << number_of_numbers.first  << '\t';
		for (const auto & method : number_of_numbers.second)
		{
			std::cout << method.first << ": ";
			auto avg = average (method.second);
			std::cout << avg  << " [ms]\t";
		}
		std::cout << std::endl;
	}

	return 0;    
}

