// SMBus.cpp: implementation of the SMBus class.
//
//////////////////////////////////////////////////////////////////////
#include "f75111_io_controller/smbus.h"
#include <sys/io.h>

//////////////////////////////////////////////////////////////////////
WORD m_SMBusMapIoAddr;

int devid; //for SMBus Devices ID
//////////////////////////////////////////////////////////////////////
// PCI Device Write/Read Function
//////////////////////////////////////////////////////////////////////
DWORD PCI_Read(int size_t)
{
	DWORD dwAddrVal;

	//GetPortVal(PCI_CONFIG_DATA,&dwAddrVal,size_t);
	dwAddrVal=inl(PCI_CONFIG_DATA);
    usleep(10);
	return dwAddrVal;
}

void PCI_Write(DWORD dwDataVal,int size_t)
{
	//SetPortVal(PCI_CONFIG_ADDR, dwDataVal,size_t);
	outl(dwDataVal,PCI_CONFIG_ADDR);
	usleep(10);
}

bool PCI_AutoDetect()
{
	return Get_Apollo_Lake_SOC_SMBusIoAddr(2147547392);
	/*
	devid =0 ;
    int PCI_Bus = 0;
    int PCI_Device = 0;
    int PCI_Function = 0;
	for (PCI_Bus = 0;PCI_Bus<5;PCI_Bus++)
	{
		for (PCI_Device = 0;PCI_Device<32;PCI_Device++)
		{
			for(PCI_Function = 0; PCI_Function<8 ; PCI_Function++ )
			{
				DWORD dwResult;
				DWORD dwIOAddr = 0x80000000 + PCI_Bus*0x10000 + PCI_Device*0x800 + PCI_Function*0x100;
				PCI_Write(dwIOAddr,4);
				dwResult = PCI_Read(4);

				if ((( dwResult & 0xFFFF) == VIA_VT8237_BUS_CTRL_VENDOR_ID )  &&
					(( dwResult >> 16 )   == VIA_VT8237_BUS_CTRL_DEVICE_ID ))
				{
					//printf ("AutoDetect_IOBase : VIA VT8237 Bus Controller Found ... \n");
					return Get_VT8237_SMBusIoAddr(dwIOAddr);
				}

				if ((( dwResult & 0xFFFF) == VIA_CX700M_BUS_CTRL_VENDOR_ID )  &&
					(( dwResult >> 16 )   == VIA_CX700M_BUS_CTRL_DEVICE_ID ))
				{
					//printf ("AutoDetect_IOBase : VIA VT8237 Bus Controller Found ... \n");
					return Get_CX700M_SMBusIoAddr(dwIOAddr);
				}

				if ((( dwResult & 0xFFFF) == INTEL_ICH4_VENDOR_ID )  &&
					(( dwResult >> 16 )   == INTEL_ICH4_DEVICE_ID ))
				{
					//printf ("AutoDetect_IOBase : Intel ICH4 Chipset Found ...\n");
					int PCI_Function=0;
					for (PCI_Function=0;PCI_Function<8;PCI_Function++)
					{
						dwIOAddr = dwIOAddr + PCI_Function*0x100;
						PCI_Write(dwIOAddr,4);
						dwResult = PCI_Read(4);

						if ((( dwResult & 0xFFFF) == INTEL_ICH4_SMBUS_VENDOR_ID )  &&
							(( dwResult >> 16   ) == INTEL_ICH4_SMBUS_DEVICE_ID ))
						{
						//	printf ("AutoDetect_IOBase : Intel ICH4 SMBus Controller Found ... \n");
							return Get_ICH4_SMBusIoAddr(dwIOAddr);
						}
					}
				}

				if ((( dwResult & 0xFFFF) == INTEL_ICH7_SMBUS_VENDOR_ID )  &&					//	0x8086
					(( dwResult >> 16   ) == INTEL_ICH7_SMBUS_DEVICE_ID ))						//	0x27DA
				{
                    //printf("AutoDetect_IOBase : Intel ICH7 SMBus Controller Found ... \n");
					return Get_ICH7_SMBusIoAddr(dwIOAddr);
				}

                if ((( dwResult & 0xFFFF) == INTEL_ICH8_SMBUS_VENDOR_ID )  &&					//	0x8086
					(( dwResult >> 16   ) == INTEL_ICH8_SMBUS_DEVICE_ID ))						//	0x27DA
				{
                   // printf("AutoDetect_IOBase : Intel ICH8 SMBus Controller Found ... \n");
					return Get_ICH8_SMBusIoAddr(dwIOAddr);
				}

				if ((( dwResult & 0xFFFF) == INTEL_ICH10_SMBUS_VENDOR_ID )  &&					//	0x8086
					(( dwResult >> 16   ) == INTEL_ICH10_SMBUS_DEVICE_ID ))						//	0x3A30
				{
                   // printf("AutoDetect_IOBase : Intel ICH10 SMBus Controller Found ... \n");
					return Get_ICH10_SMBusIoAddr(dwIOAddr);
				}

				if ((( dwResult & 0xFFFF) == INTEL_NM10_SMBUS_VENDOR_ID )  &&					//	0x8086
					(( dwResult >> 16   ) == INTEL_NM10_SMBUS_DEVICE_ID ))						//	0x27DA
				{
				//	AfxMessageBox("AutoDetect_IOBase : Intel NM10 SMBus Controller Found ... \n");
					return Get_NM10_SMBusIoAddr(dwIOAddr);
				}

				if ((( dwResult & 0xFFFF) == INTEL_QM67_SMBUS_VENDOR_ID )  &&					//	0x8086
					(( dwResult >> 16   ) == INTEL_QM67_SMBUS_DEVICE_ID ))						//	0x283E
				{
					//AfxMessageBox("AutoDetect_IOBase : Intel QM67 SMBus Controller Found ... \n");
					return Get_QM67_SMBusIoAddr(dwIOAddr);
				}

				if ((( dwResult & 0xFFFF) == INTEL_QM77_SMBUS_VENDOR_ID )  &&					//	0x8086
					(( dwResult >> 16   ) == INTEL_QM77_SMBUS_DEVICE_ID ))						//	0x283E
				{
					//AfxMessageBox("AutoDetect_IOBase : Intel QM77 SMBus Controller Found ... \n");
					return Get_QM77_SMBusIoAddr(dwIOAddr);
				}

				if ((( dwResult & 0xFFFF) == INTEL_HM65_SMBUS_VENDOR_ID )  &&					//	0x8086
					(( dwResult >> 16   ) == INTEL_HM65_SMBUS_DEVICE_ID ))						//	0x283E
				{
					//AfxMessageBox("AutoDetect_IOBase : Intel HM65 SMBus Controller Found ... \n");
					return Get_HM65_SMBusIoAddr(dwIOAddr);
				}

				if ((( dwResult & 0xFFFF) == INTEL_HM76_SMBUS_VENDOR_ID )  &&					//	0x8086
					(( dwResult >> 16   ) == INTEL_HM76_SMBUS_DEVICE_ID ))						//	0x283E
				{
					//AfxMessageBox("AutoDetect_IOBase : Intel HM76 SMBus Controller Found ... \n");
					return Get_HM76_SMBusIoAddr(dwIOAddr);
				}

				if ((( dwResult & 0xFFFF) == INTEL_SOC_SMBUS_VENDOR_ID )  &&					//	0x8086
					(( dwResult >> 16   ) == INTEL_SOC_SMBUS_DEVICE_ID ))						//	0x283E
				{
					//AfxMessageBox("AutoDetect_IOBase : Intel SOC SMBus Controller Found ... \n");
					return Get_SOC_SMBusIoAddr(dwIOAddr);
				}
				if ((( dwResult & 0xFFFF) == INTEL_Apollo_Lake_SOC_SMBUS_VENDOR_ID )  &&					//	0x8086
					(( dwResult >> 16   ) == INTEL_Apollo_Lake_SOC_SMBUS_DEVICE_ID ))						//	0x9C22
				{
					//AfxMessageBox("AutoDetect_IOBase : Intel Apollo_Lake_SOC SMBus Controller Found ... \n");
					//m_TwoDio = true;
					return Get_Apollo_Lake_SOC_SMBusIoAddr(dwIOAddr);
				}

				//20170829 Add Sky_Lake  by Tracy↓↓↓
				if ((( dwResult & 0xFFFF) == INTEL_Sky_Lake_SOC_SMBUS_VENDOR_ID )  &&
					(( dwResult >> 16 )   == INTEL_Sky_Lake_SOC_SMBUS_DEVICE_ID ))
				{
					//printf ("AutoDetect_IOBase : Sky_Lake_SOC SMBus Controller Found ... \n");
					return Get_Sky_Lake_SOC_SMBusIoAddr(dwIOAddr);
				}
                //20170829 Add Sky_Lake  by Tracy↑↑↑

				//20170829 Add Sky_Lake U by Tracy↓↓↓
				if ((( dwResult & 0xFFFF) == INTEL_Sky_Lake_U_SOC_SMBUS_VENDOR_ID )  &&
					(( dwResult >> 16 )   == INTEL_Sky_Lake_U_SOC_SMBUS_DEVICE_ID ))
				{
					//printf ("AutoDetect_IOBase : Sky_Lake_U_SOC SMBus Controller Found ... \n");
					return Get_Sky_Lake_U_SOC_SMBusIoAddr(dwIOAddr);
				}
				//20170829 Add Sky_Lake U by Tracy↑↑↑



				if ((( dwResult & 0xFFFF) == VIA_VX900_BUS_CTRL_VENDOR_ID )  &&					//	0x1106
					(( dwResult >> 16   ) == VIA_VX900_BUS_CTRL_DEVICE_ID ))					//	0x8410
				{

				//	printf("AutoDetect_IOBase : VIA VX900 SMBus Controller Found ... \n");
					devid = VIA_VX900_BUS_CTRL_DEVICE_ID;
					return Get_VX900_SMBusIoAddr(dwIOAddr);
				}
			}
		}
	}
	//printf("AutoDetect_IOBase : Can't Found Any SMBus Controller!\n");
	return false;
	*/
}

