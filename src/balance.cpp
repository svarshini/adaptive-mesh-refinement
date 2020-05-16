#include<stdio.h>
#include<iostream>

#include<vector>
#include<queue>

#include<math.h>

#include "quadtree.h"

Quadtree* Quadtree::balanceTree(std::queue<Quadtree*> &leafNodes, std::queue<Quadtree*> &dividedNodes,
		      std::queue<Quadtree*> &balancedNodes, std::vector<Cell*> &cellPoints,
		      double yn, double ys, double xw, double xe)
  {
    Cell* tempqtcell = NULL;
    Quadtree* tempobj = NULL;
    Quadtree* tempneighbour = NULL;
    Quadtree** iter = &dividedNodes.front();

    while(!leafNodes.empty())
    {

      if(leafNodes.front()->nw == NULL)  //Checks for leaf nodes which got divided and became internal nodes, pops them if true
	tempobj = leafNodes.front(); //Same node has to be subdivided due to multiple different sized neighbors 

      else
	{
	  leafNodes.pop();
	  continue;
	}

      tempneighbour = tempobj->findNorthNeighbour(yn);

      if ((tempneighbour != NULL) && (tempneighbour->sw != NULL)) //tempneighbour->sw->sw exists only if tempneighbour->sw exists.
	                                                      //If sw exists, se automatically exists
        {
	  if((tempneighbour->sw->sw != NULL) || (tempneighbour->se->se != NULL))
	    {
	      
	      dividedNodes.push(tempobj);
	      iter = &dividedNodes.back();
	      
	      tempobj->nw = new Quadtree(tempobj->root->centre.x-(tempobj->root->halfwidth/2),
					 tempobj->root->centre.y+(tempobj->root->halfwidth/2),
					 tempobj->root->halfwidth);

	      tempobj->ne = new Quadtree(tempobj->root->centre.x+(tempobj->root->halfwidth/2),
					 tempobj->root->centre.y+(tempobj->root->halfwidth/2),
					 tempobj->root->halfwidth);

	      tempobj->sw = new Quadtree(tempobj->root->centre.x-(tempobj->root->halfwidth/2),
					 tempobj->root->centre.y-(tempobj->root->halfwidth/2),
					 tempobj->root->halfwidth);
	      
	      tempobj->se = new Quadtree(tempobj->root->centre.x+(tempobj->root->halfwidth/2),
					 tempobj->root->centre.y-(tempobj->root->halfwidth/2),
					 tempobj->root->halfwidth);
	      	    
	      tempobj->nw->parent = *iter;
	      tempobj->ne->parent = *iter;
	      tempobj->sw->parent = *iter;
	      tempobj->se->parent = *iter;
	      
	      (*iter)->nw = tempobj->nw;   //Dereferencing needs brackets - (*iter)
	      (*iter)->ne = tempobj->ne;
	      (*iter)->sw = tempobj->sw;
	      (*iter)->se = tempobj->se;

	      leafNodes.push(tempobj->nw);
	      leafNodes.push(tempobj->ne);
	      leafNodes.push(tempobj->sw);
	      leafNodes.push(tempobj->se);    
	    }
	}
	  

      if(tempobj->nw == NULL) //Checks if node has been previously divided.
	{
	  tempneighbour = tempobj->findSouthNeighbour(ys);
	  
	  if((tempneighbour != NULL) && (tempneighbour->nw != NULL)) //Checks if a neighbour is present & has been divided before
	    {
	      
	      if((tempneighbour->nw->nw != NULL) || (tempneighbour->ne->ne != NULL))

		{
		  dividedNodes.push(tempobj);
		  iter = &dividedNodes.back();
		  
		  tempobj->nw = new Quadtree(tempobj->root->centre.x-(tempobj->root->halfwidth/2),
					     tempobj->root->centre.y+(tempobj->root->halfwidth/2),
					     tempobj->root->halfwidth);
		  
		  tempobj->ne = new Quadtree(tempobj->root->centre.x+(tempobj->root->halfwidth/2),
					     tempobj->root->centre.y+(tempobj->root->halfwidth/2),
					     tempobj->root->halfwidth);
		  
		  tempobj->sw = new Quadtree(tempobj->root->centre.x-(tempobj->root->halfwidth/2),
					     tempobj->root->centre.y-(tempobj->root->halfwidth/2),
					     tempobj->root->halfwidth);
		  
		  tempobj->se = new Quadtree(tempobj->root->centre.x+(tempobj->root->halfwidth/2),
					     tempobj->root->centre.y-(tempobj->root->halfwidth/2),
					     tempobj->root->halfwidth);
		  		  
		  tempobj->nw->parent = *iter;
		  tempobj->ne->parent = *iter;
		  tempobj->sw->parent = *iter;
		  tempobj->se->parent = *iter;

		  (*iter)->nw = tempobj->nw;
		  (*iter)->ne = tempobj->ne;
		  (*iter)->sw = tempobj->sw;
		  (*iter)->se = tempobj->se;
		  
		  leafNodes.push(tempobj->nw);
		  leafNodes.push(tempobj->ne);
		  leafNodes.push(tempobj->sw);
		  leafNodes.push(tempobj->se);   
		}
	    }	   
	}
      

      if(tempobj->nw == NULL)
	{
	  tempneighbour = tempobj->findWestNeighbour(xw);
	  
	  if((tempneighbour != NULL) && (tempneighbour->nw != NULL))
	    {
	      if((tempneighbour->ne->ne != NULL) || (tempneighbour->se->se != NULL)) 

		{
		  dividedNodes.push(tempobj);
		  iter = &dividedNodes.back();
		  
		  tempobj->nw = new Quadtree(tempobj->root->centre.x-(tempobj->root->halfwidth/2),
					     tempobj->root->centre.y+(tempobj->root->halfwidth/2),
					     tempobj->root->halfwidth);
		  
		  tempobj->ne = new Quadtree(tempobj->root->centre.x+(tempobj->root->halfwidth/2),
					     tempobj->root->centre.y+(tempobj->root->halfwidth/2),
					     tempobj->root->halfwidth);
		  
		  tempobj->sw = new Quadtree(tempobj->root->centre.x-(tempobj->root->halfwidth/2),
					     tempobj->root->centre.y-(tempobj->root->halfwidth/2),
					     tempobj->root->halfwidth);
		  
		  tempobj->se = new Quadtree(tempobj->root->centre.x+(tempobj->root->halfwidth/2),
					     tempobj->root->centre.y-(tempobj->root->halfwidth/2),
					     tempobj->root->halfwidth);
		  		  
		  tempobj->nw->parent = *iter;
		  tempobj->ne->parent = *iter;
		  tempobj->sw->parent = *iter;
		  tempobj->se->parent = *iter;
		  
		  (*iter)->nw = tempobj->nw;
		  (*iter)->ne = tempobj->ne;
		  (*iter)->sw = tempobj->sw;
		  (*iter)->se = tempobj->se;
		  
		  leafNodes.push(tempobj->nw);
		  leafNodes.push(tempobj->ne);
		  leafNodes.push(tempobj->sw);
		  leafNodes.push(tempobj->se);
		}
	    }
	}
      
      
      if(tempobj->nw == NULL)
	{
	  tempneighbour = tempobj->findEastNeighbour(xe);

	  if((tempneighbour != NULL) && (tempneighbour->nw != NULL))

	    {
	      if((tempneighbour->nw->nw != NULL) || (tempneighbour->sw->sw != NULL)) 
		{
		  
		  dividedNodes.push(tempobj);
		  iter = &dividedNodes.back();
		  
		  tempobj->nw = new Quadtree(tempobj->root->centre.x-(tempobj->root->halfwidth/2),
					     tempobj->root->centre.y+(tempobj->root->halfwidth/2),
					     tempobj->root->halfwidth);
		  
		  tempobj->ne = new Quadtree(tempobj->root->centre.x+(tempobj->root->halfwidth/2),
					     tempobj->root->centre.y+(tempobj->root->halfwidth/2),
					     tempobj->root->halfwidth);
		  
		  tempobj->sw = new Quadtree(tempobj->root->centre.x-(tempobj->root->halfwidth/2),
					     tempobj->root->centre.y-(tempobj->root->halfwidth/2),
					     tempobj->root->halfwidth);
		  
		  tempobj->se = new Quadtree(tempobj->root->centre.x+(tempobj->root->halfwidth/2),
					     tempobj->root->centre.y-(tempobj->root->halfwidth/2),
					     tempobj->root->halfwidth);
		  		  
		  tempobj->nw->parent = *iter;
		  tempobj->ne->parent = *iter;
		  tempobj->sw->parent = *iter;
		  tempobj->se->parent = *iter;
		  
		  (*iter)->nw = tempobj->nw;
		  (*iter)->ne = tempobj->ne;
		  (*iter)->sw = tempobj->sw;
		  (*iter)->se = tempobj->se;
	    
		  leafNodes.push(tempobj->nw);
		  leafNodes.push(tempobj->ne);
		  leafNodes.push(tempobj->sw);
		  leafNodes.push(tempobj->se);
		}
	    }
	}
      
      if(tempobj->nw != NULL)
	{
	  tempneighbour = tempobj->findNorthNeighbour(yn); //Check newly created child nodes for larger neighbours

	  if(tempneighbour != NULL) 
	    {                            
	      if((tempneighbour->root->halfwidth) > (tempobj->root->halfwidth))
		  leafNodes.push(tempneighbour);
	    }
	  
	  tempneighbour=tempobj->findSouthNeighbour(ys);

	  if(tempneighbour != NULL)
	    {
	      if((tempneighbour->root->halfwidth) > (tempobj->root->halfwidth))
		  leafNodes.push(tempneighbour);
	    }
	  
	  tempneighbour=tempobj->findWestNeighbour(xw);
	  if(tempneighbour!=NULL)
	    {
	      if((tempneighbour->root->halfwidth) > (tempobj->root->halfwidth))
		 leafNodes.push(tempneighbour);
	    }
	  
	  tempneighbour=tempobj->findEastNeighbour(xe);
	  if(tempneighbour!=NULL)
	    {
	      if((tempneighbour->root->halfwidth) > (tempobj->root->halfwidth))
		  leafNodes.push(tempneighbour);
	    }
	}
      
      if(tempobj->nw == NULL)   //Undivided leaf nodes are input for strong balancing
	{
	  tempobj->qtcell = new Cell(tempobj->root->centre.x-(tempobj->root->halfwidth),
				     tempobj->root->centre.y+(tempobj->root->halfwidth),
				     tempobj->root->centre.x-(tempobj->root->halfwidth),
				     tempobj->root->centre.y-(tempobj->root->halfwidth),
				     tempobj->root->centre.x+(tempobj->root->halfwidth),
				     tempobj->root->centre.y-(tempobj->root->halfwidth),
				     tempobj->root->centre.x+(tempobj->root->halfwidth),
				     tempobj->root->centre.y+(tempobj->root->halfwidth));
	  
	  cellPoints.push_back(tempobj->qtcell);
	     balancedNodes.push(tempobj); 
	}

	 leafNodes.pop();
    }
  }

