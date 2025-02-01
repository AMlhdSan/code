#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int α, β;
    cin >> α >> β;
    vector<vector<bool>> Ω(α + 1, vector<bool>(α + 1, false));
    for (int σ = 0; σ < β; σ++){
        char θ;
        int ζ, η;
        cin >> θ >> ζ >> η;
        if(θ == 'N'){
            if(ζ >= 1 && ζ <= α && η >= 1 && η <= α) Ω[ζ][η] = true;
            int ι[8] = {2, 2, -2, -2, 1, 1, -1, -1};
            int κ[8] = {1, -1, 1, -1, 2, -2, 2, -2};
            for (int λ = 0; λ < 8; λ++){
                int μ = ζ + ι[λ], ν = η + κ[λ];
                if(μ >= 1 && μ <= α && ν >= 1 && ν <= α) Ω[μ][ν] = true;
            }
        } else if(θ == 'R'){
            for (int ξ = 1; ξ <= α; ξ++) Ω[ζ][ξ] = true;
            for (int ο = 1; ο <= α; ο++) Ω[ο][η] = true;
        } else if(θ == 'Q'){
            for (int π = 1; π <= α; π++) Ω[ζ][π] = true;
            for (int ρ = 1; ρ <= α; ρ++) Ω[ρ][η] = true;
            for (int σ_ = ζ, τ = η; σ_ >= 1 && τ >= 1; σ_--, τ--) Ω[σ_][τ] = true;
            for (int υ = ζ, φ = η; υ >= 1 && φ <= α; υ--, φ++) Ω[υ][φ] = true;
            for (int χ = ζ, ψ = η; χ <= α && ψ >= 1; χ++, ψ--) Ω[χ][ψ] = true;
            for (int ω = ζ, Σ = η; ω <= α && Σ <= α; ω++, Σ++) Ω[ω][Σ] = true;
        }
    }
    long long δ = 0;
    for (int Ω1 = 1; Ω1 <= α; Ω1++){
        for (int α2 = 1; α2 <= α; α2++){
            if(Ω[Ω1][α2]) δ++;
        }
    }
    cout << δ << "\n";
    return 0;
}