//////////////////////////////////////////////////////////////////////
// Get VT8237 SMBus I/O Address
//////////////////////////////////////////////////////////////////////
bool Get_VT8237_SMBusIoAddr(DWORD dwIOAddr)
{
	PCI_Write(dwIOAddr+VT8237_SMBUS_HOST_CONFIGURE,4);

	DWORD dwResult = PCI_Read(2);

	if ( dwResult & VT8237_SMBUS_HOST_CONTROLER_ENABLE )
	{
//		printf ("AutoDetect_IOBase : VIA VT8237 SMBus Host Enable!\n");
	}
	else
	{
//		printf ("AutoDetect_IOBase : VIA VT8237 SMBus Host Disable!\n");

		return false;
	}

	PCI_Write(dwIOAddr+VT8237_SMBUS_HOST_IOBASE,4);

	m_SMBusMapIoAddr = 	(WORD) PCI_Read(4) & 0xFF00 ;

//	printf ("AutoDetect_IOBase : VIA VT8237 SMBus Host I/O Base = 0x%4X\n",m_SMBusMapIoAddr );

	return true;
}

bool Get_CX700M_SMBusIoAddr(DWORD dwIOAddr)
{
	PCI_Write(dwIOAddr+CX700M_SMBUS_HOST_CONFIGURE,4);

	DWORD dwResult = PCI_Read(2);

	if ( dwResult & CX700M_SMBUS_HOST_CONTROLER_ENABLE )
	{
//		printf ("AutoDetect_IOBase : VIA CX700M SMBus Host Enable!\n");
	}
	else
	{
//		printf ("AutoDetect_IOBase : VIA CX700M SMBus Host Disable!\n");

		return false;
	}

	PCI_Write(dwIOAddr+CX700M_SMBUS_HOST_IOBASE,4);

	m_SMBusMapIoAddr = 	(WORD) PCI_Read(4) & 0xFF00 ;
	//printf("CX700M's m_SMBusMapIoAddr is %x\n",m_SMBusMapIoAddr);

	return true;
}

