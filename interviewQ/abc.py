import streamlit as st
import numpy as np
import cv2
import tensorflow as tf
from PIL import Image

# Load the pre-trained model
model = tf.keras.models.load_model("brain_tumor_detection_model.h5")
categories = ["glioma", "meningioma", "notumor", "pituitary"]

# Function to preprocess the image
def preprocess_image(image):
    image_size = (150, 150)  # Must match the training image size
    image = image.resize(image_size)
    image_array = np.array(image) / 255.0  # Normalize
    image_array = np.expand_dims(image_array, axis=0)  # Add batch dimension
    return image_array

# Streamlit application
st.title("Brain Tumor Detection")
st.write("Upload an MRI image to detect the type of brain tumor.")

# File uploader
uploaded_file = st.file_uploader("Choose an image...", type=["jpg", "jpeg", "png"])

if uploaded_file is not None:
    # Display the uploaded image
    image = Image.open(uploaded_file)
    st.image(image, caption="Uploaded Image", use_column_width=True)

    # Preprocess and predict
    if st.button("Predict"):
        processed_image = preprocess_image(image)
        prediction = model.predict(processed_image)
        predicted_class = categories[np.argmax(prediction)]
        confidence = np.max(prediction) * 100

        # Display prediction
        st.write(f"**Predicted Class:** {predicted_class}")
        st.write(f"**Confidence:** {confidence:.2f}%")
