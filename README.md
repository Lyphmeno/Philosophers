<!DOCTYPE html>
<html>
<body>
  <h1>Philosophers : <a href="https://github.com/JaeSeoKim/badge42"><img src="https://badge42.vercel.app/api/v2/cljbd5ceo007308mltneinai5/project/2353767" alt="hlevi's 42 Philosophers Score" /></a></h1>
  
  <h2>Project Description</h2>
  <p>The Philosophers project involves simulating a dining philosophers problem. The programs simulate philosophers sitting at a table and performing eating, sleeping, and thinking actions using threads and mutexes.</p>
  
  <h2>Project Requirements</h2>
  <ul>
    <li>Global variables are forbidden.</li>
    <li>The program(s) should take the following arguments:</li>
    <ul>
      <li>number_of_philosophers: The number of philosophers and also the number of forks.</li>
      <li>time_to_die (in milliseconds): If a philosopher doesn't start eating within time_to_die milliseconds since their last meal or the beginning of the simulation, they die.</li>
      <li>time_to_eat (in milliseconds): The time it takes for a philosopher to eat. During this time, they will hold two forks.</li>
      <li>time_to_sleep (in milliseconds): The time a philosopher spends sleeping.</li>
      <li>number_of_times_each_philosopher_must_eat (optional argument): If specified, the simulation stops when all philosophers have eaten at least this many times. If not specified, the simulation stops when a philosopher dies.</li>
    </ul>
    <li>Each philosopher has a unique number ranging from 1 to number_of_philosophers.</li>
    <li>Philosopher number 1 sits next to philosopher number number_of_philosophers. Any other philosopher N sits between philosopher N - 1 and philosopher N + 1.</li>
    <li>State changes of a philosopher should be logged with the following format:</li>
    <ul>
      <li>timestamp_in_ms X has taken a fork</li>
      <li>timestamp_in_ms X is eating</li>
      <li>timestamp_in_ms X is sleeping</li>
      <li>timestamp_in_ms X is thinking</li>
      <li>timestamp_in_ms X died</li>
    </ul>
    <li>A displayed state message should not be mixed up with another message.</li>
    <li>A message announcing a philosopher's death should be displayed no more than 10 ms after the actual death of the philosopher.</li>
    <li>Philosophers should avoid dying!</li>
  </ul>
  
<h2>Getting Started</h2>
To solve the dining philosophers problem, you can follow these general steps:

<ol>
  <li>Identify the main components needed for the solution, such as philosophers, forks, and threads.</li>
  <li>Design a solution that ensures mutual exclusion and avoids deadlocks and resource starvation.</li>
  <li>Here is a little tip, you can use Atomic variable to avoid data race.</li>
</ol>
  
  <h2>Resources</h2>
  <ul>
    <li><a href="https://en.wikipedia.org/wiki/Dining_philosophers_problem">Dining philosopher problem</a> in order to picture it better</li>
    <li><a href="https://www.tala-informatique.fr/wiki/index.php/C_pthread">Threads & Mutex</a></li>
  </ul>

</body>
</html>
