#include<stdio.h>
#include<iostream>

#include<vector>
#include<queue>

#include<math.h>

#include "quadtree.h"
#include "stencil.h"

void scaleTrans(Quadtree* quad, int &connectivity, int count,
		std::vector<Point> &nodalStencilPoints)
{
  std::vector<Point>::iterator itp;
  std::vector<Connect>::iterator itc;

  for(itp = quad->Stencil.begin(); itp != quad->Stencil.end(); itp++)
    {
      itp->x = ((itp->x * (2*(quad->root->halfwidth))) +
		 quad->root->centre.x); //Scale and shift origin	   
      
      itp->y = ((itp->y * (2*(quad->root->halfwidth))) +
		quad->root->centre.y);

      itp->number = connectivity;

      connectivity++;
      nodalStencilPoints.push_back(*itp);
    }
	  
  for(itc = quad->StencilConnect.begin(); itc != quad->StencilConnect.end(); itc++)
    {
      itc->a += count;
      itc->b += count;
      itc->c += count;
    }
  
}

void scaleRotTrans(Quadtree* quad, int &connectivity, int count, double theta,
		   std::vector<Point> &nodalStencilPoints)
{
  std::vector<Point>::iterator itp;
  std::vector<Connect>::iterator itc;
  double tempx, tempy;

  for(itp = quad->Stencil.begin(); itp != quad->Stencil.end(); itp++)
    {
      itp->x = (itp->x * (2*(quad->root->halfwidth)));  //Scale
      itp->y = (itp->y * (2*(quad->root->halfwidth)));

      tempx = itp->x;
      tempy = itp->y;
      itp->x = (tempx * cos(theta)) - (tempy * sin(theta)); //Rotate
      itp->y = (tempx * sin(theta)) + (tempy * cos(theta));

      itp->x = itp->x + quad->root->centre.x; //Translate
      itp->y = itp->y + quad->root->centre.y;

      itp->number = connectivity;
      connectivity++;
      nodalStencilPoints.push_back(*itp);
    }
  
  for(itc = quad->StencilConnect.begin(); itc!=quad->StencilConnect.end(); itc++)
    {
      itc->a += count;
      itc->b += count;
      itc->c += count;
    }
  
}

