#include "../include/std_lib_facilities.h"

int main() {

    std::cout << "Please enter distances:\n";
    std::vector<double> distances;
    // Each value entered is the distance between
    // two cities along the given route. 
    for(double distance; std::cin >> distance;) {
        distances.push_back(distance);
    }

    if(distances.size() == 0) {
        std::cout << "Empty size vector.\n";
    }
    else {
        double sum{};
        double min{distances[0]};
        double max{distances[0]};

        for(size_t i{}; i < distances.size(); ++i) {
            sum += distances[i];
            if(distances[i] < min) min = distances[i];
            if(distances[i] > max) max = distances[i];
        }

        std::cout << "\nThe sum of distances: "  << sum
                  << "\nThe smallest distance: " << min
                  << "\nThe largest distance: "  << max 
                  << "\nThe mean: " << (sum / distances.size()) << '\n';
    }
    
    return 0;
}