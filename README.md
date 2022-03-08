# PSU-101_navy
Epitech B1 project : navy (2021)

Result : 100%
Coding style: Too many style errors

## Build :
`make`

## Run : 
`./navy boat_positions`
### Display help :
`./navy -h`

## Info about project :

**Authorized functions :** 
     *open, close, read, write, lseek, malloc, free, getpid, kill, signal,
    sigaction, sigemptyset, setcontext, getcontext, usleep, nanosleep, pause, getline, fopen,
    fclose*

### How our program work

- Load PIDs, map & ships position into structures.
- First player wait for connection.
- Second player start the game by connecting (with PID).
- The program create an int array for the map and store it in memory.
- The program write positions of the ships in the map.
- The program wait player input and send it to the other player's processus in binary base, using signals.
- It check if a ship is located at the position received and return 0 or 1 if False or True.
- The game continues until one player wins.
