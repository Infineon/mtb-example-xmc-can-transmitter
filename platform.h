/******************************************************************************
* File Name:   platform.h
*
* Description: This file contains kit specific macro definitions.
*
******************************************************************************
*
* Copyright (c) 2021, Infineon Technologies AG
* All rights reserved.
*
* Boost Software License - Version 1.0 - August 17th, 2003
*
* Permission is hereby granted, free of charge, to any person or organization
* obtaining a copy of the software and accompanying documentation covered by
* this license (the "Software") to use, reproduce, display, distribute,
* execute, and transmit the Software, and to prepare derivative works of the
* Software, and to permit third-parties to whom the Software is furnished to
* do so, all subject to the following:
*
* The copyright notices in the Software and this entire statement, including
* the above license grant, this restriction and the following disclaimer,
* must be included in all copies of the Software, in whole or in part, and
* all derivative works of the Software, unless such copies or derivative
* works are solely in the form of machine-executable object code generated by
* a source language processor.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
* SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
* FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
* DEALINGS IN THE SOFTWARE.
*
*****************************************************************************/

#ifndef PLATFORM_H_
#define PLATFORM_H_

#include "cybsp.h"
#include "cy_utils.h"
#include "xmc_can.h"
#include "xmc_scu.h"

#if(UC_SERIES == XMC14)

#define CAN_CLOCK_SOURCE            XMC_CAN_CANCLKSRC_MCLK   /* CAN module clock source  - Peripheral Clock*/
#define CAN_FREQUENCY               48000000                 /* Frequency of the CAN module in Hz */
#define CAN_NODE                    CAN_NODE1
#define CAN_TX_PIN_MODE             XMC_GPIO_MODE_OUTPUT_PUSH_PULL | XMC_GPIO_MODE_OUTPUT_ALT9
#define XMC_CAN_NODE_RECEIVE_INPUT  XMC_CAN_NODE_RECEIVE_INPUT_RXDCC
#define NODE_NUMBER                 1

#endif

#if(UC_SERIES == XMC47)

#define CAN_CLOCK_SOURCE            XMC_CAN_CANCLKSRC_FPERI  /* CAN module clock source  - Peripheral Clock*/
#define CAN_FREQUENCY               144000000                /* Frequency of the CAN module in Hz */
#define CAN_NODE                    CAN_NODE1
#define CAN_TX_PIN_MODE             XMC_GPIO_MODE_OUTPUT_PUSH_PULL | XMC_GPIO_MODE_OUTPUT_ALT2
#define XMC_CAN_NODE_RECEIVE_INPUT  XMC_CAN_NODE_RECEIVE_INPUT_RXDCC
#define NODE_NUMBER                 1

#endif

#endif /* PLATFORM_H_ */
