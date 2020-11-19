#if defined (__cplusplus)
extern "C" {
#endif
#include "f75111_io_controller/f75111.h"
#if defined (__cplusplus)
}
#endif

#include "f75111_io_controller/f75111_io_controller.h"
#include <stdexcept>
#include <unistd.h>
#include <iostream>


F75111IOController::F75111IOController()
{
  // check if process is running as root
  if (geteuid() != 0) throw std::runtime_error("F75111 io control requires root privileges. Try running as sudo.");

  m_F75111.bAddress = F75111_INTERNAL_ADDR;

  if (!F75111_Init()) throw std::runtime_error("Failed to initialize I/O");
}

void F75111IOController::setByte(BYTE byte)
{
  F75111_SetDigitalOutput(byte);
}
