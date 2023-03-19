
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm> 
#include <random>
#include <chrono>
#include <map>


// #include <memory>
 

#define debug(x)   std::cerr << __FILE__ << " (" << __LINE__ << ") " << #x << " == " << x << std::endl; 
 
 

 
 
int main ()
{
    std::vector<std::string> imiona
    {
       "Antoni", "Jakub", "Jan", "Szymon", "Aleksander", "Filip", "Mikołaj", "Wojciech", "Adam", "Stanisław", "Michał", "Wiktor", "Piotr", "Nikodem", "Igor", "Ignacy", "Tymon", "Miłosz", "Maksymilian", "Tymoteusz", "Mateusz", "Bartłomiej", "Krzysztof", "Julian", "Tomasz", "Gabriel", "Hubert", "Fabian", "Natan", "Paweł", "Kamil", "Ksawery", "Bruno", "Borys", "Kajetan", "Artur", "Adrian", "Olaf", "Krystian", "Sebastian", "Cezary", "Grzegorz", "Daniel", "Eryk", "Tadeusz", "Błażej", "Łukasz", "Witold", "Rafał", "Henryk", "Tobiasz", "Damian"
       ,
       "Zuzanna", "Julia", "Maja", "Zofia", "Hanna", "Alicja", "Maria", "Amelia", "Oliwia", "Aleksandra", "Wiktoria", "Emilia", "Laura", "Natalia", "Pola", "Liliana", "Iga", "Marcelina", "Anna", "Helena", "Kornelia", "Klara", "Jagoda", "Łucja", "Barbara", "Małgorzata", "Joanna", "Aniela", "Izabela", "Kalina", "Marta", "Róża", "Katarzyna", "Ewa", "Eliza", "Klaudia", "Rozalia", "Dominika", "Adrianna", "Patrycja", "Urszula", "Melania", "Malwina", "Marianna", "Lidia", "Liwia", "Aurelia", "Olga", "Daria", "Kamila", "Bianka", "Dorota", "Gaja", "Ada", "Apolonia", "Wanda", "Diana", "Dagmara", "Jowita", "Inga", "Jagna", "Agnieszka", "Ida", "Luiza", "Monika", "Emma", "Jadwiga"
    };
    
    std::vector<std::string> nazwiska
    {
        "Nowak", "Wójcik", "Kowalczyk", "Woźniak", "Mazur", "Krawczyk", "Kaczmarek", "Zając", "Król", "Wróbel", "Wieczorek", "Dudek", "Adamczyk", "Stępień", "Pawlak", "Sikora", "Walczak", "Szewczyk", "Pietrzak", "Włodarczyk", "Kubiak", "Kołodziej", "Sobczak", "Mróz", "Szulc"
    };
    
    const int N { 500 };
    const std::string PLIK { "osoby" };
    
    std::uniform_int_distribution<int> rozklad_imion (0, imiona.size() - 1);
    std::uniform_int_distribution<int> rozklad_nazwisk (0, nazwiska.size() - 1);
    
    std::default_random_engine silnik;
    silnik.seed(std::chrono::system_clock::now().time_since_epoch().count());
    
    
    std::ofstream plik (PLIK);
    if (plik)
    {
        for (int i = 0; i < N; i++)
        {
            plik << i + 1 << "\t" << imiona[rozklad_imion(silnik)]
                 << "\t" << nazwiska[rozklad_nazwisk(silnik)] 
                 << std::endl;
        }
    }
    return 0;    
}



 
