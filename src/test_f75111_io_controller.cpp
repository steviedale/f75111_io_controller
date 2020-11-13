#include "f75111_io_controller/f75111_io_controller.h"
#include <string>
#include <thread>
#include <chrono>
#include <exception>
#include <iostream>

enum Color { OFF, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE };

int main(int argc, char** argv)
{
  try
  {
    F75111IOController f75111_io_controller_;
    std::string color;
    for (int color_index : {RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, OFF})
    {
      switch(color_index)
      {
        case OFF:
          color = "OFF";
          f75111_io_controller_.setPin(0, false);
          f75111_io_controller_.setPin(1, false);
          f75111_io_controller_.setPin(2, false);
          break;
        case RED:
          color = "RED";
          f75111_io_controller_.setPin(0, true);
          f75111_io_controller_.setPin(1, false);
          f75111_io_controller_.setPin(2, false);
          break;

       case GREEN:
          color = "GREEN";
          f75111_io_controller_.setPin(0, false);
          f75111_io_controller_.setPin(1, true);
          f75111_io_controller_.setPin(2, false);
          break;
        case YELLOW:
          color = "YELLOW";
          f75111_io_controller_.setPin(0, true);
          f75111_io_controller_.setPin(1, true);
          f75111_io_controller_.setPin(2, false);
          break;
        case BLUE:
          color = "BLUE";
          f75111_io_controller_.setPin(0, false);
          f75111_io_controller_.setPin(1, false);
          f75111_io_controller_.setPin(2, true);
          break;
        case MAGENTA:
          color = "MAGENTA";
          f75111_io_controller_.setPin(0, true);
          f75111_io_controller_.setPin(1, false);
          f75111_io_controller_.setPin(2, true);
          break;
        case CYAN:
          color = "CYAN";
          f75111_io_controller_.setPin(0, false);
          f75111_io_controller_.setPin(1, true);
          f75111_io_controller_.setPin(2, true);
          break;
        case WHITE:
          color = "WHITE";
          f75111_io_controller_.setPin(0, true);
          f75111_io_controller_.setPin(1, true);
          f75111_io_controller_.setPin(2, true);
          break;
      }
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
