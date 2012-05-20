/*
 * test.cpp
 *
 * Simple test program for verifying that interaction with SFML works.
 */

#include <SFML/Graphics.hpp>

#include <sstream>
#include <string>

namespace {
  std::string float2str(float in);
}

int main(int, char **argv)
{
  sf::RenderWindow win(sf::VideoMode(800, 600), argv[0]);
  win.setVerticalSyncEnabled(true);
  //win.SetFramerateLimit(100);

  const sf::Color red(255,0,0);
  const sf::Font &font = sf::Font::getDefaultFont();

  sf::Text rotStr;
  rotStr.setPosition(600, 500);
  rotStr.setFont(font);


  sf::ConvexShape triangle;
  triangle.setPointCount(3);
  triangle.setPoint(0, {100.0,   0.0});
  triangle.setPoint(1, {-50.0,  50.0});
  triangle.setPoint(2, {-50.0, -50.0});
  triangle.setOutlineThickness(5);
  triangle.setOutlineColor(red);
  triangle.setPosition(200, 200);
  triangle.setFillColor(sf::Color::Blue);

  while (win.isOpen()) {
    sf::Event ev;

    /* Exhaust the event queue */
    while (win.pollEvent(ev)) {
      if (ev.type == sf::Event::Closed) {
        win.close();
      }
    }

    /* Update objects */
    triangle.rotate(3.8);

    const std::string rot = "Rot: " + float2str(triangle.getRotation());
    rotStr.setString(rot.c_str());

    /* Begin drawing stuff */
    win.clear();

    win.draw(triangle);
    win.draw(rotStr);

    win.display();
  }

  return 0;
}

namespace {
std::string
float2str(float in)
{
  std::stringstream out;
  out << in;
  return out.str();
}
}
