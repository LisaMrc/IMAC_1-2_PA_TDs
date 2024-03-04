#include <iostream>

int main() {

    float float1;
    float float2;
    float float3;

    std::cout << "Enter three float values :";
    std::cin >> float1 >> float2 >> float3;

    float sum{float1 + float2 + float3};
    float average{sum/3};

    std::cout << "Sum :" << sum << std::endl;
    std::cout << "Average :" << average << std::endl;

    return 0;
}