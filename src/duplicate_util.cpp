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

void insertPoints(std::vector<Point> nodalStencilPoints, std::vector<Point> &newPoints,
		  std::map<int,int> &map1, std::map<int,int> &map2)
{
  Point temp;
  bool check;
  double threshold = 0.000003;

  for(std::vector<Point>::iterator it1 = nodalStencilPoints.begin(); it1!=nodalStencilPoints.end(); it1++)
    {
      check = false;
      temp.x = it1->x;
      temp.y = it1->y;
      temp.number = it1->number;

      for(std::vector<Point>::iterator it2 = newPoints.begin(); it2 != newPoints.end(); it2++)
	{
	  if((fabs(temp.x-it2->x) < threshold) && (fabs(temp.y-it2->y) < threshold))
	    {
	      map1.insert(std::make_pair(temp.number, it2->number));
	      check = true;
	      break;
	    }
	}

      if(check == false)
	{
	  newPoints.push_back(temp);
	}
    }
  
  std::map<int,int>::iterator newmapit = map1.begin();
  
  while(newmapit != map1.end())
    newmapit++;
  
  int count1 = 1;
  int count2 = 1; 
  //Fill second map with only those elements which are not being mapped in the first map
  
  for(std::map<int,int>::iterator mapit = map1.begin(); mapit != map1.end(); mapit++)
    {
      while(count1<mapit->first)
	{
	  map2.insert(std::make_pair(count1, count2));
	  count1++;
	  count2++;
	}
      
      if((count1 == mapit->first) && ((mapit->first) == (mapit->second)))
	{
	  map2.insert(std::make_pair(count1, count2));
	  count1++;
	  count2++;
	  continue;
	}
      
      else if(mapit->first!=mapit->second)
	{
	  count1++;
	  continue;
	}
    }
  
  while(count1 != nodalStencilPoints.size()+1)
    {
      map2.insert(std::make_pair(count1, count2));
      count1++;
      count2++;
    }
  
  std::map<int,int>::iterator mapit = map2.begin();
  
  while(mapit != map2.end())
    mapit++;
  
  
  for(std::map<int,int>::iterator iter = map1.begin(); iter != map1.end(); iter++)
    {
      for(std::map<int,int>::iterator it = map2.begin(); it != map2.end(); it++)
	{
	  if(iter->second==it->first)
	    {
	      iter->second = it->second;
	      break;
	    }
	}
    }
  
  std::map<int,int>::iterator newmapit2 = map1.begin();
  
  while(newmapit2 != map1.end())
      newmapit2++;
  
}


void checkPoints(std::vector<Point> &newPoints)
  {
    typedef bg::model::point<double, 2, bg::cs::cartesian> point;
    typedef std::pair<point, int> value;
    bg::index::rtree<value, bg::index::quadratic<4>> rtree;

    std::vector<value> checkresult;
    point pt;
    int i = 1, count;
    bool check, flag;
    double threshold = 0.000003;

    for(std::vector<Point>::iterator it = newPoints.begin(); it != newPoints.end(); it++)
      {
	pt.set<0>(it->x);
	pt.set<1>(it->y);
        rtree.insert(std::make_pair(pt, i));
        i++;
      }

    for(std::vector<Point>::iterator it = newPoints.begin(); it != newPoints.end(); it++)
      {
	pt.set<0>(it->x);
	pt.set<1>(it->y);
	rtree.query(bg::index::nearest(pt, 4), std::back_inserter(checkresult));
      }
    
    for(int i=0; i<checkresult.size(); i=i+4)
      {
	count=0;

	for(int j=i; j<(i+4); j++)
	  {
	    if((fabs(bg::get<0>(checkresult[i].first)-bg::get<0>(checkresult[j].first))<threshold) &&
	       (fabs(bg::get<1>(checkresult[i].first)-bg::get<1>(checkresult[j].first))<threshold))
	      count++;
	  }
      }
  }

