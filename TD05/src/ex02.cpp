#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::string random_name(size_t size)
{
    std::string name {""};
    // Optimisation pour que la chaîne de caractère ne réalloue pas de la mémoire à chaque caractère ajouté
    // https://cplusplus.com/reference/string/string/reserve/
    name.reserve(size);
    for(size_t i {0}; i < size; ++i) {
        name.push_back('A' + std::rand() % 26);
    }
    return name;
}

std::vector<std::pair<std::string, float>> get_robots_fix(size_t size)
{
    std::vector<std::pair<std::string, float>> robots_fix {};
    // Meme optimisation que dans random_name()
    // https://cplusplus.com/reference/vector/vector/reserve/
    robots_fix.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        // random name 
        std::string robotName { random_name(2) };
        // random cost
        float cost {static_cast<float>(std::rand()) / RAND_MAX * 1000.0f};
        robots_fix.push_back(std::make_pair(robotName, cost));
    }
    return robots_fix;
}

std::unordered_map<std::string, std::vector<float>> robots_fixes_mapping (std::vector<std::pair<std::string, float>> const& robots_fixes)
{
    std::unordered_map<std::string, std::vector<float>> output_map{};

    for (std::pair<std::string, float> pair : robots_fixes)
    {
        auto key {output_map.find(pair.first)};

        if (key == output_map.end())
        {
            std::vector<float> fix {pair.second};
            output_map.insert(std::make_pair(pair.first, fix));
        }
        else
        {
            (*key).second.push_back(pair.second);
        }
    }
    return output_map;
}
// PROTOCOL
// create empty map
// for each pair of entry vector,
//  first member of pair is key (== robot's name is the map's key)
//      if key isn't in map
//          create a vector with second member of the pair
//          insert pair in output map, composed of robot name (first element of entry pair, already as string) and fix in float vector (created in line above)
//      else
//          add second member in the map (next to the key)

float sum_vec_floats (std::vector<float> vec)
{
    float sum{};

    for (float nbr : vec)
    {
        sum+=nbr;
    }

    return sum;
}

void fixes_sum (std::unordered_map<std::string, std::vector<float>> map)
{
    for (std::pair<std::string, std::vector<float>> pair : map)
    {
        std::cout << "Robot name : " << pair.first << std::endl;
        std::cout << "Total cost of fixes : " << sum_vec_floats(pair.second) << std::endl;
    }
    
}
// PROTOCOL
// for each pair in map
//      print out first member of pair (robot name)
//       print out sum of second member of pair

int main()
{
    int nbr_of_robots = 4;
    std::vector<std::pair<std::string, float>> robots_fixes = get_robots_fix(nbr_of_robots);
    std::unordered_map<std::string, std::vector<float>> robots_map = robots_fixes_mapping(robots_fixes);
    fixes_sum(robots_map);

    return 0;
}