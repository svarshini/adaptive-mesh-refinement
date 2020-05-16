#ifndef CONN_UTIL_H
#define CONN_UTIL_H

void insertPoints(std::queue<Quadtree*> finalLeafNodes, std::vector<double> &xNodalPoints,
		  std::vector<double> &yNodalPoints);

void makePointVector(std::vector<Point> &nodalPoints, std::vector<double> xNodalPoints,
		     std::vector<double> yNodalPoints);

void markConnectivity(std::queue<Quadtree*> finalLeafNodes,
		      std::vector<Point> nodalPoints);

void modifyConnectivities(std::queue<Quadtree*> finalLeafNodes,
			  std::map<int,int> map1, std::map<int,int> map2);

#endif
