#include<stdio.h>
#include<iostream>

#include<vector>
#include<queue>

#include<math.h>

#include "quadtree.h"

Quadtree* Quadtree::stronglyBalanceTree(std::queue<Quadtree*> &balancedNodes, std::queue<Quadtree*> &dividedNodes,
					std::queue<Quadtree*> &finalLeafNodes, std::vector<Cell*> &cellPoints,
					double yn, double ys, double xw, double xe)
  {
    Cell* tempqtcell = NULL;
    Quadtree* tempobj = NULL;
    Quadtree* tempneighbour = NULL;
    Quadtree** iter = &dividedNodes.front();

    while(!balancedNodes.empty())
    {
       if(balancedNodes.front()->nw == NULL)
	tempobj = balancedNodes.front();

       else
	{
	  balancedNodes.pop();
	  continue;
	}
	
	tempneighbour=tempobj->findNorthWestNeighbour(yn, xw);
	
	if((tempneighbour != NULL) && (tempneighbour->se != NULL))
	  {
	    
	    if(tempneighbour->se->se != NULL)
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
		
		balancedNodes.push(tempobj->nw);
		balancedNodes.push(tempobj->ne);
		balancedNodes.push(tempobj->sw);
		balancedNodes.push(tempobj->se);	    
	      }
	  }
	
	
	if(tempobj->nw == NULL) //Check if node has been previously divided
	  {
	    
	    tempneighbour = tempobj->findNorthEastNeighbour(yn, xe);
	    
	    if((tempneighbour != NULL) && (tempneighbour->sw != NULL)) 
	      {
		
		if((tempneighbour->sw->sw!=NULL))
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

		    tempobj->nw->parent= *iter;
		    tempobj->ne->parent= *iter;
		    tempobj->sw->parent= *iter;
		    tempobj->se->parent= *iter;
		    
		    (*iter)->nw = tempobj->nw;
		    (*iter)->ne = tempobj->ne;
		    (*iter)->sw = tempobj->sw;
		    (*iter)->se = tempobj->se;
		    
		    balancedNodes.push(tempobj->nw);
		    balancedNodes.push(tempobj->ne);
		    balancedNodes.push(tempobj->sw);
		    balancedNodes.push(tempobj->se);
		    
		  }
	      }	   
	  }
	
	
	if(tempobj->nw == NULL)
	  {
	    tempneighbour = tempobj->findSouthWestNeighbour(ys, xw);

	    if((tempneighbour != NULL) && (tempneighbour->ne != NULL))
	      {
		if(tempneighbour->ne->ne != NULL) 

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
		    		    
		    tempobj->nw->parent= *iter;
		    tempobj->ne->parent= *iter;
		    tempobj->sw->parent= *iter;
		    tempobj->se->parent= *iter;

		    (*iter)->nw = tempobj->nw;
		    (*iter)->ne = tempobj->ne;
		    (*iter)->sw = tempobj->sw;
		    (*iter)->se = tempobj->se;
		    
		    balancedNodes.push(tempobj->nw);
		    balancedNodes.push(tempobj->ne);
		    balancedNodes.push(tempobj->sw);
		    balancedNodes.push(tempobj->se);
		  }
	      }
	  }
	
	
	if(tempobj->nw == NULL)
	  {
	    tempneighbour = tempobj->findSouthEastNeighbour(ys, xe);
	    if((tempneighbour != NULL) && (tempneighbour->nw != NULL))
	      {
		if(tempneighbour->nw->nw != NULL)
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
		    
		    balancedNodes.push(tempobj->nw);
		    balancedNodes.push(tempobj->ne);
		    balancedNodes.push(tempobj->sw);
		    balancedNodes.push(tempobj->se);
		  }
	      }
	  }
	
	
	if(tempobj->nw != NULL)
	 {
	   tempneighbour = tempobj->findNorthNeighbour(yn); //Check new child nodes for larger neighbours
	   if(tempneighbour != NULL)
	     {                            
	       if((tempneighbour->root->halfwidth)>(tempobj->root->halfwidth))
		   balancedNodes.push(tempneighbour);
	     }
	   
	   tempneighbour = tempobj->findSouthNeighbour(ys);
	   if(tempneighbour!=NULL)
	       {
		 if((tempneighbour->root->halfwidth)>(tempobj->root->halfwidth))
		     balancedNodes.push(tempneighbour);
	       }
	   
	   tempneighbour=tempobj->findWestNeighbour(xw);
	   if(tempneighbour!=NULL)
	     {
	       if((tempneighbour->root->halfwidth)>(tempobj->root->halfwidth))
		 balancedNodes.push(tempneighbour);
	     }
	   
	   tempneighbour=tempobj->findEastNeighbour(xe);
	   if(tempneighbour!=NULL)
	     {
	       if((tempneighbour->root->halfwidth)>(tempobj->root->halfwidth))
		   balancedNodes.push(tempneighbour);
	     }
	   
	   tempneighbour=tempobj->findNorthWestNeighbour(yn, xw);
	   if(tempneighbour!=NULL)
	     {
	       if((tempneighbour->root->halfwidth)>(tempobj->root->halfwidth))
		   balancedNodes.push(tempneighbour);
	     }
	   
	   tempneighbour=tempobj->findNorthEastNeighbour(yn, xe);
	   if(tempneighbour!=NULL)
	     {
	       if((tempneighbour->root->halfwidth)>(tempobj->root->halfwidth))
		   balancedNodes.push(tempneighbour);
	     }
	   
	      tempneighbour=tempobj->findSouthWestNeighbour(ys, xw);
	      if(tempneighbour!=NULL)
		{
		  if((tempneighbour->root->halfwidth)>(tempobj->root->halfwidth))
		      balancedNodes.push(tempneighbour);
		}
	      
	      tempneighbour=tempobj->findSouthEastNeighbour(ys, xe);
	      if(tempneighbour!=NULL)
		{
		  if((tempneighbour->root->halfwidth)>(tempobj->root->halfwidth)) 
		      balancedNodes.push(tempneighbour);
		}
	      
	 }
	
	if(tempobj->nw == NULL)
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

	    finalLeafNodes.push(tempobj);
	  }
	
	balancedNodes.pop();
    }
  }
