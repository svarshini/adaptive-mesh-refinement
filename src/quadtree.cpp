#include "quadtree.h"

Quadtree::Quadtree(double x, double y, double width)
 {
   root = new Node(x, y, width/2);

   square = NULL;
   qtcell = NULL;
   parent = NULL;
   nw = NULL;
   ne = NULL;
   sw = NULL;
   se = NULL;
 }

double Quadtree::error()
{
  double cx = fabs(root->centre.x);
  double cy = fabs(root->centre.y);
  double error = 0.1+(2*(cx*cy)); //Arbitrary error function f(x,y) with offset 0.1 to avoid zero error
  //std::cout<<"Error is: \n"<<error<<std::endl;
  return error;
}

Quadtree* Quadtree::makeTree(std::vector<Cell*> &cellPoints,
			     std::queue<Quadtree*> &leafNodes)
  {
    if(((root->halfwidth)*2)<error()) //If sizeof(cell)<error, don't subdivide
      {
	leafNodes.push(this);

        qtcell = new Cell(root->centre.x-(root->halfwidth), root->centre.y+(root->halfwidth),
			    root->centre.x-(root->halfwidth), root->centre.y-(root->halfwidth),
			    root->centre.x+(root->halfwidth), root->centre.y-(root->halfwidth),
			    root->centre.x+(root->halfwidth), root->centre.y+(root->halfwidth));

       cellPoints.push_back(qtcell);
       return this;
      }

    else
      {

     nw = new Quadtree(root->centre.x-(root->halfwidth/2), root->centre.y+(root->halfwidth/2), root->halfwidth);
     ne = new Quadtree(root->centre.x+(root->halfwidth/2), root->centre.y+(root->halfwidth/2), root->halfwidth);
     sw = new Quadtree(root->centre.x-(root->halfwidth/2), root->centre.y-(root->halfwidth/2), root->halfwidth);  
     se = new Quadtree(root->centre.x+(root->halfwidth/2), root->centre.y-(root->halfwidth/2), root->halfwidth);

     nw->parent=this;
     ne->parent=this;
     sw->parent=this;
     se->parent=this;     
     
     nw->makeTree(cellPoints, leafNodes);
     ne->makeTree(cellPoints, leafNodes);     
     sw->makeTree(cellPoints, leafNodes);
     se->makeTree(cellPoints, leafNodes); 
   }
  }

bool Quadtree::checkTree(std::queue<Quadtree*> finalLeafNodes, double yn, double ys, double xw, double xe)
{
Quadtree* tempobj = NULL;
Quadtree* tempneighbour = NULL;

while(!finalLeafNodes.empty())
  {
    tempobj = finalLeafNodes.front();

    if(tempobj->nw != NULL)
      {
	finalLeafNodes.pop();
	continue;
      }
    
    tempneighbour = tempobj->findNorthNeighbour(yn);

    if((tempneighbour != NULL) && (tempneighbour->sw != NULL)) 
      {
	if((tempneighbour->sw->sw != NULL) || (tempneighbour->se->se != NULL))
	  {
	    return false;
	  }
      }
    tempneighbour = tempobj->findSouthNeighbour(ys);

    if((tempneighbour != NULL) && (tempneighbour->nw != NULL)) 
      {
	if((tempneighbour->nw->nw != NULL)||(tempneighbour->ne->ne != NULL))
	  {
	    return false;
	  }
      }
    
    tempneighbour = tempobj->findWestNeighbour(xw);

    if((tempneighbour != NULL) && (tempneighbour->nw != NULL))
      {
	if((tempneighbour->ne->ne != NULL)||(tempneighbour->se->se != NULL)) 
	  {
	    return false;
	  }
      }
    
    tempneighbour=tempobj->findEastNeighbour(xe);
    if((tempneighbour!=NULL) && (tempneighbour->nw!=NULL))
      {
	if((tempneighbour->nw->nw != NULL)||(tempneighbour->sw->sw != NULL)) 
	  {
	    return false;
	  }
      }
    
    tempneighbour = tempobj->findNorthWestNeighbour(yn, xw);

    if((tempneighbour != NULL) && (tempneighbour->se != NULL)) 
      {
	if(tempneighbour->se->se != NULL)
	  {
	    return false;
	  }
      }
    
    tempneighbour = tempobj->findNorthEastNeighbour(yn, xe);

    if((tempneighbour != NULL) && (tempneighbour->sw != NULL))
      {
	if((tempneighbour->sw->sw != NULL))
	  {
	    return false;
	  }
      }
    
    tempneighbour = tempobj->findSouthWestNeighbour(ys, xw);

    if((tempneighbour != NULL) && (tempneighbour->ne != NULL))
      {
	if(tempneighbour->ne->ne != NULL) 
	  {
	    return false;
	  }
      }
    
    tempneighbour = tempobj->findSouthEastNeighbour(ys, xe);
    
    if((tempneighbour != NULL) && (tempneighbour->nw != NULL))
      {
	if(tempneighbour->nw->nw != NULL)
	  {
	    return false;
	  }
      }
    
    finalLeafNodes.pop();
  }

 return true;
}