bool Get_ICH4_SMBusIoAddr(DWORD dwIOAddr)
{
	DWORD dwResult;

	PCI_Write(dwIOAddr+ICH4_SMBUS_HOST_CONFIGURE,4);

	dwResult = 	PCI_Read(2);

	//printf ("ICH4 SMBus Host Configure = 0x%4X\n",dwResult );

	if ( dwResult & ICH4_SMBUS_HOST_HST_EN )
	{
		//printf ("AutoDetect_IOBase : Intel ICH4 SMBus Host Enable!\n");
	}
	else
	{
		//printf ("AutoDetect_IOBase : Intel ICH4 SMBus Host Disable!\n");

		return false;
	}

	PCI_Write(dwIOAddr+ICH4_SMBUS_HOST_IOBASE,4);

	m_SMBusMapIoAddr = 	(WORD) PCI_Read(4) & 0xFF00 ;

	//printf ("AutoDetect_IOBase : Intel ICH4 SMBus Host I/O Base = 0x%4X\n",this->m_MapIOAddress );

	return true;
}

bool Get_ICH7_SMBusIoAddr(DWORD dwIOAddr)
{
	DWORD dwResult;

	PCI_Write(dwIOAddr+ICH7_SMBUS_HOST_CONFIGURE,4);

	dwResult = 	PCI_Read(2);

	//printf ("ICH7 SMBus Host Configure = 0x%4X\n",dwResult );

	if ( dwResult & ICH7_SMBUS_HOST_HST_EN )
	{
		//printf ("AutoDetect_IOBase : Intel ICH7 SMBus Host Enable!\n");
	}
	else
	{
		//printf ("AutoDetect_IOBase : Intel ICH7 SMBus Host Disable!\n");

		return false;
	}

	PCI_Write(dwIOAddr+ICH7_SMBUS_HOST_IOBASE,4);

	m_SMBusMapIoAddr = 	(WORD) PCI_Read(4) & 0xFF00 ;

	//printf ("AutoDetect_IOBase : Intel ICH7 SMBus Host I/O Base = 0x%4X\n",this->m_MapIOAddress );

	return true;
}
bool Get_ICH8_SMBusIoAddr(DWORD dwIOAddr)
{
	DWORD dwResult;

	PCI_Write(dwIOAddr+ICH8_SMBUS_HOST_CONFIGURE,4);

	dwResult = 	PCI_Read(2);

	//printf ("ICH7 SMBus Host Configure = 0x%4X\n",dwResult );

	if ( dwResult & ICH8_SMBUS_HOST_HST_EN )
	{
		//printf ("AutoDetect_IOBase : Intel ICH7 SMBus Host Enable!\n");
	}
	else
	{
		//printf ("AutoDetect_IOBase : Intel ICH7 SMBus Host Disable!\n");

		return false;
	}

	PCI_Write(dwIOAddr+ICH8_SMBUS_HOST_IOBASE,4);

	m_SMBusMapIoAddr = 	(WORD) PCI_Read(4) & 0xFF00 ;

	//printf ("AutoDetect_IOBase : Intel ICH7 SMBus Host I/O Base = 0x%4X\n",this->m_MapIOAddress );

	return true;
}

