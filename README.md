Philosophers :
==============

Project Description
-------------------

The Philosophers project involves simulating a dining philosophers problem. The programs simulate philosophers sitting at a table and performing eating, sleeping, and thinking actions using threads and mutexes.

Project Requirements
--------------------

* Global variables are forbidden.
* The program(s) should take the following arguments:
  * number\_of\_philosophers: The number of philosophers and also the number of forks.
  * time\_to\_die (in milliseconds): If a philosopher doesn't start eating within time\_to\_die milliseconds since their last meal or the beginning of the simulation, they die.
  * time\_to\_eat (in milliseconds): The time it takes for a philosopher to eat. During this time, they will hold two forks.
  * time\_to\_sleep (in milliseconds): The time a philosopher spends sleeping.
  * number\_of\_times\_each\_philosopher\_must\_eat (optional argument): If specified, the simulation stops when all philosophers have eaten at least this many times. If not specified, the simulation stops when a philosopher dies.

* Each philosopher has a unique number ranging from 1 to number\_of\_philosophers.
* Philosopher number 1 sits next to philosopher number number\_of\_philosophers. Any other philosopher N sits between philosopher N - 1 and philosopher N + 1.
* State changes of a philosopher should be logged with the following format:
  * timestamp\_in\_ms X has taken a fork
  * timestamp\_in\_ms X is eating
  * timestamp\_in\_ms X is sleeping
  * timestamp\_in\_ms X is thinking
  * timestamp\_in\_ms X died

* A displayed state message should not be mixed up with another message.
* A message announcing a philosopher's death should be displayed no more than 10 ms after the actual death of the philosopher.
* Philosophers should avoid dying!

Getting Started
---------------

To solve the dining philosophers problem, you can follow these general steps:

1.  Identify the main components needed for the solution, such as philosophers, forks, and threads.
2.  Design a solution that ensures mutual exclusion and avoids deadlocks and resource starvation.
3.  Here is a little tip, you can use Atomic variable to avoid data race.

Resources
---------

* [Dining philosopher problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem) in order to picture it better
* [Threads & Mutex](https://www.tala-informatique.fr/wiki/index.php/C_pthread)
