import cv2
import numpy as np

# Start webcam
cap = cv2.VideoCapture(2, cv2.CAP_V4L2)

if not cap.isOpened():
    print("Error: Could not open webcam.")
    exit()

while True:
    # Read frame from webcam
    ret, frame = cap.read()

    if not ret:
        print("Error: Could not read frame.")
        break

    # Convert BGR image to HSV
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # Lower and upper ranges for red
    lower_red1 = np.array([0, 120, 70])
    upper_red1 = np.array([10, 255, 255])

    lower_red2 = np.array([170, 120, 70])
    upper_red2 = np.array([180, 255, 255])

    # Create masks for red
    mask1 = cv2.inRange(hsv, lower_red1, upper_red1)
    mask2 = cv2.inRange(hsv, lower_red2, upper_red2)

    # Combine both red masks
    mask = mask1 + mask2

    # Remove small noise
    kernel = np.ones((5, 5), np.uint8)
    mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel)
    mask = cv2.morphologyEx(mask, cv2.MORPH_DILATE, kernel)

    # Find contours
    contours, _ = cv2.findContours(
        mask,
        cv2.RETR_EXTERNAL,
        cv2.CHAIN_APPROX_SIMPLE
    )

    # Find the largest red object
    if contours:
        largest_contour = max(contours, key=cv2.contourArea)
        area = cv2.contourArea(largest_contour)

        # Ignore very small objects/noise
        if area > 500:
            x, y, w, h = cv2.boundingRect(largest_contour)

            # Draw bounding box
            cv2.rectangle(
                frame,
                (x, y),
                (x + w, y + h),
                (0, 255, 0),
                2
            )

            # Calculate center
            center_x = x + w // 2
            center_y = y + h // 2

            # Draw center point
            cv2.circle(
                frame,
                (center_x, center_y),
                5,
                (255, 0, 0),
                -1
            )

            # Display information
            cv2.putText(
                frame,
                "Red Object Detected",
                (x, y - 30),
                cv2.FONT_HERSHEY_SIMPLEX,
                0.7,
                (0, 255, 0),
                2
            )

            cv2.putText(
                frame,
                f"Center: ({center_x}, {center_y})",
                (x, y - 5),
                cv2.FONT_HERSHEY_SIMPLEX,
                0.6,
                (255, 255, 255),
                2
            )

    # Display webcam feed
    cv2.imshow("Red Object Detector", frame)

    # Display red mask
    cv2.imshow("Red Mask", mask)

    # Press Q to quit
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release webcam
cap.release()
cv2.destroyAllWindows()
