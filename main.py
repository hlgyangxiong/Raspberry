import sys
import time  
import Adafruit_DHT
import RPi.GPIO as GPIO 

# Parse command line parameters.
sensor_args = { '11': Adafruit_DHT.DHT11,
                '22': Adafruit_DHT.DHT22,
                '2302': Adafruit_DHT.AM2302 }
sensor = sensor_args['11']
DHT11pin = 4

def GetTH():
    time.sleep(1)
    humidity, temperature = Adafruit_DHT.read_retry(sensor, DHT11pin)
    if humidity is not None and temperature is not None:
        print('Temp={0:0.1f}*  Humidity={1:0.1f}%'.format(temperature, humidity))
    else:
        print('Failed to get reading. Try again!')
        sys.exit(1)
    time.sleep(1)
    
    
def init():  
    GPIO.setwarnings(False)  
    GPIO.setmode(GPIO.BOARD)  
    GPIO.setup(12, GPIO.IN)  
    GPIO.setup(11,GPIO.OUT)  
    pass  
    
def beep():  
        for i in range(1,6):  
            GPIO.output(11, GPIO.LOW) 
            time.sleep(0.5)  
            GPIO.output(11, GPIO.HIGH)  
            time.sleep(0.5)  
            print "the Buzzer will make sound"  
 
def detct():  
    #for i in range(1, 31):  
    if GPIO.input(12) == True:  
        print time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))+"  Someone is closing!"  
        beep()  
    else:  
        GPIO.output(11, GPIO.HIGH)  
        print time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))+"  Noanybody!"  
    time.sleep(6) 
        
init()         
        
while True:
    GetTH()
#    time.sleep(2)
    detct()
