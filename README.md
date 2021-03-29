# arduino_lcd_games

______________________________________________________________________________________________________________________________________________________________________

In this repository I've uploaded different "games" coded in C++ thought to be run in a 16x2 LCD using an arduino board. I tryed to imitate those 80's pocket computers that were able to run games coded in BASIC in a little LCD screen, with the diference of using the arduino C++ instead of BASIC and the use of a bluetooth module in some games.
______________________________________________________________________________________________________________________________________________________________________


These are the components and the instructions about how connect them you will need:
___________________________________________________________________________________

COMPONENTS:

- An Arduino board (no matter witch)
- A 16-connections LCD screen
- A pair of bottons
- A buzzer
- A bluetooth module
- All cables and resistors you need (depending on the specific components used)


CONNECTIONS:

- Connect the LCD by this way: lcd(11, 10, 6, 5, 4, 3);
- Connect the 1st button to pin 2
- Connect the 2nd button to pin 7
- Connect the buzzer to pin 9
- Power the bluetooth module using the pin 13 (in order to turn it on or off when we want)
- The data of the bluetooth module must be trasfered to arduino using its serial pins

______________________________________________________________________________________________________________________________________________________________________

Enjoy the project as I did making it

