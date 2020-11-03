#if defined (__cplusplus)
extern "C" {
#endif
#include "f75111_io_controller/f75111.h"
#if defined (__cplusplus)
}
#endif

#include "f75111_io_controller/f75111_io_controller.h"
#include <stdexcept>


F75111IOController::F75111IOController()
{
  m_F75111.bAddress = F75111_INTERNAL_ADDR;
  if (!F75111_Init()) {
    throw std::runtime_error("Failed to initialize I/O");
  }
}

void F75111IOController::setPin(int pin_num, bool enable)
{
  BYTE address;
  if (enable) {
    switch (pin_num) {
        case 0:
          address = 0x01;
          break;
        case 1:
          address = 0x02;
          break;
        case 2:
          address = 0x04;
          break;
        case 3:
          address = 0x08;
          break;
        default:
          throw std::runtime_error("Invalid pin_num: %d. Must be 0-3.");
    }
  }
  else {
    switch (pin_num) {
        case 0:
          address = 0x10;
          break;
        case 1:
          address = 0x20;
          break;
        case 2:
          address = 0x40;
          break;
        case 3:
          address = 0x80;
          break;
        default:
          throw std::runtime_error("Invalid pin_num: %d. Must be 0-3.");
    }
  }
  F75111_SetDigitalOutput(address);
}
