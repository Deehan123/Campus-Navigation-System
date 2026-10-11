# KIIT Campus-25 Navigation System

A C-based indoor navigation CLI application developed for the KIIT School of Computer Engineering. The program models the campus floor plan as a bidirectional weighted graph and applies **Dijkstra's Algorithm** to compute the optimal walking path between indoor locations based on estimated step counts.

---

## Table of Contents
- [Project Overview](#project-overview)
- [Repository Structure](#repository-structure)
- [How It Works](#how-it-works)
- [Data Format Specification](#data-format-specification)
- [Prerequisites](#prerequisites)
- [Build and Run](#build-and-run)
- [Sample Usage](#sample-usage)
- [Troubleshooting](#troubleshooting)
- [Known Limitations](#known-limitations)

---

## Project Overview

Indoor positioning systems (GPS) often fail inside multi-story academic blocks. This utility serves as a terminal-based routing assistant for Campus-25:
- Parses indoor connectivity and step ranges from an external configuration file.
- Builds an in-memory adjacency representation of rooms, corridors, and entrances.
- Calculates and renders the shortest path along with estimated total steps.

---

## Repository Structure

```text
.
├── navigation.c           # Core application source code (Graph parser & Dijkstra solver)
├── navigation_data.txt    # Campus graph dataset (Nodes, edges, and step intervals)
└── README.md              # Project documentation
