FROM python:3.12-slim

# install gcc to compile the C library
RUN apt-get update && apt-get install -y gcc && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# copy everything
COPY . .

# compile the C shared library
RUN gcc -shared -fPIC -o libnotes.so src/*.c

# install Python deps
RUN pip install fastapi uvicorn

# serve frontend statically from FastAPI
WORKDIR /app/backend

EXPOSE 8000

CMD ["uvicorn", "main:app", "--host", "0.0.0.0", "--port", "8000"]
