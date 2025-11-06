
function getExpenses() { return JSON.parse(localStorage.getItem("expenses")||"[]"); }
function setExpenses(arr) { localStorage.setItem("expenses", JSON.stringify(arr)); }
function renderExpenses() {
  const list = document.getElementById("list"), total = document.getElementById("total");
  const arr = getExpenses(); list.innerHTML = "";
  let sum = 0;
  arr.forEach((exp, idx) => {
    sum += exp.amount;
    const li = document.createElement("li");
    li.textContent = `${exp.desc}: ₹${exp.amount}`;
    const delBtn = document.createElement("button");
    delBtn.textContent = "Delete"; delBtn.className = "delete";
    delBtn.onclick = () => { arr.splice(idx, 1); setExpenses(arr); renderExpenses(); };
    li.appendChild(delBtn); list.appendChild(li);
  });
  total.textContent = `Total: ₹${sum}`;
}
document.getElementById("addBtn").onclick = function() {
  const desc = document.getElementById("desc").value.trim();
  const amount = parseFloat(document.getElementById("amount").value);
  if(desc && !isNaN(amount) && amount > 0) {
    const arr = getExpenses(); arr.push({desc, amount}); setExpenses(arr); renderExpenses();
    document.getElementById("desc").value = ""; document.getElementById("amount").value = "";
  }
};
window.onload = renderExpenses;
