
document.getElementById('rollBtn').onclick = function() {
  const roll = Math.floor(Math.random() * 6) + 1;
  const diceDisplay = document.getElementById('diceDisplay');
  const result = document.getElementById('result');
  
  diceDisplay.textContent = ['⚀','⚁','⚂','⚃','⚄','⚅'][roll-1];
  result.textContent = `You rolled a ${roll}!`;
};
