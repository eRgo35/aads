#include <iostream>
#include <map>
#include <random>
#include <iomanip>

std::pair<long double, long double> calculate_range(char letter, std::map<char, long double> &input_probabilities, std::pair<long double, long double> &range)
{
    std::map<char, std::pair<long double, long double>> input_total_probabilities;
    long double lower_bound = range.first;
    long double upper_bound = range.second;
    long double range_length = range.second - range.first;

    for (std::pair<char, long double> probability : input_probabilities)
    {
        long double probability_range = range_length * probability.second;
        input_total_probabilities[probability.first] = {lower_bound, lower_bound + probability_range};
        lower_bound += probability_range;
    }

    for (auto i : input_total_probabilities)
    {
        std::cout << i.first << ": (" << i.second.first << ", " << i.second.second << ")" << std::endl;
    }

    return {input_total_probabilities[letter].first, input_total_probabilities[letter].second};
}

int main(int argc, char* argv[])
{
    std::string input = "BACA";
    double omega = input.length();
    std::map<char, int> input_letters;

    for (char letter : input)
    {
        input_letters[letter]++;
    }

    for (auto i : input_letters)
    {
        std::cout << i.first << ": " << i.second << std::endl;
    }

    std::cout << std::endl;

    std::map<char, long double> input_probabilities;

    for (std::pair<char, int> letter : input_letters)
    {
        input_probabilities[letter.first] = letter.second / omega;
    }

    for (auto i : input_probabilities)
    {
        std::cout << i.first << ": " << i.second << std::endl;
    }

    std::cout << std::endl;

    std::pair<long double, long double> range = {0, 1};

    for (char letter : input)
    {
        range = calculate_range(letter, input_probabilities, range);
        std::cout << std::endl << std::setprecision(128) << "(" << range.first << ", " << range.second << ")" << std::endl << std::endl;
    }

    std::cout << "---------------------------------------------" << std::endl << std::endl;

    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_real_distribution<long double> distr(range.first, range.second);

    std::cout << distr(generator) << std::endl;

    return 0;
}
