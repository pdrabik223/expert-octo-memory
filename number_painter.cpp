//
// Created by piotr on 30/11/2021.
//

#include "maze_painter/maze_painter.h"
#include <iostream>

int main() {
  printf("welcome to Ain't!\n");
  MazePainter maze(800, 800, 10, 10);
  maze.color_scheme_.LoadMetaSet();
  std::string label;
  while (true) {
    maze.MainLoop();
    printf("please input label (to quit enter 'q')\t");
    std::cin >> label;
    printf("\n");
    if(label == "q") break;
    std::string path = "../maze_painter/" + label + ".txt";
    maze.GetPlane().SaveToFile(path, label);
    maze.Clear();
  }
  return 0;
}