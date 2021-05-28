#include "arm.h"

unsigned char DM_Speed_Position[10] = {0xff, 0x01, 0x00, 0x01, 0x00, 0xff, 0x02, 0x00, 0xdc, 0x05};  //ͨ��0���ٶ�=1��λ��90��


/**
  * @brief  ���õ���������ٶȺͽǶ�
  * @param  channel: ���ͨ����0~15
  * @param  speed: ת���ٶ�1~20
  * @param	angle: ����Ƕ�0~180
  * @retval None
  */
void setSpeedPosition(uint8_t channel, uint8_t speed, uint16_t angle)
{
	uint16_t position = (uint16_t) (angle * 1.0 * 2000 / 180 + 500);
//	uint32_t position = angle;
	/*ʹ�ô���1�����ٶ�*/
	
	DM_Speed_Position[2] = channel;
	DM_Speed_Position[3] = speed;
	
	/*ʹ�ô���1����λ��*/
	
	DM_Speed_Position[7] = channel;
	
	DM_Speed_Position[8] = (position % 256);
	DM_Speed_Position[9] = (position / 256);
	HAL_UART_Transmit(&huart2, DM_Speed_Position, 10, 0xffff);//����ͨ�����ٶȣ�λ�� 
		
}

/**
  * @brief  ��ȡԭ��������������
  * @param  None
  * @retval None
  */
void GetRawMass()
{
	setSpeedPosition(0,4,90);
	delay_ms(2000);
	setSpeedPosition(1,4,90);
	delay_ms(2000);
	setSpeedPosition(2,4,90);
	delay_ms(2000);
	setSpeedPosition(3,4,90);
	delay_ms(2000);
	setSpeedPosition(4,4,90);
	delay_ms(2000);
}

void putRawMassToRoughMachine()
{	
	setSpeedPosition(0,4,60);
	delay_ms(2000);
	setSpeedPosition(1,4,60);
	delay_ms(2000);
	setSpeedPosition(2,4,60);
	delay_ms(2000);
	setSpeedPosition(3,4,60);
	delay_ms(2000);
	setSpeedPosition(4,4,60);
	delay_ms(2000);
}

void putRawMassToSemiProcess()
{
	
}