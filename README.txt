KIIT CAMPUS-25 NAVIGATION
=========================

PROJECT OVERVIEW
----------------
A simple C-based indoor navigation program for the KIIT School of Computer
Engineering. It uses Dijkstra's algorithm to find a shortest route between
locations represented in navigation_data.txt.

PROJECT FILES
-------------
1. navigation.c
   The C source code. It reads the navigation data, builds a bidirectional
   weighted graph, and calculates a shortest route.

2. navigation_data.txt
   The navigation graph data. Each valid connection line contains:
       Location1 Location2 MinimumSteps MaximumSteps

   Example:
       A001 A002 10 20

   The program uses the average of the minimum and maximum values as the
   edge weight. In the example above, the weight is 15 steps.

HOW IT WORKS
------------
1. The program opens navigation_data.txt from the current working directory.
2. It reads the file line by line and skips comment/blank lines.
3. It assigns each location a node in the graph.
4. Each connection is added in both directions, so travel is bidirectional.
5. Dijkstra's algorithm finds the route with the lowest total estimated steps.
6. The program prints the route and estimated total steps.

REQUIREMENTS
------------
- A C compiler such as GCC.
- navigation.c and navigation_data.txt in the same project folder.

COMPILE
-------
Open Command Prompt in the project folder and run:

    gcc navigation.c -o navigation

RUN
---
Run:

    navigation.exe

When prompted, enter the start and destination IDs exactly as written in
navigation_data.txt.

Example:

    Enter starting location: A001
    Enter destination: A201

ENTRANCE LOCATIONS
------------------
Entrance IDs can be used as a start or destination if they exist in the data
file and are connected to the graph. Use the exact ID, for example:

    Main_Entrance_A
    Main_Entrance_B

Check navigation_data.txt for the exact available IDs.

DISTANCE CALCULATION
--------------------
For each connection:

    Weight = (MinimumSteps + MaximumSteps) / 2

The weight is an estimated number of steps, not a measured walking distance.
For example, a range of 10 to 20 steps becomes 15 steps.

BIDIRECTIONAL CONNECTIONS
-------------------------
Each connection is treated as bidirectional. If the file contains:

    A001 A002 10 20

the graph contains both A001 -> A002 and A002 -> A001, each with a weight of
15 steps.

IMPORTANT NOTES
---------------
- Location IDs must match the IDs in navigation_data.txt exactly.
- IDs containing spaces are not supported by the current input format; use
  underscore-separated IDs such as Main_Entrance_A.
- A location must appear in at least one valid connection line to be loaded
  into the graph.
- A route is available only if the start and destination are connected through
  the listed edges.
- The upper-floor connections were generated from the supplied layout pattern
  and should be physically checked before using this for real navigation.
- Distances are approximate and results depend on the accuracy of the data.
- Keep navigation_data.txt in the same folder from which navigation.exe is run.

TROUBLESHOOTING
---------------
1. "Cannot open navigation_data.txt"
   Check that navigation_data.txt is in the current working directory and
   that the filename is spelled correctly.

2. "Invalid starting location or destination!"
   Check that both IDs appear in valid data lines in navigation_data.txt.
   Also confirm the program successfully reads the data file.

3. "No route found!"
   The locations may be disconnected in the graph, or a connection may be
   missing from navigation_data.txt.

4. Compilation error
   Check that navigation.c is saved correctly and GCC is installed.

PROJECT LIMITATIONS
-------------------
- This is a basic graph-based navigation prototype, not a live indoor
  positioning system.
- It does not detect the user's current location automatically.
- It calculates the shortest route by estimated step count, not by time,
  accessibility, or real measured distance.
- Staircases are represented by the connections listed in the data file.

END
