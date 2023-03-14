import serial
import time

from tkinter import *


class Servo:

    # Init serial port communication, init UI

    def __init__(self):
        
        self.serial_port = '/dev/ttyUSB0'

        # Handle serial port communication errors - TODO: scan for available serial ports

        try:
            self.ser = serial.Serial(port=self.serial_port, baudrate=9600)
        except:
            print("Caouldn't open serial port")
        
        self.master = Tk()
        self.master.geometry('400x200')
        self.slider_shoulder = Scale(self.master, from_=0, to=300, length=500, command=self.update_shoulder)
        self.slider_shoulder.pack()
        self.slider_elbow = Scale(self.master, from_=0, to=300, length=500, command=self.update_elbow)
        self.slider_elbow.pack()
        self.slider_base = Scale(self.master, from_=0, to=300, length=500, orient=HORIZONTAL, command=self.update_base)
        self.slider_base.pack()
        self.slider_base.set(133)
        self.slider_jaw = Scale(self.master, from_=0, to=200, length=500, orient=HORIZONTAL, command=self.update_jaw)
        self.slider_jaw.pack()
        self.master.mainloop()

    def update_shoulder(self, event):
        self.ser.write(bytes('s', 'ascii'))
        self.ser.write(bytes(str(self.slider_shoulder.get()), 'ascii'))
        self.ser.write(bytes('\n', 'ascii'))
    
    def update_elbow(self, event):
        self.ser.write(bytes('l', 'ascii'))
        self.ser.write(bytes(str(self.slider_elbow.get()), 'ascii'))
        self.ser.write(bytes('\n', 'ascii'))

    def update_base(self, event):
        self.ser.write(bytes('b', 'ascii'))
        self.ser.write(bytes(str(self.slider_base.get()), 'ascii'))
        self.ser.write(bytes('\n', 'ascii'))

    def update_jaw(self, event):
        self.ser.write(bytes('j', 'ascii'))
        self.ser.write(bytes(str(self.slider_jaw.get()), 'ascii'))
        self.ser.write(bytes('\n', 'ascii'))

    
    # Simple move functions


    def move_shoulder(pos):
        self.ser.write(bytes('s', 'ascii'))
        self.ser.write(bytes(str(pos), 'ascii'))
        self.ser.write(bytes('\n', 'ascii'))

    def move_elbow(pos):
        self.ser.write(bytes('l', 'ascii'))
        self.ser.write(bytes(str(pos), 'ascii'))
        self.ser.write(bytes('\n', 'ascii'))

    def move_base(pos):
        self.ser.write(bytes('b', 'ascii'))
        self.ser.write(bytes(str(pos), 'ascii'))
        self.ser.write(bytes('\n', 'ascii'))

    def move_jaw(pos):
        self.ser.write(bytes('j', 'ascii'))
        self.ser.write(bytes(str(pos), 'ascii'))
        self.ser.write(bytes('\n', 'ascii'))

    # Make our arm do something

    def dance():
       while True:
            self.move_shoulder(50)
            time.sleep(0.5)
            self.move_shoulder(100)
            time.sleep(0.5)
            self.move_elbow(50)
            time.sleep(1)
            self.move_elbow(100)
            time.sleep(1)
    

serv = Servo()
serv.dance()
