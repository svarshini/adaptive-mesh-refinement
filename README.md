# Adaptive Mesh Refinement Using Quadtrees

![Cover Image](/results/adaptive_eg3.png)

## Overview
This work implements mesh generation algorithms introduced by Bern, Eppstein and Gilbert, in the paper - [Provably Good Mesh Generation](https://www.sciencedirect.com/science/article/pii/S0022000005800595#:~:text=We%20study%20several%20versions%20of,meshes%20for%20finite%20element%20methods.&text=All%20our%20triangulations%20have%20size,and%20output%20of%20size%20k.). It takes in a user-defined error function or point cloud as input which quantifies the underlying error, based on which a preliminary quadtree is constructed. 

Methods of balancing and strong balancing as prescribed by the paper are applied, after which stencils are fit, to obtain the final adaptively refined mesh. This software was used to improve the solution accuracy of an obstacle problem by an order of magnitude. 

This work was conducted under the guidance of [Prof. Ramsharan Rangarajan](https://mecheng.iisc.ac.in/~rram/index.html) at the Mechanics and Computation Lab, Department of Mechanical Engineering, Indian Institute of Science.

## Project Page

More details can be found at the project page - [Adaptive Mesh Refinement Using Quadtrees](https://svarshini.github.io/index_project_quad.html).

## Code Usage

To compile, run the following commands:

```
mkdir build
cd build/
cmake .
make
```

Modify the error function in *quadtree.cpp* to prescribe the erroneous finite element region:

```
error = offset+(f(x,y))
```

Here, *(x,y)* denotes the coordinates of the centre of the quadtree and *offset* denotes an arbitrary constant which is used to avoid a zero error during subdivision.

For the error function 0.1+(2*x*y), the following demonstrates a sample input:

```
Enter spatial dimensions of the QuadTree:
X coordinate:
1
Y coordinate: 
1
Width:
4
```

Alternatively, you can prescribe a point cloud with *(x,y)* coordinates to generate your preliminary quadtree.

## Examples

The following inputs generate the meshes shown in the images:

* Function: 0.1 + xy

Preliminary quadtree:

<img src="/results/quad_0.1+xy.png" width="402" height="402"/>

Strongly balanced tree:

<img src="/results/quad_0.1+xy_strbal.png" width="402" height="402"/>

* Function: 0.01 + xy

Centre of quadtree: (1,1)

Width: 6

<img src="/results/fn_0.01+xy.png" width="808" height="406"/>


## Stencil Fitting

Bern and Eppstein recommend the fitting of stencils to obtain provably good meshes after generating the strongly balanced quadtree.

<img src="/results/stencil_animation.gif" width="400" height="400"/>

## Point Clouds

A hole in a plate can be analysed as shown using an adaptively refined mesh. The inputs include the dimensions of the plate and a point cloud describing the hole. 

<img src="/results/adaptive_eg.gif" width="400" height="400"/>

Any arbitrary point cloud (like the flower shown below) can also be used to generate a mesh, which can be refined in an adaptive manner, using this algorithm.

<img src="/results/adaptive_eg2.gif" width="400" height="400"/>


## Obstacle Problem 
The obstacle problem studies the contact region boundary between a thin square membrane clamped at its four corners and a flat infinite plate which acts as an obstacle. Two meshes were tested, a regular triangulation and an adaptively refined triangulation based on an input point cloud. The solution obtained by the adaptively refined mesh was in the range (-0.03, 0.03) as opposed to the range (-0.1, 0.1) obtained by the regular mesh. This demonstrates nearly an order of magnitude higher accuracy in the adaptively refined mesh, since the true solution for the displacement flux = 0.

<img src="/results/obstacle.png" width="748" height="365"/>

### Solution Comparisons

Initial guesses perturbed to final positions are visualized below along with solutions for the displacement flux: 

#### Regular Mesh 

<img src="/results/regular_obstacle.gif" width="495" height="479"/>

<img src="/results/regular_flux.png" width="544" height="408"/>

#### Adaptive Mesh

<img src="/results/adaptive_obstacle.gif" width="770" height="425"/>

<img src="/results/adaptive_flux.png" width="544" height="408"/>

