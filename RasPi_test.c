#include <pigpio.h>
#include <unistd.h>

int main (void)
{
    int led_gpio = 21;
    gpioInitialise();
    gpioSetMode(led_gpio, PI_OUTPUT);

    while (1)
    {
        gpioWrite(led_gpio, 1);
        usleep(500000);
        gpioWrite(led_gpio, 0);
        usleep(500000);
    }
    return 0 ;
}
