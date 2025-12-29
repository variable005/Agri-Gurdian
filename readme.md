# Agri Guardian

Agri Guardian is a GenAI-assisted crop monitoring and decision-support prototype.  
It combines environmental sensing with explainable AI reasoning to provide clear, practical crop guidance instead of opaque or overconfident recommendations.

The project focuses on **interpretability, reliability, and real-world feasibility**, especially for low-connectivity agricultural environments.

---

Agri Guardian processes field-level data such as temperature, humidity, soil temperature, and light intensity, and uses a Generative AI model to:

- Suggest crop-care actions  
- Explain why a recommendation is made  
- Express confidence and uncertainty  
- Provide actionable Do’s and Don’ts  

Rather than acting as a black box, the system makes its reasoning visible.

---

## Tools & Technologies Used

### Hardware (Prototype / Simulated)
- ESP32  
- DHT22 – Temperature & Humidity  
- DS18B20 – Soil Temperature  
- LDR – Light Intensity  
- OLED Display  
- MQ-series Gas Sensor (environment safety indicator)  

### Software & AI
- **Gemma 3** (local LLM)
- **LM Studio** (local inference server)
- **Python FastAPI** (local AI backend / API layer)
- HTML, CSS, JavaScript (Web Dashboard)
- OpenAI-compatible API workflow
- Wokwi (used during simulation and testing)

---

## How AI Is Used

Agri Guardian uses **Gemma 3 running locally via LM Studio** as its reasoning engine.

AI is not used for simple threshold-based logic. Instead, the model:

- Interprets multiple environmental signals together  
- Weighs conflicting conditions  
- Generates explainable decisions in natural language  
- Outputs confidence levels to reflect uncertainty  

FastAPI acts as a lightweight bridge between the web dashboard and the local GenAI engine.

This design allows the system to work **offline-first**, while remaining compatible with cloud-based GenAI services.

---

## Demo Images

### Sensor View
![Sensor View](demo.png)

### Dashboard & AI Verdict
![Dashboard View](demo1.png)

---

## System Flow

1. Environmental data is collected (real or simulated)
2. Data is structured and sent to the FastAPI backend
3. FastAPI forwards the data to the local Gemma 3 model via LM Studio
4. GenAI generates:
   - Decision
   - Confidence score
   - Reasoning
   - Do’s and Don’ts
5. Output is rendered on the web-based dashboard

---

## Hackathon Context

Built for the **GenAI Hackathon Hajipur** under the **AgriTech** theme, aligned with Google’s GenAI ecosystem and responsible AI practices.

---

## Current Status

- Core system functional  
- Local GenAI (Gemma 3) integration complete  
- FastAPI backend operational  
- Web dashboard working  
- Cloud-compatible architecture (Gemini-ready)

---

## Future Scope

- Deployment on **NVIDIA Jetson Nano** for edge inference
- Fully live sensor data streaming
- Crop- and growth-stage–specific advisory models
- Multilingual AI responses for regional accessibility
- Mobile-first dashboard
- Cloud scaling using Gemini / Google Cloud APIs

---

This project is a hackathon prototype focused on **clarity, explainability, and reliability**, prioritizing real-world constraints over feature overload.

##Developed by Hariom Sharnam
