
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm> 
#include <random>
#include <chrono>
#include <map>



#define debug(x)   std::cerr << __FILE__ << " (" << __LINE__ << ") " << #x << " == " << x << std::endl; 
 
 
int main ()
{
    std::vector<std::string> names
    {
		"Oliver", "Elijah", "William", "James", "Benjamin", "Lucas", "Henry", "Alexander", "Mason", "Michael", "Ethan", "Daniel", "Jacob", "Logan", "Jackson", "Levi", "Sebastian", "Mateo", "Jack", "Owen", "Theodore", "Aiden", "Samuel", "Joseph", "John", "David", "Wyatt", "Matthew", "Luke", "Asher", "Carter", "Julian", "Grayson", "Leo", "Jayden", "Gabriel", "Isaac", "Lincoln", "Anthony", "Hudson", "Dylan", "Ezra", "Thomas", "Olivia", "Emma", "Ava", "Charlotte", "Sophia", "Amelia", "Isabella", "Mia", "Evelyn", "Harper", "Camila", "Gianna", "Abigail", "Luna", "Ella", "Elizabeth", "Sofia", "Emily", "Avery", "Mila", "Scarlett", "Eleanor", "Madison", "Layla", "Penelope", "Aria", "Chloe", "Grace", "Ellie", "Nora", "Hazel", "Zoey", "Riley", "Victoria", "Lily", "Aurora", "Violet", "Nova", "Hannah", "Emilia"
    };
    
    std::vector<std::string> surnames
    {
        "White", "Black", "Red", "Green", "Blue", "Yellow", "Brown", "Pink", "Violet", "Orange", "Grey", "Purple", "Sapphire", "Silver", "Gold", "Crimson", "Azure", "Magenta", "Cyan", "Indigo", "Turquoise", "Ultramarine"
    };
    
    const int N { 500 };
    const std::string FILE_NAME { "persons" };
    
    std::uniform_int_distribution<int> distro_names (0, names.size() - 1);
    std::uniform_int_distribution<int> distro_surnames (0, surnames.size() - 1);
    
    std::default_random_engine engine;
    engine.seed(std::chrono::system_clock::now().time_since_epoch().count());
    
    
    std::ofstream file (FILE_NAME);
    if (file)
    {
        for (int i = 0; i < N; i++)
        {
            file << i + 1 << "\t" << names[distro_names(engine)]
                 << "\t" << surnames[distro_surnames(engine)] 
                 << std::endl;
        }
    }
    return 0;    
}



 
