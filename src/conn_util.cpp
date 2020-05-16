#include<stdio.h>
#include<iostream>

#include<vector>
#include<queue>
#include<map>

#include<algorithm>
#include<math.h>

#include "quadtree.h"
#include "conn_util.h"


void insertPoints(std::queue<Quadtree*> finalLeafNodes, std::vector<double> &xNodalPoints,
		  std::vector<double> &yNodalPoints)
{
    std::vector<double>::iterator iter1, iter2;

    while(!finalLeafNodes.empty())
      {
	Quadtree* tempobj = finalLeafNodes.front();
	
	if(tempobj->nw != NULL)
	  {
	    finalLeafNodes.pop();
	    continue;
	  }
	
	else
	  {

	    for(int count = 0; count < 4; count++)
	      {
		double temp_x, temp_y;

		if(count == 0)
		  {
		    temp_x = tempobj->qtcell->a.x;
		    temp_y  = tempobj->qtcell->a.y;
		  }

		if(count == 1)
		  {
		    temp_x = tempobj->qtcell->b.x;
		    temp_y  = tempobj->qtcell->b.y;
		  }

		if(count == 2)
		  {
		    temp_x = tempobj->qtcell->c.x;
		    temp_y  = tempobj->qtcell->c.y;
		  }

		if(count == 3)
		  {
		    temp_x = tempobj->qtcell->d.x;
		    temp_y  = tempobj->qtcell->d.y;
		  }
		
		iter1 = std::find(xNodalPoints.begin(), xNodalPoints.end(), temp_x);
		iter2 = std::find(yNodalPoints.begin(), yNodalPoints.end(), temp_y);
		
		if((iter1 == xNodalPoints.end()) && (iter2 == yNodalPoints.end()))
		  {
		    xNodalPoints.push_back(temp_x);
		    yNodalPoints.push_back(temp_y);
		  }
		
		else if((iter1 == xNodalPoints.end()) || (iter2 == yNodalPoints.end()))
		  {
		    xNodalPoints.push_back(temp_x);
		    yNodalPoints.push_back(temp_y);
		  }
		
		else
		  {
		    while(iter1 != xNodalPoints.end())
		      {
			iter1 = std::find(iter1, xNodalPoints.end(), temp_x);
			auto index = std::distance(xNodalPoints.begin(), iter1);
			
			if(index == xNodalPoints.size())
			  break;
			
			else if(yNodalPoints.at(index) == temp_y)
			  break;
			
			else
			  iter1++;
		      }
		    
		    if(iter1 == xNodalPoints.end())
		      {
			xNodalPoints.push_back(temp_x);
			yNodalPoints.push_back(temp_y);
		      }
		  }
	      }
	    
	    finalLeafNodes.pop();
	    
	  }
      }   
}


void makePointVector(std::vector<Point> &nodalPoints, std::vector<double> xNodalPoints,
		     std::vector<double> yNodalPoints)
  {
    int count = 1;
    Point* temppt = NULL;
    
    std::vector<double>::iterator iter1 = xNodalPoints.begin();
    std::vector<double>::iterator iter2 = yNodalPoints.begin();

    while((iter1 != xNodalPoints.end()) && (iter2 != yNodalPoints.end()))
      {
	temppt = new Point(*iter1, *iter2);
	temppt->number = count;

	nodalPoints.push_back(*temppt);

	iter1++;
	iter2++;
	count++;
      }
  }


void markConnectivity(std::queue<Quadtree*> finalLeafNodes, std::vector<Point> nodalPoints)
  {
    Quadtree* tempobj;
    Point* temppt;
    std::vector<Point>::iterator iter;
    
    while(!finalLeafNodes.empty())
      {
	tempobj = finalLeafNodes.front();
	
	for(iter = nodalPoints.begin(); iter != nodalPoints.end(); iter++)
       {
	 temppt = &(*iter);
	 
	 if((tempobj->qtcell->a.x == temppt->x) && (tempobj->qtcell->a.y == temppt->y))
	   tempobj->qtcell->a.number = temppt->number;
	 
	 if((tempobj->qtcell->b.x == temppt->x) && (tempobj->qtcell->b.y == temppt->y))
	   tempobj->qtcell->b.number = temppt->number;
	 
	 if((tempobj->qtcell->c.x == temppt->x) && (tempobj->qtcell->c.y == temppt->y))
	   tempobj->qtcell->c.number = temppt->number;	        
	 
	 if((tempobj->qtcell->d.x == temppt->x) && (tempobj->qtcell->d.y == temppt->y))
	   tempobj->qtcell->d.number = temppt->number;
	  
      }
	
    finalLeafNodes.pop();
  }
}


void modifyConnectivities(std::queue<Quadtree*> finalLeafNodes, std::map<int,int> map1,
			  std::map<int,int> map2)
  {
    Quadtree* ptr;
    bool checka, checkb, checkc;

    while(!finalLeafNodes.empty())
      {
	ptr = finalLeafNodes.front();
	if(ptr->nw != NULL)
	  {
	    finalLeafNodes.pop();
	    continue;
	  }

	for(std::vector<Connect>::iterator iter = ptr->StencilConnect.begin();
	    iter!=ptr->StencilConnect.end(); iter++)
	{
	  checka = checkb = checkc = false; 

	  for(std::map<int,int>::iterator it1 = map2.begin(); it1 != map2.end(); it1++)
	    {
	      if(iter->a == it1->first)
		{
		  iter->a = it1->second;
		  checka = true;
		  break;
		}
	    }
	  
	  if(checka == false)
	    {
	      for(std::map<int,int>::iterator it2 = map1.begin(); it2 != map1.end(); it2++)
		{
		  if(iter->a == it2->first)
		    {
		      iter->a = it2->second;
		      checka = true;
		      break;
		    }
		}
	    }
	  
	  for(std::map<int,int>::iterator it1 = map2.begin(); it1 != map2.end(); it1++)
	    {
	      if(iter->b == it1->first)
		{
		  iter->b = it1->second;
		  checkb = true;
		  break;
		}
	    }

	  if(checkb == false)
	    {
	      for(std::map<int,int>::iterator it2 = map1.begin(); it2 != map1.end(); it2++)
		{
		  if(iter->b == it2->first)
		    {
		      iter->b = it2->second;
		      checkb = true;
		      break;
		    }
		}
	    }
	  
	  for(std::map<int,int>::iterator it1 = map2.begin(); it1 != map2.end(); it1++)
	    {
	       if(iter->c == it1->first)
		 {
		   iter->c = it1->second;
		   checkc = true;
		   break;
		 }
	    }
	  
	  if(checkc == false)
	    {
	      for(std::map<int,int>::iterator it2 = map1.begin(); it2 != map1.end(); it2++)
		{
		  if(iter->c == it2->first)
		    {
		      iter->c = it2->second;
		      checkc = true;
		      break;
		    }
		}
	    }
	}
	
	finalLeafNodes.pop();
      }
  }


