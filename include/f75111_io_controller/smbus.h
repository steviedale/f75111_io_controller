// SMBus.h: interface for the SMBus class.
//
//////////////////////////////////////////////////////////////////////
//#include "../stdafx.h"
#include <stdbool.h>
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;
//----------------------------------------------------------------------------------
//	PCI Device Read/Write I/O
//----------------------------------------------------------------------------------
#define 	PCI_CONFIG_ADDR					0xCF8
#define 	PCI_CONFIG_DATA					0xCFC
//----------------------------------------------------------------------------------
//	Intel ICH4 Vendor ID & Device ID
//----------------------------------------------------------------------------------
#define 	INTEL_ICH4_VENDOR_ID				0x8086
#define 	INTEL_ICH4_DEVICE_ID				0x24C0
#define 	INTEL_ICH4_SMBUS_VENDOR_ID			0x8086
#define 	INTEL_ICH4_SMBUS_DEVICE_ID			0x24C3
//----------------------------------------------------------------------------------
#define     ICH4_SMBUS_HOST_IOBASE				0x20
//----------------------------------------------------------------------------------
#define     ICH4_SMBUS_HOST_CONFIGURE			0x40
#define     ICH4_SMBUS_HOST_HST_EN				0x01
#define     ICH4_SMBUS_HOST_SMI_EN				0x02
#define     ICH4_SMBUS_HOST_I2C_EN				0x04

//----------------------------------------------------------------------------------
//	Intel 945 ICH7 Vendor ID & Device ID
//----------------------------------------------------------------------------------
#define		INTEL_ICH7_VENDOR_ID				0x8086
#define		INTEL_ICH7_DEVICE_ID				0x2448

#define		INTEL_ICH7_SMBUS_VENDOR_ID			0x8086
#define		INTEL_ICH7_SMBUS_DEVICE_ID			0x27DA
//----------------------------------------------------------------------------------
#define		ICH7_SMBUS_HOST_IOBASE				0x20
//----------------------------------------------------------------------------------
#define		ICH7_SMBUS_HOST_CONFIGURE			0x40
#define		ICH7_SMBUS_HOST_HST_EN				0x01
#define		ICH7_SMBUS_HOST_SMI_EN				0x02
#define		ICH7_SMBUS_HOST_I2C_EN				0x04

//----------------------------------------------------------------------------------
//	Intel 510&525 ICH8 Vendor ID & Device ID
//----------------------------------------------------------------------------------
#define		INTEL_ICH8_VENDOR_ID				0x8086
#define		INTEL_ICH8_DEVICE_ID				0x244E

#define		INTEL_ICH8_SMBUS_VENDOR_ID			0x8086
#define		INTEL_ICH8_SMBUS_DEVICE_ID			0x283E
//----------------------------------------------------------------------------------
#define		ICH8_SMBUS_HOST_IOBASE				0x20
//----------------------------------------------------------------------------------
#define		ICH8_SMBUS_HOST_CONFIGURE			0x40
#define		ICH8_SMBUS_HOST_HST_EN				0x01
#define		ICH8_SMBUS_HOST_SMI_EN				0x02
#define		ICH8_SMBUS_HOST_I2C_EN				0x04

//----------------------------------------------------------------------------------
//	Intel 275 ICH10 Vendor ID & Device ID
//----------------------------------------------------------------------------------
#define		INTEL_ICH10_VENDOR_ID				0x8086
#define		INTEL_ICH10_DEVICE_ID				0x244E

#define		INTEL_ICH10_SMBUS_VENDOR_ID			0x8086
#define		INTEL_ICH10_SMBUS_DEVICE_ID			0x3A30
//----------------------------------------------------------------------------------
#define		ICH10_SMBUS_HOST_IOBASE				0x20
//----------------------------------------------------------------------------------
#define		ICH10_SMBUS_HOST_CONFIGURE			0x40
#define		ICH10_SMBUS_HOST_HST_EN				0x01
#define		ICH10_SMBUS_HOST_SMI_EN				0x02
#define		ICH10_SMBUS_HOST_I2C_EN				0x04

