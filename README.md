ID - 208768978
Email - michibinyamin@gmail.com


how will a players choose a road\settelment positions :
- settalment - a number representing the position on the board
- road - a number representing the road on the board
- I have attached a catan map which is a map of the road numbers and the positions(vertexes) numbers

objects :
- catan
- board
- player
- tile
- position (where we put settelments)
- path (where we put roads)
- development card
- monopoly card
- knight
- victory point
- road builder
- year of plenty

Catan : 
- 3 players
- board
- print winner

Tile :
- land (desert, forest, hills, pastures, mountains, fields)
- number (0 - no number, 2,3,4,5,6,8,9,10,11,12)

Path : 
- number representing on board (int)
- owner - indicates to who this path belongs (0 - belongs to no one)
- two positions, the vertecies in both sides of the path (Position)

Position : (a class which represents a vertex on the graph)
- number representing on board (int)
- owner - indicates to who this vertex belongs (who build a settalment, 0 - belongs to no one)
- city - a boolean indicating if a city is built here
- 3 tiles   (Tile)
- 3 paths(linked together)    (Path)

board :
- a list of positions   (54)
- a list of paths       (72)
- a list of tiles       (19)
- init method which initializes the board accourding to a list of tiles that it gets + linkes together the paths and positions in the correct order
- set position - gets a owner and int representing the position and places the settalment(player class cals this function)
- set initial position - same as above but no need for path between two settalments, for the initial rounds
- set path - get a owner and int representing the path and place a road (player class calls this function)
- print board - I have used ascii art to represent the board printed, the vertecies and paths have a number representing who it belongs to(if it does) but i did not print if there is a city for estetic reasons, but a city exists aswell in the logic!

player :
- instance of Catan (so player can controll the game)
- name
- player num(id)
- points 
- resources (integers representing the 5 resources)
- Roll dice
- place settalment
- place city
- place road
- buy card
- use card (3 types uses function overloading to use diffarent cards)
- trade
- end turn
- won game - player uses to say that he won the game. returns true if so.

development card : a general class representing a development card
- instance of Catan game (for using actions)
- get name (card name)
- print card (a virtual class, prints what the card does)

monopoly card : inherits from development card
- print card (override)
- action - uses the Catan instance to do the action

Same for :
knight
victory point
road builder
year of plenty


Librarys :  
- #include <iostream>
- #include <vector>
- #include <string>
- #include <stdexcept>

Test :
- I defined public to private in the test unit so i have acces to change things manually in all of the objects this gives me more flexibility for testing
- There is one test unit which checks the diffarent stages of the game and the legal moves


General :
- position = vertex = where settalment/city is put
- the resources are named the same as the tiles


![alt text](1000195580.png)