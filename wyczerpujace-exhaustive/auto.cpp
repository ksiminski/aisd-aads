// Program do wyczerpujace wyszukiwania rozwiazania

#include <iostream>

#define FOREACH(i)  for (i = 0; i < 10; i++)
#define FOREACH_BEZZERA(i)  for (i = 1; i < 10; i++)

using namespace std;

int main (int ile, char ** argumenty)
{
	std::cout << "Program wypisuje rozwiazania kryptarytmu:" << std::endl;
	std::cout << std::endl;
	std::cout << "   KOLO" << std::endl;
	std::cout << "   KOLO" << std::endl;
	std::cout << "   KOLO" << std::endl;
	std::cout << "+  KOLO" << std::endl;
	std::cout << "-------" << std::endl;
	std::cout << "   AUTO" << std::endl;
	std::cout << std::endl;

	// kolo + kolo + kolo + kolo = auto
	ushort K, O, L, A, U, T;
	ushort P1, P2, P3, P4;
	bool jest_rozwiazanie = false;
	int numer_rozwiazania = 1;   

	//      O + O + O + O = O + 10 * P1 (przeniesienie)
	// P1 + L + L + L + L = T + 10 * P2
	// P2 + O + O + O + O = U + 10 * P3
	// P3 + K + K + K + K = A

	FOREACH(O)
	{
		int temp = 4 * O;
		P1 = temp / 10;
		if (O == temp % 10)
		{
			FOREACH(L)
			{
				if (L != O)
				{
					int temp = P1 + 4 * L;
					T = temp % 10;
					P2 = temp / 10;
					if (T != O && T != L)
					{

						//FOREACH (O)
						{
							int temp = P2 + 4 * O;
							U = temp % 10;
							P3 = temp / 10;

							if (U != O && U != L && U != T)
							{
								FOREACH_BEZZERA(K)
								{
									if (K != O && K != L && U && K != T)
									{
										A = P3 + 4 * K;
										if (A < 10 && A != O && A != L && A != U && A != K && A != T)
										{
											// KOLO + KOLO + KOLO + KOLO = AUTO
											int KOLO = (((K * 10) + O) * 10 + L) * 10 + O;
											int AUTO = (((A * 10) + U) * 10 + T) * 10 + O;
											if (4 * KOLO == AUTO)
											{
												cout << "(" << numer_rozwiazania++ << ") "  
													<< KOLO << " + " 
													<< KOLO << " + " 
													<< KOLO << " + " 
													<< KOLO << " = " << AUTO << endl;
												jest_rozwiazanie = true;
											}
											else
												cout << "cos nie tak ...." << endl;
										}
									}
								}
							}
						}
					}
				}
			}  
		}
	}

	if (!jest_rozwiazanie)
		cout << "brak rozwiazania" << endl;

	return 0;
}
