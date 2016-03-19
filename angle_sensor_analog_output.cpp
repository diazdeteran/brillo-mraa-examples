#include <unistd.h>
#include <base/logging.h>
#include <base/macros.h>
#include <mraa.h>

int main(int argc __unused, char **argv __unused) {
  // Initialize MRAA
  mraa_init();
  // Analog input pin
  mraa_aio_context aio0 = mraa_aio_init(0);
  // Analog output pin
  mraa_pwm_context pwmio3 = mraa_pwm_init(3);
  // Set the period to 10ms
  mraa_pwm_period_ms(pwmio3, 10);
  // Enable PWM output
  mraa_pwm_enable(pwmio3, 1);
  /*
  // Set led brightness to 0
  mraa_pwm_write(pwmio3, 0);
  // Increase led brightness gradually
  for(float i = 0.0; i < 1; i += 0.1){
    mraa_pwm_write(pwmio3, i);
    sleep(1);
  }
  */
  // Control led brightness with angle sensor
  while(true){
    int value = mraa_aio_read(aio0);
    float voltage = (5 * (float)value)/1023;
    // Brightness is 0 to 1.0
    float brightness = voltage/5;
    mraa_pwm_write(pwmio3, brightness);
    sleep(0.1);
  }
  // Disable pins and clean up
  mraa_pwm_enable(pwmio3, 0);
  mraa_pwm_close(pwmio3);
  mraa_aio_close(aio0);
  return MRAA_SUCCESS;
}
