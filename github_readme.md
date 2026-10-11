<div align="center">

# 📍 KIIT Campus-25 Navigator

### *Indoor Pathfinding Engine for the School of Computer Engineering*

[![C Standard](https://img.shields.io/badge/C-C99-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C99)
[![Algorithm](https://img.shields.io/badge/Algorithm-Dijkstra's%20Pathfinding-FF6B6B?style=for-the-badge&logo=thealgorithms&logoColor=white)](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)
[![Build](https://img.shields.io/badge/Build-GCC%20%7C%20Clang-success?style=for-the-badge&logo=gnu&logoColor=white)](#-quick-start)
[![License](https://img.shields.io/badge/License-MIT-blue?style=for-the-badge)](LICENSE)

<br />

<p align="center">
  <b>A lightweight, zero-dependency graph routing engine built in C.</b><br />
  Maps multi-floor building topologies and computes minimal-cost walking trajectories using step-range estimations.
</p>

[Explore The Map](#-topology-data-format) •
[Quick Start](#-quick-start) •
[Algorithm Details](#-algorithm--math) •
[Troubleshooting](#-troubleshooting)

</div>

---

## 🧭 Overview

Satellite-based navigation (GPS) degrades significantly within dense multi-floor structures. **Campus-25 Navigator** solves this for the KIIT School of Computer Engineering by modeling the facility as a discrete weighted graph.

```
       [Main_Entrance_A]
               │
               ▼  (avg. 20 steps)
            [A001]
               │
               ▼  (avg. 15 steps)
            [A002] ══════════════════════════════════► [A201]
                     Staircase climb (avg. 50 steps)     (Destination Lab)
```

### Highlights
- ⚡ **Pure Standard C:** Zero third-party dependencies; compiles anywhere in milliseconds.
- 📐 **Graph Modeling:** Automatic bidirectional edge synthesis with runtime average step resolution.
- 🎯 **Deterministic Routing:** Guarantees lowest estimated foot-traffic effort via Dijkstra's shortest-path algorithm.
- 📄 **Data-Decoupled:** Modify room connections, blockages, or new floors inside `navigation_data.txt` without touching or recompiling code.

---

## 🧠 Algorithm & Math

### 1. Midpoint Step Weighting
Corridor traversal costs are represented as intervals $[\text{MinSteps}, \text{MaxSteps}]$. The graph compiler computes edge weight $W(u, v)$ as:

$$W(u, v) = \frac{\text{MinimumSteps} + \text{MaximumSteps}}{2}$$

Because hallways support two-way pedestrian movement, each valid entry creates symmetric edges:

$$(u, v) \in E \iff (v, u) \in E, \quad W(u, v) = W(v, u)$$

### 2. Path Finding
Starting from node $S$, the algorithm iteratively explores the minimum tentatively weighted node $u$:

$$\text{dist}[v] = \min \Big( \text{dist}[v], \, \text{dist}[u] + W(u, v) \Big)$$

---

## 📂 Repository Structure

```text
kiit-campus-25-navigation/
│
├── navigation.c             # Graph ingestion, matrix/list construction & Dijkstra engine
├── navigation_data.txt      # Campus topology definition (Nodes, Edges, Step spans)
└── README.md                # Documentation & usage manual
```

---

## 🗺 Topology Data Format

The campus map resides entirely in `navigation_data.txt`. Each connection is structured as four whitespace-separated tokens:

```text
<Location1> <Location2> <MinimumSteps> <MaximumSteps>
```

### Sample Dataset

```text
# Ground Floor Corridors
Main_Entrance_A   A001              15   25
A001              A002              10   20

# Staircase Transitions
A002              A201              40   60

# Second Floor Corridors
A201              Lab_Network_01    12   18
```

> [!NOTE]
> Node names must use underscores (`_`) instead of whitespace (e.g., `Main_Entrance_A`). Empty lines and lines starting with `#` are ignored by the parser.

---

## 🚀 Quick Start

### Prerequisites
- Any standard C compiler: `gcc`, `clang`, or `cl` (MSVC).

### 1. Clone & Navigate
```bash
git clone https://github.com/your-username/kiit-campus-25-navigation.git
cd kiit-campus-25-navigation
```

### 2. Compile

```bash
# Using GCC with standard optimizations
gcc -O2 navigation.c -o navigation
```

### 3. Run

> [!IMPORTANT]
> Keep `navigation_data.txt` in the same directory where you execute the binary.

**Windows:**
```powershell
.\navigation.exe
```

**Linux / macOS:**
```bash
./navigation
```

---

## 💻 Terminal Preview

```text
=======================================================
            KIIT CAMPUS-25 INDOOR NAVIGATOR
=======================================================
Loaded graph topology from navigation_data.txt

[>] Enter starting location: Main_Entrance_A
[>] Enter destination      : A201

[✓] Optimal Route Found:
    Main_Entrance_A  ──>  A001  ──>  A002  ──>  A201

[*] Estimated Foot Effort  : ~85 steps (~1 min walk)
=======================================================
```

---

## 🔧 Troubleshooting

<details>
<summary><b>Click to expand common issues & solutions</b></summary>

<br />

| Symptom / Log Output | Cause | Solution |
| :--- | :--- | :--- |
| `Cannot open navigation_data.txt` | Binary invoked from a different path | Ensure the file exists in your active shell directory (`pwd` / `cd`). |
| `Invalid starting location or destination!` | Mismatched ID casing or typo | Check IDs against `navigation_data.txt` (IDs are strictly case-sensitive). |
| `No route found!` | Disconnected node island | Inspect data file to verify a continuous edge chain connects both endpoints. |
| Undefined symbols on compile | Obsolete compiler version | Use standard GCC command: `gcc navigation.c -o navigation`. |

</details>

---

## 🛣 Future Enhancements

- [ ] **Min-Heap Optimization:** Transition to an indexed binary min-heap for $O(E \log V)$ scaling on campus-wide graphs.
- [ ] **Accessibility Profile (`--accessible`):** Flag to exclude high-cost stairs and re-route via elevator nodes.
- [ ] **Turn-By-Turn Vector Cues:** Directional indicators (e.g., *Left*, *Right*, *Floor Shift*).
- [ ] **WebAssembly (WASM) Playground:** Browser-based interactive layout viewer.

---

<div align="center">

Crafted for **KIIT School of Computer Engineering (Campus-25)**  
*Graph Theory • C Systems Programming*

</div>