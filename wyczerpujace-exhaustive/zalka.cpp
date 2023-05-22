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
	std::cout << "  ZALKA" << std::endl;
	std::cout << std::endl;

	// kolo + kolo + kolo + kolo = zalka
	ushort K, O, L, A, Z;
	ushort P1, P2, P3, P4;
	bool jest_rozwiazanie = false;
	int numer_rozwiazania = 1;


	//      O + O + O + O = A + 10 * P1 (przeniesienie)
	// P1 + L + L + L + L = K + 10 * P2
	// P2 + O + O + O + O = L + 10 * P3
	// P3 + K + K + K + K = A + 10 * P4
	// P4                 = Z

	FOREACH(O)
	{
		int temp = 4 * O;
		P1 = temp / 10;
		A = temp % 10;
		if (A == O)
		{
			FOREACH(L)
			{
				if (L != O)
				{
					int temp = P1 + 4 * L;
					K = temp % 10;
					P2 = temp / 10;
					if (K != O && K != L && K != A)
					{

						//FOREACH (O)
						{
							int temp = P2 + 4 * O;

							P3 = temp / 10;

							if (L == temp % 10)
							{
								//FOREACH_BEZZERA(K)
								if (K != 0)
								{
									if (K != O && K != L)
									{
										int temp = P3 + 4 * K;
										if (temp % 10 == A)
										{
											Z = temp / 10;
											if (Z != K && Z != O && Z != L && Z != A)
											{
												// KOLO + KOLO + KOLO + KOLO = ZALKA
												int KOLO  =  (((K * 10) + O) * 10 + L) * 10 + O;
												int ZALKA = ((((Z * 10) + A) * 10 + L) * 10 + K) * 10 + A;
												if (4 * KOLO == ZALKA)
												{
													cout << "(" << numer_rozwiazania++ << ") "  
														<< KOLO << " + " 
														<< KOLO << " + " 
														<< KOLO << " + " 
														<< KOLO << " = " << ZALKA << endl;
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
	}

	if (!jest_rozwiazanie)
		cout << "brak rozwiazania" << endl;

	return 0;
}
