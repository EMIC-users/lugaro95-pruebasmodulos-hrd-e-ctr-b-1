// Define microcontroller type (assuming PIC24 family based on the configuration)

// I2C configuration (using I2C2)

// LEDs
#define TRIS_Led1	                _TRISB7
#define PORT_Led1 	                _RB7
#define PIN_Led1 	                _RB7
#define LAT_Led1 	                _LATB7
#define ODC_Led1	                _ODB7
#define RPOUT_Led1		            RPOR3bits.RP7R
#define RPIN_Led1		            7
#define CN_Led1		                23
#define TRIS_Led2	                _TRISB6
#define PIN_Led2 	                _RB6
#define LAT_Led2 	                _LATB6
#define ODC_Led2	                _ODB6
#define RPOUT_Led2		            RPOR3bits.RP6R
#define RPIN_Led2		            6
#define CN_Led2		                24
#define TRIS_Led3	                _TRISB5
#define PIN_Led3 	                _RB5
#define Lat_Led3 	                _LATB5
#define ODC_Led3	                _ODB5
#define RPOUT_Led3		            RPOR2bits.RP5R
#define RPIN_Led3		            5
#define CN_Led3		                27

// RS485 communication
#define TRIS_RS485_TX	                _TRISB10
#define PORT_RS485_TX 	                _RB10
#define LAT_RS485_TX 	                _LATB10
#define ODC_RS485_TX	                _ODB10
#define PIN_RS485_TX 	                _RB10
#define RPOUT_RS485_TX	                RPOR5bits.RP10R
#define RPIN_RS485_TX	                10
#define CN_RS485_TX		                16
#define TRIS_RS485_RX	                _TRISB11
#define PORT_RS485_RX 	                _RB11
#define LAT_RS485_RX 	                _LATB11
#define ODC_RS485_RX	                _ODB11
#define PIN_RS485_RX 	                _RB11
#define RPOUT_RS485_RX		            RPOR5bits.RP11R
#define RPIN_RS485_RX		            11
#define CN_RS485_RX		                15
#define TRIS_RS485_RTS	                _TRISB15
#define PORT_RS485_RTS 	                _RB15
#define LAT_RS485_RTS 	                _LATB15
#define ODC_RS485_RTS	                _ODB15
#define PIN_RS485_RTS 	                _RB15
#define RPOUT_RS485_RTS	                RPOR7bits.RP15R
#define RPIN_RS485_RTS	                15
#define CN_RS485_RTS		                11
#define ADC_value_RS485_RTS              Buffer_entradas[9] 
#define HAL_SetAnalog_RS485_RTS()        {_PCFG9=0;\
                                        adc_addAnalogChannel(9);}
#define TRIS_RS485_CTS	                _TRISB14
#define PORT_RS485_CTS 	                _RB14
#define LAT_RS485_CTS 	                _LATB14
#define ODC_RS485_CTS	                _ODB14
#define PIN_RS485_CTS 	                _RB14
#define RPOUT_RS485_CTS	                RPOR7bits.RP14R
#define RPIN_RS485_CTS	                14
#define CN_RS485_CTS		                12
#define ADC_value_RS485_CTS              Buffer_entradas[10] 
#define HAL_SetAnalog_RS485_CTS()        {_PCFG10=0;\
                                        adc_addAnalogChannel(10);}


// Control master mode definition
#define CTR_Master

// Board name definition
