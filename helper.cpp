#include "helper.h"

// Check if possible to go to position (x, y)
// Already visited cells are not accessible
bool isAccessible(std::vector< std::vector<char> > &labyrinth,
            std::vector< std::vector<int> > &visited, int x, int y)
{
    if (labyrinth[x][y] == '#' || visited[x][y]) {
        return false;
    }
 
    return true;
}

bool isWithinBounds(int x, int y, std::vector< std::vector<char> > &labyrinth)
{
  int N_ROWS = labyrinth.size();
  int N_COLS = labyrinth[0].size();
    if (x < N_ROWS && y < N_COLS && x >= 0 && y >= 0) {
        return true;
    }
 
    return false;
}

void dfs(std::vector< std::vector<char> > &labyrinth, 
         std::vector< std::vector<int> > &visited, int i, 
         int j, int &max_dist, int dist, int MAX_EVER) {
  visited[i][j] = dist;

  if (dist == MAX_EVER) {
    for (int i = 0; i < labyrinth.size(); i++) {
      for (auto it = labyrinth[i].begin();
          it != labyrinth[i].end(); it++) {
        int j = it - labyrinth[i].begin();
        if (visited[i][j]==0)
          std::cout << labyrinth[i][j];
        else
          std::cout << visited[i][j]-1;
      }
      std::cout << '\n';
    }
  }
  
  if (dist > max_dist) {
    max_dist = dist;
  }
  if (isWithinBounds(i + 1, j, labyrinth) && isAccessible(labyrinth, visited, i + 1, j)) {
      dfs(labyrinth, visited, i + 1, j, max_dist, dist + 1, MAX_EVER);
  }

  // go to the right cell
  if (isWithinBounds(i, j + 1, labyrinth) && isAccessible(labyrinth, visited, i, j + 1)) {
      dfs(labyrinth, visited, i, j + 1, max_dist, dist + 1, MAX_EVER);
  }

  // go to the top cell
  if (isWithinBounds(i - 1, j, labyrinth) && isAccessible(labyrinth, visited, i - 1, j)) {
      dfs(labyrinth, visited, i - 1, j, max_dist, dist + 1, MAX_EVER);
  }

  // go to the left cell
  if (isWithinBounds(i, j - 1, labyrinth) && isAccessible(labyrinth, visited, i, j - 1)) {
      dfs(labyrinth, visited, i, j - 1, max_dist, dist + 1, MAX_EVER);
  }

  // backtrack: remove `(i, j)` from the visited matrix
  visited[i][j] = 0;
  return;
}
