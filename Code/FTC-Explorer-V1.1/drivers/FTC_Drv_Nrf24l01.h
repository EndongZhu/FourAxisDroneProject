#ifndef __FTC_DRV_NRF24L01_H__
#define __FTC_DRV_NRF24L01_H__

#include "board.h"

#define MODEL_RX				1			//普通接收
#define MODEL_TX				2			//普通发送
#define MODEL_RX2				3			//接收模式2,用于双向传输
#define MODEL_TX2				4			//发送模式2,用于双向传输

#define RX_PLOAD_WIDTH  255  	
#define TX_PLOAD_WIDTH  255  	
#define TX_ADR_WIDTH    5 	 	
#define RX_ADR_WIDTH    5   

class FTC_NRF : public FTC_SPI2
{
	
public:
	
	//初始化,model=1/2/3/4,ch为实用的通道号
	void Init(u8 model, u8 ch);	
	//发送数据包,用于model 2/4
	void TxPacket(uint8_t * tx_buf, uint8_t len);	
	//发送数据包,用于model 3
	void TxPacket_AP(uint8_t * tx_buf, uint8_t len);	
	//检查NRF模块是否正常工作
	bool Check(void);
	//检查是否有通信事件
	void Check_Event(void);

private:

	uint8_t NRF24L01_2_RXDATA[RX_PLOAD_WIDTH];//nrf24l01接收到的数据
	uint8_t NRF24L01_2_TXDATA[RX_PLOAD_WIDTH];//nrf24l01需要发送的数据

	uint8_t Read_Reg(uint8_t reg);
	uint8_t Write_Reg(uint8_t reg, uint8_t value);
	uint8_t Write_Buf(uint8_t reg, uint8_t *pBuf, uint8_t uchars);
	uint8_t Read_Buf(uint8_t reg, uint8_t *pBuf, uint8_t uchars);

};

extern FTC_NRF nrf;

#endif















