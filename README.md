![Memory Notes Screenshot](assets/screenshot.png)

# Memory Notes

A fast, full-stack notes app powered by a **C backend**, wrapped in **FastAPI**, with a clean vanilla **HTML/CSS/JS** frontend.

Originally started as a CLI project to learn C fundamentals — now evolved into a complete web app with a REST API and modern UI.

## Features

- Add, view, and delete notes
- Notes stored and managed by a custom C library (compiled to `.so`)
- FastAPI REST API wrapping the C core via `ctypes`
- Clean, responsive frontend UI

## Tech Stack

| Layer    | Tech                           |
| -------- | ------------------------------ |
| Core     | C (compiled to shared library) |
| Backend  | Python, FastAPI, ctypes        |
| Frontend | HTML, CSS, JavaScript          |

## Project Structure

```txt
memory-notes/
├── include/          # C header files
├── src/              # C source files
├── libnotes.so       # Compiled C shared library
├── backend/
│   └── main.py       # FastAPI app
├── frontend/
│   ├── index.html
│   ├── style.css
│   └── script.js
└── README.md
```

## Setup

### 1. Compile the C library

```bash
gcc -shared -fPIC -o libnotes.so src/*.c

(For Linux Users)
```

### 2. Run the backend

```bash
cd backend
pip install fastapi uvicorn
uvicorn main:app --reload
```

The API will be running at `http://127.0.0.1:8000`

### 3. Run the frontend

```bash
cd frontend
python -m http.server 5500
```

Open `http://127.0.0.1:5500` in your browser.

## API Endpoints

| Method | Endpoint      | Description         |
| ------ | ------------- | ------------------- |
| GET    | `/notes`      | Get all notes       |
| POST   | `/notes`      | Add a new note      |
| DELETE | `/notes/{id}` | Delete a note by ID |

## Purpose

This project was built for learning:

- C fundamentals — structs, pointers, arrays, manual memory management
- Bridging C and Python with `ctypes`
- Building and consuming a REST API with FastAPI
- Frontend development with vanilla JS

## License

This project is licensed under the [MIT License](LICENSE).
