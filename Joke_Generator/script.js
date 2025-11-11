
const jokes = [
  "Why did the scarecrow win an award? Because he was outstanding in his field.",
  "Why don’t scientists trust atoms? Because they make up everything!",
  "Why did the math book look sad? Because it had too many problems.",
  "Parallel lines have so much in common. It’s a shame they’ll never meet.",
  "What do you call fake spaghetti? An Impasta!",
  "Why don’t programmers like nature? It has too many bugs.",
  "I'm reading a book on anti-gravity. It's impossible to put down!"
];

function showJoke() {
  const randomIndex = Math.floor(Math.random() * jokes.length);
  document.getElementById('jokeBox').textContent = jokes[randomIndex];
}

document.getElementById('jokeBtn').onclick = showJoke;

window.onload = showJoke;
