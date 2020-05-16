#include<stdio.h>
#include<iostream>

#include<vector>
#include<queue>

#include<math.h>

#include "quadtree.h"
#include "stencil.h"

void aaaa(Quadtree* iterator, std::ifstream &infile)
{
  infile.open("../quadstencils/pointfiles/AAAA.dat");
  
  Point* temp = new Point();
  
  for(int i = 1; i <= 25; i++)
     {
       infile>>temp->x;
       infile>>temp->y;
       iterator->Stencil.push_back(*temp);
     }

  infile.close();
  
}

void aaaa_conn(Quadtree* iterator, std::ifstream &infile)
{
  infile.open("../quadstencils/pointfiles/AAAAConn.dat");

  Connect* tempconn = new Connect();

  for(int i = 1; i <= 32; i++)
    {
      infile>>tempconn->a;
      infile>>tempconn->b;
      infile>>tempconn->c;
      iterator->StencilConnect.push_back(*tempconn);
    }

  infile.close();
}

void bbbb(Quadtree* iterator, std::ifstream &infile)
{
  infile.open("../quadstencils/pointfiles/BBBB.dat");

  Point* temp = new Point();

  for(int i = 1; i <= 20; i++)
    {
      infile>>temp->x;
      infile>>temp->y;
      iterator->Stencil.push_back(*temp);
    }

  infile.close();
}

void bbbb_conn(Quadtree* iterator, std::ifstream &infile)
{
  infile.open("../quadstencils/pointfiles/BBBBConn.dat");
  Connect* tempconn = new Connect();

   for(int i = 1; i <= 26; i++)
    {
      infile>>tempconn->a;
      infile>>tempconn->b;
      infile>>tempconn->c;
      iterator->StencilConnect.push_back(*tempconn);
    }

  infile.close();
}

void aaab(Quadtree* iterator, std::ifstream &infile)
{
  infile.open("../quadstencils/pointfiles/AAAB.dat");

  Point* temp = new Point();

  for(int i = 1; i <= 22; i++)
    {
      infile>>temp->x;
      infile>>temp->y;
      iterator->Stencil.push_back(*temp);
    }
  
  infile.close();
}

void aaab_conn(Quadtree* iterator, std::ifstream &infile)
{
  infile.open("../quadstencils/pointfiles/AAABConn.dat");

  Connect* tempconn = new Connect();

  for(int i = 1; i <= 27; i++)
    {
      infile>>tempconn->a;
      infile>>tempconn->b;
      infile>>tempconn->c;
      iterator->StencilConnect.push_back(*tempconn);
    }
  
  infile.close();
}

void bbbc(Quadtree* iterator, std::ifstream &infile)
{
  infile.open("../quadstencils/pointfiles/BBBC.dat");

  Point* temp = new Point();

  for(int i = 1; i <= 19; i++)
    {
      infile>>temp->x;
      infile>>temp->y;
      iterator->Stencil.push_back(*temp);
    }

  infile.close();
}

void bbbc_conn(Quadtree* iterator, std::ifstream &infile)
{
  infile.open("../quadstencils/pointfiles/BBBCConn.dat");

  Connect* tempconn = new Connect();

  for(int i = 1; i <= 25; i++)
    {
      infile>>tempconn->a;
      infile>>tempconn->b;
      infile>>tempconn->c;
      iterator->StencilConnect.push_back(*tempconn);
    }
  
  infile.close();
}

void bbcc(Quadtree* iterator, std::ifstream &infile)
{
  infile.open("../quadstencils/pointfiles/BBCC.dat");

  Point* temp = new Point();

  for(int i = 1; i <= 17; i++)
    {
      infile>>temp->x;
      infile>>temp->y;
      iterator->Stencil.push_back(*temp);
    }

  infile.close();
}

void bbcc_conn(Quadtree* iterator, std::ifstream &infile)  
{
  infile.open("../quadstencils/pointfiles/BBCCConn.dat");

  Connect* tempconn = new Connect();

  for(int i = 1; i <= 22; i++)
    {
      infile>>tempconn->a;
      infile>>tempconn->b;
      infile>>tempconn->c;
      iterator->StencilConnect.push_back(*tempconn);
    }

  infile.close();
}

void abcb(Quadtree* iterator, std::ifstream &infile)
{
  infile.open("../quadstencils/pointfiles/ABCB.dat");

  Point* temp = new Point();

  for(int i = 1; i <= 18; i++)
    {
      infile>>temp->x;
      infile>>temp->y;
      iterator->Stencil.push_back(*temp);
    }
  
  infile.close();
}

void abcb_conn(Quadtree* iterator, std::ifstream &infile)
{
  infile.open("../quadstencils/pointfiles/ABCBConn.dat");

  Connect* tempconn = new Connect();

  for(int i = 1; i <= 22; i++)
    {
      infile>>tempconn->a;
      infile>>tempconn->b;
      infile>>tempconn->c;
      iterator->StencilConnect.push_back(*tempconn);
    }
  
  infile.close();
}

