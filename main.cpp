// trunc8 did this

// O(n^3) solution but survives most fail cases

#include "helper.h"

int main() {
  std::vector< std::vector<char> > labyrinth;

  std::ifstream infile("labyrinth.txt");
  std::string line;

  while (getline(infile, line)) {

    std::vector<char> row;

    std::string::iterator it;    
    for (it = line.begin(); it != line.end();
                                   it++) {
      // Traversing the string
      row.push_back(*it);
    }
    labyrinth.push_back(row);
  }
  int N_ROWS = labyrinth.size();
  int N_COLS = labyrinth[0].size();

  // MAX_EVER is used to track when to print the final labyrinth
  int MAX_EVER = INT_MAX;

  // construct a matrix to keep track of visited cells
  std::vector<std::vector<int> > visited(
    N_ROWS, std::vector<int>(N_COLS));

  int max_dist = 0;
  int prev_max_dist = 0;
  std::pair<int, char> BEST_PT;
  for (int i = 0; i < N_ROWS; i++) {
    for (auto it = labyrinth[i].begin();
        it != labyrinth[i].end(); it++) {
      if (*it == '.') {
        int j = it - labyrinth[i].begin();
        dfs(labyrinth, visited, i, j, max_dist, 1, MAX_EVER);
        if (max_dist > prev_max_dist) {
          BEST_PT.first = i;
          BEST_PT.second = it - labyrinth[i].begin();
          prev_max_dist = max_dist;
        }
      }      
    }
  }
  std::cout << max_dist << '\n';
  MAX_EVER = max_dist;
  dfs(labyrinth, visited, BEST_PT.first, BEST_PT.second, max_dist, 1, MAX_EVER);
  
  return 0;
}