/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint8_t Rxbuffer3[10], Rxbuffer4[10], Rxbuffer6[1];

uint8_t flag_QR = 0, flag_color = 0;

uint8_t for_x1_val = 0, for_x2_val = 0, for_x3_val = 0, for_x4_val = 0;
uint8_t beh_x1_val = 0, beh_x2_val = 0, beh_x3_val = 0, beh_x4_val = 0;
uint8_t left_x1_val = 0, left_x2_val = 0, left_x3_val = 0, left_x4_val = 0;
uint8_t right_x1_val = 0, right_x2_val = 0, right_x3_val = 0, right_x4_val = 0;

uint8_t state = backwalkToRaw2;
//
//uint8_t state = test;
unsigned char hexEND[3] = {0xff, 0xff, 0xff};

uint16_t QR[6] = {0}, color[6] = {0}, rx3[10], rx4[10], rx6[10];
uint16_t number3 = 0, number6 = 0, angle;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int fputc(int ch, FILE *f)
{
	HAL_UART_Transmit(&huart6, (uint8_t *)&ch, 1, 0xffff);
	return ch;
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
//color[0] = 1;
//color[1] = 2;
//color[2] = 3;
//color[3] = 2;
//color[4] = 3;
//color[5] = 1;
 	
//QR[0] = 2;
//QR[1] = 3;
//QR[2] = 1;
//QR[3] = 1;
//QR[4] = 2;
//QR[5] = 3;
  /* USER CODE END 1 */
  
  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();
  MX_TIM2_Init();
  MX_USART6_UART_Init();
  MX_UART4_Init();
  /* USER CODE BEGIN 2 */
  initializeARM();
//	printf("t2.txt=\"���\"");
//	HAL_UART_Transmit(&huart6, hexEND, 3, 0xffff);
//	printf("t0.txt=\"���\"");
//	HAL_UART_Transmit(&huart6, hexEND, 3, 0xffff);
//	printf("t1.txt=\"���\"");
//	HAL_UART_Transmit(&huart6, hexEND, 3, 0xffff);
  HAL_TIM_Base_Start_IT(&htim2);
  
  HAL_UART_Receive_IT(&huart3, Rxbuffer3, 10);
  HAL_UART_Receive_IT(&huart6, Rxbuffer6, 1);
  HAL_UART_Receive_IT(&huart4, Rxbuffer4, 10);
  
//	uint8_t for_x1,for_x2,for_x3,for_x4;
//	getLeftLine(&for_x1, &for_x2, &for_x3,&for_x4);
//	printf("t0.txt=\"%d%d%d%d\"",for_x1,for_x2,for_x3,for_x4);
//	HAL_UART_Transmit(&huart6, hexEND, 3, 0xffff);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
#if 1
//	  if(flag_QR)
//	  {
//		  printf("t0.txt=\"�ж�\"");
//			HAL_UART_Transmit(&huart6, hexEND, 3, 100);
//	  }
//	  if(flag_color)
//	  {
//		printf("t1.txt=\"�ɹ�\"");
//		HAL_UART_Transmit(&huart6, hexEND, 3, 100);
//	  }
	  switch(state)
		{
			/**
			*ԭ�����ڶ���
			*/
			
			/*ͣ��ɨ��*/
			case stopToScanQR:
				delay_ms(1000);
				readQR();
				while(flag_QR == 0)
//				while(rx4[9] != 'Z')
				{
						printf("t1.txt=\"��ʼ\"");
						HAL_UART_Transmit(&huart6, hexEND, 3, 0xffff);
						printf("t2.txt=\"ɨ��\"");
						HAL_UART_Transmit(&huart6, hexEND, 3, 0xffff);
				}
				printf("t1.txt=\"%d%d%d\"",QR[0],QR[1],QR[2]);
				HAL_UART_Transmit(&huart6, hexEND, 3, 0xffff);
				printf("t2.txt=\"%d%d%d\"",QR[3],QR[4],QR[5]);
				HAL_UART_Transmit(&huart6, hexEND, 3, 0xffff);
				clearValue();
				HAL_TIM_Base_Start_IT(&htim2);             //������ʱ��TIM2�ж�
				state = leftwalkToRaw4;			 		//״̬�л�Ϊ������ʻ��ԭ����
				break;
			/*ͣ��ʶ����ɫ*/
			case stopwalkToIdentifyColor:
				scanColor();
				delay_ms(2000);
				while(flag_color == 0)
////				while(rx3[9] != 'Z')
				{
					printf("t1.txt=\"%d%d%d\"",QR[0],QR[1],QR[2]);
					HAL_UART_Transmit(&huart6, hexEND, 3, 0xffff);
//					if(flag_QR)
//				  {
//					  printf("t0.txt=\"�ж�\"");
//						HAL_UART_Transmit(&huart6, hexEND, 3, 100);
//				  }
//				  if(flag_color)
//				  {
//					printf("t1.txt=\"�ɹ�\"");
//					HAL_UART_Transmit(&huart6, hexEND, 3, 100);
//				  }
				}
//				printf("t1.txt=\"%d%d%d\"",color[3],color[4],color[5]);
//				HAL_UART_Transmit(&huart6, hexEND, 3, 0xffff);
				clearValue();
				HAL_TIM_Base_Start_IT(&htim2);            //������ʱ��TIM3�ж�
				state = forwalkToRaw1;			 //ǰ��һ��ԭ����
				break;
			/*ͣ����ȡ����*/
			case stopwalkToGetRawMass1:						//С��ֹͣʱ�ɹرն�ʱ���ж�
				GetAllMass();								//��ȥ����
//				while(1);
//				delay_ms(2500);
				initializeARM();
				clearValue();
				HAL_TIM_Base_Start_IT(&htim2);             //������ʱ��TIM3�ж�
				state = backToRough3;
				break; 

			
			/**
			*�ּӹ�������
			*/
			
			/*�ڴּӹ�ǰ����ת*/
			case counterclkRota1:
				counterclockwiseRotation();					//��ת90��
				delay_ms(2500);
				clearValue();
				HAL_TIM_Base_Start_IT(&htim2);             //������ʱ��TIM3�ж�
				state = backToAdjustAtRough;			 		//״̬����Ϊ���������ߵ�ԭ����
				clearValue();
				break;
			
			/*�����Ϸ��õ��ּӹ���*/
			case stopwalkToPutRough1:						//�ڴּӹ���������
//				while(1);
				putRawMassToRoughMachine();					//�����ϵ��ּӹ���
				delay_ms(1000);
				getMassAtRough();								//������֮��������
				delay_ms(1000);
//				while(1);
				clearValue();
				HAL_TIM_Base_Start_IT(&htim2);            //������ʱ��TIM3�ж�
				state = backRoughToSemiProcess;			 //״̬�л�Ϊ������ʻ����ӹ���
				break;
			case counterclkRota4:
				counterclockwiseRotation();					//��ת90��
				delay_ms(2500);
				clearValue();
				HAL_TIM_Base_Start_IT(&htim2);             //������ʱ��TIM3�ж�
				state = forwalkRoughToSemiProcess;			 		//״̬����Ϊ���������ߵ�ԭ����
				clearValue();
				break;
			/**
			*���Ʒ������
			*/
			case stopwalkToPutSemi1:
				putRawMassToSemiProcess();					//�����ϵ��ּӹ���
//				while(1);
//				delay_ms(1000);
				clearValue();
				HAL_TIM_Base_Start_IT(&htim2);             //������ʱ��TIM3�ж�
				state = backSemiToRaw3;			 		//״̬�л�Ϊ������ʻ��ԭ����
				break;
			
			case counterclkRota5:							//�ڰ�ӹ������ص�ԭ��������ת״̬
				counterclockwiseRotation();					//��ת90��
				delay_ms(2500);
				clearValue();
				HAL_TIM_Base_Start_IT(&htim2);             //������ʱ��TIM3�ж�
				state = backSemiToRaw2;			 		//״̬����Ϊ���������ߵ�ԭ����
				break;
			case counterclkRota6:
				counterclockwiseRotation();					//��ת90��
				delay_ms(2500);
				clearValue();
				HAL_TIM_Base_Start_IT(&htim2);             //������ʱ��TIM3�ж�
				state = forSemiToRaw3;			 		//״̬����Ϊ���������ߵ�ԭ����
				break;
			/*�ڶ���*/
			case stopwalkToGetRawMassFirst:
//				while(1);
				postureArm(order2[0]);
				delay_ms(2500);
				clearValue();
				HAL_TIM_Base_Start_IT(&htim2);             //������ʱ��TIM3�ж�
				state = forToGetRawMassFirst;
				break;
			
			case stopToCatchFirstMass:
				setSpeedPosition(8,4,13);
				delay_ms(1500);
				clearValue();
				HAL_TIM_Base_Start_IT(&htim2);             //������ʱ��TIM3�ж�
				state = backToPutMassFirst;
				break;
			case stopToPutFirstMass:
				sputMass(QR[3]);
				clearValue();
				postureArm(order2[1]);
				HAL_TIM_Base_Start_IT(&htim2);             //������ʱ��TIM3�ж�
				state = forToGetRawMassSecond;
				break;
			case stopToCatchSecondMass:
				setSpeedPosition(8,4,13);
				delay_ms(1500);
				clearValue();
				HAL_TIM_Base_Start_IT(&htim2);             //������ʱ��TIM3�ж�
				state = backToPutMassSecond;
				break;
			case stopToPutSecondMass:
				sputMass(QR[4]);
				clearValue();
				postureArm(order2[2]);
				HAL_TIM_Base_Start_IT(&htim2);             //������ʱ��TIM3�ж�
				state = forToGetRawMassThird;
				break;
			case stopToCatchThirdMass:
				setSpeedPosition(8,4,13);
				delay_ms(1500);
				clearValue();
				HAL_TIM_Base_Start_IT(&htim2);             //������ʱ��TIM3�ж�
				state = backToPutMassThird;
				break;
			case stopToPutThirdMass:
				sputMass(QR[5]);
				clearValue();
				HAL_TIM_Base_Start_IT(&htim2);             //������ʱ��TIM3�ж�
				state = backToRough;
				break;
			/**
			*�ּӹ�������
			*/
			
			/*�ڴּӹ�ǰ����ת*/
			case counterclkRota3:
				counterclockwiseRotation();					//��ת90��
				delay_ms(2500);
				clearValue();
				HAL_TIM_Base_Start_IT(&htim2);             //������ʱ��TIM3�ж�
				state = backToAdjustAtRough2;			 		//״̬����Ϊ���������ߵ�ԭ����
				clearValue();
				break;
			
			/*�����Ϸ��õ��ּӹ���*/
			case stopwalkToPutRough2:						//�ڴּӹ���������
				clearValue();
				putRawMassToRoughMachine3();					//�����ϵ��ּӹ���
				delay_ms(1000);
				getMassAtRough3();								//������֮��������
				delay_ms(1000);
				HAL_TIM_Base_Start_IT(&htim2);            //������ʱ��TIM3�ж�
				state = backRoughToSemiProcess2;			 //״̬�л�Ϊ������ʻ����ӹ���
				break;
			
			case counterclkRota7:
				counterclockwiseRotation();					//��ת90��
				delay_ms(2500);
				clearValue();
				HAL_TIM_Base_Start_IT(&htim2);             //������ʱ��TIM3�ж�
				state = forwalkRoughToSemiProcess3;			 		//״̬����Ϊ���������ߵ�ԭ����
				clearValue();
				break;
			/**
			*���Ʒ������
			*/
			case stopwalkToPutSemi2:
				putRawMassToSemiProcess2();					//�����ϵ��ּӹ���
				//delay_ms(2500);
				clearValue();
				HAL_TIM_Base_Start_IT(&htim2);             //������ʱ��TIM3�ж�
				state = backwalkSemiToEnd;			 		//״̬�л�Ϊ������ʻ��ԭ����
				break;
		}
		  #endif
  }

  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 72;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */


