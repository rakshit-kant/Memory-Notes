const API_URL = "http://127.0.0.1:8000";

const notesDiv = document.getElementById("notes");


async function loadNotes() {

  notesDiv.innerHTML = "";

  try {

    const response = await fetch(`${API_URL}/notes`);

    const notes = await response.json();

    if (notes.length === 0) {
      notesDiv.innerHTML = `<p>No Notes Yet... Start your Productivity</p>`;
      return;
    }

    notes.forEach((note) => {

      notesDiv.innerHTML += `
                    <div class ="note-card">

                      <h3>${note.title}</h3>

                      <p>${note.content}</p>

                      <button
                        class="delete-btn"
                        onclick="deleteNote(${note.id})"
                      >
                        Delete
                      </button>
                    </div>
`;
    });

  } catch (error) {

    console.error(error);

    notesDiv.innerHTML = `
          <p>Failed to Load Notes</p>
`;
  }
}


async function addNote() {

  const titleInput = document.getElementById("title");

  const contentInput = document.getElementById("content");

  const title = titleInput.value.trim();
  const content = contentInput.value.trim();


  if (!title || !content) {
    alert("Fill all Fields!");
    return;
  }

  try {

    const response = await fetch(`${API_URL}/notes`, {
      method: "POST",

      headers: {
        "Content-Type": "application/json"
      },

      body: JSON.stringify({
        title,
        content
      })
    });

    const data = await response.json();

    console.log(data);

    titleInput.value = "";
    contentInput.value = "";

    await loadNotes();

  } catch (error) {

    console.error(error);

    alert("Failed to Add Note");
  }
}

async function deleteNote(id) {

  try {

    await fetch(`${API_URL}/notes/${id}`, {
      method: "DELETE"
    });

    await loadNotes();

  } catch (error) {

    console.error(error);

    alert("Failed to Delete Note");
  }
}


loadNotes();
