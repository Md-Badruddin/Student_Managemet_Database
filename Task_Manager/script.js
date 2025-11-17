
function getTasks() {
  return JSON.parse(localStorage.getItem("tasks") || "[]");
}

function setTasks(tasks) {
  localStorage.setItem("tasks", JSON.stringify(tasks));
}

function renderTasks() {
  const list = document.getElementById("taskList");
  list.innerHTML = "";
  const tasks = getTasks();
  tasks.forEach((task, idx) => {
    const li = document.createElement("li");
    li.className = task.completed ? "completed" : "";
    li.textContent = task.text;
    const actions = document.createElement("div");
    actions.className = "action-btns";
    const completeBtn = document.createElement("button");
    completeBtn.textContent = task.completed ? "Undo" : "Done";
    completeBtn.onclick = () => {
      tasks[idx].completed = !tasks[idx].completed;
      setTasks(tasks);
      renderTasks();
    };
    const deleteBtn = document.createElement("button");
    deleteBtn.textContent = "Delete";
    deleteBtn.onclick = () => {
      tasks.splice(idx, 1);
      setTasks(tasks);
      renderTasks();
    };
    actions.appendChild(completeBtn);
    actions.appendChild(deleteBtn);
    li.appendChild(actions);
    list.appendChild(li);
  });
}

document.getElementById("addBtn").onclick = function() {
  const input = document.getElementById("taskInput");
  const text = input.value.trim();
  if (text) {
    const tasks = getTasks();
    tasks.push({ text, completed: false });
    setTasks(tasks);
    renderTasks();
    input.value = "";
  }
};

window.onload = renderTasks;
