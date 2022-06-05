#include <mpi.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
int process_count;
int my_rank;
int is_prime(int n) {
	int top, d;
	top = (int)(sqrt((double)n) + 0.0001);
	for (d = 2; d <= top; d++)
		if (n % d == 0)
			return 0;
	return 1;
}
void do_work() {
	int number = 84;
	int current_prime;
	int primes[10];
	int i = 0;
	int j = 0;
	for (j = 2; i < 10; j++) {
		if (is_prime(j)) {
			primes[i] = j;
			i++;
		}
	}
	if (my_rank == 0) {
		printf("number %d\n", number);
		current_prime = primes[my_rank];
		while (current_prime <= number) {
			if (number % current_prime == 0) {
				number = number / current_prime;
				printf("divider %d \n", current_prime);
				if (number == 1)
					return;
			}
			else {
				int data_to_send[1];
				data_to_send[0] = number;
				MPI_Send(data_to_send, 1, MPI_INT, my_rank + 1, 0, MPI_COMM_WORLD);
				return;
			}
		}
	}
	else {
		int data_to_recv[1];
		MPI_Recv(data_to_recv, 1, MPI_INT, (my_rank - 1) % process_count, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		current_prime = primes[my_rank];
		number = data_to_recv[0];
		while (current_prime <= number) {
			if (number % current_prime == 0) {
				number = number / current_prime;
				printf("divider %d \n", current_prime);
			}
			else {
				int data_to_send[1];
				data_to_send[0] = number;
				MPI_Send(data_to_send, 1, MPI_INT, (my_rank + 1) % process_count, 0, MPI_COMM_WORLD);
				return;
			}
		}
	}
}
int main(int argc, char** argv) {
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &process_count);
	do_work();
	MPI_Finalize();
}


}
