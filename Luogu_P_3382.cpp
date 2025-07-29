#include <bits/stdc++.h>
using namespace std;

const int N = 15;      // Board size
const int INF = 1000;  // Large value for white's win or depth limit

// Global board state
vector<vector<int>> board(N, vector<int>(N));

// Precomputed lines: all_lines stores lines, lines_per_pos maps positions to line indices
vector<vector<pair<int, int>>> all_lines;
vector<vector<vector<int>>> lines_per_pos(N, vector<vector<int>>(N));

// Generate all possible lines of five consecutive positions
void generate_lines() {
    // Horizontal
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N - 5; j++) {
            vector<pair<int, int>> line;
            for (int k = 0; k < 5; k++) line.push_back({i, j + k});
            all_lines.push_back(line);
        }
    }
    // Vertical
    for (int j = 0; j < N; j++) {
        for (int i = 0; i <= N - 5; i++) {
            vector<pair<int, int>> line;
            for (int k = 0; k < 5; k++) line.push_back({i + k, j});
            all_lines.push_back(line);
        }
    }
    // Diagonal / (slope 1)
    for (int i = 0; i <= N - 5; i++) {
        for (int j = 0; j <= N - 5; j++) {
            vector<pair<int, int>> line;
            for (int k = 0; k < 5; k++) line.push_back({i + k, j + k});
            all_lines.push_back(line);
        }
    }
    // Diagonal \ (slope -1)
    for (int i = 4; i < N; i++) {
        for (int j = 0; j <= N - 5; j++) {
            vector<pair<int, int>> line;
            for (int k = 0; k < 5; k++) line.push_back({i - k, j + k});
            all_lines.push_back(line);
        }
    }
    // Map each position to the lines it belongs to
    for (int idx = 0; idx < all_lines.size(); idx++) {
        for (const auto& p : all_lines[idx]) {
            lines_per_pos[p.first][p.second].push_back(idx);
        }
    }
}

// Check if player has five in a row after placing a stone at (i, j)
bool has_won(int player, int i, int j) {
    for (int line_idx : lines_per_pos[i][j]) {
        bool won = true;
        for (const auto& p : all_lines[line_idx]) {
            if (board[p.first][p.second] != player) {
                won = false;
                break;
            }
        }
        if (won) return true;
    }
    return false;
}

// Generate candidate moves: empty positions near existing stones
vector<pair<int, int>> get_candidates() {
    vector<pair<int, int>> candidates;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                bool near = false;
                for (int di = -2; di <= 2 && !near; di++) {
                    for (int dj = -2; dj <= 2 && !near; dj++) {
                        int ni = i + di, nj = j + dj;
                        if (ni >= 0 && ni < N && nj >= 0 && nj < N && board[ni][nj] != 0) {
                            near = true;
                        }
                    }
                }
                if (near) candidates.push_back({i, j});
            }
        }
    }
    return candidates;
}

// Minimax with alpha-beta pruning
// turn: 0 (black), 1 (white)
// black_moves: number of black moves made so far
int minimax(int turn, int black_moves, int alpha, int beta) {
    // Depth limit to prevent excessive recursion (adjustable)
    if (black_moves > 5) return INF; // Assume win takes ≤5 moves for efficiency

    vector<pair<int, int>> candidates = get_candidates();
    if (candidates.empty()) return INF; // No moves left, black hasn’t won

    if (turn == 0) { // Black's turn (minimize moves)
        int v = INF;
        for (const auto& m : candidates) {
            int i = m.first, j = m.second;
            board[i][j] = 1;
            int val;
            if (has_won(1, i, j)) {
                val = black_moves; // Black wins with this move
            } else {
                val = minimax(1, black_moves, alpha, beta);
            }
            board[i][j] = 0;
            v = min(v, val);
            if (v <= alpha) break;
            beta = min(beta, v);
        }
        return v;
    } else { // White's turn (maximize delay or win)
        int v = -1;
        for (const auto& m : candidates) {
            int i = m.first, j = m.second;
            board[i][j] = 2;
            int val;
            if (has_won(2, i, j)) {
                val = INF; // White wins, black fails
            } else {
                val = minimax(0, black_moves + 1, alpha, beta);
            }
            board[i][j] = 0;
            v = max(v, val);
            if (v >= beta) break;
            alpha = max(alpha, v);
        }
        return v;
    }
}

int main() {
    // Read input
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    // Precompute lines
    generate_lines();

    // Find minimum moves and optimal first moves
    int min_val = INF;
    vector<pair<int, int>> best_moves;
    vector<pair<int, int>> candidates = get_candidates();

    for (const auto& m : candidates) {
        int i = m.first, j = m.second;
        board[i][j] = 1;
        int val;
        if (has_won(1, i, j)) {
            val = 1; // Win in one move
        } else {
            val = minimax(1, 1, -1, INF);
        }
        board[i][j] = 0;
        if (val < min_val) {
            min_val = val;
            best_moves.clear();
            best_moves.push_back({i + 1, j + 1}); // Convert to 1-based
        } else if (val == min_val) {
            best_moves.push_back({i + 1, j + 1});
        }
    }

    // Sort moves by 15*i + j (lexicographical order of 1-based indices suffices)
    sort(best_moves.begin(), best_moves.end());

    // Output result
    cout << min_val << " " << best_moves.size() << endl;
    for (const auto& m : best_moves) {
        cout << m.first << " " << m.second << endl;
    }

    return 0;
}