
import numpy as np
import matplotlib.pyplot as plt
import math

bardzo_male_x = range(100);
male_x        = range(120);
srednie_x     = range(200);
duze_x        = range(360);
wielkie_x     = range(600);
olbrzymie_x   = range(2000); 

_5N  = [5 * n   for n in olbrzymie_x     ]
_N2  = [n **  2 for n in olbrzymie_x     ]
_N3  = [n **  3 for n in olbrzymie_x     ]
_N10 = [n ** 10 for n in olbrzymie_x     ]
_2N  = [2 ** n  for n in wielkie_x       ]
_3N  = [3 ** n  for n in duze_x          ]
_Ns  = [math.factorial(n) for n in male_x]
_NN  = [n ** n  for n in bardzo_male_x   ]

liczba_ns_w_dobie      = 24 * 60 * 60 * 1000000000;
liczba_ns_w_roku       = liczba_ns_w_dobie * 365.2422;
wiek_Wszechswiata_lata = 13820000000; # w latach
wiek_Wszechswiata_ns   = wiek_Wszechswiata_lata * liczba_ns_w_roku;

_doba     = [liczba_ns_w_dobie       for n in olbrzymie_x];
_rok      = [liczba_ns_w_roku        for n in olbrzymie_x];
_wszech   = [wiek_Wszechswiata_ns    for n in olbrzymie_x];


plt.xscale('log',base=10);
plt.yscale('log');

plt.plot(bardzo_male_x, _NN,           label="n^n");
plt.plot(male_x,        _Ns,           label="n!");
plt.plot(duze_x,        _3N,           label="3^n");
plt.plot(wielkie_x,     _2N,           label="2^n");

plt.plot(olbrzymie_x,   _N10,    '--', label="n^10");
plt.plot(olbrzymie_x,   _N3 ,    '--', label="n³");
plt.plot(olbrzymie_x,   _N2 ,    '--', label="n²");
plt.plot(olbrzymie_x,   _5N ,    '--', label="5n");

plt.plot(olbrzymie_x,   _wszech, ':',  label="ns od Wielkiego Wybuchu");
plt.plot(olbrzymie_x,   _rok   , ':',  label="ns w roku");
plt.plot(olbrzymie_x,   _doba  , ':',  label="ns w dobie");


plt.legend();

plt.show();

