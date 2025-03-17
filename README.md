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

`git clone git@github.com:maelgini/fract-ol.git`

Then situate yourself inside the repo :

`cd fract-ol`

Access the lib/ folder then minilibx-linux/ and make inside of it :

`cd lib/minilibx-linux/
make`

Go back to the root of the folder and make

`cd ..
cd ..
make`

The binary will automatically be placed in bin/
To run the program, do :

`bin/fractol <mandelbrot/tricorn/burningship/newton>`

or

`bin/fractol <julia> <double x> <double y>`

(these 2 double values will be the coordinates of the point inside the mandelbrot set you want to display)
## SCREENSHOTS
![Mandelbrot fractal](screenshots/mandelbrot1.png)
![Julia fractal 1](screenshots/julia3.png)
![Julia fractal 2](screenshots/julia1.png)
![Newton fractal](screenshots/newton1.png)
![Burningship fractal](screenshots/burningship1.png)
![Tricorn fractal](screenshots/tricorn1.png)
