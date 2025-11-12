
let seconds = 0;
let minutes = 0;
let hours = 0;
let timerInterval = null;

function updateDisplay() {
  const pad = n => n.toString().padStart(2, '0');
  document.getElementById('timer').textContent = `${pad(hours)}:${pad(minutes)}:${pad(seconds)}`;
}

function startTimer() {
  if (timerInterval) return;
  timerInterval = setInterval(() => {
    seconds++;
    if (seconds === 60) { seconds = 0; minutes++; }
    if (minutes === 60) { minutes = 0; hours++; }
    updateDisplay();
  }, 1000);
}

function stopTimer() {
  clearInterval(timerInterval);
  timerInterval = null;
}

function resetTimer() {
  stopTimer();
  seconds = 0; minutes = 0; hours = 0;
  updateDisplay();
}

document.getElementById('startBtn').onclick = startTimer;
document.getElementById('stopBtn').onclick = stopTimer;
document.getElementById('resetBtn').onclick = resetTimer;

updateDisplay();
