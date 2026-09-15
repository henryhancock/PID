import json
import matplotlib.pyplot as plt

with open('sim_data.json') as f:
    data = json.load(f)

plt.figure(figsize=(12, 6))

plt.subplot(1, 2, 1)
plt.plot(data['time'], data['error_x'], label='error_x', linewidth=2)
plt.plot(data['time'], data['error_y'], label='error_y', linewidth=2)
plt.xlabel('Time (s)')
plt.ylabel('Error')
plt.title('Tracking Error')
plt.legend()
plt.grid()

plt.subplot(1, 2, 2)
plt.plot(data['time'], data['dx'], label='x', linewidth=2)
plt.plot(data['time'], data['dy'], label='y', linewidth=2)
plt.xlabel('Time (s)')
plt.ylabel('Position')
plt.title('Position vs Time')
plt.legend()
plt.grid()

plt.tight_layout()
plt.savefig('sim_plot.png')
plt.show()