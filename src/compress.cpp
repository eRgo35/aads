#include <iostream>
#include <map>

std::pair<double, double> calculate_range(char letter, std::map<char, double> &input_probabilities, std::pair<double, double> &range)
{
    std::map<char, std::pair<double, double>> input_total_probabilities;
    double lower_bound = range.first;
    double upper_bound = 0;

    for (std::pair<char, double> probability : input_probabilities)
    {
        upper_bound += probability.second;
        double up = upper_bound * range.second;
        input_total_probabilities[probability.first] = {lower_bound, up};
        lower_bound = up;
    }

    for (auto i : input_total_probabilities)
    {
        std::cout << i.first << ": (" << i.second.first << ", " << i.second.second << ")" << std::endl;
    }

    return {input_total_probabilities[letter].first, input_total_probabilities[letter].second};
}

int main()
{
    std::string input = "ABAC";
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

    std::map<char, double> input_probabilities;

    for (std::pair<char, int> letter : input_letters)
    {
        input_probabilities[letter.first] = letter.second / omega;
    }

    for (auto i : input_probabilities)
    {
        std::cout << i.first << ": " << i.second << std::endl;
    }

    std::cout << std::endl;

    std::pair<double, double> range = {0, 1};
    range = calculate_range(input[0], input_probabilities, range);

    std::cout << std::endl << range.first << ", " << range.second << std::endl << std::endl;


    range = calculate_range(input[1], input_probabilities, range);

    std::cout << std::endl << range.first << ", " << range.second << std::endl << std::endl;

    range = calculate_range(input[2], input_probabilities, range);

    std::cout << std::endl << range.first << ", " << range.second << std::endl << std::endl;

    range = calculate_range(input[3], input_probabilities, range);
    
    std::cout << std::endl;

    std::cout << "(" << range.first << ", " << range.second << ")" << std::endl;

    return 0;
}