void compareLabels(int &aaaa, int &bbbb, int &aaab, int &bbbc,
		   int &bbcc, int &abcb, int &abbb, int &abab,
		   int &aabb, std::queue<Quadtree*> finalLeafNodes,
		   std::vector<Point> &nodalStencilPoints)
{
  int count = 0;
  int connectivity = 1;
  double theta;
  double pi = 3.14159;
  Quadtree* tempobj;

  while(!finalLeafNodes.empty())
    {
	tempobj = finalLeafNodes.front();
	if(tempobj->nw!=NULL)
	  {
	    finalLeafNodes.pop();
	    continue;
	  }

	if(tempobj->square->label == "aaaa")
	{
	  aaaa += 1;	  
	  scaleTrans(tempobj, connectivity, count, nodalStencilPoints);
	  count += 25;
	}

	else if(tempobj->square->label == "bbbb")
	{
	  bbbb += 1;
	  scaleTrans(tempobj, connectivity, count, nodalStencilPoints);
	  count += 20;
	}
	
	else if((tempobj->square->label == "aaab") || (tempobj->square->label == "aaba")
		|| (tempobj->square->label == "abaa") || (tempobj->square->label == "baaa"))
	{
	  aaab += 1;

	  if(tempobj->square->label == "aaab")
	    scaleTrans(tempobj, connectivity, count, nodalStencilPoints);

	  else if(tempobj->square->label == "aaba") //Rotate counter-clockwise by 90 deg
	    {
	      theta = (pi/180)*90;
	      scaleRotTrans(tempobj, connectivity, count, theta, nodalStencilPoints);
	    }

	  else if(tempobj->square->label == "abaa") //Rotate counter-clockwise by 180 deg
	    {
	      theta = (pi/180)*180;
	      scaleRotTrans(tempobj, connectivity, count, theta, nodalStencilPoints);
	    }
	  
	  else if(tempobj->square->label == "baaa") //Rotate counter-clockwise by 270 deg
	    {
	      theta = (pi/180)*270;
	      scaleRotTrans(tempobj, connectivity, count, theta, nodalStencilPoints);
	    }
	  
	  count += 22;
	}
	
	else if((tempobj->square->label == "bbbc") || (tempobj->square->label == "bbcb")
		|| (tempobj->square->label == "bcbb") || (tempobj->square->label == "cbbb"))
	{
	  bbbc += 1;
	  
	  if(tempobj->square->label == "bbbc")
	    scaleTrans(tempobj, connectivity, count, nodalStencilPoints);

	  else if(tempobj->square->label == "bbcb") //Rotate counter-clockwise by 90 deg
	    {
	      theta = (pi/180)*90;
	      scaleRotTrans(tempobj, connectivity, count, theta, nodalStencilPoints);
	    }

	  else if(tempobj->square->label == "bcbb") //Rotate counter-clockwise by 180 deg
	    {
	      theta = pi;
	      scaleRotTrans(tempobj, connectivity, count, theta, nodalStencilPoints);
	    }

	  else if(tempobj->square->label == "cbbb") //Rotate counter-clockwise by 270 deg
	    {
	      theta = (pi/180)*270;
	      scaleRotTrans(tempobj, connectivity, count, theta, nodalStencilPoints);
	    }
	  
	  count += 19;
	}

	else if((tempobj->square->label == "bbcc") || (tempobj->square->label == "bccb")
		|| (tempobj->square->label == "ccbb") || (tempobj->square->label == "cbbc"))
	  {
	    bbcc += 1;

	    if(tempobj->square->label == "bbcc")
	      scaleTrans(tempobj, connectivity, count, nodalStencilPoints);

	    else if(tempobj->square->label == "bccb") //Rotate counter-clockwise by 90 deg
	    {
	      theta = (pi/180)*90;
	      scaleRotTrans(tempobj, connectivity, count, theta, nodalStencilPoints);
	    }

	  else if(tempobj->square->label == "ccbb") //Rotate counter-clockwise by 180 deg
	    {
	      theta = pi;
	      scaleRotTrans(tempobj, connectivity, count, theta, nodalStencilPoints);
	    }

	  else if(tempobj->square->label == "cbbc") //Rotate counter-clockwise by 270 deg
	    {
	      theta = (pi/180)*270;
	      scaleRotTrans(tempobj, connectivity, count, theta, nodalStencilPoints);
	    }

	    count += 17;
	  }

	else if((tempobj->square->label == "abcb") || (tempobj->square->label == "bcba")
		|| (tempobj->square->label == "cbab") || (tempobj->square->label == "babc"))
	{
	  abcb += 1;
	  
	  if(tempobj->square->label == "abcb")
	    scaleTrans(tempobj, connectivity, count, nodalStencilPoints);

	  else if(tempobj->square->label == "bcba") //Rotate counter-clockwise by 90 deg
	    {
	      theta = (pi/180)*90;
	      scaleRotTrans(tempobj, connectivity, count, theta, nodalStencilPoints);
	    }

	  else if(tempobj->square->label == "cbab") //Rotate counter-clockwise by 180 deg
	    {
	      theta = pi;
	      scaleRotTrans(tempobj, connectivity, count, theta, nodalStencilPoints);
	    }

	  else if(tempobj->square->label == "babc") //Rotate counter-clockwise by 270 deg
	    {
	      theta = (pi/180)*270;
	      scaleRotTrans(tempobj, connectivity, count, theta, nodalStencilPoints);
	    }

	  count += 18;

	}

	else if((tempobj->square->label == "abbb") || (tempobj->square->label == "bbba")
		|| (tempobj->square->label == "bbab") || (tempobj->square->label == "babb"))
	{
	  abbb += 1;

	  if(tempobj->square->label == "abbb")
	    scaleTrans(tempobj, connectivity, count, nodalStencilPoints);

	  else if(tempobj->square->label == "bbba") //Rotate counter-clockwise by 90 deg
	    {
	      theta = (pi/180)*90;
	      scaleRotTrans(tempobj, connectivity, count, theta, nodalStencilPoints);
	    }

	  else if(tempobj->square->label == "bbab") //Rotate counter-clockwise by 180 deg
	    {
	      theta = pi;
	      scaleRotTrans(tempobj, connectivity, count, theta, nodalStencilPoints);
	    }

	  else if(tempobj->square->label == "babb") //Rotate counter-clockwise by 270 deg
	    {
	      theta = (pi/180)*270;
	      scaleRotTrans(tempobj, connectivity, count, theta, nodalStencilPoints);
	    }

	  count += 19;
	}

	else if((tempobj->square->label == "abab") || (tempobj->square->label == "baba"))
	  //Only two rotations required
	{
	  abab += 1;

	  if(tempobj->square->label == "abab")
	    scaleTrans(tempobj, connectivity, count, nodalStencilPoints);

	  else if(tempobj->square->label == "baba") //Rotate counter-clockwise by 90 deg
	    {
	      theta = (pi/180)*90;
	      scaleRotTrans(tempobj, connectivity, count, theta, nodalStencilPoints);
	    }

	  count += 18;	  
	}

	else if((tempobj->square->label == "aabb") || (tempobj->square->label == "abba")
		||(tempobj->square->label == "bbaa") || (tempobj->square->label == "baab"))
	{
	  aabb += 1;

	  if(tempobj->square->label == "aabb")
	    scaleTrans(tempobj, connectivity, count, nodalStencilPoints);

	  else if(tempobj->square->label == "abba") //Rotate counter-clockwise by 90 deg
	    {
	      theta = (pi/180)*90;
	      scaleRotTrans(tempobj, connectivity, count, theta, nodalStencilPoints);
	    }

	  else if(tempobj->square->label == "bbaa") //Rotate counter-clockwise by 180 deg
	    {
	      theta = pi;
	      scaleRotTrans(tempobj, connectivity, count, theta, nodalStencilPoints);
	    }

	  else if(tempobj->square->label == "baab") //Rotate counter-clockwise by 270 deg
	    {
	      theta = (pi/180)*270;
	      scaleRotTrans(tempobj, connectivity, count, theta, nodalStencilPoints);
	    }	
	  count += 21;

	}
	
	finalLeafNodes.pop();
    }
    
}

