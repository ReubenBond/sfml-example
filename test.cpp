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

int main(int argc, char **argv)
{
  sf::RenderWindow win(sf::VideoMode(800, 600), argv[0]);
  win.UseVerticalSync(true);
  //win.SetFramerateLimit(100);

  const sf::Color red(255,0,0);
  const sf::Font &font = sf::Font::GetDefaultFont();

  sf::String rotStr;
  rotStr.SetPosition(600,500);

  sf::Shape triangle;
  triangle.AddPoint( 100.0,   0.0, red);
  triangle.AddPoint( -50.0,  50.0, red);
  triangle.AddPoint( -50.0, -50.0, red);

  triangle.SetPosition(200,200);

  while (win.IsOpened()) {
    sf::Event ev;

    /* Exhaust the event queue */
    while (win.GetEvent(ev)) {
      if (ev.Type == sf::Event::Closed) {
        win.Close();
      }
    }

    /* Update objects */
    triangle.Rotate(0.1);

    const std::string rot = "Rot: " + float2str(triangle.GetRotation());
    rotStr.SetText(rot.c_str());

    /* Begin drawing stuff */
    win.Clear();

    win.Draw(triangle);
    win.Draw(rotStr);

    win.Display();
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