#if 1
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) 
{
  	if(huart->Instance==USART3)
	{  
		for(int i = 0; i < 10; i++)
		{
			rx3[i] = Rxbuffer3[i];
		}
		if(rx3[0] == 'C')
		{
			flag_QR= 1;
			if(rx3[9] == 'Z')
			{
				if(rx3[1] == 'F')
				{
					color[0] = rx3[2] - '0';
					color[1] = rx3[3] - '0';
					color[2] = rx3[4] - '0';
				}
				if(rx3[5] == 'S')
				{
					color[3] = rx3[6] - '0';
					color[4] = rx3[7] - '0';
					color[5] = rx3[8] - '0';
				}
				flag_color = 1;
//				printf("%d %d %d %d %d %d",color[0],color[1],color[2],color[3],color[4],color[5]);
			}
		 }
      HAL_UART_Receive_IT(&huart3,Rxbuffer3,10);
//		rx3[number3++] = Rxbuffer3[0];
//		if(rx3[0] == 'Q')
//		{
//			if(rx3[number3-1] == 'Z')
//			{
//				printf("Z");
//				if(rx3[1] == 'F')
//				{
//					QR[0] = rx3[2]-'0';
//					QR[1] = rx3[3]-'0';
//					QR[2] = rx3[4]-'0';
//				}
//				if(rx3[5] == 'S')
//				{
//					QR[3] = rx3[6]-'0';
//					QR[4] = rx3[7]-'0';
//					QR[5] = rx3[8]-'0';
//				}
//				number3 = 0;
//			}
//		 }
//		if(rx3[0] == 'C')
//		{
//			if(rx3[number3-1] == 'Z')
//			{
//				if(rx3[1] == 'F')
//				{
//					color[0] = rx3[2]-'0';
//					color[1] = rx3[3]-'0';
//					color[2] = rx3[4]-'0';
//				}
//				if(rx3[5] == 'S')
//				{
//					color[3] = rx3[6]-'0';
//					color[4] = rx3[7]-'0';
//					color[5] = rx3[8]-'0';
//				}
//				number3 = 0;
//			}
//		 }
//    else
//	{
//      number3=0;
//    }
//    HAL_UART_Receive_IT(&huart3,Rxbuffer3,1);
  }
	if(huart->Instance==UART4)
	{  
		for(int i = 0; i < 10; i++)
		{
			rx4[i] = Rxbuffer4[i];
		}
		if(rx4[0] == 'Q')
		{
			if(rx4[9] == 'Z')
			{
				if(rx4[1] == 'F')
				{
					QR[0] = rx4[2]-'0';
					QR[1] = rx4[3]-'0';
					QR[2] = rx4[4]-'0';
				}
				if(rx4[5] == 'S')
				{
					QR[3] = rx4[6]-'0';
					QR[4] = rx4[7]-'0';
					QR[5] = rx4[8]-'0';
				}
//				for(int i = 0; i < 10; i++)
//				{
//					rx3[i] = 0;
//				}
//				printf("%d %d %d %d %d %d",QR[0],QR[1],QR[2],QR[3],QR[4],QR[5]);
				flag_QR= 1;
			}
		 }
      HAL_UART_Receive_IT(&huart4,Rxbuffer4,10);
  }
	if(huart->Instance==USART6)
	{
		rx6[number6++] = Rxbuffer6[0];
		if(rx6[0] == 'A')
		{
			if(rx6[number6-1] == 'Z')
			{	
				angle = (rx6[2]-'0')*100+(rx6[3]-'0')*10+(rx6[4]-'0')*1;
				setSpeedPosition(rx6[1] - '0', 4, angle);
				number6=0;
			}
		}
		else
		{
			number6=0;
		}
		HAL_UART_Receive_IT(&huart6,Rxbuffer6,1);
	}
}