bool Get_ICH10_SMBusIoAddr(DWORD dwIOAddr)
{
	DWORD dwResult;

	PCI_Write(dwIOAddr+ICH10_SMBUS_HOST_CONFIGURE,4);

	dwResult = 	PCI_Read(2);

	//printf ("ICH10 SMBus Host Configure = 0x%4X\n",dwResult );

	if ( dwResult & ICH10_SMBUS_HOST_HST_EN )
	{
		//printf ("AutoDetect_IOBase : Intel ICH10 SMBus Host Enable!\n");
	}
	else
	{
		//printf ("AutoDetect_IOBase : Intel ICH10 SMBus Host Disable!\n");

		return false;
	}

	PCI_Write(dwIOAddr+ICH10_SMBUS_HOST_IOBASE,4);

	m_SMBusMapIoAddr = 	(WORD) PCI_Read(4) & 0xFF00 ;

	//printf ("AutoDetect_IOBase : Intel ICH10 SMBus Host I/O Base = 0x%4X\n",this->m_MapIOAddress );

	return true;
}

bool Get_NM10_SMBusIoAddr(DWORD dwIOAddr)
{
	DWORD dwResult;

	PCI_Write(dwIOAddr+NM10_SMBUS_HOST_CONFIGURE,4);

	dwResult = 	PCI_Read(2);

	//AfxMessageBox ("NM10 SMBus Host Configure = 0x%4X\n",dwResult );

	if ( dwResult & NM10_SMBUS_HOST_HST_EN )
	{
		//AfxMessageBox("AutoDetect_IOBase : Intel NM10 SMBus Host Enable!\n");
	}
	else
	{
		//AfxMessageBox("AutoDetect_IOBase : Intel NM10 SMBus Host Disable!\n");

		return false;
	}

	PCI_Write(dwIOAddr+NM10_SMBUS_HOST_IOBASE,4);

	m_SMBusMapIoAddr = 	(WORD) PCI_Read(4) & 0xFF00 ;

	//printf ("AutoDetect_IOBase : Intel ICH8 SMBus Host I/O Base = 0x%4X\n",this->m_MapIOAddress );

	return true;
}

