![Memory Notes Screenshot](assets/screenshot.png)

# Memory Notes

Memory Notes is a simple full-stack notes application built around a C core, with a FastAPI backend and a traditional HTML, CSS, and JavaScript frontend. It allows users to create, view, and delete notes while exploring how low-level C code can be integrated into a modern web application through shared libraries and Python's ctypes. The project was built to learn modular software design in C, memory management, file persistence, shared libraries, REST APIs, Docker-based deployment, and full-stack application development.

## Run

```bash
gcc -shared -fPIC -o libnotes.so src/*.c

cd backend
uvicorn main:app --reload

cd ../frontend
python -m http.server 5500
```

## LICENSE

MIT
