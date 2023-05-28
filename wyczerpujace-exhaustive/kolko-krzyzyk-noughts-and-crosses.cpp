
/* Program wypisuje drzewo gry dla kółka i krzyżyka. */


#include <vector>
#include <iostream>
#include <memory>


 
class position
{
	static const int SIZE = 3; 

	char board [SIZE][SIZE];

	std::vector<std::shared_ptr<position>> children;
	int evaluate(const char symbol);
	std::shared_ptr<position> copy ();
	int evaluation;
	
  public:
	static int number;

	static const char CROSS = 'X';
	static const char NOUGHT = 'O';
	static const char EMPTY = ' ';
	void initialise();

	void insert (const char symbol);
	void insert (const char symbol, int w, int k);
	// ocenia sytuacje ze wzgledu na podany symbol, 
	// gdy symbol wygrywa +1, gdy przegrywa -1, remis 0
	int estimate_for_cross();

	void print();
	void print_leaves();

	int estimate_max();
	int estimate_min();
	~position ();

};

int position::number;

int main(int argc, char * argv[])
{
	position first;
	first.initialise();
	first.number = 0;
	// rozpoczynamy od wstawienia krzyzyka
	first.insert(position::CROSS);

	

	first.print_leaves();
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	auto ocena = first.estimate_max();
	std::cout << "ocena dla gracza rozpoczynajacego: " << ocena << std::endl;
	std::cout << "estimation for starting player:    " << ocena << std::endl;
	

	return 0;
}

void position::print_leaves()
{
	if (children.size() == 0)
	{
		std::cout << std::endl << std::endl;
		std::cout << "===" << ++number << "===" << std::endl << std::endl;

		print();
		return;
	}
	for (auto iter = children.begin(); iter != children.end(); ++iter)
		(*iter)->print_leaves();
}

void position::print()
{
	int w, k;

	std::cout << "+";
	for (k = 0; k < SIZE; k++)
		std::cout << "-+";
	std::cout << std::endl;
	for (w = 0; w < SIZE; w++)
	{
		std::cout << "|";
		for (k = 0; k < SIZE; k++)
			std::cout << board[w][k] << "|";
		std::cout << std::endl;

		std::cout << "+";
		for (k = 0; k < SIZE; k++)
			std::cout << "-+";
		std::cout << std::endl;

	}

}

void position::insert (const char symbol, int w, int k)
{
	board[w][k] = symbol;
}

void position::insert (const char symbol)
{
	// [PL] Najpierw trzeba ocenic sytuacje na planszy, moze juz koniec rozgrywki.
	// [EN] Estimate the board, maybe it's the end.
	evaluation = estimate_for_cross();
	if (evaluation != 0)
		return; // koniec | game over

	int w, k;
	for (w = 0; w < SIZE; w++)
		for (k = 0; k < SIZE; k++)
		{
			if (board[w][k] == EMPTY)
			{
				auto p = copy();
				p->insert(symbol, w, k);
				children.push_back(p);
			}
		}

	char opposite_symbol = symbol == CROSS ? NOUGHT : CROSS;

	for (auto iter = children.begin(); iter != children.end(); ++iter)
		(*iter)->insert(opposite_symbol);
}

std::shared_ptr<position> position::copy()
{
	auto temp = std::shared_ptr<position> (new position);
	int w, k;
	for (w = 0; w < SIZE; w++)
		for (k = 0; k < SIZE; k++)
			temp->board[w][k] = board[w][k];

	return temp;
}

position::~position ()
{
}

int position::estimate_max()
{
	if (children.size() == 0)
		return estimate_for_cross();
	else
	{
		int estimation = -10;
		for (auto iter = children.begin(); iter != children.end(); ++iter)
		{
			int child_estimation = (*iter)->estimate_min();
			if (estimation < child_estimation)
				estimation = child_estimation;

		}
		return estimation;
	}
}

int position::estimate_min()
{
	if (children.size() == 0)
		return estimate_for_cross();
	else
	{
		int estimation = +10;
		for (auto iter = children.begin(); iter != children.end(); ++iter)
		{
			int child_estimation = (*iter)->estimate_max();
			if (estimation > child_estimation)
				estimation = child_estimation;

		}
		return estimation;
	}
}


int position::estimate_for_cross()
{
	if (evaluate(CROSS) == 1)
		return 1;
	if (evaluate(NOUGHT) == 1)
		return -1;
	return 0;
}

int position::evaluate(const char symbol)
{
	int w, k;

	 
	for (w = 0; w < SIZE; w++)
	{
		bool row_present = true;
		for (k = 0; k < SIZE; k++)
		{
			if (board[w][k] != symbol)
				row_present = false;
		}

		if (row_present)
			return 1; 
	}

	for (k = 0; k < SIZE; k++)
	{
		bool column_present = true;
		for (w = 0; w < SIZE; w++)
		{
			if (board[w][k] != symbol)
				column_present = false;
		}

		if (column_present)
			return 1; 
	}

	// przekatne | diagonal
	bool diagonal_present = true;
	for (w = 0; w < SIZE; w++)
	{
		if (board[w][w] != symbol)
			diagonal_present = false;
	}
	if (diagonal_present)
		return 1;

	diagonal_present = true;
	for (w = 0; w < SIZE; w++)
	{
		if (board[w][SIZE - 1 - w] != symbol)
			diagonal_present = false;
	}
	if (diagonal_present)
		return 1;

	return 0;
}
void position::initialise()
{
	int w, k;
	for (w = 0; w < SIZE; w++)
		for (k = 0; k < SIZE; k++)
			board[w][k] = EMPTY;
}


