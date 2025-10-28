# 🧮 Math-Guard

**A safer way to perform mathematical operations in C — with automatic logging, auditing, and fault-injection controls.**

---

## 🚀 Overview

Math-Guard is a lightweight C library that wraps standard math functions with:
- **Safety checks**
- **Structured logging (JSON & stderr)**
- **Configurable “sabotage” modes** for fault injection or resilience testing

It’s designed for engineers who need **traceable, testable math operations** in sensitive or audited systems.

---

## ✨ Features

- ✅ Safe wrappers for common math operations (`sin`, `exp`, `fmod`, etc.)
- 🧾 Optional JSON-line ledger logging
- ⚙️ Configurable sabotage/failure modes
- 🧪 Unit tests included (`make test`)
- 🤖 GitHub Actions CI workflow ready
- 📦 Simple `Makefile` build system

---

## 🧰 Getting Started

### Requirements
- GCC or Clang
- `make`
- (Optional) GitHub account for CI integration

### Build
```bash
git clone https://github.com/litalien101/math-guard.git
cd math-guard
make
Run Tests
bash
Copy code
make test
Enable detailed logging:

bash
Copy code
export MATH_LEDGER_FILE=test_logs.jsonl
make test
📘 Usage
Include in Your Project
c
Copy code
#include "math_guard.h"

double result = safe_sin(angle);
Math-Guard will:

Execute the safe wrapper

Log inputs, outputs, and error states

Write structured events to your ledger file

Example Environment Logging
bash
Copy code
export MATH_LEDGER_FILE=math_ledger.jsonl
./your_program
A sample log entry:

json
Copy code
{
  "function": "safe_exp",
  "input": 1.2,
  "output": 3.3201169,
  "status": "ok",
  "timestamp": "2025-10-27T20:41:33Z"
}
⚡ Configurable Sabotage Modes
You can simulate controlled failures for testing system resilience.

Example:

c
Copy code
#define SABOTAGE_EXP_RETURN_VALUE -999.0
Math-Guard will return the sabotage value and log it as:

json
Copy code
{"function": "safe_exp", "status": "sabotaged"}
🧱 Project Structure
bash
Copy code
math-guard/
├── Makefile
├── main.c
├── math_guard.c / .h
├── math_ledger.c / .h
├── math_types.h
├── math_simd.c
├── test/
│   └── test_math_guard.c
└── .github/workflows/ci.yml
🧩 Example Workflow (CI)
GitHub Actions workflow automatically:

Builds the library

Runs unit tests

Reports any safety or logging failures

View it under .github/workflows/ci.yml

🧑‍💻 Contributing
Contributions are welcome!

Fork the repo

Create a feature or bugfix branch

Run tests and ensure everything passes

Open a pull request with a clear description

📜 License
Licensed under the MIT License — see LICENSE for details.

🙏 Acknowledgments
Developed by Michael Litalien
Inspired by the need for transparent, traceable math operations in C projects.

“Trust, but verify — even in arithmetic.”
