# FRACT-OL
It’s time for you to create a basic computer graphics project!
You will use the school’s graphical library, the MiniLibX. This library was developed
internally and includes basic necessary tools to open a window, create images and deal
with keyboard and mouse events.
This will be an opportunity for you to become familiar with the MiniLibX library, dis-
cover or use the mathematical concept of complex numbers, explore computer graphics
optimization, and practice event handling.

## USAGE
If you want to explore my project clone the repository with :

```sh
git clone git@github.com:maelgini/fract-ol.git
```

Then situate yourself inside the repo :

```sh
cd fract-ol
```

Access the lib/ folder then minilibx-linux/ and make inside of it :

```sh cd lib/minilibx-linux/
make
```

Go back to the root of the folder and make

```sh
cd ..
cd ..
make
```

The binary will automatically be placed in bin/
To run the program, do :

```sh
bin/fractol <mandelbrot/tricorn/burningship/newton>
```

or

```sh
bin/fractol <julia> <double x> <double y>
```

(The julia fractal will always need 2 more arguments, these 2 double values will be the coordinates of the point inside the mandelbrot set you want to display as a Julia set)
## SCREENSHOTS
![Mandelbrot fractal](screenshots/mandelbrot1.png)
![Julia fractal 1](screenshots/julia3.png)
![Julia fractal 2](screenshots/julia1.png)
![Newton fractal](screenshots/newton1.png)
![Burningship fractal](screenshots/burningship1.png)
![Tricorn fractal](screenshots/tricorn1.png)

## CODE

First of all if you are not familiar with iterative functions I suggest you take a look at this article if not already done : https://en.wikipedia.org/wiki/Mandelbrot_set
It can get kind of overwhelming to represent this by coding it but this is easier than it looks.
### FORMULA
$Z_{n+1} = Z_n^2 + c$. This formula is iterated on the complex plane, which means that we will use complex numbers as our y axis and reals on the x axis, This is what makes this set particular and so unique.
When you chose a point on your complex plain and iterate this function you can get different behaviors :

It either diverges (the iteration of the chosen point by the formula makes it quickly or slowly branch off of the plane depending on how close it is to the figure)
Or it can converge inside the fractal and stay inside it almost infinetely (limited by the machine).
Given this I started to build a structure containing complex and real numbers to manipulate them.


### COLORS

One of the most import part of the project is the color management because it is what gives that depth impression to your rendering, Its mandatory to set colors to be different for each iteration of your fractal, I decided to implement a linear interpolation ([Wikipedia link](https://en.wikipedia.org/wiki/Plotting_algorithms_for_the_Mandelbrot_set#Continuous_(smooth)_coloring))

$Of formula :\phi(z) = \lim_{n \to \infty} (\log |z_n| / P^n)$.

to eliminate all color bandings and have a smooth gradient from black outside the set (Z(0)) to blue then green then finally red, Its an R->G->B gradient from Zmax to Z0 which is probably the best colorset to represent the depth of fractals (as you can see in the screenshots)


You will have to handle each pixel and test how they behave, This is called plotting, 
