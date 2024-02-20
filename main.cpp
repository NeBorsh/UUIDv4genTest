#include "other.h"

int main(int argc, char const *argv[])
{
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1; i++)
    {
        std::cout << generate_uuid_v4() << std::endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time: " << elapsed.count() << " sec" << std::endl;
    
    std::cin.get();
    return 0;
}
