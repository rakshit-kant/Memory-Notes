![Memory Notes Screenshot](assets/screenshot.png)

# Memory Notes

Memory Notes is a simple full-stack notes application built around a C core, with a FastAPI backend and a traditional HTML, CSS, and JavaScript frontend. The project was built to learn modular software design in C, memory management, file persistence, shared libraries, REST APIs, Docker-based deployment, and full-stack application development.

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
