// SMBus.cpp: implementation of the SMBus class.
//
//////////////////////////////////////////////////////////////////////

#include "f75111_io_controller/f75111.h"
#include <stdbool.h>

bool F75111_Init()
{
	iopl(3);
	if(PCI_AutoDetect())
	{
		if(SMBus_CheckDevice(m_F75111.bAddress))
		{
			SMBus_WriteByte(m_F75111.bAddress,GPIO1X_CONTROL_MODE  ,0x00);
			SMBus_WriteByte(m_F75111.bAddress,GPIO3X_CONTROL_MODE  ,0x00);
			SMBus_WriteByte(m_F75111.bAddress,GPIO2X_CONTROL_MODE  ,0xFF);

			SMBus_WriteByte(m_F75111.bAddress,GPIO2X_OUTPUT_DRIVING,0xFF);
			SMBus_WriteByte(m_F75111.bAddress,F75111_CONFIGURATION,0x07);
			SMBus_WriteByte(m_F75111.bAddress,0x06,0x04);

			return true;
		}
	}
	else{printf("PCI Autodect error\n");}
	return false;
}

BYTE F75111_GetDigitalInput ()
{
	BYTE byteGPIO1X = 0;
	BYTE byteGPIO3X = 0;
	BYTE byteData   = 0;

	SMBus_ReadByte(m_F75111.bAddress,GPIO1X_INPUT_DATA,&byteGPIO1X) ;
	SMBus_ReadByte(m_F75111.bAddress,GPIO3X_INPUT_DATA,&byteGPIO3X) ;
	byteGPIO1X = byteGPIO1X  & 0xF0;
	byteGPIO3X = byteGPIO3X  & 0x0F;

	byteData = ( byteGPIO1X & 0x10 )? byteData + 0x01 : byteData;
	byteData = ( byteGPIO1X & 0x80 )? byteData + 0x02 : byteData;
	byteData = ( byteGPIO1X & 0x40 )? byteData + 0x04 : byteData;
	byteData = ( byteGPIO3X & 0x01 )? byteData + 0x08 : byteData;

	byteData = ( byteGPIO3X & 0x02 )? byteData + 0x10 : byteData;
	byteData = ( byteGPIO3X & 0x04 )? byteData + 0x20 : byteData;
	byteData = ( byteGPIO3X & 0x08 )? byteData + 0x40 : byteData;
	byteData = ( byteGPIO1X & 0x20 )? byteData + 0x80 : byteData;

	return byteData;
}

void F75111_SetDigitalOutput(BYTE byteValue)
{
	BYTE byteData = 0;

	byteData = (byteValue & 0x01 )? byteData + 0x01 : byteData;
	byteData = (byteValue & 0x02 )? byteData + 0x02 : byteData;
	byteData = (byteValue & 0x04 )? byteData + 0x04 : byteData;
	byteData = (byteValue & 0x80 )? byteData + 0x08 : byteData;
	byteData = (byteValue & 0x40 )? byteData + 0x10 : byteData;
	byteData = (byteValue & 0x20 )? byteData + 0x20 : byteData;
	byteData = (byteValue & 0x10 )? byteData + 0x40 : byteData;
	byteData = (byteValue & 0x08 )? byteData + 0x80 : byteData;

	SMBus_WriteByte(m_F75111.bAddress,GPIO2X_OUTPUT_DATA,byteData);
	usleep(10);
}

void F75111_SetWDTEnable (BYTE byteTimer)
{
	SMBus_WriteByte(m_F75111.bAddress,WDT_TIMER_RANGE  ,byteTimer);
	usleep(10);
	SMBus_WriteByte(m_F75111.bAddress,WDT_CONFIGURATION,WDT_TIMEOUT_FLAG | WDT_ENABLE | WDT_PULSE | WDT_PSWIDTH_100MS);
}

void F75111_SetWDTDisable ()
{
	SMBus_WriteByte(m_F75111.bAddress,WDT_CONFIGURATION,0x00);
}
