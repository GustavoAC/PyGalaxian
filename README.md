# PyGalaxian 

![](https://github.com/shivamshekhar/PyGalaxian/raw/master/Screenshots/1.png)

### Description:
A simple vertical space shooter game. This project's current version is intended to implement a joystick-like input for a game of our choice using BeagleBone Black and electronic components, an then use sockets to make the communication between the joystick and the game.

The game executes on user's computer as a server, and the joystick code runs on BeagleBone Black as a client.

### Technology:
Built using pygame library on Python 2.7

C++11 Standard used on joystick code

### Version and Release:
First Release, version 1.0

### Target Platforms:
Linux

### BeagleBone Black configuration:
To play the game the way it was intended to be on this project, some electronic pieces will 
be needed: a potentiometer, a LDR (Light Dependent Resistor), a 10K-ohm resistor and a push button, along with some wires to connect them.

The BeagleBone Black proper configuration can be seen on the image below:
![bbb configuration](http://i.imgur.com/DURERrP.png)

### Instructions and Prerequisites:  
Before compiling and running the program, be sure to have the `/beaglebone` folder copied to your BeagleBone Black, and have the components set on the right configuration like stated above. 

**Compiling and running the joystick**

On BBB, enter `/beaglebone` folder and run the following

```bash
g++ -std=c++11 -pthread adc.cpp gpio.cpp cliente_bb.cpp -o joystick
./joystick
```

**Running the game**

Make sure you have Python 2.7 installed along with pygame (http://www.pygame.org/) library. On your computer, run PyGalaxian.py

##### Controls:
* Move your spaceship using the potentiometer
* Fire lazers using button
* Destroy all enemies to win the game
* Choose option on starting screen tapping LDR and confirm pushing button
* To exit the game while playing, gently tap LDR or press ESC key


### Screenshots:
![](https://github.com/shivamshekhar/PyGalaxian/raw/master/Screenshots/2.png)


### Developed by: 
**Original**

Shivam Shekhar  
Email: shivam.shekhar.ece14@itbhu.ac.in   

**BeagleBone Black version**
* [GustavoAC](https://github.com/GustavoAC)
* [thiagocesarm](https://github.com/thiagocesarm)

#### Credits:
* Sprites : http://millionthvector.blogspot.in/p/free-sprites.html
* Logo: http://www4.flamingtext.in

#### References:
* http://www.pygame.org/docs
* https://github.com/TheLycaeum/pygame 

