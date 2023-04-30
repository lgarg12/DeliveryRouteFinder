#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

// Sample data
struct Package {
    int id;
    std::string address;
};

struct House {
    int id;
    std::string address;
};

std::vector<Package> packages = {{1, "123 Main St"}, {2, "456 Elm St"}, {3, "789 Oak St"}};
std::vector<House> houses = {{1, "111 Maple Ave"}, {2, "222 Pine St"}, {3, "333 Cedar Blvd"}};

// Sample distance function
double calculate_distance(const std::string& address1, const std::string& address2) {
    // Returns the distance between two addresses
    return std::abs(address1.length() - address2.length()); // Sample distance calculation
}

// Step 3: Calculate the distance matrix
std::unordered_map<int, std::unordered_map<int, double>> distance_matrix;
void calculate_distance_matrix() {
    for (const auto& package : packages) {
        distance_matrix[package.id] = {};
        for (const auto& house : houses) {
            double distance = calculate_distance(package.address, house.address);
            distance_matrix[package.id][house.id] = distance;
        }
    }
}

// Step 4: Sort the packages
std::vector<Package> sorted_packages;
void sort_packages() {
    sorted_packages = packages;
    std::sort(sorted_packages.begin(), sorted_packages.end(),
              [&](const Package& p1, const Package& p2) {
                  return *std::min_element(distance_matrix[p1.id].begin(), distance_matrix[p1.id].end(),
                                           [](const auto& a, const auto& b) {
                                               return a.second < b.second;
                                           }) <
                         *std::min_element(distance_matrix[p2.id].begin(), distance_matrix[p2.id].end(),
                                           [](const auto& a, const auto& b) {
                                               return a.second < b.second;
                                           });
              });
}

// Step 5-7: Create the optimized route
std::vector<int> route;
void create_optimized_route() {
    route.push_back(0); // Start at distribution center
    for (const auto& package : sorted_packages) {
        for (const auto& house_distance : distance_matrix[package.id]) {
            if (std::find(route.begin(), route.end(), house_distance.first) == route.end()) {
                route.push_back(house_distance.first);
            }
        }
        route.push_back(package.id);
    }
}

// Step 8: Print the optimized route
void print_optimized_route() {
    for (const auto& step : route) {
        if (step == 0) {
            std::cout << "Starting at distribution center" << std::endl;
        } else if (step <= houses.size()) {
            std::cout << "Delivering to house " << houses[step - 1].id << " at " << houses[step - 1].address << std::endl;
        } else {
            std::cout << "Delivering package " << sorted_packages[step - houses.size() - 1].id << " to "
                      << sorted_packages[step - houses.size() - 1].address << std::endl;
        }
    }
}

int main() {
    calculate_distance_matrix();
    sort_packages();
    create_optimized_route();
    print_optimized_route();
    return 0;
}