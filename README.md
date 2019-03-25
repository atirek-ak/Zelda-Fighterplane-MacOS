# Zelda Fighterplane
A 3D fighter plane game  
Designed to run on Mac OS   

## Getting Started
### Install OpenGL
You need to install the development packages of the following libraries:  
* GLEW 
* GLFW3 
* GLM
```brew install glew glfw glm cmake pkg-config```

### Make instructions: (or directly run this script using ```bash make.sh```)
- ```mkdir build```
- ```cd build```
- ```cmake ../```
- ```make all -j 4```

Note - In case of Experimental Error for GLM add ```#define GLM_ENABLE_EXPERIMENTAL``` in the files main.h, nonedit.cpp, other_handlers.cpp, and input.cpp before you include glm.

### To run the game
- Go to build directory
- ```./graphics_asgn1```

## Controls:
* w - Forward
* a,d - Roll
* q,e - Yaw
* 2,s - Pitch
* Space Bar - Increase height
* k - hover
* Right mouse click - Drop bomb
* Left Mouse Click - Missile
* c - Change camera view
* r - Perform a barrel roll
* l - Perform a loop the loop

## Built using
* C++
* OpenGL

## Author
Atirek Kumar
Github Handle Link: https://github.com/atirek-ak/

## Acknowledgement
Boilerplate : https://github.com/sidgairo18/Graphics_Spring_19_Boilerplate.git
