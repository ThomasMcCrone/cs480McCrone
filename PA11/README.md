# PA11: Sumo Snowmen

# Team Members
### Thomas McCrone

# Dependencies, Building, and Running

## Notes:
Tried to implement sound on collisions and when a player died, not working. Tried to allow the players to grab snowballs and fire them at each other, not working. could not get spotlights to follow
the players around.

## Dependency Instructions
This project uses the following libraries:
- GLM
- Glew
- Bullet
- Assimp
- ImageMagick

### Ubuntu/Linux
```bash
sudo apt-get install libglew-dev libglm-dev libsdl2-dev libbullet-dev
```

### Mac OSX
Installation of brew is suggested to easily install the libs. Ensure that the latest version of the Developer Tools is installed.
```bash
brew install glew glm sdl2 bullet assimp imagemagick
```



### CMake Instructions
The building of the project is done using CMake, installation with apt-get or brew may be necessary. 

```bash
mkdir build
cd build
cmake ..
make
./Bullet
```

### Keys

Move player1
	-WASD
Move player2
	-up arrow, down arrow, left arrow, right arrow