bool Get_QM67_SMBusIoAddr(DWORD dwIOAddr)
{
	DWORD dwResult;

	PCI_Write(dwIOAddr+QM67_SMBUS_HOST_CONFIGURE,4);

	dwResult = 	PCI_Read(2);

	if ( dwResult & QM67_SMBUS_HOST_HST_EN )
	{
	}
	else
	{
		return false;
	}

	PCI_Write(dwIOAddr+QM67_SMBUS_HOST_IOBASE,4);

	m_SMBusMapIoAddr = 	(WORD) PCI_Read(4) & 0xFFF0 ;

	return true;
}

bool Get_QM77_SMBusIoAddr(DWORD dwIOAddr)
{
	DWORD dwResult;

	PCI_Write(dwIOAddr+QM77_SMBUS_HOST_CONFIGURE,4);

	dwResult = 	PCI_Read(2);

	//printf ("QM77 SMBus Host Configure = 0x%4X\n",dwResult );

	if ( dwResult & QM77_SMBUS_HOST_HST_EN )
	{
		//printf ("AutoDetect_IOBase : Intel QM77 SMBus Host Enable!\n");
	}
	else
	{
		//printf ("AutoDetect_IOBase : Intel QM77 SMBus Host Disable!\n");

		return false;
	}

	PCI_Write(dwIOAddr+QM77_SMBUS_HOST_IOBASE,4);

	m_SMBusMapIoAddr = 	(WORD) PCI_Read(4) & 0xFFF0 ;

	//printf ("AutoDetect_IOBase : Intel QM77 SMBus Host I/O Base = 0x%4X\n",this->m_MapIOAddress );

	return true;
}

bool Get_HM65_SMBusIoAddr(DWORD dwIOAddr)
{
	DWORD dwResult;

	PCI_Write(dwIOAddr+HM65_SMBUS_HOST_CONFIGURE,4);

	dwResult = 	PCI_Read(2);

	//printf ("HM65 SMBus Host Configure = 0x%4X\n",dwResult );

	if ( dwResult & HM65_SMBUS_HOST_HST_EN )
	{
		//printf ("AutoDetect_IOBase : Intel HM65 SMBus Host Enable!\n");
	}
	else
	{
		//printf ("AutoDetect_IOBase : Intel HM65 SMBus Host Disable!\n");

		return false;
	}

	PCI_Write(dwIOAddr+HM65_SMBUS_HOST_IOBASE,4);

	m_SMBusMapIoAddr = 	(WORD) PCI_Read(4) & 0xFFF0 ;

	//printf ("AutoDetect_IOBase : Intel HM65 SMBus Host I/O Base = 0x%4X\n",this->m_MapIOAddress );

	return true;
}

