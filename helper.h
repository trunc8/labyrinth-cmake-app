#ifndef __jdetask_h__
#define __jdetask_h__

#include <iostream>
#include <fstream> // For ifstream
#include <sstream> // For istringstream
#include <vector>
#include <climits> // For INT_MAX

bool isSafe(std::vector< std::vector<char> > &labyrinth,
            std::vector< std::vector<int> > &visited, int x, int y);

bool isValid(int x, int y, std::vector< std::vector<char> > &labyrinth);

void dfs(std::vector< std::vector<char> > &labyrinth, 
         std::vector< std::vector<int> > &visited, int i, 
         int j, int &max_dist, int dist, int MAX_EVER);

#endif