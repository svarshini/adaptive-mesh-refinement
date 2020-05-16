#include<stdio.h>
#include<iostream>

#include<vector>
#include<queue>

#include<math.h>

#include<boost/geometry.hpp>
#include<boost/geometry/geometries/point.hpp>
#include<boost/geometry/geometries/box.hpp>
#include<boost/geometry/index/rtree.hpp>

#include "quadtree.h"
#include "stencil.h"

namespace bg = boost::geometry;
namespace bgi = boost::geometry::index;

typedef bg::model::point<double, 2, bg::cs::cartesian> point;
typedef std::pair<point, int> value;
	
void stitchNodes(std::vector<Point> nodalStencilPoints, std::vector<Point> &duplicatePoints)
{
  double threshold = 0.000003;
  bg::index::rtree<value, bg::index::quadratic<4>> rtree;
  std::vector<value> result;
  Point* temppt = new Point();
  point pt;
  int i = 1, count;
  bool check, flag;
  std::vector<Point>::iterator it;
  
  for(it = nodalStencilPoints.begin(); it != nodalStencilPoints.end(); it++)
    {
      pt.set<0>(it->x);
      pt.set<1>(it->y);
      rtree.insert(std::make_pair(pt, i));
      i++;
    }

  for(it = nodalStencilPoints.begin(); it != nodalStencilPoints.end(); it++) //Find four nearest points
    {
      pt.set<0>(it->x);
      pt.set<1>(it->y);
      rtree.query(bg::index::nearest(pt, 4), std::back_inserter(result));
    }
  
  for(int i=0; i<result.size(); i=i+4)
    {
      count=0;

      for(int j=i; j<(i+4); j++)
	{
	  if(fabs(bg::get<0>(result[i].first)-bg::get<0>(result[j].first))<threshold)
	    {
	      if(fabs(bg::get<1>(result[i].first)-bg::get<1>(result[j].first))<threshold)
		{
		  count++;
		}
	    }
	}
      
      if(count>1)
	{
	  for(int j=i; j<(i+4); j++)
	    {
	      if((fabs(bg::get<0>(result[i].first)-bg::get<0>(result[j].first))<threshold) &&
		 (fabs(bg::get<1>(result[i].first)-bg::get<1>(result[j].first))<threshold))
		{
		  temppt->x = bg::get<0>(result[j].first);
		  temppt->y = bg::get<1>(result[j].first);
		  temppt->number = result[j].second;
		  duplicatePoints.push_back(*temppt);
		}
	    }
	}
      
    }

    Point first, second, third, fourth;
    for(std::vector<Point>::iterator it = duplicatePoints.begin(); it!=duplicatePoints.end(); it++)
      {
	check = false;
	flag = false;
	count = 1;
	first.x = it->x;
	first.y = it->y;
	first.number = it->number;
	
	if(it!=duplicatePoints.end()-1)
      {
	it++;
	if((fabs(it->x-first.x) < threshold) && (fabs(it->y-first.y) < threshold))
	  {
	    second.x = it->x;
	    second.y = it->y;
	    second.number = it->number;
	  }
      }
	
	check = false;
	if(it!=duplicatePoints.end()-1)
	  {
	    it++;
	    if((fabs(it->x-first.x) < threshold) && (fabs(it->y-first.y) < threshold))
	      {
		third.x = it->x;
		third.y = it->y;
		third.number = it->number;
	      }

	    else
	      it--;
	  }
	
	check = false;
	if(it!=duplicatePoints.end()-1)	
	  {
	    
	   it++;

	   if((fabs(it->x-first.x) < threshold) && (fabs(it->y-first.y) < threshold))
	     {
	       fourth.x = it->x;
	       fourth.y = it->y;
	       fourth.number = it->number;
	     }
	   else
	     it--;
	  }
      }
}



