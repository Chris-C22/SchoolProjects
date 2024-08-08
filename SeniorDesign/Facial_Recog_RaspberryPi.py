import RPi.GPIO as GPIO
import serial
import cv2
import numpy as np
import face_recognition as fr
import time

#9600 = baud rate
#timeout 1 makes it to when we read from serial a program will not be stuck forever if data incoming
#/dev/ttyUSB0 is the Arduino
ser = serial.Serial('/dev/ttyACM0', 9600)
ser.baudrate=9600


#GPIO.input(#port)
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

lock_button = 17
unlock_button = 27
GPIO.setup(lock_button, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
GPIO.setup(unlock_button, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)


image = fr.load_image_file("/home/stephvaca/Desktop/Senior_Design/myface.jpg")
image2 = fr.load_image_file("/home/stephvaca/Desktop/Senior_Design/marwin.jpg")

image_face_encoding = fr.face_encodings(image)[0]
image2_face_encoding = fr.face_encodings(image2)[0]

known_face_encodings = [image_face_encoding]
known_face_encodings2 = [image2_face_encoding]

known_face_names = ["Verified User"]


#initial lock state
status = 'F'
ser.write(bytes(status, 'utf-8'))
print("locked")

def camera_work():
    video_capture = cv2.VideoCapture(0)
    ret, frame = video_capture.read()
    rgb_frame = np.ascontiguousarray(frame[:, :, ::-1])
    fc_locations = fr.face_locations(rgb_frame)
    fc_encodings = fr.face_encodings(rgb_frame, fc_locations)

    for (top, right, bottom, left), face_encoding in zip(fc_locations, fc_encodings):
        matches = fr.compare_faces(known_face_encodings, face_encoding)
        matches2 = fr.compare_faces(known_face_encodings2, face_encoding)

        name = "unknown"
                    
        fc_distances = fr.face_distance(known_face_encodings, face_encoding)
        fc_distances2 = fr.face_distance(known_face_encodings2, face_encoding)


        match_index = np.argmin(fc_distances)
        match_index2 = np.argmin(fc_distances2)

        if (matches[match_index]) or (matches2[match_index2]):
            name = known_face_names[match_index]

    video_capture.release()
    cv2.destroyAllWindows()
    return name
    

while (1):
    ser.write(bytes(status, 'utf-8'))
    #check to see if umlock button is pressed
    if (GPIO.input(unlock_button) == GPIO.HIGH) & (status == 'F'):
        name = camera_work()
                
            if (name == "Verified User"):
                status = 'T'
                ser.write(bytes(status, 'utf-8'))

            if name == "unknown":
                status = 'F'
                ser.write(bytes(status, 'utf-8'))

           
    #check to see if lock button is pressed
    if (GPIO.input(lock_button) == GPIO.HIGH) & (status == 'T'):
        status = 'F'
        ser.write(bytes(status, 'utf-8'))
