yash chhillar
2020484
os bonus

I use semaphores to tackle this problem. In this scenario,
I define one counting semaphore table to represent the table.
This will be used to enable or deny any philosopher entry into the room.
This will be set to a maximum value of 5. I've additionally 
defined an array of binary semaphores named forks to represent the problem's five possible forks.

part 1

we create 5 different threads. Each thread here represents a philosopher. In the
function philosopher, we first lock the table. Then we check if the respective
forks for that philosopher are available that is if the respective semaphores
are unlocked. If yes, we lock them and sleep for 3 seconds. Then we make them
available for other processes to use using the post call.
After the thread is completed that is the philosopher has eaten, we join the 
thread back using pthread_join.

part 2

we create 5 different threads. Each thread here represents a philosopher. In the
function philosopher, we first lock the table. Then we check if there is any one 
of the 4 sauce bowl available using the sem_trywait function. We lock that particular 
sauce bowl otherwise we wait for it. Then we check if one of the two respective forks 
for that philosopher are available that is if it the semaphores is unlocked. If yes, 
we lock it and sleep for 3 seconds. Then we make them available for other processes 
to use using the post call.
After the thread is completed that is the philosopher has eaten, we unlock all respective 
semaphores and join the thread back using pthread_join.

part 3

we create 5 different threads. Each thread here represents a philosopher. In the
function philosopher, we first lock the table. Then we check if there is any one 
of the 4 sauce bowl available using the sem_trywait function. We lock that particular 
sauce bowl otherwise we wait for it. Then we check if the respective
forks for that philosopher are available that is if the respective semaphores
are unlocked. If yes, we lock them and sleep for 3 seconds. Then we make them
available for other processes to use using the post call.
After the thread is completed that is the philosopher has eaten, we join the 
thread back using pthread_join