//�ⲿ�жϻص�����
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	switch(GPIO_Pin)
	{
		case for_x1_Pin:
			for_x1_val++;
			break;
		case for_x2_Pin:
			for_x2_val++;
			break;
		case for_x3_Pin:
			for_x3_val++;
			break;
		case for_x4_Pin:
			for_x4_val++;
			break;
		case beh_x1_Pin:
			beh_x1_val++;
			break;
		case beh_x2_Pin:
			beh_x2_val++;
			break;
		case beh_x3_Pin:
			beh_x3_val++;
			break;
		case beh_x4_Pin:
			beh_x4_val++;
			break;
		case left_x1_Pin:
			left_x1_val++;
			break;
		case left_x2_Pin:
			left_x2_val++;
			break;
		case left_x3_Pin:
			left_x3_val++;
			break;
		case left_x4_Pin:
			left_x4_val++;
			break;
		case right_x1_Pin:
			right_x1_val++;
			break;
		case right_x2_Pin:
			right_x2_val++;
			break;
		case right_x3_Pin:
			right_x3_val++;
			break;
		case right_x4_Pin:
			right_x4_val++;
			break;
	}

	/*�ӳ�������ʻ��ԭ�����켣����ֹͣץȡ*/
	 if(right_x3_val >= 2 && state == backwalkToRaw2)//�ӳ��������2����
	 {
		stop();
		clearValue();
		state = leftwalkToScan2 ;
	 }
	 if(right_x1_val >= 2 && right_x4_val >= 2 && state == leftwalkToScan2)//����������ɨ��
	 {
		stop();
		clearValue();
		__HAL_TIM_CLEAR_IT(&htim2 ,TIM_IT_UPDATE ); //���TIM3�жϹ���
		HAL_TIM_Base_Stop_IT(&htim2);             //ֹͣ��ʱ��TIM3�ж�
		state = stopToScanQR;
	 }
	 if(for_x1_val >= 4 && beh_x4_val >= 4 && state == leftwalkToRaw4)//ɨ�������4����
	 {
		stop();
		clearValue();            
		state = backToAdjustAtRaw;
	 }
	 
	 if(left_x1_val >= 1 && right_x4_val >= 1 && state == backToAdjustAtRaw)//���������߽��н���
	 {
		stop();
		clearValue();
		state = forToAdjustAtRaw;
	 }
	 
	 if(for_x4_val >= 1 && for_x1_val >= 1 && state == forToAdjustAtRaw)//ǰ�������߽��н���
	 {
		stop();
		clearValue();
		state = stopwalkToIdentifyColor;
	 }
	 
	if(left_x4_val >= 2 && right_x1_val >= 2 && state == forwalkToRaw1)//ǰ��һ����ʻ��ԭ����
	{
//		printf("t2.txt=\"%d%d%d%d\"", left_x4_val,left_x3_val,right_x1_val,right_x2_val);
//		HAL_UART_Transmit(&huart6, hexEND, 3, 0xffff);
		stop();
		clearValue();
		__HAL_TIM_CLEAR_IT(&htim2 ,TIM_IT_UPDATE ); 
		HAL_TIM_Base_Stop_IT(&htim2);             
		state = stopwalkToGetRawMass1;
	}
	
	/*��ԭ������ʻ���ּӹ����켣����ͣ������ץȡ*/
	if(left_x1_val >= 3 && right_x4_val >= 3 && state == backToRough3)//���������ߵ��ּӹ���
	{
//		printf("t2.txt=\"%d %d\"", left_x1_val,right_x4_val);
//		HAL_UART_Transmit(&huart6, hexEND, 3, 0xffff);
		stop();
		clearValue();
		__HAL_TIM_CLEAR_IT(&htim2 ,TIM_IT_UPDATE ); 
		HAL_TIM_Base_Stop_IT(&htim2);             
		state = counterclkRota1;
	}
	
	if(beh_x1_val >= 1 && beh_x4_val >= 1 && state == backToAdjustAtRough)//�ڴּӹ���ǰ���˽�������
	{
		stop();
		clearValue();
		state = forToAdjustAtRough;
	}
	if(left_x3_val >= 2 && right_x2_val >= 2 && state == forToAdjustAtRough)//ǰ����������ʻ���ּӹ���ֹͣ
	{
		stop();
		clearValue();        
		__HAL_TIM_CLEAR_IT(&htim2 ,TIM_IT_UPDATE ); 
		HAL_TIM_Base_Stop_IT(&htim2); 
//		if(HAL_GPIO_ReadPin(GPIOD,left_x4_Pin) == 0 || HAL_GPIO_ReadPin(GPIOD,right_x1_Pin) == 0)
		state = stopwalkToPutRough1;
	}	
	if(left_x1_val >= 3 && right_x4_val >= 3 && state == backRoughToSemiProcess)//���˵���ӹ���
	{
		stop();
		clearValue();
		__HAL_TIM_CLEAR_IT(&htim2 ,TIM_IT_UPDATE );
		HAL_TIM_Base_Stop_IT(&htim2);    
		state = counterclkRota4;
	}
	/*�Ӵּӹ��������Ʒ��*/		
	if(right_x1_val >= 3 && left_x4_val >= 3 && state == forwalkRoughToSemiProcess)//ǰ��3������ʻ����ӹ���ֹͣ
	{
		clearValue();
		__HAL_TIM_CLEAR_IT(&htim2 ,TIM_IT_UPDATE ); 
		HAL_TIM_Base_Stop_IT(&htim2);             
		state = stopwalkToPutSemi1;													//״̬�л�Ϊ���ð�ӹ���
		stop();
	}
	if(left_x1_val >= 3 && right_x4_val >= 3 && state == backSemiToRaw3)//�Ӱ�ӹ�������������ԭ����
	{
		stop();
		clearValue();
		__HAL_TIM_CLEAR_IT(&htim2 ,TIM_IT_UPDATE );
		HAL_TIM_Base_Stop_IT(&htim2);             
		state = counterclkRota5;
	}
	if(left_x1_val >= 2 && right_x4_val >= 2 && state == backSemiToRaw2)//��ת��������
	{
		stop();
		clearValue();
		__HAL_TIM_CLEAR_IT(&htim2 ,TIM_IT_UPDATE );
		HAL_TIM_Base_Stop_IT(&htim2);             
		state = counterclkRota6;
	}

	/*�ڶ���*/
	if(left_x4_val >= 2 && right_x1_val >= 2 && state == forSemiToRaw3)//ǰ������ԭ������ǰ����ʼչ����е��
	{
		stop();
		clearValue();
		state = stopwalkToGetRawMassFirst;
		__HAL_TIM_CLEAR_IT(&htim2 ,TIM_IT_UPDATE ); 
		HAL_TIM_Base_Stop_IT(&htim2);             
	}
	if(left_x4_val >= 1 && right_x1_val >= 1 && state == forToGetRawMassFirst)
	{
		stop();
		clearValue();
		state = stopToCatchFirstMass;
		__HAL_TIM_CLEAR_IT(&htim2 ,TIM_IT_UPDATE );
		HAL_TIM_Base_Stop_IT(&htim2);
	}
	if(left_x1_val >= 1 && right_x4_val >= 1 && state == backToPutMassFirst)
	{
		stop();
		clearValue();
		state = stopToPutFirstMass;
		__HAL_TIM_CLEAR_IT(&htim2 ,TIM_IT_UPDATE );
		HAL_TIM_Base_Stop_IT(&htim2);
	}
	if(left_x4_val >= 1 && right_x1_val >= 1 && state == forToGetRawMassSecond)
	{
		stop();
		clearValue();
		state = stopToCatchSecondMass;
		__HAL_TIM_CLEAR_IT(&htim2 ,TIM_IT_UPDATE );
		HAL_TIM_Base_Stop_IT(&htim2);
	}
	if(left_x1_val >= 1 && right_x4_val >= 1 && state == backToPutMassSecond)
	{
		stop();
		clearValue();
		state = stopToPutSecondMass;
		__HAL_TIM_CLEAR_IT(&htim2 ,TIM_IT_UPDATE );
		HAL_TIM_Base_Stop_IT(&htim2);
	}
	if(left_x4_val >= 1 && right_x1_val >= 1 && state == forToGetRawMassThird)
	{
		stop();
		clearValue();
		state = stopToCatchThirdMass;
		__HAL_TIM_CLEAR_IT(&htim2 ,TIM_IT_UPDATE );
		HAL_TIM_Base_Stop_IT(&htim2);
	}
	if(left_x1_val >= 1 && right_x4_val >= 1 && state == backToPutMassThird)
	{
		stop();
		clearValue();
		state = stopToPutThirdMass;
		__HAL_TIM_CLEAR_IT(&htim2 ,TIM_IT_UPDATE );
		HAL_TIM_Base_Stop_IT(&htim2);
	}
