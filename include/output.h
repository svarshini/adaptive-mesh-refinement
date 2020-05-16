#ifndef OUT_H
#define OUT_H

#include<fstream>

void quadOutput(std::queue<Quadtree*> finalLeafNodes,
		std::vector<Point> nodalPoints, std::ofstream &outfile);

void meshOutput(std::queue<Quadtree*> finalLeafNodes,
		std::vector<Point> nodalPoints, std::vector<Point> newPoints,
		std::ofstream &outfile, int sum);

#endif
