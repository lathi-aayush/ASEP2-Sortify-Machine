# Sortify

**IoT-enabled deep learning add-on for dry waste classification with incentivization**

Sortify is a smart, retrofittable extension that converts regular dustbins into AI-assisted sorting units. It combines computer vision, embedded hardware, and a mobile experience to classify dry waste as recyclable or non-recyclable, route it into the correct compartment, and reward responsible disposal behavior.

## Project Overview

Sortify is designed for campuses and public institutions where dry waste is often mixed due to lack of real-time segregation systems. Instead of replacing existing bins, Sortify adds a detachable hardware module on top of them, making smart waste sorting more affordable and scalable.

### Core Objectives

- Build a detachable IoT add-on compatible with existing dustbins.
- Classify dry waste into recyclable and non-recyclable categories using a CNN model.
- Add user accountability through QR-based logging and user identity tracking.
- Drive participation through gamification, scoreboards, and monthly rewards.

## Ideology Behind Sortify

Sortify is built on the idea that sustainability works best when technology and behavior change are designed together.

- **Infrastructure-first practicality:** reuse existing bins to reduce deployment cost and friction.
- **AI for public good:** automate repetitive segregation effort and improve recycling efficiency.
- **Behavioral design:** make eco-friendly actions visible, trackable, and rewarding.
- **Data-driven sustainability:** capture usage data for better waste planning and operational decisions.

## Impact

Sortify targets both environmental and social impact in institutional settings:

- Improves source-level segregation of dry waste.
- Reduces contamination of recyclable streams.
- Encourages consistent user participation through incentives.
- Supports Swachh Bharat goals with measurable campus-level outcomes.
- Creates a replicable framework for smart waste systems in colleges and similar communities.

## System Workflow

1. User places waste item on/in the Sortify interface.
2. Camera captures image.
3. Backend model classifies item (`recyclable` / `non-recyclable`).
4. Arduino + servo mechanism opens corresponding flap.
5. Result is shown to the user.
6. QR-based action logging updates contribution records.
7. User score and leaderboard are updated for incentives.

## 3D Model and Physical Prototype

Sortify uses a two-part mechanical design:

- **Primary body:** houses electronics (camera module, controller wiring, mounts).
- **Flap mechanism:** servo-driven sorting interface directing waste by class.

The design was created with parametric 3D modeling to support multiple dustbin sizes and improve manufacturability, assembly, and maintenance.

### 3D / Prototype Images

#### Sortify Add-on Model
![Sortify 3D Model](ASEP%202%20photos%20and%20video%20of%20sotify%20model/finalfinal.png)
[Direct link to image](./ASEP%202%20photos%20and%20video%20of%20sotify%20model/finalfinal.png)

#### Prototype Views
![Prototype View 1](ASEP%202%20photos%20and%20video%20of%20sotify%20model/WhatsApp%20Image%202025-06-16%20at%2010.30.15_2b0ff6da.jpg)
[Direct link to image 1](./ASEP%202%20photos%20and%20video%20of%20sotify%20model/WhatsApp%20Image%202025-06-16%20at%2010.30.15_2b0ff6da.jpg)
![Prototype View 2](ASEP%202%20photos%20and%20video%20of%20sotify%20model/WhatsApp%20Image%202025-06-16%20at%2010.30.16_40792147.jpg)
[Direct link to image 2](./ASEP%202%20photos%20and%20video%20of%20sotify%20model/WhatsApp%20Image%202025-06-16%20at%2010.30.16_40792147.jpg)
![Prototype View 3](ASEP%202%20photos%20and%20video%20of%20sotify%20model/WhatsApp%20Image%202025-06-16%20at%2010.30.20_3851bbe5.jpg)
[Direct link to image 3](./ASEP%202%20photos%20and%20video%20of%20sotify%20model/WhatsApp%20Image%202025-06-16%20at%2010.30.20_3851bbe5.jpg)

## Performance Highlights

Based on current project documentation:

- **Recyclable classification accuracy:** 88%
- **Non-recyclable classification accuracy:** 84%
- **Execution time (proposed setup):** ~3.2s to ~3.56s (vs ~6.04s to ~6.56s baseline in report table)

## Tech Stack

### AI / ML
- Python
- TensorFlow + Keras
- OpenCV

### Embedded / IoT
- ESP32-CAM
- Arduino Uno
- Servo motors
- OLED/LED display interface
- Camera + supporting circuit components

### Application / Software
- Android app (Jetpack Compose, MVVM architecture)
- Firebase Realtime Database
- Firebase Authentication
- Room Database (offline sync)
- QR scanning with ZXing

### Web / Backend Components
- Node.js
- JavaScript
- SQL (for structured data handling, per project documentation)

## Methodology Snapshot

- Data collection and labeling of dry waste images (recyclable vs non-recyclable).
- Image preprocessing (augmentation, resize to fixed dimensions, normalization).
- CNN training with regularization and evaluation (accuracy, precision, recall, confusion matrix).
- Hardware integration with camera capture, model response, and servo actuation.
- User logging, scoring, dashboard updates, and incentive workflow.

## Why This Matters

Sortify demonstrates that smart waste management does not have to start with expensive replacement infrastructure. A retrofit + AI + engagement model can deliver practical sustainability gains while building long-term environmental responsibility habits in users.
