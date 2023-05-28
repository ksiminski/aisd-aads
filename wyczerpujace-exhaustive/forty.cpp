// Exhaustive search to solve a cryptarithm.

#include <iostream>

#define FOREACH(i)  for (i = 0; i < 10; i++)
#define FOREACH_WITHOUT_ZERO(i)  for (i = 1; i < 10; i++)

using namespace std;

int main ()
{
	std::cout << "Program solves the cryptarithm:" << std::endl;
	std::cout << std::endl;
	std::cout << "  FORTY " << std::endl;
	std::cout << "    TEN" << std::endl;
	std::cout << "    TEN" << std::endl;
	std::cout << "-------" << std::endl;
	std::cout << "  SIXTY" << std::endl;
	std::cout << std::endl;

	// forty + ten + ten = sixty
	ushort F, O, R, T, Y, E, N, S, I, X;
	ushort C1, C2, C3, C4, C5;  // carries
	bool got_solution = false;
	int solution_number = 1;   

	//      Y + N + N = Y + 10 * C1  (carry)
	// C1 + T + E + E = T + 10 * C2
	// C2 + R + T + T = X + 10 * C3
	// C3 + O         = I + 10 * C4
	// C4 + F         = S


	FOREACH(Y)
	{
		FOREACH(N)
		{
			if (Y != N)
			{
				int sum = Y + N + N;
				C1 = sum / 10;
				int sum1 = sum % 10;
				if (Y == sum1)
				{
					FOREACH_WITHOUT_ZERO(T)
					{
						if (T != Y and T != N)
						{
							FOREACH(E)
							{
								if (E != T and E != T and E != N)
								{
									int sum = C1 + T + E + E;
									C2 = sum / 10;
									int sum1 = sum % 10;
									if (sum1 == T)
									{
										FOREACH(R)
										{
											if (R != Y and R != N and R != T and R != E)
											{
												int sum = C2 + R + T + T;
												X = sum % 10;
												C3 = sum / 10;
												if (X != R and X != Y and X != N and X != T and X != E)
												{
													FOREACH(O)
													{
														if (O != X and O != R and O!= Y and O != N and O!= T and O!= E)
														{
															int sum = C3 + O;
															I = sum % 10;
															C4 = sum / 10;
															if (I != O and I != X and I != R and I != Y and I != N and I!= T and I!= E)
															{
																FOREACH_WITHOUT_ZERO(F)
																{
																	if (F != I and F != O and F != X and F != R and F != Y and F != N and F!= T and F!= E)
																	{
																		S = C4 + F;
																		if (S != F and S != I and S != O and S != X and S != R and S != Y and S != N and S != T and S != E and S != 0 and S < 10)
																		{
																			int FORTY = (((F * 10 + O) * 10 + R) * 10 + T) * 10 + Y;
																			int TEN = (T * 10 + E) * 10 + N;
																			int SIXTY = (((S * 10 + I) * 10 + X) * 10 + T) * 10 + Y;
																			
																			if (FORTY + TEN + TEN == SIXTY)
																			{
																				cout << "(" << solution_number++ << ") "  
																				<< FORTY << " + " 
																				<< TEN << " + " 
																				<< TEN << " = " << SIXTY << endl;
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
