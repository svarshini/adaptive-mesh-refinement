#include<stdio.h>
#include<iostream>

#include<vector>
#include<queue>

#include<math.h>

#include "quadtree.h"
#include "output.h"

void quadOutput(std::queue<Quadtree*> finalLeafNodes,
		std::vector<Point> nodalPoints, std::ofstream &outfile)

{
  outfile.open("../meshes/PointsForTecFile.tec");
  outfile<<"VARIABLES = \"X\", \"Y\" ";
  outfile<<"ZONE t=\"t:0\", N="<<nodalPoints.size()
	 <<", E="<<finalLeafNodes.size()<<", F=FEPOINT, ET=QUADRILATERAL\n";
    
  for(std::vector<Point>::iterator iter = nodalPoints.begin(); iter != nodalPoints.end(); iter++)
       outfile<<iter->x<<" "<<iter->y<<"\n";

    Quadtree* ptr;

    while(!finalLeafNodes.empty())
      {
	ptr = finalLeafNodes.front();

	outfile<<ptr->qtcell->a.number<<" "<<ptr->qtcell->b.number<<" "
	       <<ptr->qtcell->c.number<<" "<<ptr->qtcell->d.number<<"\n";
	
	finalLeafNodes.pop();
      }
    
    outfile.close();
}

void meshOutput(std::queue<Quadtree*> finalLeafNodes,
		std::vector<Point> nodalPoints, std::vector<Point> newPoints,
		std::ofstream &outfile, int sum)
{
  outfile.open("../meshes/PointsForTecStencils.tec");
  outfile<<"VARIABLES = \"X\", \"Y\" ";
  outfile<<"ZONE t=\"t:0\", N="<<newPoints.size()<<", E="<<sum<<", F=FEPOINT, ET=TRIANGLE\n";

  for(std::vector<Point>::iterator iter = newPoints.begin(); iter!=newPoints.end(); iter++)
       outfile<<iter->x<<" "<<iter->y<<"\n";

  Quadtree* ptr;
  
  while(!finalLeafNodes.empty())
    {
      ptr = finalLeafNodes.front();
      
      if(ptr->nw != NULL)
	{
	  finalLeafNodes.pop();
	  continue;
	}
      
      for(std::vector<Connect>::iterator it = ptr->StencilConnect.begin();
	  it != ptr->StencilConnect.end(); it++)
	outfile<<it->a<<" "<<it->b<<" "<<it->c<<"\n";
      
      finalLeafNodes.pop();
    }
  
  outfile.close();
}

