#include<stdio.h>
#include<iostream>

#include<vector>
#include<queue>

#include<math.h>

#include "quadtree.h"


Quadtree* Quadtree::findNorthNeighbour(double yn)
  {
    Quadtree* ptr = NULL;
    double threshold = 0.000001;
    
	if(parent==NULL)
	    return NULL;
	
	else if (fabs((root->centre.y+root->halfwidth)-yn) < threshold)
	    return NULL;
	
	else if ((parent->root->centre.x == (root->centre.x+root->halfwidth)) &&
		 (parent->root->centre.y == (root->centre.y+root->halfwidth))) //SW
	    return parent->nw;
	
	  else if((parent->root->centre.x == (root->centre.x-root->halfwidth)) &&
		  (parent->root->centre.y == (root->centre.y+root->halfwidth))) //SE
	    return parent->ne;
	
	  else  //NW and NE
	  {
	    ptr=parent->findNorthNeighbour(yn);
	    
	    if(ptr!=NULL)
	   {
	     
	    if ((ptr->nw == NULL) && (ptr->ne == NULL) && (ptr->sw == NULL) && (ptr->se == NULL))  //Leaf Node
	      return ptr;
	    
	    else
	      {
		if((parent->root->centre.x == (root->centre.x+root->halfwidth)) &&
		   (parent->root->centre.y == (root->centre.y-root->halfwidth))) //NW
		  return ptr->sw;
		
		else if((parent->root->centre.x == (root->centre.x-root->halfwidth)) &&
			(parent->root->centre.y == (root->centre.y-root->halfwidth))) //NE
		  return ptr->se;
		
		else
		  std::cout<<"Debugging required\n";

		return NULL; 
	      }
	   }
	    else
	      return NULL;
	  }
  }

Quadtree* Quadtree::findSouthNeighbour(double ys)
  {
    Quadtree* ptr=NULL;
    double threshold = 0.000001;
      
	if(parent==NULL)
	  return NULL;
	
	else if (fabs((root->centre.y-root->halfwidth)-ys) < threshold)
	  return NULL;
	
	else if ((parent->root->centre.x == (root->centre.x+root->halfwidth)) &&
		 (parent->root->centre.y == (root->centre.y-root->halfwidth))) //NW
	  return parent->sw;
	
	else if((parent->root->centre.x == (root->centre.x-root->halfwidth)) &&
		(parent->root->centre.y==(root->centre.y-root->halfwidth))) //NE
	  return parent->se;
	
	else  //SW and SE
	  {
	    ptr=parent->findSouthNeighbour(ys);
	    
	    if(ptr!=NULL)
	   {
	    if ((ptr->nw == NULL) && (ptr->ne == NULL) && (ptr->sw == NULL) && (ptr->se == NULL))  //Leaf Node
	      return ptr;
	    
	    else
	      {
		if((parent->root->centre.x == (root->centre.x+root->halfwidth)) &&
		   (parent->root->centre.y == (root->centre.y+root->halfwidth))) //SW
		  return ptr->nw;
		
		else if((parent->root->centre.x == (root->centre.x-root->halfwidth)) &&
			(parent->root->centre.y == (root->centre.y+root->halfwidth))) //SE
		  return ptr->ne;
		
		else
		  std::cout<<"Debugging required\n";

		return NULL; 
	      }
	   }
	    
	    else
	      return NULL;
	  }
  }

  Quadtree* Quadtree::findWestNeighbour(double xw)
  {
    Quadtree* ptr=NULL;
    double threshold = 0.000001;
    
    if(parent==NULL)
      return NULL;
    
    else if (fabs((root->centre.x-root->halfwidth)-xw) < threshold)
      return NULL;
    
    else if ((parent->root->centre.x == (root->centre.x-root->halfwidth)) &&
	     (parent->root->centre.y == (root->centre.y-root->halfwidth))) //NE
      return parent->nw;
    
    else if((parent->root->centre.x == (root->centre.x-root->halfwidth)) &&
	    (parent->root->centre.y == (root->centre.y+root->halfwidth))) //SE
      return parent->sw;
    
    else  //NW and SW
      {
	ptr=parent->findWestNeighbour(xw);

	if(ptr!=NULL)
	   {
	     if ((ptr->nw == NULL) && (ptr->ne == NULL) && (ptr->sw == NULL) && (ptr->se == NULL))  //Leaf Node
	       return ptr;
	     
	     else
	       {

		 if((parent->root->centre.x == (root->centre.x+root->halfwidth)) &&
		    (parent->root->centre.y == (root->centre.y-root->halfwidth))) //NW
		   return ptr->ne;
		 
		 else if((parent->root->centre.x == (root->centre.x+root->halfwidth)) &&
			 (parent->root->centre.y == (root->centre.y+root->halfwidth))) //SW
		   return ptr->se;
		 
		 else
		   std::cout<<"Debugging required\n";

		 return NULL; 
	       }
	   }

	else
	  return NULL;
      }
  }



  Quadtree* Quadtree::findEastNeighbour(double xe)
  {
    Quadtree* ptr=NULL;
    double threshold = 0.000001;

    if(parent==NULL)
      return NULL;
    
    else if (fabs((root->centre.x+root->halfwidth)-xe) < threshold)
      return NULL;

    else if ((parent->root->centre.x == (root->centre.x+root->halfwidth)) &&
	     (parent->root->centre.y == (root->centre.y-root->halfwidth))) //NW
      return parent->ne;

    else if ((parent->root->centre.x == (root->centre.x+root->halfwidth)) &&
	     (parent->root->centre.y == (root->centre.y+root->halfwidth))) //SW
	return parent->se;
    
    else  //NE and SE
      {
	ptr=parent->findEastNeighbour(xe);

	if(ptr!=NULL)
	  {
	    
	    if ((ptr->nw == NULL) && (ptr->ne == NULL) && (ptr->sw == NULL) && (ptr->se == NULL))  //Leaf Node
		return ptr;
	    
	    else
	      {
		if((parent->root->centre.x == (root->centre.x-root->halfwidth)) &&
		   (parent->root->centre.y == (root->centre.y-root->halfwidth))) //NE
		  return ptr->nw;
		
		else if((parent->root->centre.x == (root->centre.x-root->halfwidth)) &&
			(parent->root->centre.y == (root->centre.y+root->halfwidth))) //SE
		  return ptr->sw;
		
		else
		  std::cout<<"Debugging required\n";

		return NULL; 
	      }
	  }
	
	else
	  return NULL;
      }
  }

