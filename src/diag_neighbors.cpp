#include<stdio.h>
#include<iostream>

#include<vector>
#include<queue>

#include<math.h>

#include "quadtree.h"

Quadtree* Quadtree::findNorthWestNeighbour(double yn, double xw)
  {
    Quadtree* ptr = NULL;
    double threshold = 0.000001;
    
    if(parent == NULL)
      return NULL;
    
    else if ((fabs((root->centre.y+root->halfwidth)-yn) < threshold) ||
	     (fabs((root->centre.x-root->halfwidth)-xw) < threshold))
      return NULL;

    else if ((parent->root->centre.x == (root->centre.x-root->halfwidth)) &&
	     (parent->root->centre.y == (root->centre.y+root->halfwidth))) //SE
      return parent->nw;
    
    else  //NW, SW and NE
      {
	if((parent->root->centre.x == (root->centre.x-root->halfwidth)) &&
	   (parent->root->centre.y == (root->centre.y-root->halfwidth))) //NE
	  {
	    ptr = parent->findNorthNeighbour(yn);

	    if(ptr != NULL)
	      {
		if ((ptr->nw == NULL) && (ptr->ne == NULL) &&
		    (ptr->sw == NULL) && (ptr->se == NULL)) //Leaf Node
		  return ptr;

		else
		  return ptr->sw;
	      }
	  }
	
	else if((parent->root->centre.x == (root->centre.x+root->halfwidth)) &&
		(parent->root->centre.y == (root->centre.y+root->halfwidth))) //SW
	  {
	    ptr = parent->findWestNeighbour(xw);

	    if(ptr != NULL)
	      {
		if ((ptr->nw == NULL) && (ptr->ne == NULL) &&
		    (ptr->sw == NULL) && (ptr->se == NULL)) //Leaf Node
		  return ptr;
		
		else
		  return ptr->ne;
	      }
	  }
	
	else if((parent->root->centre.x == (root->centre.x+root->halfwidth)) &&
		(parent->root->centre.y == (root->centre.y-root->halfwidth))) //NW
	  { 
	    ptr = parent->findNorthWestNeighbour(yn, xw);

	    if(ptr != NULL)
	      {
		if ((ptr->nw == NULL) && (ptr->ne == NULL) && (ptr->sw == NULL) && (ptr->se == NULL)) //Leaf Node
		  return ptr;

		else
		  return ptr->se;
	      }
	  }
	
	else
	  std::cout<<"Debugging required\n";

	return NULL;
      }
  }



Quadtree* Quadtree::findNorthEastNeighbour(double yn, double xe)
  {
    Quadtree* ptr = NULL;
    double threshold = 0.000001; 
    
    if(parent == NULL)
      return NULL;

    else if ((fabs((root->centre.y+root->halfwidth)-yn) < threshold) ||
	     (fabs((root->centre.x+root->halfwidth)-xe) < threshold))
      return NULL;

    else if ((parent->root->centre.x == (root->centre.x+root->halfwidth)) &&
	     (parent->root->centre.y == (root->centre.y+root->halfwidth))) //SW
      return parent->ne;
    
    else  //SE, NW and NE
      {
	if ((parent->root->centre.x == (root->centre.x-root->halfwidth)) &&
	   (parent->root->centre.y == (root->centre.y+root->halfwidth))) //SE
	  {
	    ptr=parent->findEastNeighbour(xe);

	    if(ptr != NULL) //Segmentation fault while balancing
	      {
		if ((ptr->nw==NULL) && (ptr->ne==NULL) && (ptr->sw==NULL) && (ptr->se==NULL)) //Leaf Node
		  return ptr;
		
		else
		  return ptr->nw;
	      }
	  }
	
	else if ((parent->root->centre.x == (root->centre.x+root->halfwidth)) &&
		(parent->root->centre.y == (root->centre.y-root->halfwidth))) //NW
	  {
	    ptr = parent->findNorthNeighbour(yn);

	    if(ptr != NULL)
	      {
		if ((ptr->nw == NULL) && (ptr->ne == NULL) && (ptr->sw == NULL) && (ptr->se == NULL)) //Leaf Node
		  return ptr;
		
		else
		  return ptr->se;
	      }
	  }
	
	else if ((parent->root->centre.x == (root->centre.x-root->halfwidth)) &&
		 (parent->root->centre.y == (root->centre.y-root->halfwidth))) //NE
	  {
	    ptr = parent->findNorthEastNeighbour(yn, xe);
	    if(ptr != NULL)
	      {
		if ((ptr->nw == NULL) && (ptr->ne == NULL) && (ptr->sw == NULL) && (ptr->se == NULL))  //Leaf Node
		  return ptr;
		
		else
		  return ptr->sw;
	      }
	  }

	else
	  std::cout<<"Debugging required\n";
	
	return NULL;
      }
  }


