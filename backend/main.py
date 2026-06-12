from fastapi.middleware.cors import CORSMiddleware
from fastapi import FastAPI
from fastapi.staticfiles import StaticFiles
from pydantic import BaseModel
import ctypes

app = FastAPI()

app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)


lib = ctypes.CDLL("../libnotes.so")


class CNote(ctypes.Structure):
    _fields_ = [
        ("id", ctypes.c_int),
        ("title", ctypes.c_char * 64),
        ("content", ctypes.c_char * 256),
    ]


class Note(BaseModel):
    title: str
    content: str


lib.api_add_note.argtypes = [ctypes.c_char_p, ctypes.c_char_p]
lib.api_add_note.restype = ctypes.c_int

lib.api_delete_note.argtypes = [ctypes.c_int]
lib.api_delete_note.restype = ctypes.c_int

lib.api_get_all_notes.argtypes = [ctypes.POINTER(CNote), ctypes.c_int]
lib.api_get_all_notes.restype = ctypes.c_int


@app.get("/api/status")
def home():
    return {"message": "Memory Notes API Running"}


@app.get("/notes")
def get_notes():

    arr = (CNote * 100)()

    count = lib.api_get_all_notes(arr, 100)

    result = []

    for i in range(count):
        result.append(
            {
                "id": arr[i].id,
                "title": arr[i].title.decode(),
                "content": arr[i].content.decode(),
            }
        )

    return result


@app.post("/notes")
def create_note(note: Note):

    note_id = lib.api_add_note(note.title.encode(), note.content.encode())

    if note_id == -1:
        return {"message": "Storage Full"}

    return {"message": "Note Added", "id": note_id}


@app.delete("/notes/{note_id}")
def delete_note(note_id: int):

    res = lib.api_delete_note(note_id)

    if res == 0:
        return {"message": "Note Not Found"}

    return {"message": "Note Deleted"}


app.mount("/", StaticFiles(directory="../frontend", html=True), name="static")
