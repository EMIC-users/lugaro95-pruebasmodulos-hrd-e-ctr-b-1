#ifndef _TRANSPORT_H_
#define _TRANSPORT_H_

#include <xc.h>
#include "stream.h"

#define		SENSOR_TIMEOUT	50
#define		FrameLf		'\n'
#define     BufferSize      1024
#define     FrameQty        16

// UART RX callback for frame detection (PIC24 UART V4 requires callback)
#define UART1_CALLBACK_RX
#define ISR_UART1_CALLBACK Transport_rx_callback
void Transport_rx_callback(char d);

extern uint16_t Transport_frame_count;

extern unsigned char fieldBusInDataBuffer[BufferSize];
extern unsigned char fieldBusOutDataBuffer[BufferSize];

extern uint16_t fieldBusInFrameBuffer[FrameQty];
extern uint16_t fieldBusOutFrameBuffer[FrameQty];

extern stream_t fieldBusInStream;
extern stream_t fieldBusOutStream;

void init_EMICfb (void);

void poll_fieldBusTransport(void);

extern uint8_t received_ID;
#ifdef CTR_Master
extern uint8_t My_ID;
extern uint8_t sensor_Qty;
extern uint32_t last_poll;
extern uint32_t last_new;
extern uint8_t sensor_polled;
#endif

#ifdef CRYS_Slave
extern uint8_t My_ID;
#endif

void empty_buffer(void);

#ifdef CTR_Master
void poll_sensors(void);
#endif

void send_fbTransport(void);

#endif