//----------------------------------------------------------------------------------
//	Intel NM10 Vendor ID & Device ID
//----------------------------------------------------------------------------------
#define		INTEL_NM10_VENDOR_ID				0x8086
#define		INTEL_NM10_DEVICE_ID				0x2448

#define		INTEL_NM10_SMBUS_VENDOR_ID			0x8086
#define		INTEL_NM10_SMBUS_DEVICE_ID			0x27DA
//----------------------------------------------------------------------------------
#define		NM10_SMBUS_HOST_IOBASE				0x20
//----------------------------------------------------------------------------------
#define		NM10_SMBUS_HOST_CONFIGURE			0x40
#define		NM10_SMBUS_HOST_HST_EN				0x01
#define		NM10_SMBUS_HOST_SMI_EN				0x02
#define		NM10_SMBUS_HOST_I2C_EN				0x04

//----------------------------------------------------------------------------------
//	Intel QM67 Vendor ID & Device ID
//----------------------------------------------------------------------------------
#define		INTEL_QM67_SMBUS_VENDOR_ID			0x8086
#define		INTEL_QM67_SMBUS_DEVICE_ID			0x1C22
//----------------------------------------------------------------------------------
#define		QM67_SMBUS_HOST_IOBASE				0x20
//----------------------------------------------------------------------------------
#define		QM67_SMBUS_HOST_CONFIGURE			0x40
#define		QM67_SMBUS_HOST_HST_EN				0x01
#define		QM67_SMBUS_HOST_SMI_EN				0x02
#define		QM67_SMBUS_HOST_I2C_EN				0x04

//----------------------------------------------------------------------------------
//	Intel QM77 Vendor ID & Device ID
//----------------------------------------------------------------------------------
#define		INTEL_QM77_SMBUS_VENDOR_ID			0x8086
#define		INTEL_QM77_SMBUS_DEVICE_ID			0x1E22
//----------------------------------------------------------------------------------
#define		QM77_SMBUS_HOST_IOBASE				0x20
//----------------------------------------------------------------------------------
#define		QM77_SMBUS_HOST_CONFIGURE			0x40
#define		QM77_SMBUS_HOST_HST_EN				0x01
#define		QM77_SMBUS_HOST_SMI_EN				0x02
#define		QM77_SMBUS_HOST_I2C_EN				0x04

//----------------------------------------------------------------------------------
//	Intel HM65 Vendor ID & Device ID
//----------------------------------------------------------------------------------
#define		INTEL_HM65_SMBUS_VENDOR_ID			0x8086
#define		INTEL_HM65_SMBUS_DEVICE_ID			0x1C22
//----------------------------------------------------------------------------------
#define		HM65_SMBUS_HOST_IOBASE				0x20
//----------------------------------------------------------------------------------
#define		HM65_SMBUS_HOST_CONFIGURE			0x40
#define		HM65_SMBUS_HOST_HST_EN				0x01
#define		HM65_SMBUS_HOST_SMI_EN				0x02
#define		HM65_SMBUS_HOST_I2C_EN				0x04

//----------------------------------------------------------------------------------
//	Intel HM76 Vendor ID & Device ID
//----------------------------------------------------------------------------------
#define		INTEL_HM76_SMBUS_VENDOR_ID			0x8086
#define		INTEL_HM76_SMBUS_DEVICE_ID			0x1E22
//----------------------------------------------------------------------------------
#define		HM76_SMBUS_HOST_IOBASE				0x20
//----------------------------------------------------------------------------------
#define		HM76_SMBUS_HOST_CONFIGURE			0x40
#define		HM76_SMBUS_HOST_HST_EN				0x01
#define		HM76_SMBUS_HOST_SMI_EN				0x02
#define		HM76_SMBUS_HOST_I2C_EN				0x04

