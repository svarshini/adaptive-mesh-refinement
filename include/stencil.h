#ifndef STENCIL_H
#define STENCIL_H

#include<iostream>
#include<fstream>
#include<map>

void label_north(Quadtree* neighbour, Quadtree* obj);

void label_south(Quadtree* neighbour, Quadtree* obj);

void label_east(Quadtree* neighbour, Quadtree* obj);

void label_west(Quadtree* neighbour, Quadtree* obj);
  
void markSides(std::queue<Quadtree*> finalLeafNodes,
	       double yn, double ys, double xw, double xe);


void aaaa(Quadtree* iterator, std::ifstream &infile);
void aaaa_conn(Quadtree* iterator, std::ifstream &infile);

void bbbb(Quadtree* iterator, std::ifstream &infile);
void bbbb_conn(Quadtree* iterator, std::ifstream &infile);

void aaab(Quadtree* iterator, std::ifstream &infile);
void aaab_conn(Quadtree* iterator, std::ifstream &infile);

void bbbc(Quadtree* iterator, std::ifstream &infile);
void bbbc_conn(Quadtree* iterator, std::ifstream &infile);

void bbcc(Quadtree* iterator, std::ifstream &infile);
void bbcc_conn(Quadtree* iterator, std::ifstream &infile);  

void abcb(Quadtree* iterator, std::ifstream &infile);
void abcb_conn(Quadtree* iterator, std::ifstream &infile);

void abbb(Quadtree* iterator, std::ifstream &infile);
void abbb_conn(Quadtree* iterator, std::ifstream &infile);

void abab(Quadtree* iterator, std::ifstream &infile);
void abab_conn(Quadtree* iterator, std::ifstream &infile);

void aabb(Quadtree* iterator, std::ifstream &infile);
void aabb_conn(Quadtree* iterator, std::ifstream &infile);

void fillStencil(std::queue<Quadtree*> finalLeafNodes, std::ifstream &infile);


void compareLabels(int &aaaa, int &bbbb, int &aaab, int &bbbc, int &bbcc,
		   int &abcb, int &abbb, int &abab, int &aabb,
		   std::queue<Quadtree*> finalLeafNodes,
		   std::vector<Point> &nodalStencilPoints);

void stitchNodes(std::vector<Point> nodalStencilPoints,
		 std::vector<Point> &duplicatePoints);

void insertPoints(std::vector<Point> nodalStencilPoints,
		  std::vector<Point> &newPoints,
		  std::map<int,int> &map1, std::map<int,int> &map2);

void checkPoints(std::vector<Point> &newPoints);


#endif
