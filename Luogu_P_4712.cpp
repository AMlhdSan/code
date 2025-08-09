#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Predator {
    long long a;
    int r;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    long long a0;
    std::cin >> n >> a0;

    std::vector<Predator> predators(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> predators[i].a >> predators[i].r;
    }

    std::vector<long double> demanded_biomass(n + 1, 0.0);

    for (int i = n - 1; i >= 0; --i) {
        int organism_idx = i + 1;
        
        long double survival_biomass_need = 5.0 * predators[i].a;
        long double predation_biomass_need = demanded_biomass[organism_idx];
        
        long double total_biomass_ingested = std::max(survival_biomass_need, predation_biomass_need);
        
        int prey_idx = predators[i].r;
        demanded_biomass[prey_idx] += total_biomass_ingested;
    }

    if (demanded_biomass[0] > a0) {
        std::cout << -1 << std::endl;
        return 0;
    }

    long double remaining_biomass = (long double)a0 - demanded_biomass[0];

    for (int i = 0; i < n; ++i) {
        int organism_idx = i + 1;
        long double total_biomass_ingested = std::max(5.0L * predators[i].a, demanded_biomass[organism_idx]);
        remaining_biomass += total_biomass_ingested - demanded_biomass[organism_idx];
    }

    long double max_energy = remaining_biomass / 5.0;

    std::cout << std::fixed << std::setprecision(7) << max_energy << std::endl;

    return 0;
}