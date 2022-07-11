/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：三群：824575535
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		gtm_pwm
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看doc内version文件 版本说明
 * @Software 		ADS v1.2.2
 * @Target core		TC364DP
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-11-23
 ********************************************************************************************************************/
 
#ifndef _zf_gtm_pwm_h
#define _zf_gtm_pwm_h

#include "common.h"
#include "ifxGtm_PinMap.h"

#define GTM_ATOM0_PWM_DUTY_MAX     10000                 //GTM_ATOM0 PWM最大占空比  最大占空比越大占空比的步进值越小
#define GTM_ATOM1_PWM_DUTY_MAX     10000                 //GTM_ATOM1 PWM最大占空比  最大占空比越大占空比的步进值越小
#define GTM_ATOM2_PWM_DUTY_MAX     10000                 //GTM_ATOM2 PWM最大占空比  最大占空比越大占空比的步进值越小
#define GTM_ATOM3_PWM_DUTY_MAX     10000                 //GTM_ATOM3 PWM最大占空比  最大占空比越大占空比的步进值越小


//此枚举定义不允许用户修改
typedef enum //枚举串口引脚
{

	ATOM0_CH0_P00_0,  ATOM0_CH0_P02_0,  ATOM0_CH0_P02_8,  ATOM0_CH0_P14_5,  ATOM0_CH0_P21_2,  ATOM0_CH0_P22_1,  
	ATOM0_CH1_P00_1,  ATOM0_CH1_P00_2,  ATOM0_CH1_P02_1,  ATOM0_CH1_P14_4,  ATOM0_CH1_P21_3,  ATOM0_CH1_P22_0,  ATOM0_CH1_P33_9,
	ATOM0_CH2_P00_3,  ATOM0_CH2_P02_2,  ATOM0_CH2_P14_3,  ATOM0_CH2_P21_4,  ATOM0_CH2_P33_11,
	ATOM0_CH3_P00_4,  ATOM0_CH3_P02_3,  ATOM0_CH3_P14_2,  ATOM0_CH3_P21_5,  ATOM0_CH3_P22_2,
	ATOM0_CH4_P00_5,  ATOM0_CH4_P02_4,  ATOM0_CH4_P14_1,  ATOM0_CH4_P20_3,  ATOM0_CH4_P21_6,  ATOM0_CH4_P22_3,
	ATOM0_CH5_P00_6,  ATOM0_CH5_P02_5,  ATOM0_CH5_P21_7,  ATOM0_CH5_P32_4,
	ATOM0_CH6_P00_7,  ATOM0_CH6_P02_6,  ATOM0_CH6_P20_0,  ATOM0_CH6_P23_1,
	ATOM0_CH7_P00_8,  ATOM0_CH7_P02_7,  ATOM0_CH7_P20_8,

	ATOM1_CH0_P00_0,  ATOM1_CH0_P02_0,  ATOM1_CH0_P02_8,  ATOM1_CH0_P15_5,  ATOM1_CH0_P15_6,  ATOM1_CH0_P20_12,
	ATOM1_CH1_P00_1,  ATOM1_CH1_P00_2,  ATOM1_CH1_P02_1,  ATOM1_CH1_P10_1,  ATOM1_CH1_P14_6,  ATOM1_CH1_P15_7,  ATOM1_CH1_P15_8,  ATOM1_CH1_P20_13, ATOM1_CH1_P33_9,
	ATOM1_CH2_P00_3,  ATOM1_CH2_P02_2,  ATOM1_CH2_P10_2,  ATOM1_CH2_P10_5,  ATOM1_CH2_P14_0,  ATOM1_CH2_P20_14, ATOM1_CH2_P33_11,
	ATOM1_CH3_P00_4,  ATOM1_CH3_P02_3,  ATOM1_CH3_P10_3,  ATOM1_CH3_P10_6,  ATOM1_CH3_P15_0,
	ATOM1_CH4_P00_5,  ATOM1_CH4_P02_4,  ATOM1_CH4_P15_1,  ATOM1_CH4_P20_3,
	ATOM1_CH5_P00_6,  ATOM1_CH5_P02_5,  ATOM1_CH5_P15_2,  ATOM1_CH5_P20_9,  ATOM1_CH5_P32_4,
	ATOM1_CH6_P00_7,  ATOM1_CH6_P02_6,  ATOM1_CH6_P15_3,  ATOM1_CH6_P20_10, ATOM1_CH6_P23_1,
	ATOM1_CH7_P00_8,  ATOM1_CH7_P02_7,  ATOM1_CH7_P15_4,  ATOM1_CH7_P20_11,

	ATOM2_CH0_P00_9,  ATOM2_CH0_P13_3,  ATOM2_CH0_P33_4,  ATOM2_CH0_P33_10,
	ATOM2_CH1_P11_2,  ATOM2_CH1_P33_5,
	ATOM2_CH2_P11_3,  ATOM2_CH2_P33_6,
	ATOM2_CH3_P00_12, ATOM2_CH3_P11_6,  ATOM2_CH3_P33_7,
	ATOM2_CH4_P11_9,  ATOM2_CH4_P33_8,  ATOM2_CH4_P33_12,
	ATOM2_CH5_P11_10, ATOM2_CH5_P13_0,  ATOM2_CH5_P20_9,  ATOM2_CH5_P33_13,
	ATOM2_CH6_P11_11, ATOM2_CH6_P13_1,  ATOM2_CH6_P20_6,  ATOM2_CH6_P32_0,
	ATOM2_CH7_P11_12, ATOM2_CH7_P13_2,  ATOM2_CH7_P20_7,

	ATOM3_CH0_P00_9,  ATOM3_CH0_P13_3,  ATOM3_CH0_P33_4,  ATOM3_CH0_P33_10,
	ATOM3_CH1_P11_2,  ATOM3_CH1_P33_5,
	ATOM3_CH2_P11_3,  ATOM3_CH2_P33_6,
	ATOM3_CH3_P00_12, ATOM3_CH3_P11_6,  ATOM3_CH3_P33_7,
	ATOM3_CH4_P11_9,  ATOM3_CH4_P33_8,  ATOM3_CH4_P33_12,
	ATOM3_CH5_P11_10, ATOM3_CH5_P13_0,  ATOM3_CH5_P33_13,
	ATOM3_CH6_P11_11, ATOM3_CH6_P13_1,  ATOM3_CH6_P20_6,  ATOM3_CH6_P32_0,
	ATOM3_CH7_P11_12, ATOM3_CH7_P13_2,  ATOM3_CH7_P20_7,
}ATOM_PIN_enum;

void gtm_pwm_init(ATOM_PIN_enum pwmch, uint32 freq, uint32 duty);
void pwm_duty(ATOM_PIN_enum pwmch, uint32 duty);



#endif
