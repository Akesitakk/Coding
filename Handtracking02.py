import cv2
import mediapipe as mp
import time
import serial
ser=serial.Serial('/dev/cu.usbmodem142101',9600)
cap = cv2.VideoCapture(0)
mpHands = mp.solutions.hands
hands = mpHands.Hands()
mpDraw = mp.solutions.drawing_utils

ptime = 0
ctime =0

finger_tips = [8,12,16,20]
thumb_tips = 4

while True:
    success, img = cap.read()
    img = cv2.flip(img,1)
    imgRGB = cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
    results = hands.process(imgRGB)
    h,w,c = img.shape

    #print(results.multi_hand_landmarks)
    if results.multi_hand_landmarks:
        for handLms in results.multi_hand_landmarks:
            lm_list = []
            for id,lm in enumerate(handLms.landmark):
                lm_list.append(lm)
            finger_fold_status=[]
            for tip in finger_tips:
                x, y = int(lm_list[tip].x*w), int (lm_list[tip].y*h)
                print(id, ":" , x,y)
                cv2.circle(img,(x,y),15,(255,255,0),cv2.FILLED)

                if lm_list[tip].y> lm_list[tip -2].y:
                    cv2.circle(img,(x,y),15,(255,255,255),cv2.FILLED)
                    finger_fold_status.append(True)
                else:
                    finger_fold_status.append(False)
            print(finger_fold_status)
            if lm_list[1].x > lm_list[17].x :
             if all(finger_fold_status):
                if (lm_list[thumb_tips].x < lm_list[thumb_tips-2].x):
                    print("\033c", end="") 
                    print("0") 
                    ser.write(b'0') 
                    print(results.multi_handedness)

                if (lm_list[thumb_tips].x > lm_list[thumb_tips-2].x):
                    print("\033c", end="") 
                    print("6") 
                    ser.write(b'6')
                    print(results.multi_handedness)
 
             if (finger_fold_status[0]==False )& (finger_fold_status[1]==True)&( finger_fold_status[2]==True)&( finger_fold_status[3]==True):
                if (lm_list[thumb_tips].x > lm_list[thumb_tips-2].x):
                        print("\033c", end="") 
                        print("7")    
                        ser.write(b'7')
                        print(results.multi_handedness)
 
                if (lm_list[thumb_tips].x < lm_list[thumb_tips-2].x):
                        print("\033c", end="")
                        print("1")
                        ser.write(b'1')
                        print(results.multi_handedness)
 
       
             if (finger_fold_status[0]==False )& (finger_fold_status[1]==False)&( finger_fold_status[2]==True)&( finger_fold_status[3]==True):
                if (lm_list[thumb_tips].x > lm_list[thumb_tips-2].x):
                        print("\033c", end="") 
                        print("8")
                        ser.write(b'8')
                        print(results.multi_handedness)
     
                if (lm_list[thumb_tips].x < lm_list[thumb_tips-2].x):
                        print("\033c", end="") 
                        print("2")
                        ser.write(b'2')
                        print(results.multi_handedness)
   
             if (finger_fold_status[0]==False )& (finger_fold_status[1]==False)&( finger_fold_status[2]==False)&( finger_fold_status[3]==True):
                    print("\033c", end="") 
                    print("3")
                    ser.write(b'3') 
                    print(results.multi_handedness)
    
             if (finger_fold_status[0]==False )& (finger_fold_status[1]==False)&( finger_fold_status[2]==False)&( finger_fold_status[3]==False):
                    if (lm_list[thumb_tips].x > lm_list[thumb_tips-2].x):
                        print("\033c", end="") 
                        print("5")
                        ser.write(b'5')
                        print(results.multi_handedness)
     
                    if (lm_list[thumb_tips].x < lm_list[thumb_tips-2].x):
                        print("\033c", end="") 
                        print("4")
                        print(results.multi_handedness)
                        ser.write(b'4')   
            if lm_list[1].x < lm_list[17].x : 
              cv2.putText(img,"Pls use another hands",(10,70),cv2.FONT_HERSHEY_PLAIN,3,(255,0,255),4)
            time.sleep(1)
        
           



        mpDraw.draw_landmarks(img,handLms,mpHands.HAND_CONNECTIONS)
            
    ctime=time.time()
    fps = 1/(ctime-ptime)
    ptime = ctime
    cv2.putText(img,str(int(fps)),(10,70),cv2.FONT_HERSHEY_PLAIN,3,(255,0,255),1)
    
    

    cv2.imshow("Image",img)
    cv2.waitKey(1)