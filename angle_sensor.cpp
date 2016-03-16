#include <unistd.h>
#include <base/logging.h>
#include <base/macros.h>
#include <mraa.h>

int main(int argc __unused, char **argv __unused) {

  mraa_init();
  
  mraa_gpio_context gpio2 = mraa_gpio_init(2);
  mraa_gpio_dir(gpio2, MRAA_GPIO_OUT);
  
  mraa_aio_context aio0 = mraa_aio_init(0);

  while(true){
    int value = mraa_aio_read(aio0);
    float voltage = (5 * (float)value)/1023;
    int angle = (300 * voltage)/5;
    LOG(INFO) << "Value: " << value;
    LOG(INFO) << "Voltage: " << voltage;
    LOG(INFO) << "Angle: " << angle;
    sleep(5);
  }
  mraa_aio_close(aio0);
  return MRAA_SUCCESS;
}
