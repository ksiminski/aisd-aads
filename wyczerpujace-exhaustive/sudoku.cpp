
#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

const int MAX = 9;

struct array 
{
	char el[MAX][MAX];
	bool orig[MAX][MAX];

	friend std::ostream & operator<< (std::ostream & s, array & t);
};

std::ostream & operator<< (std::ostream & s, array & t)
{
	int i, j;
	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			s << t.el[i][j];
		}
		s << std::endl;
	}
	return s;
}

class sudoku
{
   public:
   class clock 
   {
      std::chrono::high_resolution_clock _zegar;
      std::chrono::high_resolution_clock::time_point _start {};
      std::chrono::high_resolution_clock::time_point _stop  {};

      public:
      std::chrono::high_resolution_clock::time_point start()
      {
         return _start = _zegar.now();
      }

      std::chrono::high_resolution_clock::time_point stop()
      {
         return _stop = _zegar.now();
      }

      std::size_t elapsed_seconds()
      {
         return (std::chrono::duration_cast<std::chrono::seconds>(_stop - _start)).count();
      }

      std::size_t elapsed_milliseconds()
      {
         return (std::chrono::duration_cast<std::chrono::milliseconds>(_stop - _start)).count();
      }  

   };

   private:
   class validator
   {
      bool el[MAX];
      int number_of_items;
      public:
      validator();
      void reset();
      void add(char);
      bool validate();
   };

   array arr;
   bool solve(int w, int k, array tab);
   bool validation (array & t);
   public:
   std::string outputFile;
   void read_in(const std::string & plik);
   void save_solution (const std::string & plik);
   void print(std::ostream & s);
   bool solve();

};

void help (const std::string & name)
{
	std::cout << "Sudoku solver" << std::endl;
	std::cout << "type to run:" << std::endl;
	std::cout << name << " input_file output_file" << std::endl;

	return;
}

int main(int argc, char * argv[])
{
	if (argc < 3)
	{
		help (argv[0]);
		return 0;
	}

	std::string input (argv[1]);
	std::string output (argv[2]);
	sudoku s;
   sudoku::clock k;
	s.read_in(input);
   std::cout << "---------" << std::endl;
   s.print(std::cout);
   k.start();
	s.solve();
   k.stop();
	s.save_solution(output);
   std::cout << "---------" << std::endl;
   s.print(std::cout);
   std::cout << "---------" << std::endl;
   std::cout << "t = " << k.elapsed_milliseconds() << " ms" << std::endl;
	return 0;
}

bool sudoku::validation(array & t)
{
	int w, k;

	// [PL] sprawdzenie wierszy
	// [EN] check rows
	for (w = 0; w < MAX; w++)
	{
		validator wal;
		for (k = 0; k < MAX; k++)
			wal.add(t.el[w][k]);
		if (wal.validate() == false)
			return false;
	}

	// [PL] sprawdzenie kolumn
	// [EN] check columns
	for (k = 0; k < MAX; k++)
	{
		validator wal;
		for (w = 0; w < MAX; w++)
			wal.add(t.el[w][k]);
		if (wal.validate() == false)
			return false;
	}

	// [PL] sprawdzenie malych kwadratow
	// [EN] check small squares
	int wq, kq;

	for (wq = 0; wq < MAX / 3; wq++)
	{
		for (kq = 0; kq < MAX / 3; kq++)
		{
			validator wal;
			for (w = 0; w < MAX / 3; w++)
			{

				for (k = 0; k < MAX / 3; k++)
				{
					wal.add(t.el[wq * 3 + w][kq * 3 + k]);
				}
			}
			if (wal.validate() == false)
				return false;
		}
	}
	return true;
}
sudoku::validator::validator()
{
	number_of_items = 0;
	reset();
}
bool sudoku::validator::validate()
{
	int i;
	int counter = 0;
	for (i = 0 ; i < MAX; i ++)
		if (el[i])
			counter++;
	return (counter == number_of_items);
}
void sudoku::validator::reset()
{
	int i;
	for (i = 0; i < MAX; i++)
		el[i] = false;
}
void sudoku::validator::add(const char c)
{
	if (c != '0')
	{
		el[c - '1'] = true;
		number_of_items++;
	}
}

bool sudoku::solve(const int w, const int k, array t)
{
	// [PL] usiluje wstawic w miejsce [w][k] kolejne wartosci:
	// [EN] try to put a new value in [w][k]
	if (t.orig[w][k] == false) // [PL] nie ma danej oryginalnej | [EN] empty cell
	{
		for (char c = '1'; c <= '9'; c++)
		{
			t.el[w][k] = c;
			if (validation(t))
			{
				if (w == MAX - 1 && k == MAX - 1)
				{
					arr = t;
					return true;
				}

				if (w <= MAX)
				{
					if (k < MAX - 1)
					{
						if (solve(w, k + 1, t))
							return true;
					}
					else
					{
						if (solve(w + 1, 0, t))
							return true;
					}
				}
			}
		}
	}
	else // [PL] jest dana oryginalna, wiec przesuwam sie dalej | [EN] the cell is not empty, I move forwards
	{
		if (w == MAX - 1 && k == MAX - 1)
		{
			// cout << t << std::endl;
			arr = t;
			return true;
		}
		if (w <= MAX)
		{
			if (k < MAX - 1)
			{
				if (solve(w, k + 1, t))
					return true;

			}
			else
			{
				if (solve(w + 1, 0, t))
					return true;

			}
		}
	}
	return false;
}

bool sudoku::solve()
{

	if (solve(0, 0, arr))
		return true;
	else
		return false;
}

void sudoku::save_solution(const std::string & s)
{
	std::ofstream plik(s.c_str());

	if (plik)
	{
      print(plik);
		plik.close();
	}
}

void sudoku::print(std::ostream & s)
{
   std::stringstream sos; 
   sos << '+';
   for (int i = 0; i < MAX; i++)
   {
      sos << "-+";
   }
   std::string line = sos.str();

   if (s)
   {
      s << line << std::endl;
      for (int i = 0; i < MAX; i++)
      {
         s << '|';
         for (int j = 0; j < MAX; j++)
         {
            if (arr.el[i][j] != '0')
               s << arr.el[i][j];
            else 
               s << ' ';
            s << '|';
         }
         s << std::endl;
         s << line << std::endl;

      }
   }
}

void sudoku::read_in(const std::string & s)
{
	std::ifstream file (s.c_str());

	if (file)
	{
		int i, j;
		for (i = 0; i < MAX; i++)
		{
			std::string line;
			getline(file, line);

			if (line.length() >= MAX)
			{
				for (j = 0; j < MAX; j++)
				{
					arr.el[i][j] = line[j];
					if (arr.el[i][j] != '0')
						arr.orig[i][j] = true;
					else
						arr.orig[i][j] = false;
				}
			}
		}
		file.close();
	}
}
