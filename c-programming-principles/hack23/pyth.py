

import tensorflow


from PIL import Image, ImageOps
import numpy as np

import cv2

# im = cv2.imread(r'C:/Users/Ritvik Prakash/Downloads/dataset-resized/dataset-resized/plastic/plastic8.jpg')
# # Use this to if you read png images
# im = cv2.cvtColor(im,cv2.COLOR_BGRA2RGB)
# # Use this to if you read jpg image
# # im = cv2.cvtColor(im,cv2.COLOR_BGR2RGB)
# print(im)




import cv2



# resizing the image to be at least 224x224 and then cropping from the center
size = (224, 224)

x_train=[]
y_train=[]


#PLASTICS
for i in range(1,483):

    image = Image.open(f"C:/Users/Ritvik Prakash/Downloads/dataset-resized/dataset-resized/plastic/plastic{i}.jpg").convert("RGB")

    image = ImageOps.fit(image, size, Image.Resampling.LANCZOS)

    image_array = np.asarray(image)
    x_train.append(image_array)

print(x_train)

#TRASH
for i in range(1,137):
    image = Image.open(f"C:/Users/Ritvik Prakash/Downloads/dataset-resized/dataset-resized/trash/trash{i}.jpg").convert("RGB")

    image = ImageOps.fit(image, size, Image.Resampling.LANCZOS)

    image_array = np.asarray(image)
    x_train.append(image_array)

print(x_train)

#PAPER
for i in range(1,595):
    image = Image.open(f"C:/Users/Ritvik Prakash/Downloads/dataset-resized/dataset-resized/paper/paper{i}.jpg").convert("RGB")

    image = ImageOps.fit(image, size, Image.Resampling.LANCZOS)

    image_array = np.asarray(image)
    x_train.append(image_array)

print(x_train)


#METAL
for i in range(1,411):
    image = Image.open(f"C:/Users/Ritvik Prakash/Downloads/dataset-resized/dataset-resized/metal/metal{i}.jpg").convert("RGB")

    image = ImageOps.fit(image, size, Image.Resampling.LANCZOS)

    image_array = np.asarray(image)
    x_train.append(image_array)

print(x_train)


#GLASS
for i in range(1,502):
    image = Image.open(f"C:/Users/Ritvik Prakash/Downloads/dataset-resized/dataset-resized/glass/glass{i}.jpg").convert("RGB")

    image = ImageOps.fit(image, size, Image.Resampling.LANCZOS)

    image_array = np.asarray(image)
    x_train.append(image_array)

print(x_train)


#CARDBOARD
for i in range(1,404):
    image = Image.open(f"C:/Users/Ritvik Prakash/Downloads/dataset-resized/dataset-resized/cardboard/cardboard{i}.jpg").convert("RGB")

    image = ImageOps.fit(image, size, Image.Resampling.LANCZOS)

    image_array = np.asarray(image)
    x_train.append(image_array)

print(x_train)

# for i in range(1,137):
#     image = Image.open(f"C:/Users/Ritvik Prakash/Downloads/dataset-resized/dataset-resized/trash/trash{i}.jpg").convert("RGB")

#     image = ImageOps.fit(image, size, Image.Resampling.LANCZOS)

#     image_array = np.asarray(image)
#     x_train.append(image_array)






# # Initialize the default camera (usually the built-in webcam)
# cap = cv2.VideoCapture(0)  # 0 represents the default camera, you can change it if you have multiple cameras

# # Check if the camera was opened successfully
# if not cap.isOpened():
#     print("Error: Could not open the camera.")
#     exit()

# while True:
#     # Capture a frame from the camera
#     ret, frame = cap.read()

#     # Check if the frame was captured successfully
#     if not ret:
#         print("Error: Could not read a frame.")
#         break

#     # Display the frame in a window
#     cv2.imshow("Camera Feed", frame)

#     # Break the loop if the user presses the 'q' key (or any other key you choose)
#     if cv2.waitKey(1) & 0xFF == ord('q'):
#         break

# # Release the camera and close the window
# cap.release()
# cv2.destroyAllWindows()