/*************************************************************************************************/

/**************************************************************************************************/
	
	if(left_x1_val >= 2 && right_x4_val >= 2 && state == backToRough)
	{
		stop();
		clearValue();
		__HAL_TIM_CLEAR_IT(&htim2 ,TIM_IT_UPDATE ); 
		HAL_TIM_Base_Stop_IT(&htim2);             
		state = counterclkRota3;
	}
	
	if(beh_x1_val >= 1 && beh_x4_val >= 1 && state == backToAdjustAtRough2)
	{
		stop();
		clearValue();
		state = forToAdjustAtRough2;
	}
	
	if(left_x3_val >= 2 && right_x2_val >= 2 && state == forToAdjustAtRough2)//ǰ����������ʻ���ּӹ���ֹͣ
	{
		stop();
		clearValue();
		__HAL_TIM_CLEAR_IT(&htim2 ,TIM_IT_UPDATE );
		HAL_TIM_Base_Stop_IT(&htim2);             
		state = stopwalkToPutRough2;
	}
	if(left_x1_val >= 3 && right_x4_val >= 3 && state == backRoughToSemiProcess2)//���˵���ӹ���
	{
		stop();
		clearValue();
		__HAL_TIM_CLEAR_IT(&htim2 ,TIM_IT_UPDATE );
		HAL_TIM_Base_Stop_IT(&htim2);             
		state = counterclkRota7;
	}
	/*�Ӵּӹ��������Ʒ��*/	
	if(right_x1_val >= 3 && left_x4_val >= 3 && state == forwalkRoughToSemiProcess3)//ǰ��3������ʻ����ӹ���ֹͣ
	{
		stop();
		clearValue();
		__HAL_TIM_CLEAR_IT(&htim2 ,TIM_IT_UPDATE ); 
		HAL_TIM_Base_Stop_IT(&htim2);   		
		state = stopwalkToPutSemi2;
	}
	
	if(left_x1_val >=1 && state == backwalkSemiToEnd)//���������ߵ���������ǰ��
	{
		stop();
		clearValue();
		state = leftToReturn;
	}
	
	if(for_x1_val >= 3 && beh_x4_val >= 3 && state == leftToReturn)
	{
		stop();
		clearValue();
		state = forToReturn;
	}
	if(beh_x1_val >= 2 && beh_x4_val >= 2 && state == forToReturn)
	{
		stop();
		clearValue();
		state = lastleft;
	}
	if(right_x1_val >= 1 && right_x4_val >= 1 && state == lastleft)
	{
		stop();
		clearValue();
		state = end;
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	/**
	*ÿ��5ms���붨ʱ��2�ж�
	*��ʱ��3����С��ת��
	*/
	if (htim == (&htim2))
    {
		if(HAL_GPIO_ReadPin(GPIOB,K1_Pin) == GPIO_PIN_RESET)
		{  
			state = keyTostop;
		}
		switch(state)
		{
			case forwalkRawToRoughMachine:
			case forwalkToRaw:
			case forwalkRawToRoughMachine1:
			case forwalkRawToRoughMac:
			case forToReturn:
				strightLineWalking();//ǰ��Ѳ��
				break;
			case forwalkToRaw1:
			case forwalkRoughToSemiProcess:
			case forSemiToRaw3:
			case forToGetRawMassFirst:
			case forToGetRawMassSecond:
			case forToGetRawMassThird:
			case forwalkRoughToSemiProcess3:
			case forToAdjustAtRaw:
			case forToPosition:
				low_strightLineWalking();
				break;
			case forToAdjustAtRough:
			case forToAdjustAtRough2:
				lowlow_strightLineWalking();
				break;
			case backwalkToRaw2: 
				low_backward();
				break;
			case backToRough3:
			case backToRough:
			case backwalkSemiToEnd:
			case backToAdjustAtRaw:
			case backToAdjustAtRough:
			case backRoughToSemiProcess:
			case backSemiToRaw3:
			case backSemiToRaw2:
			case backToAdjustAtRough2:
			case backRoughToSemiProcess2:
			case backToCatchMid:
			case backToPutMassFirst:
			case backToPutMassSecond:
			case backToPutMassThird:
				backLineWalking();//��Ѳ��
				break;
			case leftwalkRawToRoughMachine3:
			case leftwalkRoughToSemiProcess:
			case leftwalkToRaw4:
			case leftwalkToScan2:
			case leftwalkSemiToRaw5:
			case leftwalkSemiToRaw2:
			case leftwalkToRa:
			case leftwalkRoughToSemiProcess3:
			case leftToReturn:
			case lastleft:
				leftwardLineWalking();//��Ѳ��
				break;
			case stopwalkToGetRawMass1:
			case stopwalkToPutRough1:
			case stopwalkToPutSemi1:
			case stopwalkToGetRawMass2:
			case stopToScanQR:
			case stopwalkToPutRough2:
			case stopwalkToPutSemi2:
			case end:
			case keyTostop:
			case stopwalkToGetRawMassFirst:
			case stopToCatchFirstMass:
			case stopToPutFirstMass:
			case stopToCatchSecondMass:
			case stopToPutSecondMass:
			case stopToCatchThirdMass:
			case stopToPutThirdMass:
			case test:
				stop();
				break;
		}
    }
}
	


#endif
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
