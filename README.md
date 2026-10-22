# MARAMMAT TANTRA: Smart Service Center Management System

MARAMMAT TANTRA is an enterprise-grade hybrid service center management platform designed to streamline diagnostic workflows, repair queues, inventory pipelines, and customer relationship management (CRM) across multi-brand electronic and automotive repair hubs.

## 🚀 Project Overview & Hybrid Architecture
The system utilizes a unique hybrid architecture:
- **Web Frontend & Dashboard:** Built with HTML5, Tailwind CSS, and JavaScript, offering responsive layouts, dark/light modes, domain setup wizards, and live analytics.
- **Pure C Backend Kernel:** Implements low-level memory data structures (Stacks & Queues) to handle high-performance operational logic, multi-level undo histories, and Reverse Polish Notation (RPN) pricing evaluations.

---

## 🔑 Key Features & Data Structures Implemented

### 📥 1. Stacks (LIFO Operations)
- **Multi-Level Undo & Redo Mechanism:** Reverts configuration changes, wizard steps, and status updates dynamically.
- **Temporary Job State Stack:** Preserves operational snapshots during shift changes and technician handovers with instant rollback capability.
- **Postfix Expression Evaluation (RPN Engine):** Cleanly calculates complex multi-variable repair pricing (parts cost, labor tiers, GST, promotional discounts) using Reverse Polish Notation.
- **Unsaved Ticket Draft Recovery:** Prevents data loss during form intake processing.

### 📤 2. Queues (FIFO & Priority Pipeline)
- **C-Based FIFO Repair Queue:** Manages incoming customer complaints sequentially with live status tracking.
- **Spare Parts Request Queue & Pipeline:** Prioritizes component requisitions based on urgency, ensuring service tickets lock until warehouse parts are received.
- **Automated Technician Load Balancing:** Routes incoming repair tickets to the least-loaded technician dynamically.
- **Customer Callback & Event Dispatcher:** Handles asynchronous notifications and post-service follow-up pipelines.

---


## 📊 System Architecture & Operation Modes
- **COCO:** Company-Owned, Company-Operated Flagship Centers.
- **ASP:** Authorized Service Provider Franchises.
- **Multi-Brand:** Third-party independent repair hubs.
- **Local Hub:** Unorganized local repair workshops.

---

## 📂 Repository File Structure
```text
marammat-tantra/
│
├── README.md        <-- Project Documentation & Architecture Details
├── index.html       <-- Full Hybrid Web Application Source Code
└── backend.c        <-- Standalone Pure C Backend Kernel (with main() driver)