void abbb(Quadtree* iterator, std::ifstream &infile)
{
  infile.open("../quadstencils/pointfiles/ABBB.dat");

  Point* temp = new Point();

  for(int i = 1; i <= 19; i++)
    {
      infile>>temp->x;
      infile>>temp->y;
      iterator->Stencil.push_back(*temp);
    }

  infile.close();
}

void abbb_conn(Quadtree* iterator, std::ifstream &infile)
{
  infile.open("../quadstencils/pointfiles/ABBBConn.dat");

  Connect* tempconn = new Connect();

  for(int i = 1; i <= 23; i++)
    {
      infile>>tempconn->a;
      infile>>tempconn->b;
      infile>>tempconn->c;
      iterator->StencilConnect.push_back(*tempconn);
    }
  
  infile.close();
}

void abab(Quadtree* iterator, std::ifstream &infile)
{
  infile.open("../quadstencils/pointfiles/ABAB.dat");

  Point* temp = new Point();

  for(int i = 1; i <= 18; i++)
    {
      infile>>temp->x;
      infile>>temp->y;
      iterator->Stencil.push_back(*temp);
    }

  infile.close();
}

void abab_conn(Quadtree* iterator, std::ifstream &infile)
{
  infile.open("../quadstencils/pointfiles/ABABConn.dat");

  Connect* tempconn = new Connect();

  for(int i = 1; i <= 20; i++)
    {
      infile>>tempconn->a;
      infile>>tempconn->b;
      infile>>tempconn->c;
      iterator->StencilConnect.push_back(*tempconn);
    }

  infile.close();
}

void aabb(Quadtree* iterator, std::ifstream &infile)
{
  infile.open("../quadstencils/pointfiles/AABB.dat");

  Point* temp = new Point();

  for(int i = 1; i <= 21; i++)
    {
      infile>>temp->x;
      infile>>temp->y;
      iterator->Stencil.push_back(*temp);
    }

  infile.close();
}

void aabb_conn(Quadtree* iterator, std::ifstream &infile)
{
  infile.open("../quadstencils/pointfiles/AABBConn.dat");

  Connect* tempconn = new Connect();

  for(int i = 1; i <= 26; i++)
    {
      infile>>tempconn->a;
      infile>>tempconn->b;
      infile>>tempconn->c;
      iterator->StencilConnect.push_back(*tempconn);
    }
  
  infile.close();
}

void fillStencil(std::queue<Quadtree*> finalLeafNodes, std::ifstream &infile)
  {
    Quadtree* iterator;
      
    while(!finalLeafNodes.empty())
   {
     iterator  = finalLeafNodes.front();

     if(iterator->nw == NULL)
       {    
	 if(iterator->square->label == "aaaa")
	   {
	     aaaa(iterator, infile);
	     aaaa_conn(iterator, infile);
	   }

	 else if(iterator->square->label == "bbbb")
	   {
	     bbbb(iterator, infile);
	     bbbb_conn(iterator, infile); 
	   }

	 else if((iterator->square->label == "aaab") ||
		 (iterator->square->label == "aaba") ||
		 (iterator->square->label == "abaa") ||
		 (iterator->square->label == "baaa"))
	   {
	     aaab(iterator, infile);
	     aaab_conn(iterator, infile); 
	   }

	 else if((iterator->square->label == "bbbc") ||
		 (iterator->square->label == "bbcb") ||
		 (iterator->square->label == "bcbb") ||
		 (iterator->square->label == "cbbb"))
	   {
	     bbbc(iterator, infile);
	     bbbc_conn(iterator, infile); 
	   }

	 else if((iterator->square->label == "bbcc") ||
		 (iterator->square->label == "bccb") ||
		 (iterator->square->label == "ccbb") ||
		 (iterator->square->label == "cbbc"))
	   {
	     bbcc(iterator, infile);
	     bbcc_conn(iterator, infile); 
	   }

	 else if((iterator->square->label == "abcb") ||
		 (iterator->square->label == "bcba") ||
		 (iterator->square->label == "cbab") ||
		 (iterator->square->label == "babc"))
	   {
	     abcb(iterator, infile);
	     abcb_conn(iterator, infile);
	   }

	 else if((iterator->square->label == "abbb") ||
		 (iterator->square->label == "bbba") ||
		 (iterator->square->label == "bbab") ||
		 (iterator->square->label == "babb"))
	   {
	     abbb(iterator, infile);
	     abbb_conn(iterator, infile);
	   }

	 else if((iterator->square->label == "abab") ||
		 (iterator->square->label == "baba"))
	   {
	     abab(iterator, infile);
	     abab_conn(iterator, infile);
	   }

	 else if((iterator->square->label == "aabb") ||
		 (iterator->square->label == "abba") ||
		 (iterator->square->label == "bbaa") ||
		 (iterator->square->label == "baab"))
	   {
	     aabb(iterator, infile);
	     aabb_conn(iterator, infile);
	   }
       }

     finalLeafNodes.pop();
   }
    
  }