bool Get_HM76_SMBusIoAddr(DWORD dwIOAddr)
{
	DWORD dwResult;

	PCI_Write(dwIOAddr+HM76_SMBUS_HOST_CONFIGURE,4);

	dwResult = 	PCI_Read(2);

	//printf ("HM76 SMBus Host Configure = 0x%4X\n",dwResult );

	if ( dwResult & HM76_SMBUS_HOST_HST_EN )
	{
		//printf ("AutoDetect_IOBase : Intel HM76 SMBus Host Enable!\n");
	}
	else
	{
		//printf ("AutoDetect_IOBase : Intel HM76 SMBus Host Disable!\n");

		return false;
	}

	PCI_Write(dwIOAddr+HM76_SMBUS_HOST_IOBASE,4);

	m_SMBusMapIoAddr = 	(WORD) PCI_Read(4) & 0xFFF0 ;

	//printf ("AutoDetect_IOBase : Intel HM76 SMBus Host I/O Base = 0x%4X\n",this->m_MapIOAddress );

	return true;
}

bool Get_SOC_SMBusIoAddr(DWORD dwIOAddr)
{
	DWORD dwResult;

	PCI_Write(dwIOAddr+SOC_SMBUS_HOST_CONFIGURE,4);

	dwResult = 	PCI_Read(2);

	//printf ("SOC SMBus Host Configure = 0x%4X\n",dwResult );

	if ( dwResult & SOC_SMBUS_HOST_HST_EN)
	{
		//printf ("AutoDetect_IOBase : Intel SOC SMBus Host Enable!\n");
	}
	else
	{
		//printf ("AutoDetect_IOBase : Intel SOC SMBus Host Disable!\n");

		return false;
	}

	PCI_Write(dwIOAddr+SOC_SMBUS_HOST_IOBASE,4);

	m_SMBusMapIoAddr = 	(WORD) PCI_Read(4) & 0xFFF0 ;

	//printf ("AutoDetect_IOBase : Intel SOC SMBus Host I/O Base = 0x%4X\n",this->m_MapIOAddress );

	return true;
}

bool Get_Apollo_Lake_SOC_SMBusIoAddr(DWORD dwIOAddr)
{
	DWORD dwResult;

	PCI_Write(dwIOAddr+Apollo_Lake_SOC_SMBUS_HOST_CONFIGURE,4);

	dwResult = 	PCI_Read(2);

	printf("Apollo_Lake_SOC SMBus Host Configure = 0x%4X\n",dwResult );

	if ( dwResult & Apollo_Lake_SOC_SMBUS_HOST_HST_EN )
	{
		printf("AutoDetect_IOBase : Intel Apollo_Lake_SOC SMBus Host Enable!\n");
	}
	else
	{
		printf("AutoDetect_IOBase : Intel Apollo_Lake_SOC SMBus Host Disable!\n");

		return false;
	}

	PCI_Write(dwIOAddr+Apollo_Lake_SOC_SMBUS_HOST_IOBASE,4);

	m_SMBusMapIoAddr = 	(WORD) PCI_Read(4) & 0xFFF0 ;

	printf("AutoDetect_IOBase : Intel Apollo_Lake_SOC SMBus Host I/O Base = 0x%4X\n",m_SMBusMapIoAddr );

	return true;
}

