
#MPI

the purpose of mpi is to allow parallelisation over sevral computer


First
---

export RSHCOMMAND=ssh

allow the connection to other computer ( ssh keygen)


create a hosts file containing all machin names
ex:
	ensipc174
	ensipc168
	...


RUN
---
mpirun --mca pml ob1 --mca btl self,tcp -machinefile hosts -np 135 display_mpi
