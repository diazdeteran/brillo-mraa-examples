#include <unistd.h>
#include <iostream>
#include <base/logging.h>
#include <base/macros.h>
#include <servo/es08a.h>
using namespace std;
using namespace upm;

int main(int argc __unused, char **argv __unused) {
  ES08A *servo = new ES08A(3);    

  // Sets the shaft to 180, then to 90, then to 0,
  // then back to 90, and finally back to 180,
  // pausing for a second in between each angle
  servo->setAngle (180);
  cout << "Set angle to 180" << endl;
  sleep(1);
  servo->setAngle (90);
  cout << "Set angle to 90" << endl;
  sleep(1);
  servo->setAngle (0);
  cout << "Set angle to 0" << endl;
  sleep(1);
  servo->setAngle (90);
  cout << "Set angle to 90" << endl;
  sleep(1);
  servo->setAngle (180);
  cout << "Set angle to 180" << endl;

  cout << "exiting application" << endl;

  delete servo;
  return 0;
}
