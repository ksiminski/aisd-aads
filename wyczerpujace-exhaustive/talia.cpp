// Program do wyczerpujace wyszukiwania rozwiazania

 
#include <iostream>

#define FOREACH(i)  for (i = 0; i < 10; i++)
#define FOREACH_BEZZERA(i)  for (i = 1; i < 10; i++)

using namespace std;

int main (int ile, char ** argumenty)
{
	std::cout << "Program wypisuje rozwiazania kryptarytmu:" << std::endl;
	std::cout << std::endl;
	std::cout << "    PIK" << std::endl;
	std::cout << "   KIER" << std::endl;
	std::cout << "   KARO" << std::endl;
	std::cout << "+ TREFL" << std::endl;
	std::cout << "-------" << std::endl;
	std::cout << "  TALIA" << std::endl;
	std::cout << std::endl;


	// PIK + KIER + KARO + TREFL = TALIA
	ushort P, I, K, E, R, A, O, T, F, L;
	ushort P1, P2, P3, P4;
	bool jest_rozwiazanie = false;
	int numer_rozwiazania = 1;


	//      K + R + O + L = A + 10 * P1 (przeniesienie)
	// P1 + I + E + R + F = I + 10 * P2
	// P2 + P + I + A + E = L + 10 * P3
	// P3     + K + K + R = A + 10 * P4
	// P4             + T = T 

	FOREACH_BEZZERA(K)
	{
		FOREACH(R)
		{
			if (R != K)
			{
				FOREACH(O) 
				{
					if (O != K && O != R)
					{
						FOREACH (L)
						{
							if (L != K && L != R && L != O)
							{
								int suma1 = K + R + O + L;
								A = suma1 % 10;
								P1 = suma1 / 10;
								if (A != K && A != R && A != O && A != L)
								{
									FOREACH(I) // P1 + I + E + R + F = I + 10 * P2
									{
										if (I != K && I != R && I != O && I != L && I != A)
										{
											FOREACH(E)
											{
												if (E != K && E != R && E != O && E != L && E != A && E != I)
												{
													FOREACH(F)
													{
														if (F != K && F != R && F != O && F != L && F != A && F != I && F != E)
														{
															int suma2 = P1 + I + E + R + F;
															if (I == suma2 % 10)
															{
																P2 = suma2 / 10;
																// P2 + P + I + A + E = L + 10 * P3
																FOREACH_BEZZERA (P)
																{
																	if(P != K && P != R && P != O && P != L 
																			&& P != A && P != I && P != E && P != F)
																	{
																		int suma3 = P2 + P + I + A + E;
																		if (suma3 % 10 == L)
																		{
																			P3 = suma3 / 10;
																			int suma4 = P3 + K + K + R;
																			if (suma4 % 10 == A)
																			{
																				P4 = suma4 / 10;
																				FOREACH_BEZZERA (T)
																				{ 
																					if(T != K && T != R && T != O && T != L 
																							&& T != A && T != I && T != E && T != F
																							&& T != P)
																					{
																						if (P4 + T == T) 
																						{
																							// PIK + KIER + KARO + TREFL = TALIA
																							int pik = ((P * 10) + I ) * 10 + K;
																							int kier = (((K * 10) + I) * 10 + E) * 10 + R;
																							int karo = (((K * 10) + A) * 10 + R) * 10 + O;
																							int trefl = ((((T * 10) + R) * 10 + E) * 10 + F) * 10 + L;
																							int talia = ((((T * 10) + A) * 10 + L) * 10 + I) * 10 + A;

																							if (pik + kier + karo + trefl == talia)
																							{
																								cout << "(" << numer_rozwiazania++ << ") "  
																									<< pik << " + " 
																									<< kier << " + " 
																									<< karo << " + " 
																									<< trefl << " = " << talia << endl;
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