//----------------------------------------------------------------------------------
//	Intel Bay Trail-I SoC Vendor ID & Device ID
//----------------------------------------------------------------------------------
#define		INTEL_SOC_SMBUS_VENDOR_ID			0x8086
#define		INTEL_SOC_SMBUS_DEVICE_ID			0x0F12
//----------------------------------------------------------------------------------
#define		SOC_SMBUS_HOST_IOBASE				0x20
//----------------------------------------------------------------------------------
#define		SOC_SMBUS_HOST_CONFIGURE			0x40
#define		SOC_SMBUS_HOST_HST_EN				0x01
#define		SOC_SMBUS_HOST_SMI_EN				0x02
#define		SOC_SMBUS_HOST_I2C_EN				0x04

//	Intel Apollo Lake SoC Vendor ID & Device ID
//----------------------------------------------------------------------------------
#define		INTEL_Apollo_Lake_SOC_SMBUS_VENDOR_ID			0x8086
#define		INTEL_Apollo_Lake_SOC_SMBUS_DEVICE_ID			0x5AD4
//----------------------------------------------------------------------------------
#define		Apollo_Lake_SOC_SMBUS_HOST_IOBASE				0x20
//----------------------------------------------------------------------------------
#define		Apollo_Lake_SOC_SMBUS_HOST_CONFIGURE			0x40
#define		Apollo_Lake_SOC_SMBUS_HOST_HST_EN				0x01
#define		Apollo_Lake_SOC_SMBUS_HOST_SMI_EN				0x02
#define		Apollo_Lake_SOC_SMBUS_HOST_I2C_EN				0x04

//20170829 Add Sky_Lake by Tracy↓↓↓
//----------------------------------------------------------------------------------
//	Intel Sky Lake SoC Vendor ID & Device ID
//----------------------------------------------------------------------------------
#define		INTEL_Sky_Lake_SOC_SMBUS_VENDOR_ID			0x8086
#define		INTEL_Sky_Lake_SOC_SMBUS_DEVICE_ID			0xA123
//----------------------------------------------------------------------------------
#define		Sky_Lake_SOC_SMBUS_HOST_IOBASE				0x20
//----------------------------------------------------------------------------------
#define		Sky_Lake_SOC_SMBUS_HOST_CONFIGURE			0x40
#define		Sky_Lake_SOC_SMBUS_HOST_HST_EN				0x01
#define		Sky_Lake_SOC_SMBUS_HOST_SMI_EN				0x02
#define		Sky_Lake_SOC_SMBUS_HOST_I2C_EN				0x04
//20170829 Add Sky_Lake by Tracy↑↑↑

//20170829 Add Sky_Lake-U by Tracy↓↓↓
//----------------------------------------------------------------------------------
//	Intel Sky Lake SoC Vendor ID & Device ID
//----------------------------------------------------------------------------------
#define		INTEL_Sky_Lake_U_SOC_SMBUS_VENDOR_ID			0x8086
#define		INTEL_Sky_Lake_U_SOC_SMBUS_DEVICE_ID			0x9D23
//----------------------------------------------------------------------------------
#define		Sky_Lake_U_SOC_SMBUS_HOST_IOBASE				0x20
//----------------------------------------------------------------------------------
#define		Sky_Lake_U_SOC_SMBUS_HOST_CONFIGURE				0x40
#define		Sky_Lake_U_SOC_SMBUS_HOST_HST_EN				0x01
#define		Sky_Lake_U_SOC_SMBUS_HOST_SMI_EN				0x02
#define		Sky_Lake_U_SOC_SMBUS_HOST_I2C_EN				0x04
//20170829 Add Sky_Lake-U by Tracy↑↑↑

