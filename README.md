# cub3D
cub3D is a group project from 42 School, inspired by the [Wolfenstein 3D game](http://users.atw.hu/wolf3d/).

## Overview
The goal was to create a dynamic view inside the maze based on the 2D map using [raycasting](https://lodev.org/cgtutor/raycasting.html) and the small graphics library [MiniLibX](https://github.com/42Paris/minilibx-linux).

![Inside the maze](/screen.png)


The input file includes floor and ceiling colors, textures for walls in each direction and 2D map where "1" represents a wall and "0" represents empty space.

![Input file example](/map_example.png)

## Controls

- **Look Around**: Use the left and right arrow keys to rotate your view.
- **Move**: Use W, A, S, and D keys to move forward, left, backward ans right.
- **Quit**: Press the ESC key or click the cross on the window frame to exit the program.

![cub3d gif](/cub3d.gif)

## Compile and run

Clone the repository
```shell
git clone https://github.com/antonioldev/cub3d.git
```

Include [MiniLibX](https://github.com/42Paris/minilibx-linux) to the root of the project and then run
```shell
make
```

Execute the program
```shell
./cub3d <path/to/map.cub>
```
## Bonus Part

Bonus part includes wall collisions, doors, animated sprites and rotation using the mouse.
Add "C" to the 2D map to put sprites, "d" to put doors on North and South walls, and "D" to put doors on East and West walls.

To compile bonus part run 

```shell
make bonus
```

## My experience

This project is my take on Cub3D, a raycasting engine built for the 9th project of the 42 London curriculum. I dove into the world of raycasting, using the minilib library and its X11 foundation to create a 3D environment from scratch.

The core concept of Cub3D is fascinating. Imagine a way to simulate a 3D world on a 2D screen — that's what raycasting is all about! This project helped me grasp the fundamentals of how rays are cast from the viewpoint of a player to determine what they see in the virtual world.

Building Cub3D involved getting my hands dirty with the minilib library, which sits on top of X11 for graphical applications. It was a great way to gain practical experience with these tools and understand how they work together to bring the 3D world to life on the screen.

Of course, the journey wasn't just about libraries –  it was also about honing my C programming skills in the context of graphics development. From manipulating data structures to handling calculations, Cub3D challenged me to apply my C knowledge in a new and exciting way.

This project is more than just code; it's a testament to the power of raycasting and the satisfaction of building a 3D world from the ground up. Feel free to explore the codebase, and who knows, maybe you'll even be inspired to add your own twist to Cub3D!
