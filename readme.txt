This is a very simple setup that can be used as a starting
point or an example of an SFML-using piece of software.

The work is simple enough that I am not sure if it
constitutes a creative work at all. Feel free to use and
redistribute this piece of code in whole or in parts in any
way you wish.

* Building on GNU/Linux:
First, ensure you have gcc, cmake and SFML installed.

The following table lists known package names of
dependencies:
| OS     | Packages                 |
|--------+--------------------------|
| Debian | g++ cmake libsfml-dev    |
| Fedora | gcc-c++ cmake SFML-devel |

Building is done by changing your unix shell to the root
directory of the project, and the running these commands.

  mkdir build
  cd build
  cmake ..

If your copy of SFML is not in the standard location, you
should be able to pass cmake the location of it like this:
cmake -DSFMLDIR=/path/to/SFML-1.6

* Building with MinGW32 for Windows
First, ensure you have a working copy of MinGW and CMake and SFML. You
probably want all of these included in the PATH of the user that will
build and run the code.

With MinGW, building is similar to how it is done on GNU/Linux. Mostly
it just becomes necessary to specify the generator type for CMake, and
some binary names are different. Also you quite certainly will need to
specify the SFMLDIR variable in the cmake command.

  mkdir build
  cd build
  cmake -G "MinGW Makefiles" "-DSFMLDIR=C:\SFML-1.6-mingw32\lib" ..
  mingw32-make