//----------------------------------------------------------------------------------
//	VIA VT8237 Vendor ID & Device ID
//----------------------------------------------------------------------------------
#define 	VIA_VT8237_BUS_CTRL_VENDOR_ID			0x1106
#define 	VIA_VT8237_BUS_CTRL_DEVICE_ID			0x3227
//----------------------------------------------------------------------------------
#define		VT8237_SMBUS_HOST_IOBASE			0xD0
//----------------------------------------------------------------------------------
#define		VT8237_SMBUS_HOST_CONFIGURE			0xD2
#define		VT8237_SMBUS_HOST_CONTROLER_ENABLE		0x01
#define		VT8237_SMBUS_HOST_INTERRUPT_ENABLE		0x02
#define		VT8237_SMBUS_HOST_INTERRUPT_TYPE		0x08
//----------------------------------------------------------------------------------
#define 	VIA_CX700M_BUS_CTRL_VENDOR_ID			0x1106
#define 	VIA_CX700M_BUS_CTRL_DEVICE_ID			0x8324
//----------------------------------------------------------------------------------
#define		CX700M_SMBUS_HOST_IOBASE			0xD0
//----------------------------------------------------------------------------------
#define		CX700M_SMBUS_HOST_CONFIGURE			0xD2
#define		CX700M_SMBUS_HOST_CONTROLER_ENABLE		0x01
#define		CX700M_SMBUS_HOST_INTERRUPT_ENABLE		0x02
#define		CX700M_SMBUS_HOST_INTERRUPT_TYPE		0x08
#define		CX700M_SMBUS_HOST_CLOCK				0x04
//----------------------------------------------------------------------------------
//	VIA VX900 Vendor ID / Devices ID & Bus-Specific configuration register
//----------------------------------------------------------------------------------
#define 	VIA_VX900_BUS_CTRL_VENDOR_ID			0x1106
#define 	VIA_VX900_BUS_CTRL_DEVICE_ID			0x8410
#define		VX900_SMBUS_HOST_IOBASE				0xD0
#define		VX900_SMBUS_HOST_CONFIGURE			0xD2
#define		VX900_SMBUS_HOST_CONTROLER_ENABLE		0x01

//-----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//		Register of VIA & Intel
//----------------------------------------------------------------------------------
#define		SMBHSTSTS		0x00	// SMBus Host  Status Register Offset
#define		SMBHSTSTS_BUSY		0x01	// SMBus Host -> 0000-0001 Busy
#define		SMBHSTSTS_INTR		0x02	// SMBus Host -> 0000-0010 Interrupt / complection
#define		SMBHSTSTS_ERROR		0x04	// SMBus Host -> 0000-0100 Error
#define		SMBHSTSTS_COLLISION	0x08	// SMBus Host -> 0000-1000 Collistion
#define		SMBHSTSTS_FAILED	0x10	// SMBus Host -> 0001-0000 Failed
//----------------------------------------------------------------------------------
#define		SMBHSTCNT		0x02	// SMBus Host Contorl Register Offset
#define		SMBHSTCNT_KILL		0x02	// SMBus Host Contorl -> 0000 0010 Kill
#define		SMBHSTCNT_QUICK		0x00	// SMBus Host Contorl -> 0000 0000 quick (default)
#define		SMBHSTCNT_SENDRECV	0x04	// SMBus Host Contorl -> 0000 0100 Byte
#define		SMBHSTCNT_BYTE		0x08	// SMBus Host Contorl -> 0000 1000 Byte Data
#define		SMBHSTCNT_WORD		0x0c	// SMBus Host Contorl -> 0000 1100 Word Data
#define		SMBHSTCNT_BLOCK		0x14	// SMBus Host Contorl -> 0001 0100 Block
#define		SMBHSTCNT_START		0x40	// SMBus Host Contorl -> 0100 0000 Start
//----------------------------------------------------------------------------------
#define	SMBHSTCMD			0x03	// SMBus Host Command		Register Offset
#define	SMBHSTADD			0x04	// SMBus Host Address		Register Offset
#define	SMBHSTDAT0			0x05	// SMBus Host Data0			Register Offset
										// SMBus Host Block Counter	Register Offset
