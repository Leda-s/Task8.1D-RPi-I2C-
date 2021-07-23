import smbus
import time

bus = smbus.SMBus(1)

address = 0x23

bus.write_byte(address, 0x01)

b = bus.write_byte(address, 0x10)


try:
    
    while 1:

        time.sleep(1)

        data = bus.read_i2c__block_data(address, 2)
        luminance = (data[0] * 256 + data[1]) / 2

        #Print the light value
        print()
        print(luminance)

        #Print some information to the user based on the data
        if luminance < 30:
            print("too dark")
        elif luminance >= 30 and luminance < 80:
            print("dark")
        elif luminance >= 80 and luminance < 100:
            print("medium")
        elif luminance >= 100 and luminance < 125:
            print("bright")
        elif luminance >= 125 and luminance < 200:
            print("too bright")



except KeyboardInterrupt:
    print("Keyboard interupt")





