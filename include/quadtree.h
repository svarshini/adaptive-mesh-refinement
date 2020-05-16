#ifndef QUADTREE_H
#define QUADTREE_H

#include<stdio.h>
#include<iostream>

#include<vector>
#include<queue>

#include<math.h>
#include "quad_util.h"

class Quadtree;
class Quadtree
{
public:
     Node* root;
     Cell* qtcell;
     Quadtree* nw;
     Quadtree* ne;
     Quadtree* sw;
     Quadtree* se;
     Quadtree* parent; //Pointer to parent of current quadtree
     Sides* square;
     std::vector<Point> Stencil;
     std::vector<Connect> StencilConnect; 
  
     Quadtree(double x, double y, double width);
     
     double error();

     Quadtree* makeTree(std::vector<Cell*> &cellPoints,
			std::queue<Quadtree*> &leafNodes);

     Quadtree* findNorthNeighbour(double yn);
     Quadtree* findSouthNeighbour(double ys);
     Quadtree* findWestNeighbour(double xw);
     Quadtree* findEastNeighbour(double xe);

     Quadtree* balanceTree(std::queue<Quadtree*> &leafNodes, std::queue<Quadtree*> &dividedNodes,
			   std::queue<Quadtree*> &balancedNodes, std::vector<Cell*> &cellPoints,
			   double yn, double ys, double xw, double xe);

     Quadtree* findNorthWestNeighbour(double yn, double xw);
     Quadtree* findNorthEastNeighbour(double yn, double xe);
     Quadtree* findSouthWestNeighbour(double ys, double xw);
     Quadtree* findSouthEastNeighbour(double ys, double xe);

     Quadtree* stronglyBalanceTree(std::queue<Quadtree*> &balancedNodes,
				   std::queue<Quadtree*> &dividedNodes,
				   std::queue<Quadtree*> &finalLeafNodes,
				   std::vector<Cell*> &cellPoints,
				   double yn, double ys, double xw, double xe);

     bool checkTree(std::queue<Quadtree*> finalLeafNodes,
		    double yn, double ys, double xw, double xe);
     
};

#endif