//20170829 Add Sky_Lake by Tracy↓↓↓
bool Get_Sky_Lake_SOC_SMBusIoAddr(DWORD dwIOAddr)
{
	DWORD dwResult;

	PCI_Write(dwIOAddr+Sky_Lake_SOC_SMBUS_HOST_CONFIGURE,4);

	dwResult = 	PCI_Read(2);

	//AfxMessageBox ("Sky_Lake_SOC SMBus Host Configure = 0x%4X\n",dwResult );

	if ( dwResult & Sky_Lake_SOC_SMBUS_HOST_HST_EN )
	{
		//AfxMessageBox ("AutoDetect_IOBase : Intel Sky_Lake_SOC SMBus Host Enable!\n");
	}
	else
	{
		//AfxMessageBox ("AutoDetect_IOBase : Intel Sky_Lake_SOC SMBus Host Disable!\n");

		return false;
	}

	PCI_Write(dwIOAddr+Sky_Lake_SOC_SMBUS_HOST_IOBASE,4);

	m_SMBusMapIoAddr = 	(WORD) PCI_Read(4) & 0xFFF0 ;

	//AfxMessageBox ("AutoDetect_IOBase : Intel Sky_Lake_SOC SMBus Host I/O Base = 0x%4X\n",m_SMBusMapIoAddr );

	return true;
}
//20170829 Add Sky_Lake by Tracy↑↑↑

//20170829 Add Sky_Lake U by Tracy↓↓↓
bool Get_Sky_Lake_U_SOC_SMBusIoAddr(DWORD dwIOAddr)
{
	DWORD dwResult;

	PCI_Write(dwIOAddr+Sky_Lake_U_SOC_SMBUS_HOST_CONFIGURE,4);

	dwResult = 	PCI_Read(2);

	//AfxMessageBox ("Sky_Lake_SOC U SMBus Host Configure = 0x%4X\n",dwResult );

	if ( dwResult & Sky_Lake_U_SOC_SMBUS_HOST_HST_EN )
	{
		//AfxMessageBox ("AutoDetect_IOBase : Intel Sky_Lake_SOC U SMBus Host Enable!\n");
	}
	else
	{
		//AfxMessageBox ("AutoDetect_IOBase : Intel Sky_Lake_SOC U SMBus Host Disable!\n");

		return false;
	}

	PCI_Write(dwIOAddr+Sky_Lake_U_SOC_SMBUS_HOST_IOBASE,4);

	m_SMBusMapIoAddr = 	(WORD) PCI_Read(4) & 0xFFF0 ;

	//AfxMessageBox ("AutoDetect_IOBase : Intel Sky_Lake_U_SOC SMBus Host I/O Base = 0x%4X\n",m_SMBusMapIoAddr );

	return true;
}
//20170829 Add Sky_Lake U by Tracy↑↑↑





bool Get_VX900_SMBusIoAddr(DWORD dwIOAddr) //Add for VX900 SMBus Controller IOAddr Function
{
	PCI_Write(dwIOAddr+VX900_SMBUS_HOST_CONFIGURE,4);

	DWORD dwResult = PCI_Read(2);

	if ( dwResult & VX900_SMBUS_HOST_CONTROLER_ENABLE )
	{
            //printf ("AutoDetect_IOBase : VIA CX700M SMBus Host Enable!\n");
	}
	else
	{
			//	printf ("AutoDetect_IOBase : VIA CX700M SMBus Host Disable!\n");

		return false;
	}

	PCI_Write(dwIOAddr+VX900_SMBUS_HOST_IOBASE,4);

	m_SMBusMapIoAddr = 	(WORD) PCI_Read(4) & 0xFF00 ;

    //printf("VX900's m_SMBusMapIoAddr is %x\n",m_SMBusMapIoAddr);

	return true;
}


//////////////////////////////////////////////////////////////////////
// VT8237 SMBus Mapping I/O read/write
//////////////////////////////////////////////////////////////////////
void SMBusIoWrite(BYTE byteOffset,BYTE byteData)
{
	//SetPortVal(m_SMBusMapIoAddr + byteOffset, byteData,1);
	//printf("byteData is %x\nAddress: %x\n", byteData, m_SMBusMapIoAddr + byteOffset);
	outb(byteData,m_SMBusMapIoAddr + byteOffset);
	usleep(10);
}

