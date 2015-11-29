#ifndef HMC5883L_H
#define HMC5883L_H
#define MAG_ADDRESS            0x1E
#define ACC_ADDRESS            0x1E


/*=========================================================================
    I2C ADDRESS/BITS
    -----------------------------------------------------------------------*/
    #define HMC5883_ADDRESS_MAG            (0x3C >> 1)         // 0011110x
/*=========================================================================*/

/*=========================================================================
    REGISTERS
    -----------------------------------------------------------------------*/
#define HMC5883_REGISTER_MAG_CRA_REG_M             = 0x00,
#define HMC5883_REGISTER_MAG_CRB_REG_M             = 0x01,
#define HMC5883_REGISTER_MAG_MR_REG_M              = 0x02,
#define HMC5883_REGISTER_MAG_OUT_X_H_M             = 0x03,
#define HMC5883_REGISTER_MAG_OUT_X_L_M             = 0x04,
#define HMC5883_REGISTER_MAG_OUT_Z_H_M             = 0x05,
#define HMC5883_REGISTER_MAG_OUT_Z_L_M             = 0x06,
#define HMC5883_REGISTER_MAG_OUT_Y_H_M             = 0x07,
#define HMC5883_REGISTER_MAG_OUT_Y_L_M             = 0x08,
#define HMC5883_REGISTER_MAG_SR_REG_Mg             = 0x09,
#define HMC5883_REGISTER_MAG_IRA_REG_M             = 0x0A,
#define HMC5883_REGISTER_MAG_IRB_REG_M             = 0x0B,
#define HMC5883_REGISTER_MAG_IRC_REG_M             = 0x0C,
#define HMC5883_REGISTER_MAG_TEMP_OUT_H_M          = 0x31,
#define HMC5883_REGISTER_MAG_TEMP_OUT_L_M          = 0x32

/*=========================================================================*/

/*=========================================================================
    MAGNETOMETER GAIN SETTINGS
    -----------------------------------------------------------------------*/
#define HMC5883_MAGGAIN_1_3                        = 0x20,  // +/- 1.3
#define HMC5883_MAGGAIN_1_9                        = 0x40,  // +/- 1.9
#define HMC5883_MAGGAIN_2_5                        = 0x60,  // +/- 2.5
#define HMC5883_MAGGAIN_4_0                        = 0x80,  // +/- 4.0
#define HMC5883_MAGGAIN_4_7                        = 0xA0,  // +/- 4.7
#define HMC5883_MAGGAIN_5_6                        = 0xC0,  // +/- 5.6
#define HMC5883_MAGGAIN_8_1                        = 0xE0   // +/- 8.1
/*=========================================================================*/

/*=========================================================================
    INTERNAL MAGNETOMETER DATA TYPE
    -----------------------------------------------------------------------*/
typedef struct hmc5883MagData_s
{
    float x;
    float y;
    float z;
  float orientation;
} hmc5883MagData;
/*=========================================================================*/

/*=========================================================================
    CHIP ID
    -----------------------------------------------------------------------*/
#define HMC5883_ID                     (0b11010100)
/*=========================================================================*/

#endif