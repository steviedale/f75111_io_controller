#include "f75111_io_controller/smbus.h"

//--------------------------------------------------------------------------------------------------------
#define F75111_INTERNAL_ADDR			0x9C 	//	OnBoard  F75111 Chipset
#define F75111_EXTERNAL_ADDR			0x6E	//	External F75111 Chipset
//--------------------------------------------------------------------------------------------------------
#define F75111_CONFIGURATION			0x03	//  Configure GPIO13 to WDT2 Function
//--------------------------------------------------------------------------------------------------------
#define GPIO1X_CONTROL_MODE				0x10	//  Select Output Mode or Input Mode
#define GPIO2X_CONTROL_MODE				0x20	//  Select GPIO2X Output Mode or Input Mode
#define GPIO3X_CONTROL_MODE				0x40	//  Select GPIO3X Output Mode or Input Mode
//--------------------------------------------------------------------------------------------------------
#define GPIO1X_INPUT_DATA				0x12	//  GPIO1X Input
#define GPIO3X_INPUT_DATA				0x42	//  GPIO3X Input
//--------------------------------------------------------------------------------------------------------
#define GPIO2X_OUTPUT_DATA				0x21	//  GPIO2X Output
//--------------------------------------------------------------------------------------------------------
#define GPIO2X_OUTPUT_DRIVING			0x2B	//  Select GPIO2X Output Mode or Input Mode
//--------------------------------------------------------------------------------------------------------
#define WDT_TIMER_RANGE					0x37	//  0-255 (secord or minute program by WDT_UNIT)
//--------------------------------------------------------------------------------------------------------
#define		WDT_CONFIGURATION			0x36	//  Configure WDT Function
#define		WDT_TIMEOUT_FLAG			0x40	//	When watchdog timeout.this bit will be set to 1.
#define		WDT_ENABLE					0x20	//	Enable watchdog timer
#define		WDT_PULSE					0x10	//	Configure WDT output mode
												//	0:Level Mode
												//	1:Pulse	Mode
#define		WDT_UNIT					0x08	//	Watchdog unit select.
												//	0:Select second.
												//	1:Select minute.
#define		WDT_LEVEL					0x04	//	When select level output mode:
												//	0:Level low
												//	1:Level high
#define		WDT_PSWIDTH_1MS				0x00	//	When select Pulse mode:	1	ms.
#define		WDT_PSWIDTH_20MS			0x01	//	When select Pulse mode:	20	ms.
#define		WDT_PSWIDTH_100MS			0x02	//	When select Pulse mode:	100	ms.
#define		WDT_PSWIDTH_4000MS			0x03	//	When select Pulse mode:	4	 s.
//--------------------------------------------------------------------------------------------------------

typedef struct F75111_Address
{
    BYTE bAddress;
}F75111_Address;
F75111_Address m_F75111;

bool	F75111_Init();
BYTE	F75111_GetDigitalInput ();
void	F75111_SetDigitalOutput(BYTE byteValue);

BYTE	F75111_GetWDTMode();
void	F75111_SetWDTMode(BYTE dwvalue);

void	F75111_SetWDTEnable    (BYTE byteTimer);
void	F75111_SetWDTDisable   ();
