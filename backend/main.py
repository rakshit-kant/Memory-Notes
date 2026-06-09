from fastapi import FastAPI
from pydantic import BaseModel

app = FastAPI()

notes = []
next_id = 1


class Note(BaseModel):
    title: str
    content: str


@app.get("/")
def home():
    return {"message": "Memory Notes API Running"}


@app.get("/notes")
def get_notes():
    return notes


@app.get("/notes/{note_id}")
def get_note(note_id: int):

    for note in notes:
        if note["id"] == note_id:
            return note
    return {"message": "Note Not Found"}


@app.post("/notes")
def create_note(note: Note):

    global next_id

    new_note = {"id": next_id, "title": note.title, "content": note.content}

    notes.append(new_note)

    next_id += 1

    return {"message": "note_added", "note": new_note}


@app.delete("/notes/{note_id}")
def delete_note(note_id: int):

    global notes

    for note in notes:
        if note["id"] == note_id:
            notes.remove(note)

            return {"message": "Note Deleted"}

    return {"message": "Note Not Found"}
