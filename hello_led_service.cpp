#include <unistd.h>
#include <base/logging.h>
#include <base/macros.h>
#include <mraa.h>

int main(int argc __unused, char **argv __unused) {
  mraa_init();
  mraa_gpio_context gpio2 = mraa_gpio_init(2);
  mraa_gpio_context gpio3 = mraa_gpio_init(3);
  mraa_gpio_dir(gpio2, MRAA_GPIO_OUT);
  mraa_gpio_dir(gpio3, MRAA_GPIO_IN);
  int status = 0;
  int new_touch = 1;
  while(true){
    if(mraa_gpio_read(gpio3) && new_touch){
      new_touch = 0;
      if(status){
        mraa_gpio_write(gpio2, 0);
        status = 0;
      }
      else{
        mraa_gpio_write(gpio2, 1);
        status = 1;
      }
    }
    else if(!mraa_gpio_read(gpio3)){
      new_touch = 1;
    }
  }
  LOG(INFO) << "End of program";
  return MRAA_SUCCESS;
}
