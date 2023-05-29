import cv2
import tictactoe
import serial
import time

cap = cv2.VideoCapture(4)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)
#cap.set(cv2.CAP_PROP_AUTO_WB, 0.0) # Disable automatic white balance
cap.set(cv2.CAP_PROP_WB_TEMPERATURE, 4200) # Set manual white balance temperature to 4200K

coord_0 = (550, 200)
coord_1 = (550, 350)
coord_2 = (550, 500)

winner = None
playerTurn = True

board_state = [None, None, None, None, None, None, None, None, None]
prev_board_state = board_state

recorded_moves = [11, 12, 13]

serial_port = '/dev/ttyUSB0'
ser = serial.Serial(port=serial_port, baudrate=9600, timeout=3)

def place_ball(pos):
     ser.write(bytes('r', 'ascii'))
  
     time.sleep(1)

     ser.write(bytes('g', 'ascii'))
    
     time.sleep(0.5)

     ser.write(bytes('u', 'ascii'))
     
     time.sleep(0.5)

     ser.write(bytes(pos, 'ascii'))
    
     time.sleep(2)

     ser.write(bytes('u', 'ascii'))
    
     ser.write(bytes('r', 'ascii'))
   
    
while True:

    _, frame = cap.read()
    hsv_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # Prima linie
        
    pixel_x0 = hsv_frame[200, 400]
    pixel_x1 = hsv_frame[200, 550]
    pixel_x2 = hsv_frame[200, 700]

    # A doua linie

    pixel_x3 = hsv_frame[350, 400]
    pixel_x4 = hsv_frame[350, 550]
    pixel_x5 = hsv_frame[350, 700]

    # A treia linie

    pixel_x6 = hsv_frame[500, 400]
    pixel_x7 = hsv_frame[500, 550]
    pixel_x8 = hsv_frame[500, 700]

    hue_value0 = pixel_x0[0]
    hue_value1 = pixel_x1[0]
    hue_value2 = pixel_x2[0]
    hue_value3 = pixel_x3[0]
    hue_value4 = pixel_x4[0]
    hue_value5 = pixel_x5[0]
    hue_value6 = pixel_x6[0]
    hue_value7 = pixel_x7[0]
    hue_value8 = pixel_x8[0]

    cv2.circle(frame, (700, 200), 5, (255, 0, 0), 3)
    cv2.circle(frame, (700, 350), 5, (255, 0, 0), 3)
    cv2.circle(frame, (700, 500), 5, (255, 0, 0), 3)
    cv2.circle(frame, (550, 200), 5, (255, 0, 0), 3)
    cv2.circle(frame, (550, 350), 5, (255, 0, 0), 3)
    cv2.circle(frame, (550, 500), 5, (255, 0, 0), 3)
    cv2.circle(frame, (400, 200), 5, (255, 0, 0), 3)
    cv2.circle(frame, (400, 350), 5, (255, 0, 0), 3)
    cv2.circle(frame, (400, 500), 5, (255, 0, 0), 3)

    if hue_value0 < 26 and hue_value0 > 5:
        cv2.putText(frame, 'X', (410, 200), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2, cv2.LINE_AA)

    if hue_value1 < 26 and hue_value1 > 5:
        cv2.putText(frame, 'X', (560, 200), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2, cv2.LINE_AA)
        
    if hue_value2 < 26 and hue_value2 > 5:
        cv2.putText(frame, 'X', (710, 200), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2, cv2.LINE_AA)
        
    if hue_value3 < 26 and hue_value3 > 5:
        cv2.putText(frame, 'X', (370, 350), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2, cv2.LINE_AA)

    if hue_value4 < 26 and hue_value4 > 5:
        cv2.putText(frame, 'X', (560, 350), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2, cv2.LINE_AA)
        
    if hue_value5 < 26 and hue_value5 > 5:
        cv2.putText(frame, 'X', (710, 350), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2, cv2.LINE_AA)
        
    if hue_value6 < 26 and hue_value6 > 6:
        cv2.putText(frame, 'X', (410, 500), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2, cv2.LINE_AA)
        
    if hue_value7 < 26 and hue_value7 > 6:
        cv2.putText(frame, 'X', (560, 500), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2, cv2.LINE_AA)
        
    if hue_value8 < 26 and hue_value8 > 6:
        cv2.putText(frame, 'X', (710, 500), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2, cv2.LINE_AA)

    cv2.imshow("Frame", frame)

    key = cv2.waitKey(1)


    if(key == 27):

        

        if hue_value0 < 26 and hue_value0 > 5:
            board_state[0] = 'X'

        if hue_value1 < 26 and hue_value1 > 5:
            board_state[1] = 'X'

        if hue_value2 < 26 and hue_value2 > 5:
            board_state[2] = 'X'

        if hue_value3 < 26 and hue_value3 > 5:
            board_state[3] = 'X'
            
        if hue_value4 < 26 and hue_value4 > 5:
            board_state[4] = 'X'
        
        if hue_value5 < 26 and hue_value5 > 5:
            board_state[5] = 'X'

        if hue_value6 < 26 and hue_value6 > 5:
            board_state[6] = 'X'

        if hue_value7 < 26 and hue_value7 > 5:
            board_state[7] = 'X'
            
        if hue_value8 < 26 and hue_value8 > 5:
            board_state[8] = 'X'
            
       
        playerTurn = False
    

        result = tictactoe.play_best_move(tuple(board_state), 'O')

        if winner is None:

            board_state = list(result[0])
            winner = result[1]

            print(tictactoe.get_printable_board(tuple(board_state)))
            print("\n")

            ser.write(bytes('h', 'ascii'))

            for i in range(9):
                if board_state[i] == 'O':
                    if i not in recorded_moves:
                        place_ball(str(i))
                        recorded_moves.append(i)
            
            ser.write(bytes('l', 'ascii'))

        else:
            
            if winner == 'T':
                print("\nEgalitate!")
            elif winner == 'X':
                print("\nA castigat X!")
            else:
                print("\nA castigat 0!")


cap.release()
