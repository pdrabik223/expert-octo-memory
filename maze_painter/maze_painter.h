//
// Created by piotr on 09/10/2021.
//

#ifndef COA_MAZE_PAINTER_MAZE_PAINTER_H_
#define COA_MAZE_PAINTER_MAZE_PAINTER_H_

#include "../plane/plane.h"
#include "../sfml_window/color_scheme.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

/// All in one window and painter logic
class MazePainter {
 public:
  MazePainter() = delete;
  MazePainter(int screen_width, int screen_height, int plane_width, int plane_height);

  /// main window loop
  void MainLoop();
  void DrawPlane(sf::RenderWindow &window);
  const Plane &GetPlane() const;
  void Clear() {
    plane_.Clear();
  }
  ColorScheme color_scheme_;

 private:
  bool PopulateMousePosition(const sf::RenderWindow &window, Coord &mouse_position);
  std::vector<Coord> GetHighlightedPositions(const sf::RenderWindow &window);
  void CheckBoundariesAndPush(const Coord &position, std::vector<Coord> &push_target);

  void DrawCircle(const Coord &center, std::vector<Coord> &target, int radius);
  void DrawFilledInCircle(const Coord &center, std::vector<Coord> &target);

 protected:
  int screen_width_;
  int screen_height_;

  float cell_size_;

  CellState current_brush_state_ = CellState::WALL;
  int brush_size_ = 1;


  sf::Event event_;
  Plane plane_;
};

#endif//COA_MAZE_PAINTER_MAZE_PAINTER_H_
