// Exhaustive search to solve a cryptarithm.

#include <iostream>

#define FOREACH(i)  for (i = 0; i < 10; i++)
#define FOREACH_WITHOUT_ZERO(i)  for (i = 1; i < 10; i++)

using namespace std;

int main ()
{
	std::cout << "Program solves the cryptarithm:" << std::endl;
	std::cout << std::endl;
	std::cout << "   SEND " << std::endl;
	std::cout << "   MORE" << std::endl;
	std::cout << "-------" << std::endl;
	std::cout << "  MONEY" << std::endl;
	std::cout << std::endl;

	// send + more = money
	ushort S, E, N, D, M, O, R, Y;
	ushort C1, C2, C3, C4, C5;  // carries
	bool got_solution = false;
	int solution_number = 1;   

	//      D + E = Y + 10 * C1  (carry)
	// C1 + N + R = E + 10 * C2
	// C2 + E + O = N + 10 * C3
	// C3 + S + M = O + 10 * C4
	// C4         = M


	FOREACH(D)
	{
		FOREACH(E)
		{
			if (D != E)
			{
				int sum = D + E;
				C1 = sum / 10;
				Y = sum % 10;
				if (Y != D and Y != E)
				{
					FOREACH(N)
					{
						if (N != D and N != E and N != Y)
						{
							FOREACH(R)
							{
								if (R != N and R != D and R != E and R != Y)
								{
									int sum = C1 + N + R;
									C2 = sum / 10;
									int sum1 = sum % 10;
									if (sum1 == E)
									{
										FOREACH(O)
										{
											if (O != R and O != N and R != D and R != E and R != Y)
											{
												int sum = C2 + E + O;
												int sum1 = sum % 10;
												C3 = sum / 10;
												if (sum1 == N)
												{
													FOREACH_WITHOUT_ZERO(S)
													{
														if (S != O and S != R and S != N and S != D and S != E and S != Y)
														{
															FOREACH_WITHOUT_ZERO(M)
															{
																if (M != S and M != O and M != R and M != N and M != D and M != E and M != Y)
																{
																	int sum = C3 + S + M;
																	int sum1 = sum % 10;
																	C4 = sum / 10;
																	if (sum1 == O)
																	{
																		if (C4 == M)
																		{
																			int SEND = (((S * 10 + E) * 10 + N) * 10 + D);
																			int MORE = (((M * 10 + O) * 10 + R) * 10 + E);
																			int MONEY = (((M * 10 + O) * 10 + N) * 10 + E) * 10 + Y;
																			
																			if (SEND + MORE == MONEY)
																			{
																				cout << "(" << solution_number++ << ") "  
																				<< SEND << " + " 
																				<< MORE << " = " << MONEY << endl;
																				got_solution = true;
																			}
																			else
																			{
																				std::cout << "Well, something went wrong..." << std::endl;
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
	
	 

	if (!got_solution)
		cout << "no solution" << endl;

	return 0;
}
