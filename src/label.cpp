#include<stdio.h>
#include<iostream>

#include<vector>
#include<queue>

#include<math.h>

#include "quadtree.h"
#include "stencil.h"

void label_north(Quadtree* neighbour, Quadtree* obj)
{
  if(neighbour != NULL)
    {
      if(neighbour->root->halfwidth > obj->root->halfwidth)
	obj->square->top->name  = "c";
      
      else if((neighbour->root->halfwidth == obj->root->halfwidth) &&
	      (neighbour->nw == NULL))
        obj->square->top->name  = "b";
      
      else
	obj->square->top->name  = "a";
    }
  
  else
    obj->square->top->name  = "b";
  
}

void label_south(Quadtree* neighbour, Quadtree* obj)
{
  if(neighbour != NULL)
    {
      if(neighbour->root->halfwidth > obj->root->halfwidth)
        obj->square->bottom->name  = "c";
      
      else if((neighbour->root->halfwidth == obj->root->halfwidth) &&
	      (neighbour->nw == NULL))
        obj->square->bottom->name  = "b";
      
      else
        obj->square->bottom->name  = "a";
    }
  
  else
    obj->square->bottom->name  = "b";
  
}

void label_east(Quadtree* neighbour, Quadtree* obj)
{
  if(neighbour!=NULL)
    {
      if(neighbour->root->halfwidth > obj->root->halfwidth)
	obj->square->right->name  = "c";

      else if((neighbour->root->halfwidth == obj->root->halfwidth) &&
	      (neighbour->nw == NULL))
	obj->square->right->name  = "b";

      else
	obj->square->right->name  = "a";
    }
  
  else
    obj->square->right->name  = "b";
  
}

void label_west(Quadtree* neighbour, Quadtree* obj)
{
  if(neighbour!=NULL)
    {
      if(neighbour->root->halfwidth > obj->root->halfwidth)
	obj->square->left->name  = "c";

      else if((neighbour->root->halfwidth == obj->root->halfwidth) &&
	      (neighbour->nw == NULL))
	obj->square->left->name  = "b";

      else
	obj->square->left->name  = "a";
    }
  
  else
    obj->square->left->name  = "b";
  
}

void markSides(std::queue<Quadtree*> finalLeafNodes, double yn, double ys,
	       double xw, double xe)
  {
    Quadtree* tempobj;
    Quadtree* tempneighbour;

    while(!finalLeafNodes.empty())
      {
	tempobj = finalLeafNodes.front();
	
	if(tempobj->nw != NULL)
	  {
	    finalLeafNodes.pop();
	    continue;
	  }
	
	if(tempobj->nw == NULL)
	  {

	    tempobj->square = new Sides();
	    tempobj->square->top = new Line();
	    tempobj->square->bottom = new Line();
	    tempobj->square->right = new Line();
	    tempobj->square->left = new Line();
	    
	    tempneighbour = tempobj->findNorthNeighbour(yn);

	    label_north(tempneighbour, tempobj);
	    
	    tempneighbour = tempobj->findSouthNeighbour(ys);

	    label_south(tempneighbour, tempobj);
	    
	    tempneighbour = tempobj->findEastNeighbour(xe);
	    
	    label_east(tempneighbour, tempobj);
	    
	    tempneighbour = tempobj->findWestNeighbour(xw);

	    label_west(tempneighbour, tempobj);
	    
	    tempobj->square->label = tempobj->square->top->name + tempobj->square->right->name +
	      tempobj->square->bottom->name + tempobj->square->left->name;
	  }
	
	finalLeafNodes.pop();
      }
  }

