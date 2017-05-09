# CarND-Controls-PID
[![Udacity - Self-Driving Car NanoDegree](https://s3.amazonaws.com/udacity-sdc/github/shield-carnd.svg)](http://www.udacity.com/drive)
---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets) == 0.13, but the master branch will probably work just fine
  * Follow the instructions in the [uWebSockets README](https://github.com/uWebSockets/uWebSockets/blob/master/README.md) to get setup for your platform. You can download the zip of the appropriate version from the [releases page](https://github.com/uWebSockets/uWebSockets/releases). Here's a link to the [v0.13 zip](https://github.com/uWebSockets/uWebSockets/archive/v0.13.0.zip).
  * If you run OSX and have homebrew installed you can just run the ./install-mac.sh script to install this
* Simulator. You can download these from the [project intro page](https://github.com/udacity/CarND-PID-Control-Project/releases) in the classroom.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`.

[//]: # (Image References)

## The PID Controller - Effect and parameter setting

#### P
The proportional component directly controls the deviation from the center of the lane. It contributes to the steering in proportion to the Cross Track Error (CTE).

#### D
The differential component prevents the controller to oscilate around the wanted value. It contributes to the steering in proportion to the derivative of the CTE.

#### I
The integral component can deal with systematic biases like a broken vehicle that is forced to go left all the time or a wind blowing consistently in one direction. It contributes to the steering in proportion to the accumulated of the CTE. As the car in the simulator has no bias, I have set the Integral component to zero, which resulted in the best results I could achieve.

[video1]: ./simulator-recording.mov "Video Output"

A sample video of the PID-controlled vehicle can be seen here: [link to my video sample][video1]

As the integral term could be set to zero (as described above), I only had two parameters left to choose, which is why I decided for manual tuning.

I had first set both the differential and integral component to zero to only have a P-Control. This way I was able to come up with a gain that was good enough to keep the controller on the road for the beginning. Unfortunately, the car was oscillating and the oscilation was building up. Next, I started to change the gain of the differential component to come up with the following parameter setting:

kP = 0.05 and kD = 5
