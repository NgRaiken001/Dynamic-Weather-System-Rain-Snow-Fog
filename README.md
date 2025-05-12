# ⛅ Dynamic Weather System (Rain, Snow, Fog) in Unreal Engine

A real-time **dynamic weather system** built in **Unreal Engine** using **Blueprints and C++**, simulating **rain**, **snow**, and **fog** conditions that transition smoothly over time. Ideal for open-world or immersive games requiring environmental variety.

---

## 🎯 Objective

To create a modular, scalable weather system capable of:
- Generating realistic atmospheric effects (rain, snow, fog)
- Dynamically transitioning between weather types
- Affecting lighting and visual ambiance based on weather

---

## 🌦️ Features

- 🌧️ **Rain Effect**: Particle system with wind influence and sound integration.
- ❄️ **Snow Simulation**: Falling snow particles + environmental accumulation.
- 🌫️ **Fog Control**: Uses exponential height fog and post-processing volume.
- 🔁 **Smooth Transitions**: Blend between states using timelines and parameters.
- 📅 **Weather Scheduling**: Randomized or time-of-day based weather changes.
- 🎮 **Editor Customization**: Easily adjustable parameters from Blueprint or C++.

---

## 🛠️ Technologies Used

- **Unreal Engine 5**
- **Blueprints + C++ (Hybrid Implementation)**
- **Particle Systems**
- **Materials and Niagara**
- **Lighting & Fog Volumes**
- **Timelines and Curves**

---

## 📂 Project Structure

```plaintext
/DynamicWeatherSystem/
│
├── C++/
│   ├── WeatherManager.cpp/.h       # Handles weather logic and transitions
│
├── Blueprints/
│   ├── BP_WeatherManager           # Core Blueprint system controller
│   ├── BP_Rain / BP_Snow           # Individual effect blueprints
│
├── Materials/
│   ├── M_RainSplash / M_Snowflake  # Custom shader effects
│
├── Niagara/
│   ├── NS_Rain / NS_Snow           # Niagara systems for precipitation