#define	SMBHSTDAT1			0x06	// SMBus Host Data1			Register Offset
#define	SMBBLKDAT			0x07	// SMBus Host Block	Data	Register Offset

//----------------------------------------------------------------------------------
//		Register of VIA only
//----------------------------------------------------------------------------------
#define	SMBHSLVSTS			0x01		// SMBus Slave Status Register Offset
//----------------------------------------------------------------------------------
#define	SMBSLVCNT			0x08		// SMBus Slave  Control
#define	SMBSHDWCMD			0x09		// SMBus Shadow Command
#define	SMBSLVEVT			0x0a		// SMBus Slave  Event
#define	SMBSLVDAT			0x0c		// SMBus Slave  Data
//----------------------------------------------------------------------------------
//      SMBus Bus Status Code
//----------------------------------------------------------------------------------
#define SMBUS_OK			0x0			// SMBUS OK
#define SMBUS_BUSY			0x1			// SMBUS BUSY
#define SMBUS_INT			0x2			// SMBUS INTR
#define SMBUS_ERROR			0x4			// SMBUS ERROR
//----------------------------------------------------------------------------------
#define	SMBUS_TIMEOUT		100
//----------------------------------------------------------------------------------
extern WORD m_SMBusMapIoAddr;

DWORD	PCI_Read (int   size_t);
void	PCI_Write(DWORD dwDataVal,int size_t);

bool	PCI_AutoDetect();
bool	Get_VT8237_SMBusIoAddr(DWORD dwIOAddr);
bool	Get_CX700M_SMBusIoAddr(DWORD dwIOAddr);
bool	Get_ICH4_SMBusIoAddr(DWORD dwIOAddr);
bool	Get_ICH7_SMBusIoAddr(DWORD dwIOAddr);
bool	Get_ICH8_SMBusIoAddr(DWORD dwIOAddr);
bool	Get_ICH10_SMBusIoAddr(DWORD dwIOAddr); //Add for 275 series SNBus Controller
bool	Get_NM10_SMBusIoAddr(DWORD dwIOAddr);
bool	Get_QM67_SMBusIoAddr(DWORD dwIOAddr);
bool	Get_QM77_SMBusIoAddr(DWORD dwIOAddr);
bool	Get_HM65_SMBusIoAddr(DWORD dwIOAddr);
bool	Get_HM76_SMBusIoAddr(DWORD dwIOAddr);
bool	Get_SOC_SMBusIoAddr(DWORD dwIOAddr);  //Add for Bay Trail-I SoC SMbus controller
bool	Get_Apollo_Lake_SOC_SMBusIoAddr(DWORD dwIOAddr);  //Add for Bay Trail-I SoC SMbus controller
bool	Get_Sky_Lake_SOC_SMBusIoAddr(DWORD dwIOAddr);  //20170829 Add for Sky Lake SoC SMBus controller
bool    Get_Sky_Lake_U_SOC_SMBusIoAddr(DWORD dwIOAddr);  //20170829 Add for Sky Lake SoC U SMBus controller By Tracy
bool	Get_VX900_SMBusIoAddr(DWORD dwIOAddr); //Add for VX900 SMbus controller

BYTE	SMBusIoRead (BYTE byteOffset);
void	SMBusIoWrite(BYTE byteOffset,BYTE byteData);

void	SMBus_Clear();
int	SMBus_Wait ();
bool	SMBus_Busy ();

bool	SMBus_CheckDevice	(BYTE byteDeviceAddress);
int	SMBus_WriteByte		(BYTE byteSlave,BYTE pCmd,BYTE  pByte);
int	SMBus_ReadByte		(BYTE byteSlave,BYTE pCmd,BYTE *pByte);
