#include <iostream>
#include <algorithm>
#include <numeric>
#include <random>
#include <chrono>
#include <array>
#include <list>
#include <iterator>
#include <map>

int main() {
    //point 1
    std::uniform_int_distribution distr(1, 10);
    std::default_random_engine engine(std::chrono::steady_clock::now().time_since_epoch().count());
    std::array<int, 10> arr{};
    std::generate(arr.begin(), arr.end(), [&distr, &engine](){return distr(engine);});
    std::cout << "Generated array:  ";
    for(const auto & i : arr) {
        std::cout << i << "\t";
    }
    std::cout << std::endl;

    //point 2
    std::list<int> sums;
    std::partial_sum(arr.begin(), arr.end(), std::back_inserter(sums));

    //point 3
    std::cout << "Partial sums:     ";
    std::copy(std::begin(sums), std::end(sums), std::ostream_iterator<int>(std::cout, "\t"));
    std::cout << std::endl;

    //point 4
    std::map<int, bool> even;
    std::for_each(std::begin(sums), std::end(sums), [&even](auto x){even[x] = ! (x % 2);});
    std::cout << "Is even:          ";
    for(const auto & i : even) {
        std::cout << std::boolalpha << i.second << "\t";
    }
    std::cout << std::endl;

    return 0;
}
