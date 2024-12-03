# Binary output of current temperature using LEDs and Arduino

- Using [Bonezegei_DHT11](https://github.com/bonezegei/Bonezegei_DHT11) library to read data from the DHT11 sensor

The leftmost LED is used to denote negative temperatures, the rightmost LED lights depending on the decimal places.
The six LEDs in the middle show the binary representation of the current temperature stripped of sign and decimal places.

![Picture of a breadboard setup with 8 LEDs as one bit for negative numbers, one bit for decimal places > 0.4 and 6 bits for the current temperature](https://github.com/Pfonks/binarytemp/blob/58c3b7f575c8f8e5c4b9fd28cb4cfb79ad119ae1/binarytemp.jpg)
