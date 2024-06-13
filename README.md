ID - 208768978
Email - michibinyamin@gmail.com



objects :

- catan
- board
- player
- dice
- tile
- settelment
- path
- card (פיתוח)
- night
- victory win
- build two roards
- monopoly, take a card from everyone



how will a player choose a road\settelment positions :
- settalment - a number representing the position on the board
- road - a number representing the road on the board


Tile :
- land (sea, desert, forest, )
- number (0 - no number, 2,3,4,5,6,8,9,10,11,12)

Path : 
- number representing on board (int)
- owner - indicates to who this path belongs (0 - belongs to no one)
- two positions, the vertecies in both sides of the path (Position)

Position : (a class which represents a vertex on the graph)
- number representing on board (int)
- owner - indicates to who this vertex belongs (0 - belongs to no one)
- 3 tiles   (Tile)
- 3 roads(which road belongs to who)    (int)
- 3 neighbors(linked together)  (position)



board :
- a list of vertecies
- a list of paths
- a list of tiles
- init method which initializes the board accourding to a list of tiles that it gets

player :
- 



![alt text](<WhatsApp Image 2024-06-09 at 11.20.40 AM.jpeg>)
