#include<stdio.h>
#include<iostream>
#include<fstream>

#include<vector>
#include<string.h>
#include<queue>
#include<map>

#include<math.h>
#include<algorithm>

#include "quadtree.h"
#include "conn_util.h"
#include "stencil.h"
#include "output.h"

int main()
{
  double x, y, width;
  double yn, ys, xw, xe;
  
  std::vector<Cell*> cellPoints;
  std::queue<Quadtree*> leafNodes;

  std::queue<Quadtree*> dividedNodes;
  std::queue<Quadtree*> balancedNodes;
  std::queue<Quadtree*> finalLeafNodes;

  std::vector<double> xNodalPoints;
  std::vector<double> yNodalPoints;
  std::vector<Point> nodalPoints;

  bool check;

  int aaaa = 0, bbbb = 0, aaab = 0, bbbc = 0,
    bbcc = 0, abcb = 0, abbb = 0, abab = 0, aabb = 0;

  std::vector<Point> nodalStencilPoints;

  std::vector<Point> duplicatePoints;

  std::vector<Point> newPoints;
  std::map<int,int> map1;
  std::map<int,int> map2;
  
  std::cout<<"Enter spatial dimensions of the QuadTree\n";
  std::cout<<"X coordinate: \n";
  std::cin>>x;
  std::cout<<"Y coordinate: \n";
  std::cin>>y;
  std::cout<<"Width: \n";
  std::cin>>width;

  Quadtree Quad(x, y, width);
  yn = y + (width/2);
  ys = y -(width/2);
  xw = x - (width/2);
  xe = x + (width/2);

  Quad.makeTree(cellPoints, leafNodes);
  std::cout<<"Mesh refined\n";

  Quad.balanceTree(leafNodes, dividedNodes,
		   balancedNodes, cellPoints,
		   yn, ys, xw, xe); 
  std::cout<<"Quadtree has been balanced\n";

   while(!dividedNodes.empty())
     dividedNodes.pop();

   Quad.stronglyBalanceTree(balancedNodes, dividedNodes,
			    finalLeafNodes, cellPoints,
			    yn, ys, xw, xe);
   
  std::cout<<"Quadtree has been strongly balanced\n";

  insertPoints(finalLeafNodes, xNodalPoints, yNodalPoints);

  makePointVector(nodalPoints, xNodalPoints, yNodalPoints);

  markConnectivity(finalLeafNodes, nodalPoints);

  std::cout<<"Connectivity marked\n";
  
  check = Quad.checkTree(finalLeafNodes, yn, ys, xw, xe); //Pass queue by value

  if(check == true)
    std::cout<<"Quadtree has been checked for balancing and strong balancing\n";
  else
    std::cout<<"Balancing check failed\n";

  markSides(finalLeafNodes, yn, ys, xw, xe);

  std::ifstream infile;
  fillStencil(finalLeafNodes, infile);
  
  compareLabels(aaaa, bbbb, aaab, bbbc, bbcc, abcb, abbb,
		abab, aabb, finalLeafNodes, nodalStencilPoints);

  stitchNodes(nodalStencilPoints, duplicatePoints);
  
  insertPoints(nodalStencilPoints, newPoints, map1, map2);

  modifyConnectivities(finalLeafNodes, map1, map2);

  checkPoints(newPoints);

  std::ofstream outfile;
  quadOutput(finalLeafNodes, nodalPoints, outfile);

  std::cout<<"Stencil Count: \n";
  std::cout<<"aaaa: "<<aaaa<<"\n";
  std::cout<<"bbbb: "<<bbbb<<"\n";
  std::cout<<"aaab: "<<aaab<<"\n";
  std::cout<<"bbbc: "<<bbbc<<"\n";
  std::cout<<"bbcc: "<<bbcc<<"\n";
  std::cout<<"abcb: "<<abcb<<"\n";
  std::cout<<"abbb: "<<abbb<<"\n";
  std::cout<<"abab: "<<abab<<"\n";
  std::cout<<"aabb: "<<aabb<<"\n";
  
  int sum = (32*aaaa)+(26*bbbb)+(27*aaab)+(25*bbbc)+(22*bbcc)+
    (22*abcb)+(23*abbb)+(20*abab)+(26*aabb);

  meshOutput(finalLeafNodes, nodalPoints, newPoints, outfile, sum);

  return 0;
  
}

 
