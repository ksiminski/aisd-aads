
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

	const std::size_t LOW      {  50'000'000 };
	const std::size_t MODERATE { 100'000'000 };
	const std::size_t HIGH     { 150'000'000 };

	auto repetitions { 15 };

	int m1, m2, m3;

	std::map<std::size_t, std::map<std::string, std::vector<std::size_t>>> execution_times;


	for (const auto number_of_numbers : { LOW, MODERATE, HIGH })
	{
		std::cout << "n = " << number_of_numbers << std::endl;

		auto numbers = get_random_numbers(number_of_numbers);
		for (decltype(repetitions) i = 0; i < repetitions; i++)
		{        
			auto searched = random_number();

			/////////////////////////
			{
				std::string method { "O(n)" };
				std::cout << method << '\t';

				clock.start();
				m1 = linear_search(numbers, searched);
				clock.stop();

				auto elapsed_time = clock.elapsed_microseconds();
				execution_times[number_of_numbers][method].push_back(elapsed_time);
			}
			/////////////////////////
			{
				std::string method { "O(log n)" };
				std::cout << method << '\t';

				clock.start();
				m2 = binary_search(numbers, searched);
				clock.stop();

				auto elapsed_time = clock.elapsed_microseconds();
				execution_times[number_of_numbers][method].push_back(elapsed_time);
			}
			std::cout << m1 << '\t' << m2 << '\t' << std::endl;
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