Quadtree* Quadtree::findSouthWestNeighbour(double ys, double xw)
  {
    Quadtree* ptr = NULL;
    double threshold = 0.000001;
    
    if(parent == NULL)
      return NULL;
    
    else if ((fabs((root->centre.y-root->halfwidth)-ys) < threshold) ||
	     (fabs((root->centre.x-root->halfwidth)-xw) < threshold))
	return NULL;
    
    else if ((parent->root->centre.x == (root->centre.x-root->halfwidth)) &&
	     (parent->root->centre.y == (root->centre.y-root->halfwidth))) //NE
      return parent->sw;
    
    else  //NW, SE and SW
      {
	if((parent->root->centre.x == (root->centre.x+root->halfwidth)) &&
	   (parent->root->centre.y == (root->centre.y-root->halfwidth))) //NW
	  {
	    ptr = parent->findWestNeighbour(xw);

	    if(ptr != NULL) //Causes segmentation fault while balancing
	      {
		if ((ptr->nw == NULL) && (ptr->ne == NULL) && (ptr->sw == NULL) && (ptr->se == NULL))  //Leaf Node
		  return ptr;
		
		else
		  return ptr->se;
	      }
	  }
	
	else if((parent->root->centre.x == (root->centre.x-root->halfwidth)) &&
		(parent->root->centre.y == (root->centre.y+root->halfwidth))) //SE
	      {		
		ptr = parent->findSouthNeighbour(ys);

		if(ptr != NULL)
		  {
		    if ((ptr->nw == NULL) && (ptr->ne == NULL) && (ptr->sw == NULL) && (ptr->se == NULL))  //Leaf Node
		      return ptr;

		    else
		      return ptr->nw;
		  }
	      }
	
	else if((parent->root->centre.x == (root->centre.x+root->halfwidth)) &&
		(parent->root->centre.y == (root->centre.y+root->halfwidth))) //SW
	  {	    
	    ptr=parent->findSouthWestNeighbour(ys, xw);

	    if(ptr != NULL) //Segmentation fault while balancing
	      {
		if ((ptr->nw == NULL) && (ptr->ne == NULL) &&
		    (ptr->sw == NULL) && (ptr->se == NULL)) //Leaf Node
		  return ptr;

		else
		  return ptr->ne;
	      }
	  }
	
	else
	  std::cout<<"Debugging required\n";

	return NULL;
      }
  }




Quadtree* Quadtree::findSouthEastNeighbour(double ys, double xe)
  {
    Quadtree* ptr = NULL;
    double threshold = 0.000001;
    
    if(parent == NULL)
	return NULL;
    
    else if ((fabs((root->centre.y-root->halfwidth)-ys) < threshold) ||
	     (fabs((root->centre.x+root->halfwidth)-xe) < threshold))
	return NULL;

    else if ((parent->root->centre.x == (root->centre.x+root->halfwidth)) &&
	     (parent->root->centre.y == (root->centre.y-root->halfwidth))) //NW
	return parent->se;
    
    else  //NE, SW and SE
      {
	if((parent->root->centre.x == (root->centre.x-root->halfwidth)) &&
	   (parent->root->centre.y == (root->centre.y-root->halfwidth))) //NE
	  {	    
	    ptr = parent->findEastNeighbour(xe);

	    if(ptr != NULL)
	      {
		if ((ptr->nw == NULL) && (ptr->ne == NULL) &&
		    (ptr->sw == NULL) && (ptr->se == NULL)) //Leaf Node
		  return ptr;
		
		else
		  return ptr->sw;
	      }
	  }
	
	else if((parent->root->centre.x == (root->centre.x+root->halfwidth)) &&
		(parent->root->centre.y == (root->centre.y+root->halfwidth))) //SW
	  {	    
	    ptr = parent->findSouthNeighbour(ys);

	    if(ptr != NULL)
	      {
		if ((ptr->nw == NULL) && (ptr->ne == NULL) &&
		    (ptr->sw == NULL) && (ptr->se == NULL)) //Leaf Node
		  return ptr;

		else
		  return ptr->ne;
	      }
	  }
	
	else if((parent->root->centre.x == (root->centre.x-root->halfwidth)) &&
		(parent->root->centre.y == (root->centre.y+root->halfwidth))) //SE
	  {	    
	    ptr = parent->findSouthEastNeighbour(ys, xe);

	    if(ptr != NULL)
	      {
		if ((ptr->nw == NULL) && (ptr->ne == NULL) &&
		    (ptr->sw == NULL) && (ptr->se == NULL))  //Leaf Node
		  return ptr;
		
		else
		  return ptr->nw;
	      }
	  }
	
	else
	  std::cout<<"Debugging required\n";

	return NULL;
      }
  }


