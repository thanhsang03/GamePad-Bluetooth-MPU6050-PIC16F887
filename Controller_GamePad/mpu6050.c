// MPU6050 required Registers

#define W_DATA         0xD0    // 2 dia chi nay de write va read du lieu tu cam bien qua giao thuc i2c
#define R_DATA         0xD1    //
#define PWR_MGMT_1     0x6B    // bat tat cam bien va che do sleep mode
#define PWR_MGMT_2     0x6C    // dieu khien nguon cap cho cac khoi cam bien cu the
#define SMPRT_DIV      0x19    // dat gia tri chia mau, xac dinh tan so lay mau cho cam bien
#define CONFIG_R       0x1A    //  bo loc thong thap
#define GYRO_CONFIG    0x1B    // pham vi do va do nhay cua con quay hoi chuyen
#define ACCEL_CONFIG   0x1C    // pham vi do va do nhay cua gia toc ke
#define ACCEL_XOUT_H   0x3B    
#define ACCEL_XOUT_L   0x3C
#define ACCEL_YOUT_H   0x3D
#define ACCEL_YOUT_L   0x3E
#define ACCEL_ZOUT_H   0x3F
#define ACCEL_ZOUT_L   0x40
#define TEMP_OUT_H     0x41
#define TEMP_OUT_L     0x42
#define GYRO_XOUT_H    0x43
#define GYRO_XOUT_L    0x44
#define GYRO_YOUT_H    0x45
#define GYRO_YOUT_L    0x46
#define GYRO_ZOUT_H    0x47
#define GYRO_ZOUT_L    0x48

void mpu6050_write(int add, int data)
{
         i2c_start();
         i2c_write(W_DATA);
         i2c_write(add);
         i2c_write(data);
         i2c_stop();
 
}
      
int16 mpu6050_read(int add){
         int retval;
         i2c_start();
         i2c_write(W_DATA);
         i2c_write(add);
         i2c_start();
         i2c_write(R_DATA);
         retval=i2c_read(0); // // Ð?c d? li?u t? thanh ghi, g?i NACK d? k?t thúc
         i2c_stop();
         return retval;
}
 
void mpu6050_init(){
         mpu6050_write(PWR_MGMT_1,  0x80);
         delay_ms(100);
         mpu6050_write(PWR_MGMT_1,  0x00);   // bat gyro  o che do power mode
         delay_ms(100);
//!         mpu6050_write(CONFIG_R,    0x01);
//!         delay_ms(10);
//!         mpu6050_write(GYRO_CONFIG, 0x00);
}
