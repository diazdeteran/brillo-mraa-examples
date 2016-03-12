#include <unistd.h>
#include <math.h>
#include <base/logging.h>
#include <base/macros.h>
#include <mraa.h>

int main(int argc __unused, char **argv __unused) {
  const int B = 4275; // B value of the thermistor
  const int R0 = 100000; // R0 = 100k

  mraa_init();
  mraa_aio_context aio0 = mraa_aio_init(0);

  while(true){
    int value = mraa_aio_read(aio0);
    float R = 1023.0/((float)value) - 1.0;
    R = 100000.0 * R;
    // Convert to temperature following thermiistor datasheet
    float temperature = 1.0/(log(R/100000.0)/B+1/298.15)-273.15;
    LOG(INFO) << temperature;
    sleep(10);
  }
  mraa_aio_close(aio0);
  return MRAA_SUCCESS;
}