BYTE SMBusIoRead(BYTE byteOffset)
{
	DWORD dwAddrVal;

	dwAddrVal=inb(m_SMBusMapIoAddr + byteOffset);
	usleep(10);
	return (BYTE)(dwAddrVal & 0x0FF);
}
//////////////////////////////////////////////////////////////////////
// Normal SMBus Function
//////////////////////////////////////////////////////////////////////
void SMBus_Clear() //Need to planing for Multi-Controller Architecture leon 2011/5/10
{


    BYTE IoState = 0x00;
    do{
        switch(devid){
        case VIA_VX900_BUS_CTRL_DEVICE_ID:
            SMBusIoWrite(SMBHSTSTS ,0xDF);//For VX900 SMBus HST_STS Clear Code
            break;
        default:
            SMBusIoWrite(SMBHSTSTS ,0xFF);//For Normal SMBus HST_STS Clear Code
            break;
        }
        usleep(1);
        IoState=SMBusIoRead(SMBHSTSTS);
        usleep(1);
        IoState=IoState & 0x01;
    }while(IoState != 0);
	SMBusIoWrite(SMBHSTDAT0,0x00);
}

int SMBus_Wait ()
{
	int		timeout = SMBUS_TIMEOUT;
	DWORD	dwValue;

	while (timeout--)
	{
		// I/O Delay
		usleep(1);
		// Read Host Status Register
		dwValue = SMBusIoRead(SMBHSTSTS) & 0x00FF;


		if ( dwValue & SMBHSTSTS_INTR )
		{
			//printf("SMBus Action Completion! %x\n",dwValue);
			return SMBUS_OK;
		}

		if ( dwValue & SMBHSTSTS_FAILED )
		{
  			printf("SMBus Action FAILED! %x\n",dwValue);
			return SMBHSTSTS_FAILED;
		}

		if (dwValue & SMBHSTSTS_COLLISION)
		{
  			printf("SMBus Action COLLISION! %x\n",dwValue);
			return SMBHSTSTS_COLLISION;
		}

		if (dwValue & SMBHSTSTS_ERROR)
		{
  			printf("SMBus Action ERROR! %x\n",dwValue);
			return SMBHSTSTS_ERROR;
		}
	}

	return SMBUS_BUSY;
}

bool SMBus_Busy ()
{
	if ( (SMBusIoRead(SMBHSTSTS) & SMBHSTSTS_BUSY ) == 1 )
		return true;
	else
		return false;
}
//////////////////////////////////////////////////////////////////////
// Normal SMBus Function
//////////////////////////////////////////////////////////////////////
bool SMBus_CheckDevice (BYTE byteDeviceAddress)
{
	int ret;

	// Clear Status First !
	SMBus_Clear();

	if (SMBus_Busy())
		return SMBUS_BUSY;

	SMBusIoWrite(SMBHSTADD  , byteDeviceAddress  & ~1 );
	SMBusIoWrite(SMBHSTCNT  , SMBHSTCNT_START | SMBHSTCNT_QUICK);

	ret = SMBus_Wait();

	if (ret == SMBUS_OK)
		return true;
	else
		return false;
}

int SMBus_WriteByte (BYTE byteSlave,BYTE pCmd,BYTE  pByte)
{
	SMBus_Clear();

	if (SMBus_Busy())
		return SMBUS_BUSY;

	SMBusIoWrite(SMBHSTADD  , byteSlave & ~1 );
	SMBusIoWrite(SMBHSTCMD  , pCmd );
	SMBusIoWrite(SMBHSTDAT0 , pByte );
	SMBusIoWrite(SMBHSTCNT  , SMBHSTCNT_START | SMBHSTCNT_BYTE);

	return (int)SMBus_Wait();
}

int SMBus_ReadByte (BYTE byteSlave,BYTE pCmd,BYTE *pByte)
{
	SMBus_Clear();

	if (SMBus_Busy())
		return SMBUS_BUSY;

	SMBusIoWrite(SMBHSTADD  , byteSlave | 1 );
	SMBusIoWrite(SMBHSTCMD  , pCmd );
	SMBusIoWrite(SMBHSTCNT  , SMBHSTCNT_START | SMBHSTCNT_BYTE);

	int ret = SMBus_Wait();

	if (ret == SMBUS_OK)
	{

		*pByte = (BYTE)SMBusIoRead(SMBHSTDAT0) &0xFF;
	}

	return ret;
}
////
