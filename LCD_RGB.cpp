#include <unistd.h>
#include <iostream>
#include <base/logging.h>
#include <base/macros.h>
#include <lcd/jhd1313m1.h>
using namespace std;
using namespace upm;


int main(int argc __unused, char **argv __unused) {
  // 0x62 RGB_ADDRESS, 0x3E LCD_ADDRESS
  Jhd1313m1 *lcd = new Jhd1313m1(0, 0x3E, 0x62);
  lcd->setCursor(0,0);
  lcd->write("Hello World!");
  lcd->setColor(0,0,255);
  sleep(2);
  printf("first\n");
  lcd->setCursor(0,0);
  lcd->write("How are you?");
  lcd->setColor(0,255,0);
  printf("second\n");
  sleep(2);
  lcd->setColor(255,0,0);
  lcd->setCursor(0,0);
  lcd->clear();
  lcd->write("This is a new test!");
  sleep(1);
  lcd->setCursor(1,4);
  lcd->write("**********");
  sleep(2);
  lcd->scroll(1);
  sleep(1);
  lcd->scroll(1);
  sleep(1);
  lcd->scroll(1);
  sleep(1);
  lcd->scroll(1);
  lcd->clear();
  lcd->setColor(255,255,0);
  sleep(1);
  lcd->setColor(255,255,255);
  sleep(1);
  lcd->setColor(0,255,255);
  sleep(1);
  lcd->setColor(0,0,0);
  sleep(1);
  lcd->setColor(255,0,255); 
  sleep(1);
  lcd->setColor(165,42,42);
  sleep(1);
  lcd->setColor(150,150,150);
  lcd->setCursor(1,4);
  lcd->write("Adios!");
  sleep(1);
  lcd->setCursor(0,6);
  lcd->write("Ciao!");
  sleep(1);
  lcd->clear();
  lcd->setCursor(0,6);
  lcd->write("Ciao!");
  lcd->setCursor(1,6),
  lcd->write("BYE!");

  printf("Sleeping for 5 seconds\n");
  sleep(5);
  delete lcd;
  return 0;
}

