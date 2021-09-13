# cellular-automaton

A cellular automaton implementation, featuring auto-resized dimension-agnostic grids.

## Features

* When more cells may be needed for subsequent steps, the **grid auto-resizes** itself to accomodate for future active cells.
* The core implementation of the algorithms is **dimension-agnostic**, which means that the same classes and algorithms can be used regardless of the number of spacial dimensions being used. 
* The structure of the project is better understood as a **library** upon which you can build visualization scripts or other software; evolutionary rules, auto-resizing constraints and the number of dimensions are some examples of parameters which can be manipulated.

## Visualization

The following visualization options are planned to be available as part of the project:

* 2D - A two dimensional square grid, with two different colors for active/inactive cell states.
* 3D [WIP] - A three dimensional cube grid, with camera options to change the view angle and with two different colors for active/inactive cell states.
* 4D [WIP] - A three dimensional cube grid, with camera options to change the view angle and with a color for inactive cell states and a range of color shades for active cell states.

You may implement yourself a visualization script for your preferred number of dimensions, using this software as an API/library to serve the core logic.

Furthermore, I would also like to add a GUI which can run any visualization program, with features such as evolutionary speed factor, forward/backwards, play/pause, etc.

## Dependencies

* xtensor C++ library (https://xtensor.readthedocs.io/en/latest/)
* sfml C++ library (https://www.sfml-dev.org/)

## Todos

* 3D and 4D visualization.
* GUI with play control options.
* Abstract cell states to allow for more than just active/inactive.
