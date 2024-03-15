#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <iostream>

std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

bool is_floating(std::string const& s)
{
    
}

int main()
{
    std::string user_input;
    std::getline (std::cin, user_input);
    
    std::vector<std::string> splitted_user_input = split_string(user_input);

  return 0;
}