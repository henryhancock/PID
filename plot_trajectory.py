import json
import matplotlib.pyplot as plt
import numpy as np

with open('sim_data.json') as f:
    data = json.load(f)

fig, ax = plt.subplots(figsize=(10, 10))

ax.plot(data['dx'], data['dy'], 'b-', linewidth=2, label='Object Path', alpha=0.7)

ax.scatter(data['dx'][0], data['dy'][0], color='green', s=100, marker='o', label='Start', zorder=5)
ax.scatter(data['dx'][-1], data['dy'][-1], color='red', s=100, marker='s', label='End', zorder=5)

circle_x = 10 * np.cos(np.linspace(0, 2*np.pi, 200))
circle_y = 10 * np.sin(np.linspace(0, 2*np.pi, 200))
ax.plot(circle_x, circle_y, 'k--', linewidth=1.5, label='Target Trajectory', alpha=0.5)

ax.set_xlabel('X Position', fontsize=12)
ax.set_ylabel('Y Position', fontsize=12)
ax.set_title('PID Trajectory Tracking - Circular Path', fontsize=14, fontweight='bold')
ax.grid(True, alpha=0.3)
ax.axis('equal')
ax.legend(loc='upper right', fontsize=10)

plt.tight_layout()
plt.show()