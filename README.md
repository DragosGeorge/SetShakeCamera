# ENABLE_SHAKE_CAMERA

## 📖 Description
This system adds a **camera shake** effect to the game, fully controllable directly from Python.

It can be used for:
- earthquakes
- special skills
- boss effects
- dungeon events
- heavy impacts
- any moment where you want to simulate aggressive camera movement

The system works using two values:
1. **Duration** of the effect (in seconds)
2. **Intensity level**

---

# 🛠 Usage

## Start shake
```python
import app
app.SetShakeCamera(2.5, 4)
```

## Strong shake
```python
import app
app.SetShakeCamera(5.0, 10)
```

## Manual stop
```python
import app
app.SetShakeCamera(0.0, 0)
```

---

# 📌 Example

```python
import app
app.SetShakeCamera(3.0, 5)
```

This call starts a camera shake effect for **3 seconds** with intensity level **5**.

---

# 🎚 Recommended Intensity Levels

| Intensity | Description |
|------------|-------------|
| 1 - 2 | Very light, suitable for small impacts |
| 3 - 5 | Medium, good for skills or normal effects |
| 6 - 8 | Strong, ideal for boss attacks or short earthquakes |
| 9 - 10 | Extremely aggressive, recommended only for short durations |

> The intensity level is internally limited between **1** and **10**.

---

# ⚙️ Behavior

- The shake effect is applied directly to the game camera.
- The system can be called from any Python script.
- If the duration is set to `0.0`, the effect stops instantly.
- High intensity values may produce aggressive visual effects and should be used carefully.

---

# ✅ Requirements

Make sure the define is enabled:

```cpp
#define ENABLE_SHAKE_CAMERA
```

---

# 📂 Available Function

```python
app.SetShakeCamera(duration, intensity)
```

### Parameters

| Parameter | Type | Description |
|------------|------|-------------|
| duration | float | Effect duration in seconds |
| intensity | int | Effect strength (1-10) |

---

# 💡 Usage Examples

### Boss spawn
```python
app.SetShakeCamera(4.0, 7)
```

### Meteor / impact
```python
app.SetShakeCamera(2.0, 5)
```

### Dungeon earthquake
```python
app.SetShakeCamera(8.0, 6)
```

### Ultimate skill
```python
app.SetShakeCamera(1.5, 9)
```

